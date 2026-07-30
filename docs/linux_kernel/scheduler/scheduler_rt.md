---
layout: default
title: RT
parent: Scheduler
nav_order: 1
---

# Real-Time Scheduler (RT)

`struct sched_rt_entity`

Linux provides two real-time scheduling policies, SCHED_FIFO and SCHED_RR. The normal, not real-time scheduling policy is SCHED_NORMAL (CFS). Via the **scheduling classes** framework, these real-time policies are managed not by the CFS, but by a special real-time scheduler, defined in [/kernel/sched/rt.c](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/rt.c).

SCHED_FIFO implements a simple first-in, first-out scheduling algorithm without timeslices. SCHED_RR is identical to SCHED_FIFO except that each process can run only until it exhausts a predetermined timeslice. It is a real-time, round-robin scheduling algorithm.

Both real-time scheduling policies implement static priorities. This ensures that a real-time process at a given priority always preempts a process at a lower priority.

The real-time scheduling policies in Linux provide soft real-time behavior. **Soft real-time** refers to the notion that the kernel tries to schedule applications within timing deadlines, but the kernel does not promise to always achieve these goals.

**Hard real-time** systems are guaranteed to meet any scheduling requirements within certain limits. Linux makes no guarantees on the capability to schedule real-time tasks.

The real-time scheduling policies in Linux provide soft real-time behavior. **Soft real-time** refers to the notion that the kernel tries to schedule applications within timing deadlines, but the kernel does not promise to always achieve these goals.
