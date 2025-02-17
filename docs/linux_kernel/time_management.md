---
layout: default
title: Time Management
parent: Linux Kernel
nav_order: 1
---

# Time Management

## Jiffies

The global variables **jiffies** holds the number of ticks that have occurred since the system booted. On boot, the kernel initializes the variable to zero, and it is incremented by one during each timer interrupt. Thus, because there are HZ timer interrupts in a second, there are HZ jiffies in a second. The system uptime is therefore jiffies/HZ seconds.

In operating systems, a **jiffy** is the time between two successive clock ticks.

## Real-Time Clock

The real-time clock (RTC) provides a nonvolatile device for storing the system time. The RTC continues to keep track of time even when the system is off by way of a small battery typically included on the system board.

On boot, the kernel reads the RTC and uses it to initialize the wall time, which is stored in the `xtime` variable. The real-time clock's primary importance is only during boot, when the `xtime` variable is initialized.

## System Timer

The idea behind the system timer is to provide a mechanism for driving an interrupt at a periodic rate.

<!-- An engineer from Google has suggested increasing the default timer interrupt frequency in the Linux kernel to 1000 Hz, which wuold lead to more frequent task switching and a reduction in the time slice used by the scheduler.

Currently, the default is set to 250 Hz, striking a balance between performance, latency, and power consumption. -->

## Timers

Timers are essential for managing the flow of time in the kernel code. A timer is easy to use. You perform some initial setup, specify an expiration time, specify a function to execute upon said expiration, and activate the timer. The given function runs after the timer expires. Timers are not cyclic. The timer is destroyed after it expires.

There is no limit on the number of timers.

Because timers run asynchronously with respect to the currently executing code, several potential race conditions exist. You must make sure to protect any shared data used in the timer handler function. The kernel runs the function asynchronously with respect to other code.
