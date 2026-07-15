---
layout: default
title: GPU Fundamentals
parent: GPU
nav_order: 1
---

# GPU Fundamentals for AI

Hardware choices dictate your project's limits.

From CPU to GPU.

* CPU: Few powerful cores acting as a highly skilled manager.

* GPU: Thousands of smaller cores acting as a massive factory. This millions of workers doing
mathematical operations in parallel match perfectly with AI workloads.

1. **Foundation**

Architecture: the underlying computational (blueprint) design family, such as Nvidia's Ampere, Hopper, or 
Blackwell.

    * Hopper (H100): the industry standard for massive AI training, delivering robust floating-point (FP8)
    performance and a poweful Transformer Enginer.

Product Family: the target application and packaging, such as GeForce for consumers or Data Center.

    * RTX 5090 (desktop) vs Data Center Accelerator (servers): same underlying blueprint, different purposes

* The Chip (die) vs the Die

    * Chip / Die: the silicon containing the *compute logic*
    * Card / Module: the complete product with *memory and I/O* + power delivery and cooling

**Nvidia GPU Microarchitectures** Timeline:

Volta --> Turing --> Ampere --> Ada --> Hopper --> Blackwell

    * Volta: introduced Tensor cores
    * Turing: further compute efficiency
    * Ampere: data center powerhouse A100
    * Ada: recent consumer generation
    * Hopper: H200 massive throughput
    * Blackwell: RTX 5090 and beyond

2. **Architecture**

Evaluating the hardware. Hardware checklist:

    * Memory bandwidth & capacity
    * Tensor core support
    * Precision support
    * Scaling capabilities: NVLink interconnect
    * Compute capability

**Precision Support**

Precision dictates how numbers are represented inside the GPU. 

    * Integer formats like INT8 are fast and compact for inference
    * Floating-point formats handle complex fractional values for training

Navigating these precision formats is all about tradeoffs. For example, if we use INT8 precision for inference
in LLMs, the LLM can suffer hallucinations. Also, using floating point precision for floating point represents
a higher memory footprint.

3. **Parallel Mechanics** 

When you're training an AI, you go through these stages: Matrix Math Flow

Split --> Load --> **Parallelize** --> Execute

    * Split: matrices are split into smaller tiles
    * Load: thread blocks load tiles into shared memory
    * Parallelize: warps operate on the tiles in parallel. Groups of threads (warps) operate on those tiles,
    constantly feeding the data into the specialized tensor cores.
    * Execute: Tensor cores execute massive multiply-add operations

**SIMT**: Single Instruction, Multiple Threads: many threads execute one instruction on different data. SIMT
is Nvidia's execution model for GPUs.

**Warp**: is the fundamental unit of execution that makes SIMT work.

4. **Interconnects**

What happens when your model is too big for your GPU? This is where interconnect comes into play.

PCIe is general-purpose, pushing traffic through the host CPU.

NVLInk is a specialized, low-latency bridge for GPU-to-GPU transfer. NVIDIA NVLink is a proprietary
high-speed hardware interconnect technology that allows GPUs and CPUs to communicate with each other at
speeds significantly faster than traditional PCIe connections. By bypassing the CPU-bound PCIe bottleneck,
NVLink enables peer-to-peer data sharing, uniform memory pools, and massively accelerated AI training and
high-performance computing (HPC) workloads.

5. **Desktop vs Datacenter**

| **GPU**   | **Architecture**      | **Memory**          | **Bandwidth** |
|-----------|-----------------------|---------------------|---------------|
| RTX 5090  | Blackwell             | 32GB GDDR7          | 1.792 GB/s    |
| A100      | Ampere                | 40GB HBM2           | 1.555 GB/s    |
| H200 NVL  | Hopper                | 141GB HBM3e         | 4.813 GB/s    |

RTX 5090:

    * Consumer flagship for enthusiast use
    * GB202 Blackwell architecture
    * 5th generation Tensor cores
    * New FP4 and FP6 precision support
    * 32GB of ultra-low voltage GDDR7

Data Center Scaling:

    * Designed for rack-scale training
    * A100: Ampere tech with MIG partitioning
    * H200 NVL: Hopper tech pushing massive FP8
    * Native high-speed NVLink infrastructure

## Practical Checklist to Choose a GPU

Evaluate your specific needs using:

* Is this workload highly parallel?
* Do you require massive memory capacity?
* Are you relying on FP8 or INT8 precisions?
* Local desktop test or rack-scale server?
* Will bottlenecks require NVLink?

    **Which architecture perfectly matches your workload?**
