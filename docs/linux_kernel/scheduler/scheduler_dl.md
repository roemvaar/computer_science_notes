---
layout: default
title: DL
parent: Scheduler
nav_order: 1
---

# Deadline Scheduler (DL)

`struct sched_dl_entity`

Deadline Scheduling Class (`SCHED_DEADLINE`) defined in  
[kernel/sched/deadline.c](https://elixir.bootlin.com/linux/v6.11/source/kernel/sched/deadline.c).

It implements a **real-time scheduling policy** based on:

- **Earliest Deadline First (EDF)** scheduling
- **Constant Bandwidth Server (CBS)** for bandwidth enforcement

`SCHED_DEADLINE` is designed for tasks with **explicit timing constraints**, commonly used in real-time systems where tasks must complete before a deadline.

## Key Parameters

Each `SCHED_DEADLINE` task defines three parameters:

- **Runtime (`runtime`)** – maximum execution time allowed
- **Deadline (`deadline`)** – time by which the job must finish
- **Period (`period`)** – activation interval of the task

These parameters define the scheduling contract:

`runtime <= deadline <= period`

## Scheduling Policy

The scheduler maintains a runqueue ordered by **absolute deadlines**.

The task with the **earliest deadline** is selected to run first, implementing the **EDF scheduling algorithm**.

If a task exceeds its allocated runtime, the **CBS mechanism throttles the task** to ensure it does not consume more CPU bandwidth than allowed.

## Admission Control

Before admitting a new `SCHED_DEADLINE` task, the kernel checks that total CPU utilization does not exceed the schedulable bound.

For a single CPU:

`Σ (runtime / period) ≤ 1`

If the constraint is violated, the task is rejected.

## Typical Use Cases

- Real-time multimedia processing
- Robotics and control systems
- Industrial real-time applications
- Deterministic embedded workloads

`SCHED_DEADLINE` provides **strong temporal guarantees**, making it suitable for systems where meeting deadlines is critical.
