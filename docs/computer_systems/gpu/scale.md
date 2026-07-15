---
layout: default
title: GPU Scale
parent: GPU
nav_order: 1
---

# GPU The Scale of Compute

1. **The Core Difference**

Sequential vs Parallel computing.

*Why does AI need a completely different brain (architecture)?*

CPUs were designed to run ONE extremely complicated computation at a time sequentially.

    * Few powerful ALUs. Fast 3-4 GHz speeds. Large caches.

AI workload need to calculate millions simple math problems, all at the exact same time.

    * Thousands of small ALUs. 1.2 GHz speeds. Small caches.

This is where GPUs come in handy.

2. **Inside SMs**

A Streaming Multiprocessor (SM) is the fundamental building block of a GPU, functioning roughly
like a highly specialized CPU core.

Streaming Multiprocessor is a self-contained execution block inside a GPU acting as a miniature processing
cluster.

Units inside an SM:

    * LD/ST - Load/Store: move memory
    * Tensor: matrix math
    * SFU (special function units): complex math - logarithms, exponentials, reciprocal functions

Having different specialized units for different math problems is the special sauce for the GPU.

3. **Cores vs Clock Speed**

RTX 3090 (consumer) vs A100 (servers) paradox:

    * They both use the same underlying silicon die (GA100)
    * Tuned for different applications

The A100 crushes in FP16 performance (~700% better than RTX 3090). Although the RTX 3090 card as more cores, higher clock speed, and more
FP32 TFLOPS.

    FP16 half precision format critical for training AI models.

It all comes down to architectural sinergy, the A100 dominates AI because it features superior mixed precision
optimization. The A100 has a greater bandwidth. Architecture, specialized cores, and massive memory pipeline
are what win the game in data centers.

4. **Scaling with NVLink**

What happens when one ultra-power GPU is not enough. Physical connection becomes the biggest bottleneck.

Multiple GPU need to share data, you need to use NVLink, a private, high-speed express lane.

**Scaling Clusters**

PCIe --> NVLink --> NVSwitch

    * PCIe: General compute and gaming
    * NVLink: Direct sharing for a small cluster
    * NVSwitch: Massive scaling for huge GPU pools

Is the future of GPUs, building faster cores or wider highways?
