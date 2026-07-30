---
layout: default
title: Kernel Internals
parent: Linux Kernel
nav_order: 1
---

# Kernel Internals

## Kernel Preemption

The Linux kernel is a fully preemptive kernel. In nonpreemptive kernels, kernel code runs until completion. That is, the scheduler cannot reschedule a task while it is in the kernel. In Linux, it is possible to preempt a task at any point, so long as the kernel is in a state in which it is safe to reschedule.

When is it safe to reschedule? The kernel can preempt a task running in the kernel so long as it does not hold a lock. That is, locks are used as markers of regions of nonpreemptability. The kernel is SMP-safe.

Kernel preemption can also occur explicitly, when a task in the kernel blocks or explicitly calls `schedule()`.

Kernel preemption can occur:

* When an interrupt handler exits, before returning to kernel-space
* When kernel code becomes preemptible again
* If a task in the kernel explicitly calls `schedule()`
* If a task in the kernel blocks (which results in a call to schedule())

User preemption can occur:

* When returning to user-space from a system call.
* When returning to user-space from an interrupt handler.

## Context Switching

Context switching, the switching from one runnable task to another, is handled by the [context_switch()](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/core.c#L5132) function defined in kernel/sched/core.c.

It is called by schedule() when a new process has been selected to run. It does two basic jobs:

* Calls `switch_mm()`, to switch the virtual memory mapping from the previous process’s to that of the new process.

* Calls `switch_to()`, declared in <asm/system.h>, to switch the processor state from the previous process’s to the current’s. This involves saving and restoring stack information and the processor registers and any other architecture-specific state that must be managed and restored on a per-process basis.
