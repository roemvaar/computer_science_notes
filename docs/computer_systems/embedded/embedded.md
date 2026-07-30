---
layout: default
title: Embedded
parent: Computer Systems
nav_order: 1
---

# Embedded Systems

**What is an embedded system?**

**Characteristics of an embedded system**

* Contains a processing engine, such as a general-purpose microprocessor.

* Typically designed for a specific application or purpose.

* Includes a single (or no) user interface.

* Often is resource-limited. For example, it might have a small memory footprint and no hard drive.

* Might have power limitations, such as requirements to operate from batteries.

* Not typically used as a general-purpose computing platform.

* Generally has application software built in, not user-selected.

* Ships with all intended application hardware and software pre-integrated.

* Often is intended for applications without human intervention.

**What is a microcontroller, microprocessor, SoC, and SoM?**

* Microprocessor

* Microcontroller

* SoC (System on Chip)

* SoM (System on Module)

**Basic processor architecture**

The ones most often found in embedded devices are Arm, MIPS, PowerPC, RISC-V, and x86, each in 32 and 64-bit variants, all with memory management units (MMU).

**Bootloaders**

A bootloader is a program in charge of initializing critical computer resources, such as program memory, and loading the OS into the memory. It serves as a bridge between the firmware and the operating system, ensuring the system is properly configured to begin execution of higher-level software.

How does the bootloader load the OS/Program?

1. Power-On / Reset: after the system is powered on or reset, the processor starts executing code from a predefined memory location, usually set by the hardware.

2. Execution of bootloader: the firmware locates and hands over control to the bootloader, typically residing in non-volatile storage (e.g., flash memory or ROM).

3. Hardware initialization: the bootloader initializes critical hardware, including memory controllers, I/O devices, and other peripherals.

4. Operating system image location: the bootloader locates the operating system image, which could be stored in local storage (HDD, SSD, eMMC) or a remote server (via network boot).

5. OS loading: the bootloader loads the OS image into RAM, preparing it for execution.

6. Control handover: the bootloader passes control to the OS kernel, along with necessary system configuration data.

Types of bootloaders:

* Stage-1 Bootloader: A minimal bootloader that loads a more complex Stage-2 bootloader. Commonly used in multi-stage boot processes.

* Stage-2 Bootloader: A more feature-complete bootloader that initializes more hardware and loads the operating system. Examples include GRUB or LILO.

* Primary Bootloader: Resides in the first sector of the boot device (e.g., MBR) and initiates the OS loading process.

* Secondary Bootloader: Used in systems requiring additional steps to load the OS, often containing more advanced capabilities.

* Network Bootloader: Supports booting the system over a network using protocols like PXE (Preboot Execution Environment).

Examples:

* GRUB (GNU GRUB): A widely used bootloader for Linux and other operating systems.

* LILO (Linux Loader): An older Linux bootloader, now largely replaced by GRUB.

* UEFI Boot Manager: Used in systems with Unified Extensible Firmware Interface.

* U-Boot: A versatile bootloader for embedded systems.

* Windows Boot Manager: The default bootloader for Microsoft Windows operating systems.

Tasks of a bootloader:

* Initialize Critical Hardware: Configure SDRAM controller, I/O controllers, graphics controllers, and other essential components.

* Prepare System Memory: Initialize and map system memory to prepare for OS loading.

* Allocate Resources: Manage resources like memory and interrupt circuits for peripheral devices.

* Locate OS Image: Find the operating system image in storage or over a network.

* Load OS Kernel: Load the OS kernel and pass control to it, along with essential configuration data such as:

    * Total memory size
    * Processor clock rates
    * Peripheral configuration (e.g., serial port settings)

**Bare metal programming**

Infinite for loop.

**OS and RTOS concepts**

Difference between an OS and RTOS:

* OS (Operating System)

* RTOS (Real-Time Operating System)

Examples: FreeRTOS, QNX, VxWorks
**What is DMA?**

Direct Memory Access

**Timers**

Time-Based - Hardware timers are key components of most microcontrollers. In addition to measuring the passage of time - for example, providing an alarm at regular intervals - timers are used to generate and decode complex pulse trains. A common use is generating a pulse-width modulated signal for motor speed control.

**What is a watchdog timer?**

**Synchronization techniques**

Mutex vs Semaphores

Synchronization techniques among threads by [IBM](https://www.ibm.com/docs/en/i/7.4?topic=techniques-synchronization-among-threads).

**Object Oriented Programming in C** - check this link http://vger.kernel.org/lkml/#s15-3

**Toolchains**

* Native: this toolchain runs on the same type of system (sometimes the actual system) as the program it generates.

* Cross: this toolchain runs on a different type of system than the target, allowing the development to be done on a fast desktop PC and then loaded onto the embedded target for testing. This process is known as cross-compiling.

**Cross-Compiling**

There are some common build systems, including the following:

* Pure Makefiles, where the toolchain is usually controlled by the make variable CROSS_COMPILE

* The GNU build system known as Autotools

* CMake (https://cmake.org)

Autotools and makefiles are needed to build a basic embedded Linux system. CMake is cross-platform.

**Schematic basics** 

How to read and understand schematics?

**Hardware Debugging tools, Oscilloscope, Multimeter, Logic Analyzer, JTAG**

**Debugging**

[Debugging](https://roemvaar.github.io/computer_science_notes/docs/computer_systems/debugging.html).

**Communication Interfaces / Devices**

**Embedded Peripherals / Interfaces:**

* I2C - synchronous serial interface
* GPIO
* Analog - ADC, DAC
* USB
* SPI - synchronous serial interface - (complex) LCD, SD flash memory card, (simple) EEPROM)

**External Communication Interfaces / Devices:**

* CAN
* LIN
* Ethernet
* Wi-Fi
* Bluetooth
* GPS
* UART
