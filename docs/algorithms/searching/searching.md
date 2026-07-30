---
layout: default
title: Searching
parent: Algorithms
nav_order: 1
---

# Searching

Looking for specific information in memory is a key operation in computing.

<!-- ## The Searching Problem

Input:
Output -->

## Linear Search

```
O(n)
```

Look at the items one after the other until you find the one you want, or check all
items to realize it's not there.

## Binary Search

<!-- Focus: variations like finding boundaries, rotated arrays, etc. -->

```
O(log(n))
```

The items must be in a sorted array. Each step of binary_search does a constant number of operations and discards half the input.

![binsearch](../../assets/img/binsearch.png)

Binary search can be implemented recursively and iteratively.

## Search using a Hash Table

```
O(1)
```

By storing items in a Hash Table, you only need to calculate the hash of the key you are
searching for, i.e. you find the element you're looking for in constant time.
