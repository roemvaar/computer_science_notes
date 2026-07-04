---
layout: default
title: Yocto
parent: Embedded Linux
nav_order: 1
---

# Yocto

This tool helps you to create your own Linux distribution.

Official website: [Yocto Project](https://www.yoctoproject.org/).

The Yocto Project is a **framework for building custom Linux distributions for embedded systems**. It provides tools, metadata, and build infrastructure to generate complete Linux-based systems for a wide range of hardware architectures.

Unlike simple build systems, Yocto is designed to create **fully customizable and reusable Linux distributions**, allowing developers to precisely control the packages, configurations, and system components included in the final image.

## Key Components

Yocto is composed of several important elements:

- **OpenEmbedded Core (OE-Core)** – Base metadata describing packages and system components
- **BitBake** – The build engine that executes tasks and builds packages
- **Layers** – Modular collections of metadata that extend functionality
- **Recipes (.bb files)** – Instructions that describe how to build individual packages

## What Yocto Generates

Using Yocto, developers can build:

- Cross-compilation toolchains  
- Linux kernel images  
- Bootloaders  
- Root filesystems  
- Complete Linux distributions  
- SDKs for application development

## Key Characteristics

- Highly **customizable and scalable**
- Designed for **large and complex embedded projects**
- Uses a **layer-based architecture**
- Supports many architectures (ARM, x86, MIPS, PowerPC, RISC-V)
- Enables **reproducible builds**

## Basic Workflow

1. Configure the build environment
2. Select layers and machine configuration
3. Build the system using BitBake
4. Generate the final image

The result is a **fully customizable Linux distribution tailored to a specific embedded platform**.