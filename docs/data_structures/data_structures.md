---
layout: default
title: Data Structures
nav_order: 2
has_children: true
permalink: /docs/data_structures
---

# Data Structures

A data structure is a data organization, management, and storage format that enables efficient access
and modification. In other words, a data structure is a collection of data values, the relationship
among them, and the functions or operations that can be applied to the data.

- Abstract Data Type (ADT): describes how variables of a given type are operated. It provides a list 
of operations but doesn't explain how data operations happen. 

- Data Structures: describe how data is to be organized and accessed in the computer's memory. 
They provide a way for implementing ADTs in data-handling modules.

*With **ADTs**, you as a coder learn to interact with the data, like a driver uses a car's dashboard. In order
to understand how the wires are structured behind the dashboard you need to learn **Data Structures**.*

## Abstract Data Type (ADT)

* **Primitive data types**

Primitive data types are those with built-in support in the programming language you're
using. These always include integers, floating-points, and generic operations with them
(addition, subtraction, division). Many languages also come with built-in support for
storing text, booleans and other simple data types in their variables.

* **Stack**

A list with the restriction that insertion and deletion can be performed only from one end,
called the top.

Used when we have a pile of items, and only work with its top item. The item on top is
always the pile's most recently inserted one, i.e. LIFO (Last-In, First-Out).

Operations:
  
  - push(e): add an item e to the top of the stack
  - pop(): retrieve and remove the item on top of the stack

More "advanced" stacks may provide more operations: to check whether the stack is empty,
to get the top element without removing it from the stack (top ()), or to get the number 
of items currently in the stack. Operations are performed in constant time O(1).
 
*Use case:* For implementing the "undo" feature in a text editor, every edition you make
is pushed onto a stack. Should you want to undo, the text editor pops an edition from the
stack and reverts it.

* **Queue**

Used for storing and retrieving items. The retrieved item is always the one in front of the
queue, i.e. FIFO (First-In, First-Out). Queue is the stack's antagonist.

Operations:

  - enqueue(e): add an item e to the back of the queue
  - dequeue(): remove the item at the front of the queue

*Use case:* When data is transferred asynchronously (data not necessarily received at same
rate as sent) between two processes, e.g. I/O buffers.


* **Priority Queue**

Similar to queue, with the difference that enqueued items must have an assigned priority.

Operations:

  - enqueue(e, p): add an item e to the queue according to the priority level p
  - dequeue(): remove the item at the front of the queue and return it

*Use case:* In a computer there are typically many running processes but only one (or a
few) CPUs to execute them. An operating system organizes all these processes waiting for
execution in a priority queue. Some processes are more time-sensitive and get immediate CPU
time, others wait in the queue longer.

* **List**

A list or sequence is an ADT that represents a countable number of values, where the same
value may occur more than once.

Operations:

  - insert(n, e): insert the item e at position n
  - remove(n): remove the item at position n
  - get(n): get the item at position n
  - sort(): sort the items in the list
  - slice(start, end): return a sub-list slice starting at the position start up until
    the position end
  - reverse(): reverse the order of the list

*Use case:* lists can be used to store a list of elements. Lists are a basic example of
containers, as they contain other values. If the same value occurs multiple times, each
occurrence is considered a distinct item.

* **Sorted List**

Is useful when you need to maintain an always sorted list of items.

Operations: 

  - insert(e): insert item e at the right position in the list
  - remove(n): remove the item at the position n in the list
  - get(n): get the item at position n

*Use case:* If you need to store links to the most frequently accessed files in a system,
a list is ideal: you can sort the links for display purposes, and remove links at will as
the corresponding files become less frequently accessed.

* **Map**

Map (aka Dictionary) is used to store mappings between two objects: a key object and a
value object. You can query a map with a key and get its associated value.

Operations:

  - set(key, value): add a key-value mapping
  - delete(key): remove key and its associated value
  - get(key): retrieve the value that was associated to key

*Use case:* you might use a map to store a user's ID number as key, and its full name as
value. Then, given the ID number of a user, the map returns the related name.

* **Set**

Set represents unordered groups of unique items.

Operations:

  - add(e): add an item to the set or produce an error if the item is already in the set
  - list(): list the items in the set
  - delete(e): remove an item from the set

*Use case:* They're used when the order of the items you need to store is meaningless,
or if you must ensure no items in the group occurs more than once.


## Data Structures

* **Arrays**

* **Strings**

* **Linked List**

* **Tree**

* **Binary Search Tree**

* **Binary Heap**

* **Graph**

* **Hash Table**
