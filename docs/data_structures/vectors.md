---
layout: default
title: Vectors
parent: Data Structures
nav_order: 1
---

# Vectors

## **1. Overview**

A vector is an array that resizes itself as needed while still providing O(1) access.

Arrays are fixed in C and C++, when you need an array-like data structure that offers dynamic resizing, you would use a `std::vector` in C++. Dynamic arrays are called `lists` in Python.

Dynamic arrays are implemented using static arrays under the hood. The dynamic array starts just like a regular static array, and once it's full and you need to insert a new element at the end of the array, the runtime allocates a new static array that is (usually) double the size of the original static array, then copies the elements of the original array into the new array. This only happens when the array is full.

A typical implementation of vectors is that when the array is full, the array doubles in size. Each doubling takes O(n) time, but happens so rarely that its amortized insertion time is O(1).

* **Use Cases:**
  * Example: Efficient searching and sorting (e.g., database indexing).
  * Example: Suitable for priority-based tasks (e.g., heaps for priority queues).

---

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                      |
|----------------|-----------------|--------------------------------------------|
| Search         | O(n)          |                                            |
| Insertion      | O(1)            | Amortized time, worst case is O(n)         |
| Insertion (at the end) | O(n)    | Worst case: O(n). On average (amortized): O(1)  |
| Deletion         | O(...)          |                                            |

<!-- * Same as a fixed-size array, plus:
* insert_at(idx, value) - make x the new x_i, shifting all numbers to the "right"
* delete_at(idx) - delete element at i, and shift all elements bigger than x_i+1 to
the "left"
* insert/delete at first/last (value)/() -->

Insertion at the end is called `append` in Python.

---

## **6. Common Mistakes**

* Inserting on a vector that is full. Insertions take O(1) time in vectors, but when we insert into a full vector, it needs to double its size to allocate new elements, this operation takes O(n).
* Insertion has an amortized time of O(1), worst case is O(n).

---

## **7. Cheat Sheet / Key Formulas**

* Special types of arrays.
* Dynamic arrays help us improve static arrays' performance by implementing certain operations differently. 
* Python: lists. C++: vectors.
* Checking lenght in O(1) in Python:

```python
len(A)
```
