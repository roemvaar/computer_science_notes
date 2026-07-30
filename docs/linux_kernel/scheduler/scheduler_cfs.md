---
layout: default
title: CFS
parent: Scheduler
nav_order: 1
---

# Completely Fair Scheduler (CFS)

`kernel/sched/fair.c`

## Implementation of CFS

## Time Accounting

All process schedulers must account for the time that a process runs. Linux keeps an account of the time that each process runs because it needs to ensure that each process runs only for its fair share of the processor. CFS uses the **scheduler entity structure**, `struct sched_entity` in `include/linux/sched.h`, to keep track of process accounting. The scheduler entity structure is embedded in the process descriptor, `struct task_struct`, as a member variable named se.

### Virtual Runtime (vruntime)

The vruntime variable stores the virtual runtime of a process, which is the actual runtime (the amount of time spent running) normalized (or weighted) by the number of runnable processes. The virtual runtime’s units are nanoseconds. CFS uses vruntime to account for how long a process has run and, thus, how much longer it ought to run.

The function [update_curr()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/fair.c#L1156) in **`kernel/sched/fair.c`** manages this accounting. `update_curr()` calculates the execution time of the current process and stores that value in `delta_exec`. The current process’s `vruntime` is then incremented by the weighted value.

**`update_curr()` is invoked periodically by the system timer, and whenever a process becomes runnable or blocks, it becomes unrunnable.** In this manner, vruntime is an accurate measure of the runtime of a given process and an indicator of what process should run next. 

On real hardware, we can run only a single task at once. Thus, we introduce the concept of “virtual runtime.” The virtual runtime of a task specifies when its next timeslice would start execution on the ideal multitasking CPU. In practice, the virtual runtime of a task is its actual runtime normalized to the total number of running tasks.

In CFS the virtual runtime is expressed and tracked via the per-task p->se.vruntime (nanosec-unit) value. This value represents how much CPU time the task has used. This way, it’s possible to accurately timestamp and measure the “expected CPU time” a task should have gotten.

The vruntime is incremented based on the actual time a task runs, but tasks with lower priority (i.e., nice values) will have their runtime increased faster, so higher priority tasks (with lower nice values) get more CPU time.

## Process Selection

**When CFS is deciding what process to run next, it picks the process with the smallest vruntime.** This is the core of CFS’s scheduling algorithm.

CFS’s task picking logic is based on this p->se.vruntime value and it is thus very simple: it always tries to run the task with the smallest p->se.vruntime value (i.e., the task which executed least so far). CFS always tries to split up CPU time between runnable tasks as close to “ideal multitasking hardware” as possible.

### Red-Black Tree (rbtree)

CFS uses a **red-black tree** to manage the list of runnable processes and efficiently find the process with the smallest vruntime. A red-black tree, called an **rbtree** in Linux, is a type of **self-balancing binary search tree**. Red-black trees are a data structure that store **nodes** of arbitrary data, identified by a specific **key**, and that enable efficient search for a given **key**. Specifically, obtaining a node identified by a given key is logarithmic in time as a function of total nodes in the tree.

Tasks are stored in a time-ordered (sorted based on their vruntime) rbtree to build a “timeline” of future task execution. The task with the smallest vruntime (i.e., the task that has used the least CPU time compared to the other tasks) is always selected to run next.

This ensures that tasks that have not had a chance to run for a while are favored to get scheduled soon, ensuring fairness.

CFS’s process selection algorithm is thus summed up as “run the process represented by the leftmost node in the rbtree.”

## Process Selection

### Red-Black Tree (rbtree)

Let’s start with the assumption that we have a red-black tree populated with every runnable process in the system where the key for each node is the runnable process’s virtual runtime. Given this tree, the process that CFS wants to run next, which is the process with the smallest vruntime, is the **leftmost node in the tree**. That is, if you follow the tree from the root down through the left child, and continue moving to the left until you reach a leaf node, you find the process with the smallest vruntime. The process that performs this selection is [pick_next_entity()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/fair.c#L5472), defined in kernel/sched/fair.c. If the function returns NULL, there is no leftmost node, and thus no nodes in the tree. In that case, there are no runnable processes, and CFS schedules the idle task.

CFS adds processes to the rbtree and caches the leftmost node when a process becomes runnable (wake up) or is first created via `fork()`. Adding processes to the tree is performed by [enqueue_entity()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/fair.c#L5282), although this function is more for updating the runtime and statistics. The actual heavy lifting of inserting the entry into the red-black tree is handled by [__enqueue_entity()](https://elixir.bootlin.com/linux/v6.11/C/ident/__enqueue_entity).

`dequeue_entity()` and `__dequeue_entity()` are used to remove a process from the red-black tree. This happens when a process blocks (becomes unrunnable) or terminates (ceases to exist).

### The Scheduler Entry Point

The main entry point into the process schedule is the function [schedule()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/core.c#L6611) defined in `kernel/sched/core.c`. This is the function that the rest of the kernel uses to invoke the process scheduler, deciding which process to run and then running it.

Schedule is generic with respect to scheduler classes. That is, it finds the highest priority scheduler class with a runnable process and asks it what it wants to run next.

The most important part of `schedule()` is its invocation of [__pick_next_task()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/core.c#L5798), this function goes through each scheduler class, starting with the highest priority, and selecting the highest priority process in the highest priority class. Because CFS is the scheduler class for normal processes, and most systems run mostly normal processes, there is a small hack to quickly select the next CFS-provided process if the number of runnable processes is equal to the number of CFS runnable process (which suggests that all runnable processes are provided by CFS).

### Sleeping and Waking Up

Tasks that are sleeping (blocked) are in a special non runnable state. A task sleeps for a number of reasons, but always while it is waiting for some event. Examples: file I/O - for example, the task issued a `read()` request on a file, which needs to be read from disk. A task can also involuntarily go to sleep when it tries to obtain a contended semaphore in the kernel. Another example could be waiting for keyboard input.

Whatever the case, the kernel behavior is the same: the task marks itself as sleeping, puts itself on a wait queue, removes itself from the red-black tree of runnable, and calls schedule() to select a new process to execute.

Waking back up is the inverse: The task is set as runnable, removed from the wait queue, and added back to the red-black tree.

Two tasks are associated with sleeping, TASK_INTERRUPTIBLE (wake up prematurely and respond to a signal if one is issued) and TASK_UNINTERRUPTIBLE (ignore signals). Both types of sleeping tasks sit on a wait queue, waiting for an event to occur, and are not runnable.

A wait queue is a simple list of processes waiting for an event to occur. It is important to implement sleeping and waking correctly, to avoid race conditions.

An important note about sleeping is that there are spurious wake-ups. Just because a task is awakened does not mean that the event for which the task is waiting has occurred; sleeping should always be handled in a loop that ensures that the condition for which the task is waiting has indeed occurred. 
