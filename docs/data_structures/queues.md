---
layout: default
title: Queues
parent: Data Structures
nav_order: 1
---

# Queues

## **1. Overview**

A queue is a dynamic set in which the element removed from the set by the delete operation is prespecified. In a queue, the element deleted is always the one that has been in the set for the longest time. The queue implements a first-in, first-out (FIFO) policy.

![queue](../../assets/img/queue.png)

In C++, the standard library provides a queue implementation named `std::queue`. In Python, we use `queue`.

* **Use Cases:** 
  * [Breadth-First Search (BFS)](https://roemvaar.github.io/computer_science_notes/docs/algorithms/bfs.html)
  * Implementing a cache

---

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                      |
|----------------|-----------------|--------------------------------------------|
| Enqueue(elem)         | O(1)          | Insert                                      |
| Dequeue         | O(1)          | Delete takes no argument                    |
| Peek            | O(1)        |                                               |
| Empty            | O(1)        |                                               |

---

## **5. Must-Know Problems**

* **[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/description/):.**

---

## **6. Common Mistakes / Corner Cases**

* Easy to mess up updating of the first and last nodes in a queue.
* Empty queue.
* Queue with one item.
* Queue with two items.

---
