---
layout: default
title: Memory
parent: Linux Kernel
nav_order: 1
---

# Memory Management

Linux memory management is a complex subsystem that deals with:

* Management of the physical memory: allocating and freeing memory
* Management of the virtual memory: paging, swapping, demand paging, copy on write
* User services: user address space management (e.g., mmap(), brk(), shared memory)
* Kernel services: SL*B allocators, vmalloc

Before you can delve into the actual allocation interfaces you need to understand how the kernel handles memory.

## Pages

The kernel treats physical pages as the basic unit of memory management.

Although the processor's smallest addresable unit is a byte or a word, the memory management unit (MMU, the hardware that manages memory and performs virtual to physical address translations) typically deals with pages.

Therefore, the MMU maintains the system's page tables with page-size granularity. In terms of virtual memory, pages are the smallest unit that matters.

Each architecture defines its page size. Typically:

* Most 32-bit architectures have 4KB pages
* Most 64-bit architectures have 8KB pages

The kernel represents every physical page on the system with a `struct page` structure. This structure is defined in `<linux/mm_types.h>`.

The most important fields of the `struct page` are the following:

```c
struct page {
    unsigned long           flags;
    atomic_t                _count;
    atomic_t                _mapcount;
    unsigned long           private;
    struct address_space    *mapping;
    pgoff_t                 index;
    struct list_head        lru;
    void                    *virtual;
}
```

The `flags` field stores the status of the page. Such flags include whether the page is dirty or whether it is locked in memory.

The `_count` field stores the usage count of the page - that is, how many references there are to this page. When this count reaches negative one, no one is using the page, and it becomes available for use in a new allocation. Kernel code uses `page_count()` to check if the page is available.

A page may be used by the page cache (in which case the `mapping` field points to the `address_space` object associated with this page), as private data (pointed at by `private`), or as a mapping in a process's page table.

The `virtual` field is the page's virtual address.

The important point to understand is that the `page` structure is associated with physical pages, not virtual pages. The kernel uses this data structure to describe the associated physical page. The data structure's goal is to describe physical memory, not the data contained therein.

The kernel uses this structure to keep track of all the pages in the system, because the kernel needs to know whether a page is free (that is, if the page is not allocated). If a page is not free, the kernel needs to know who owns the page. Possible owners include user-space process, dynamically allocated kernel data, static kernel code, the page cache, and so on.

Developers are often surprised that an instance of this structure is allocated for each physical page in the system.They think,“What a lot of memory wasted!” Let’s look at just how bad (or good) the space consumption is from all these pages.Assume struct page consumes 40 bytes of memory, the system has 8KB physical pages, and the system has
4GB of physical memory. In that case, there are about 524,288 pages and page structures on the system.The page structures consume 20MB: perhaps a surprisingly large number in absolute terms, but only a small fraction of a percent relative to the system’s 4GB—not too high a cost for managing all the system’s physical pages.

## Zones

Some pages, because of their physical address in memory, cannot be used for certain tasks. Because of this limitation, the kernel divides pages into different zones. The kernel uses the zones to group pages of similar properties.

Linux has four primary memory zones:

* ZONE_DMA - pages that can undergo DMA
* ZONE_DMA32 - like ZONE_DMA, but only 32-bit devices can access it
* ZONE_NORMAL - normal, regularly mapped, pages
* ZONE_HIGHEM - "high memory", which are pages not permanentyl mapped into the kernel's address space

The use and layout of the memory zones is architecture-dependent.

Linux partition the system's pages into zones to have a pooling in place to satisfy allocation as needed.

Each zone is represented by `struct zone`, which is defined in `<linux/mmzone.h>`.

## Getting Pages

The kernel provides one low-level mechanism for requesting memory, along with several interfaces to access it.

```c
struct page *alloc_pages(gfp_t gfp_mask, unsigned int order);
```

This allocates 2^order (that is, 1 << order) contiguous physical pages and return a pointer to the first page's page structure; on error it returns NULL.

You can also use the `get_zeroed_page()` that allocates a single page, zero its contents and returns a pointer to its logical address.

## kmalloc()

The `kmalloc()` function's operation is similar to that of user-space's familiar `malloc()` routine, with the exception of the additional `flags` parameter. The `kmalloc()` function is a simple interface for obtaining kernel memory in byte-sized chunks. For most kernel allocations `kmalloc()` is the preferred interface.

The function is declared in `<linux/slab.h>`:

```c
void * kmalloc(size_t size, gfp_t flags);
```

The function returns a pointer to a region of memory that is at least `size` bytes in length. The region of memory is physcally contiguous.

The vast majority of allocations in the kernel use the `GFP_KERNEL` flag. The resulting allocation is a normal priority allocation that might sleep.

In process context (and can sleep) use `GFP_KERNEL`, for process context that cannot sleep, interrupt handlers, softirqs, and tasklets use `GFP_ATOMIC`.

## vmalloc()

The `vmalloc()` function works in a similar fashion to `kmalloc()`, except it allocates memory that is only virtually contiguous and not necessarily physically contiguous. This is how a user-space allocation function works: The pages returned by `malloc()` are contiguous within the virtual address space of the processor, but there is no guarantee that they are actually contiguous in physical RAM. The `kmalloc()` function guarantees that the pages are physically contiguous (and virtually contiguous).

For the most part, only hardware devices require physically contiguous memory allocations.

The **TLB** (translation lookaside buffer) is a hardware cache used by most architectures to cache the mapping of virtual addresses to physical addresses. This greatly improves the performance of the system, because most memory access is done via virtual addressing.

## Slab Layer

The slab allocator is a memory management mechanism in the Linux kernel that helps speed up the allocation of frequently used objects and reduce memory fragmentation.

Allocating and freeing data structures is one of the most common operations inside any kernel. To facilitate frequent allocations and deallocations of data, programmers often introduce **free lists**. A free list contains a block of available, already allocated, data structures. When code requires a new instance of a data structure, it can grab one of the structures off the free list rather than allocate the sufficient amount of memory and set it up for the data structure. Later, when the data structure is no longer needed, it is returned to the free list instead of deallocated. In this sense, the free list acts as an object cache, caching a frequently used type of object.

The problem with this is that there's no global control of the free lists. A potential problem is when the system is running low on memory, there's no way for the kernel to modify (shrink the size) the free lists.

To remedy this, the Linux kernel provides the slab layer (also called the slab allocator). The slab layer acts as a generic data structure-caching layer. This strategy reduces fragmentation.

If you frequently create many objects of the same type, consider using the slab cache.

## Statically Allocating on the Stack

In kernel space the kernel's stack is small and fixed. When each process is given a small, fixed stack, memory consumption is minimized, and the kernel need not burden itself with stack management code.

The size of the per-process kernel stacks depends on both the architecture and a compile-time option. Historically, the kernel stack has been two pages per process. This is usually 8KB for 32-bit architectures and 16KB for 64-bit architectures because they usualy have 4KB and 8KB pages, respectively.
