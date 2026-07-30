---
layout: default
title: RTOS
parent: Computer Systems
nav_order: 1
---

# RTOS

Real-Time Operating System (RTOS).

## Important Topics

1. **OS Concepts**

    * Embedded OS
    
    Why use an OS? 
    
        * Manage shared resources.
        * Manage CPU time.
        * Enable deterministic behavior for real-time systems.

    Types:
        
        * Non-preemptive: Typically implemented with a `while(1)` loop. Tasks are executed sequentially without interruption.
        * Preemptive: Task-based systems where higher-priority tasks can interrupt lower-priority tasks (e.g., FreeRTOS).

    Scheduling:
    
        * Non-preemption: Tasks are scheduled in a fixed order and cannot be interrupted.
        * Preemption: Tasks can be interrupted by higher-priority tasks, improving responsiveness.

2. **RTOS Components**

    Typical Components:

        * Scheduler: Manages task execution order based on priority or deadlines.
        * Inter-task Communication: Mechanisms like queues, mailboxes, and semaphores.
        * Memory Management: Static or dynamic allocation for task execution.
        * Device Drivers: Interfaces with hardware devices.
        * Debugging Tools: Tools for analyzing real-time performance.

    Threads:

        * Lightweight units of execution managed by the RTOS scheduler.
        * Each thread can have its own stack and priority.

    Memory Management:

        * Limited dynamic memory usage is common to ensure predictable behavior.
        * Stack and heap sizes are carefully configured.

    Interrupts:

        * Hardware events that require immediate attention.
        * RTOS must handle interrupts efficiently and often use ISRs (Interrupt Service Routines).

3. **RTOS Issues**
        
    - **Priority Inversion**: A high-priority task is waiting on a resource held by a lower-priority task while a medium-priority task runs.
    - Solution: Priority inheritance protocols.

    - **Deadlock**: Tasks are waiting on resources in a circular dependency, causing the system to stall.
    - Solution: Avoid circular resource dependencies or use deadlock detection mechanisms.

    - **Starvation**: Lower-priority tasks never get CPU time due to higher-priority tasks dominating the scheduler.
    - Solution: Implement aging mechanisms or priority ceilings.

    - **CPU Loading**: Balancing the system's tasks to avoid overloading the CPU.
    - Solution: Load balancing and careful task scheduling.

    - **Resource Sharing**: Preventing race conditions and ensuring data consistency.
    - Solution: Use mutexes, semaphores, or other synchronization primitives.

## What is a Real-Time Operating System?

A Real-Time Operating System (RTOS) is an operating system designed to manage hardware resources and run applications with strict timing requirements. The primary goal is to ensure that tasks are completed within their deadlines, providing deterministic and predictable behavior.

## What's the Difference Between a General-Purpose OS and an RTOS?

| Feature               | General-Purpose OS      | Real-Time OS           |
|-----------------------|-------------------------|------------------------|
| **Determinism**       | Non-deterministic      | Highly deterministic   |
| **Response Time**     | Not guaranteed         | Guaranteed             |
| **Use Case**          | General applications   | Time-critical systems  |
| **Scheduling**        | Best-effort            | Priority or deadline-based |
| **Interrupt Handling**| May delay handling     | Immediate handling     |

## Real-Time Systems - Hard vs Soft

A real-time system is required to react to stimuli from the environment (including the passage of physical time) within time intervals dictated by the environment. The Oxford Dictionary defines a real-time system as “any system in which the time at which output is produced is significant.”

### Hard Real-Time Systems
- Must meet deadlines; failure results in system failure.
- Examples: Anti-lock braking systems (ABS), pacemakers, flight control systems.

### Soft Real-Time Systems
- Deadlines are desirable but not strictly enforced; delays degrade performance.
- Examples: Streaming video, online gaming.

### Key Differences:

| Feature                | Hard Real-Time System   | Soft Real-Time System    |
|------------------------|-------------------------|--------------------------|
| **Deadline Enforcement**| Strict                 | Best-effort              |
| **Consequence of Failure** | System failure       | Degraded performance     |
| **Examples**           | ABS, airbag system     | Video streaming, VoIP    |

---

## Additional Resources

- **Books**: 
  - "Real-Time Systems" by Jane W. Liu.
  - "Operating Systems: Principles and Practice" by Anderson and Dahlin.

- **Online Tutorials**:
  - FreeRTOS Documentation: [www.freertos.org](https://www.freertos.org)
  - Embedded Real-Time Systems: [Embedded.com](https://www.embedded.com)

- **Tools for RTOS Development**:
  - Tracealyzer (real-time system tracing and visualization).
  - RTOS-aware debuggers in IDEs like Keil, IAR, and SEGGER.
