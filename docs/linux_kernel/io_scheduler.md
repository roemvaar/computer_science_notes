---
layout: default
title: I/O Scheduler
parent: Linux Kernel
nav_order: 1
---

# I/O scheduler

## What is the role of the I/O scheduler in the Linux kernel?

One of the slowest operations in a modern computer is disk seeking. The kernel does not issue block I/O requests to the disk in the order they are received or as soon as they are received. Instead, it performs operations called merging and sorting to improve the performance of the system as a whole greatly. The I/O scheduler conducts these operations.

The I/O scheduler in the Linux kernel manages input/output (I/O) operations for block devices (storage devices), such as hard drives and solid-state drives. The I/O scheduler determines the order in which I/O requests are processed, which can significantly impact system performance.

## Mention the most important I/O schedulers and explain them

Completely Fair Queuing I/O (CFQ) scheduler: allocates I/O bandwidth based on process priorities. The CFQ I/O scheduler assigns incoming I/O requests to specific queues based on the process originating the I/O request.

Noop scheduler: simple scheduler that processes I/O requests in the order in which they are received.

Deadline I/O scheduler: ensures that I/O requests meet their deadlines. In the Deadline I/O scheduler, each request is associated with an expiration time (default is 500 milliseconds in the future for read requests and 5 seconds in the future for write requests). 
