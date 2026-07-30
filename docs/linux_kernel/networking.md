---
layout: default
title: Networking
parent: Linux Kernel
nav_order: 1
---

# Networking

The networking subsystem is not an essential component of an operating system kernel (the Linux kernel can be compiled without networking support). It is, however, quite unlikely for a computer system to have a non-networked operating system due to the need for connectivity.

The Linux kernel provides three basic structures for working with network packets: `struct socket`, `struct sock`, and `struct sk_buff`.
