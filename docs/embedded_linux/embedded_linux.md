---
layout: default
title: Embedded Linux
nav_order: 2
has_children: true
permalink: /docs/embedded_linux
---

# Embedded Linux

Embedded Linux refers to the embedded systems that use the Linux kernel as its main operating system. 

The Linux kernel is only a small component of an embedded system based on Linux. In addition to the Linux kernel, you need the following components to develop, test, and launch your embedded Linux project:

* A **cross-compiler** and the associated **toolchain** for your chosen architecture. The toolchain is a set of tools that compile source code into executables that can run on your target device, including a compiler, linker, and runtime libraries.

* A **bootloader** ported and configured for your specific hardware platform. It's the program that initializes the board and loads the Linux kernel.

* **Linux kernel**, the heart of the system, manages system resources and interfacing with hardware.

* A **root filesystem** containing many packages - binary executables and libraries compiled for your native hardware architecture/processor. Contains libraries and programs that are run once the kernel has completed its initialization.

Optionally, there are other elements, such as:

* **Device drivers** for any custom devices on your board.

* A **device tree** enabled for your particular processor and board. It's a data structure that describes the device's hardware.

* The collection of **programs** specific to your embedded application that makes the device do whatever it is supposed to do, e.g. display movies, control a robot, fly a drone, etc.

These are the components of an embedded Linux distribution.

## Selecting hardware for embedded Linux

1. A CPU architecture supported by the kernel - find them in the Linux repo at `arch/` directory. All of them are 32 or 64 bits, and most of them have MMU.

2. A reasonable amount of RAM - 16 MiB is a good minimum.

3. Non-volatile storage - usually flash memory. 8 MiB is enough for a simple device such as a webcam or router.

4. A serial port is very useful, preferably a UART-based serial port. It doesn't have to be fitted in production boards but makes board bring-up, debugging, and development much easier.

5. You need some means to load software when starting from scratch. JTAG is common, but modern SoCs support SD and micro SD cards or serial interfaces such as UART or USB.
