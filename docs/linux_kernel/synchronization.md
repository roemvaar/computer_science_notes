---
layout: default
title: Synchronization
parent: Linux Kernel
nav_order: 1
---

# Synchronization

In a shared memory application, developers must ensure that shared resources are protected from concurrent access. If multiple threads of execution access and manipulate the data at the same time, the threads may overwrite each other's changes or access data while it is in an inconsistent state.

Before symmetric multiprocessing (SMP) was supported, preventing concurrent access of data was simple. SMP is difficult to implement because it creates race conditions in the kernel if two processes run kernel functions that access the same memory locations.

In SMP, the kernel must implement synchronization primitives (e.g., spinlocks) to guarantee that only one processor executes a critical section.

The Linux kernel provides a family of synchronization methods that enable the developers to write kernel code that prevents race conditions, ensures the correct synchronization, and correctly runs on machines with multiple processors.

The simplest method of ensuring synchronization is atomic operations.

The programmer should write kernel code that prevents race conditions, ensures the correct synchronization, and correctly runs on machines with multiple processors.

**Methods:**

* The simplest method of ensuring synchronization is the atomic operations.

* Spin locks are the most common lock in the kernel, which provide a lightweight single-holder lock that busy waits while contended.

* Semaphores are sleeping locks, which can be used to protect multiple resources with a count.

* A mutex is a semaphore with a count of one, also known as a binary semaphore.

### Use: Spin Locks vs Semaphores

| **Requirement**                       | **Recommended Lock**           |
| --------------------------------------| -------------------------------|
| Low overhead locking                  | Spin lock is preferred         |
| Short lock hold time                  | Spin lock is preferred         |
| Long lock hold time                   | Mutex / Semaphore is preferred |
| Need to lock from interrupt context   | Spin lock is required          |
| Need to sleep while holding lock      | Mutex / Semaphore is required  |

## Critical Regions and Race Conditions

Code paths that access and manipulate shared data are called **critical regions** (also called critical sections). To prevent concurrent access during critical regions, the programmer must ensure that code executes atomically - that is, operations complete without interruption as if the entire critical region were one indivisible instruction. 

It is a bug if it is possible for two threads of execution to be simultaneously executing within the same critical region. When this does occur, we call it a **race condition**. Debugging race conditions is often difficult because they are not easily reproducible.

Ensuring that unsafe concurrency is prevented and that race conditions do not occur is called **synchronization**.

## Atomic Operations

**Atomic operations** provide instructions that execute atomically - without interruption. Atomicity ensures that instructions occur without interruption and
that they complete either in their entirety or not at all.

Atomic operations are the **foundation** on which other synchronization methods are built. A good exercise is to implement the "complex" synchronization methods using atomic operations, i.e., build them from foundational concepts.

It is never possible for two atomic operations to occur on the same variable concurrently.

The kernel provides two sets of atomic operations - one that operates on integers
and another that operates on individual bits. These interfaces are implemented
on every architecture that Linux supports.

### Atomic Integer Operations

The atomic integer methods operate on a special data type, `atomic_t`.

```c
typedef struct {
    volatile int counter;
} atomic_t;
```

Operations are simple:

```c
atomic_t u = ATOMIC_INIT(0);    /* define u and initialize it to zero */
atomic_t v;                     /* define v with atomic_t 32-bits type */
atomic_t x;                     /* define x with atomic_t 64-bits type */

atomic_set(&v, 4);              /* v = 4 (atomically) */ 
atomic_add(2, &v);              /* v = v + 2 = 6 (atomically) */
atomic_inc(&v);                 /* v = v + 1 = 7 (atomically) */
```

All the operations implemented on a specific architecture can be found in `<asm/atomic.h>`.

A common use of atomic integer operations is to implement counters. Use `atomic_inc()` and `atomic_dec()`.

Atomic integer operators are used for atomically performing an operation and testing the result. For example, the `atomic_dec_and_test()` function decrements by one the
given atomic value. If the result is zero, it returns true; otherwise, it returns false.

The atomic operations are typically implemented as inline functions with inline assembly.

### Atomic Bitwise Operations

Family of functions that operate at the bit level. They are architecture-specific and defined in `<asm/bitops.h>`.

```c
unsigned long word = 0;

set_bit(0, &word);              /* bit zero is now set (atomically) */
set_bit(1, &word);              /* bit one is now set (atomically) */
printk("%ul\n", word);          /* will print "3" */
clear_bit(1, &word);            /* bit one is now unset */
change_bit(0, &word);           /* bit zero is flipped; now it is unset (atomically) */
```

Other important functions are:

* `test_and_set_bit()`
* `test_and_clear_bit()`
* `test_and_change_bit()`

If you don't require atomicity (say, for example, because a lock already protects
your data), the nonatomic versions of all bitwise functions might be faster. For
example, the nonatomic form of `set_bit()` is `__set_bit()`.

Although it would be nice if every critical region consisted of code that did nothing
more complicated than incrementing a variable, reality is harder.

## Spin Locks

In real life, critical regions can span multiple functions.

The most common lock in the Linux kernel is the spin lock. A spin lock is a lock that can be held by at most one thread of execution. A spin lock provides a lightweight single-holder lock that busy waits while contended.

```c
spin_lock(&mr_lock);
/* critical region */
spin_unlock(&mr_lock);
```

## Semaphores

Semaphores are sleeping locks. The main difference between a spin lock and a semaphore is that spin locks busy wait, i.e., no context switch is needed, and the semaphores sleep while waiting, i.e., context switch is needed.

When a task attempts to acquire a semaphore that is unavailable, the semaphore places the task onto a wait queue and puts the task to sleep. When the semaphore becomes available, one of the tasks on the wait queue is awakened so that it can then acquire the semaphore.

### Counting and Binary Semaphores (Mutex)

Semaphores allow for an arbitrary number of simultaneous lock holders. This value is called the **count**. Spin locks permit at most one task to hold the lock at a time.

The most common value is to allow only one lock holder at a time. In this case, it is called a **mutex** (a type of semaphore with a count of one), and it is also known as a binary semaphore.

Alternatively, the count can be initialized to a nonzero value greater than one. This is called a **counting** semaphore, and it enables at most count holders of the lock at a time. You down a semaphore to acquire it. You `up()` a semaphore to release it upon completion of a critical region.

You can use `down_trylock()` to try to acquire the given semaphore without blocking.
