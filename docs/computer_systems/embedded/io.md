---
layout: default
title: I/O
parent: Embedded
nav_order: 1
---

# I/O

Data registers: contain data that needs to be read or written, e.g., data received from the UART.

Status registers: contain device information, e.g., health, data received or succesfully written, configuration.

## I/O Access

Two major mechanisms to access data from I/O devices.

* **Polling**: synchronous. Also known as busy waiting. Polling blocks other activities, high power consumption, predictable timing, high throughput.

* **Interrupts**: asyncrhonous operation. The CPU can do other activities while waiting for data to complete, non-linear contorl flow (source of bugs), requires prioritization, bugs hard to reproduce.