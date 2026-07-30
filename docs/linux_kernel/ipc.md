---
layout: default
title: IPC
parent: Linux Kernel
nav_order: 1
---

# Inter-Process Communication (IPC)

Communication among different processes through: 

* Signals
* Inter-process communication primitives
* Pipes
* Message queues
* Shared memory
The shared-memory mechanism consists of allocating a chunk of memory that will be used by two or more processes. It's important to use synchronization mechanisms to avoid data race conditions.

* Semaphores
