---
layout: default
title: Memory Problems in C
parent: Computer Systems
nav_order: 1
---

# Common Memory Problems in C

* Using uninitialized values
* Using memory that you don't know
    * Deallocated stack or heap variable
    * Out-of-bounds reference to stack or heap array
* Improper use of free/realloc by messing with the pointer handle
returned by malloc/calloc
* Memory leaks (you allocated something you forgot to later free)
