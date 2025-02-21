---
layout: default
title: Bottom Halves
parent: Linux Kernel
nav_order: 1
---

<!-- TODO: Get the actual deferred-work mechanisms from here: https://lwn.net/Articles/960041/ -->

# Bottom Halves and Deferring Work

**Three mechanisms used to defer work in the Linux kernel: softirqs, tasklets, and work queues.**

## Top Halves Versus Bottom Halves

It's imperative that the ![interrupt handler](./interrupts.md) runs quickly, to resume execution of the interrupted code as soon as possible.

Interrupt handlers need to **execute quickly** and **perform a large amount of work**. These two goals are conflict with one another. Because of these competing goals, the processing of interrupts is spit into two parts, or halves. The interrupt handler is the **top half**. Work that can be performed later is deferred until the **bottom half**.

Later is often simply not now. The point of a bottom half is not to do work at some specific point in the future, but simply to defer work until any point in the future when the system is less busy and interrupts are again enabled. Bottom halves run with all interrupts enabled.

Here are some useful tips on how to divide thw work between the top and bottom half:

* If the work is time sensitive, perform it in the interrupt handler.
* If the work is related to the hardware, perform it in the interrupt handler.
* If the work needs to ensure that another interrupt (particularly the same interrupt) does not interrupt it, perform it in the interrupt handler.
* For everything else, consider performing the work in the bottom half.

## Bottom Halves

Bottom half is a generic operating system term referring to the deferred portion of interrupt processing, so named because it represents the second, or bottom, half of the interrupt processing solution.

The job of the bottom halves is to perform any interrupt-related work not performed by the interrupt handler. The bottom half runs in the future, at a more convenient time, with all the interrupts enabled. 

The primary criteria for differentiating the mechanisms are the context in which each runs.

Another mechanism for deferring work is kernel timers.

Unlike the top half, which is implemented entirely via the interrupt handler, multiple mechanisms are available for implementing a bottom half. Currently, three methods exist for deferring work: softirqs, tasklets, and work queues.

## SoftIRQs

**SoftIRQs** run immediately in interrupt context. Softirqs are a set of statically defined bottom halves that can run simultaneously on any processor.

Softirqs are statically allocated at compile time. A softirq never preempts another softirq. The only event that can preempt a softirq is an interrupt handler. Usually, an interrupt handler marks its softirq for execution before returning.

Softirqs are reserved for the most timing-critical and important bottom-half processing on the system.

## Tasklets

**Tasklets** serve as lower-priority bottom halves for deferred work processing. Tasklets are scheduled and executed in a serialized manner to prevent concurrency issues. Tasklets are being **deprecated**. Tasklets are flexible, dynamically created bottom halves built on top of softirqs. For most bottom-half processing, the tasklet is sufficient. Tasklets are deprecated.

Tasklets are a legacy mechanism for handling softirqs (software interrupts) in the Linux kernel. Since workqueues provide better flexibility and control over scheduling, the kernel communicaty is moving away from tasklets.

Tasklets are a bottom-half mechanism built on top of softirqs. You almost always want to use tasklets.

Scheduled tasklets are stored in two per-processor structures `tasklet_vec` (for regular tasklets) and `tasklet_hi_vec` (for high-priority tasklets). Both of these structures are linked lists of `tasklet_struct` structures.

Tasklets also run with all interrupts enabled, so you must take precautions (for example, disable interrupts and obtain a lock) if your tasklet shares data with an interrupt handler. If your tasklet shares data with another tasklet or softirq, you need to use proper locking.

If the same tasklet is scheduled again, before it has had a chance to run, it still runs only once.

## Workqueues 

**Workqueues** run in process context. Workqueues provide a way to handle non-time-critical tasks asynchronously outside interrupt context.

Work queues defer work into a kernel thread - this bottom half always runs in process context. Work queues are schedulable and can therefore sleep. Normally, it is easy to decide between using work queues and softirqs/tasklets. If the deferred work needs to sleep, work queues are used.

## Which Bottom Half Should I Use?

Softirqs and tasklets run in interrupt context. Work queues run in process context.

Softirqs are the fastest alternatie for timinig critical and high-frequency uses.

Tasklets make more sense if the code is not finely threaded. A driver developer should always choose tasklets over softirqs.

If your deferred work needs to run in process context, your only choice of the three is work queues.

Work queues are the easiest to use.

## Latest and Greatest: The End of Tasklets

As of February 2024, tasklets are not longer seen as a reliable bottom half mechanism and the [idea](https://lwn.net/Articles/960041/) is to remove them from the kernel source code.


A common problem in kernel development is controlling *when* a specific task should be done. The kernel has a number of deferred-execution mechanisms designed to ensure that every task is handled at the right time. Tasklets is one of those mechanisms. Tasklets removal might happen in the near future.

An interrupt needs to be handled as quickly as possible. Sleeping is not an option in interrupt context. Interrupt hanlders typically just make a note of what needs to be done, then arrange for the actual work to be done in another context.

There are four deferred-work mechanisms: threaded interrupt handlers, workqueues, software interrupts, tasklets.

Workqueues (added in 2.5) are a deferred-work mechanism. A driver can create a work item, containing a function pointer and some data, and submit it to a workqueue. At some future time, that function will be called with the provided data; again, this call will happen in **process context**. There are various types of workqueues with different performance characteristics, and subsystems can create their own private workqueues if need be.

Tasklets like workqueues are a way to arrange for a function to be called at a future time. In this case, though, the tasklet function is called from a software interrupt, and it runs in atomic context. Tasklets have been around since the 2.3 development series.

Threaded interrupt handlers and workqueues are seen as the preferred mechanisms for deferred work in modern kernel code, but the other APIs have proved hard to phase out. Tasklets, in particular, remain because they offer lower latency than workqueues which, since they must go through the CPU scheduler, can take longer to execute a deferred-work item.

Tasklet API problem: the tasklet subsystem could end up writing to a structure that has been freed and allocated for another use, with predictably unpleasant consequences. A "one shot" tasklet variant was discarded. Instead, a workqueue that run in softirq context is a better solution.

The result of the workqueue that runs in softirq is here: https://lwn.net/ml/linux-kernel/20240130091300.2968534-1-tj@kernel.org/. The patch series converts a number of tasklet users over to the new workqueue type, though, and the plan is clearly to convert the rest over time. That may take a while; there are well over 500 tasklet users in the kernel. Once that conversion is complete, though, it will be possible to run WQ_BH workqueues directly from a software interrupt and remove tasklet API entirely.
