---
layout: default
title: U-Boot
parent: Embedded Linux
nav_order: 1
---

# U-Boot

Official website: [Das U-Boot](https://github.com/u-boot/u-boot).

Das U-Boot is an open-source **bootloader** commonly used in embedded systems. It performs low-level hardware initialization and loads the operating system kernel (usually Linux) into memory before transferring execution to it.

U-Boot supports many processor architectures including **ARM, x86, MIPS, PowerPC, and RISC-V**, making it one of the most widely used bootloaders in embedded Linux systems.

## Main Responsibilities

U-Boot is responsible for several tasks during the system boot process:

- Initializing basic hardware (CPU, RAM, clocks)
- Setting up memory and device configuration
- Loading the Linux kernel into RAM
- Passing boot parameters to the kernel
- Booting the operating system

## Boot Process

A typical embedded Linux boot process involving U-Boot is:

1. Boot ROM executes code from a predefined storage location
2. Boot ROM loads the **U-Boot bootloader**
3. U-Boot initializes hardware
4. U-Boot loads the **Linux kernel and device tree**
5. Execution is transferred to the Linux kernel

## U-Boot Features

- Interactive command-line interface
- Support for multiple boot sources (SD card, NAND, NOR, eMMC, network)
- Network boot capabilities (TFTP, DHCP)
- Flash memory management
- Environment variables for boot configuration

## Common U-Boot Commands

Some commonly used commands include:

- `printenv` – display environment variables  
- `setenv` – set environment variables  
- `saveenv` – save environment variables to persistent storage  
- `boot` / `bootm` / `bootz` – boot the kernel  
- `tftpboot` – load images over the network  

U-Boot plays a critical role in embedded Linux systems by acting as the **bridge between the hardware platform and the operating system kernel**.