---
layout: default
title: Arrays
parent: Data Structures
nav_order: 1
---

# **Arrays**

## **1. Overview**

An array (or static array) is a data structure consisting of a collection of elements (values), of same data type, each identified by at least one array index. Arrays are used as the basis for most other data structures. The elements are stored in neighboring (contiguous) memory locations. Arrays can hold up to N elements.

Arrays are fixed in C and C++. The size of the array is defined when you create the array.

```c
    // Declare an array of 10 int elements in C
    int array[10];
```

In C, if an array is not defined, i.e. if you don't store anything inside, the array elements could contain completely random data. The array capacity must be decided when the array is created. The capacity cannot be changed during runtime.

Static arrays have a static sequence interface, i.e., arrays are great when you need random access memory, as long as you know the beginning of the array, you can access any element inside the array in constant time.

Arrays are mutable (changeable) objects. You can't change the array size, but you can change the elements of the array.

Members:
  
* element: each item stored in an array is called an element.
* index: each location of an element in an array has a numerical index, which is used to identify the element. Arrays in C and C++ are 0-based indexing, i.e., the first item of it has an index of 0.
* capacity: the number of elements that the array could hold if it were full.
* length: the number of elements that the array currently has.

- **Use Cases:** 
  - Example: Efficient searching and sorting (e.g., database indexing).
  - Example: Suitable for priority-based tasks (e.g., heaps for priority queues).

---

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                        |
|----------------|-----------------|----------------------------------------------|
| Access         | O(1)            |                                              |
| Search         | O(n)            | Linear search to find the key in the array   |
| Insertion      | O(n)            |                                              |
| Deletion       | O(n)            |                                              |

---

## **3. Strengths and Weaknesses**

| **Strengths**                | **Weaknesses**               |
|------------------------------|------------------------------|
| Direct access to any element |  Contiguos memory block      |
| Modifying an element takes O(1) | You need to shift the elements if you want to insert or delete |

---

## **4. Important Techniques**

* **Sliding Window:** Brief explanation (e.g., balancing for AVL Trees).  
* **Two Pointers:** Description (e.g., traversal methods like Inorder, Preorder).

---

## **5. Must-Know Problems**

- **[Rotate Image](https://leetcode.com/problems/rotate-image/solution/)**

<!-- * Best Time to Buy and Sell Stock II
* Count and Say
* Design a stack (linked list vs arrays/vectors) -->

---

## **6. Common Mistakes**

- Forgetting edge cases like empty/null structures.
- Misunderstanding amortized complexities (e.g., hash table operations).

---

## **7. Cheat Sheet / Key Formulas**

* Contiguous block of memory with a fixed size.

---

## **8. References**

* [Greg Hogg: Static Arrays, Dynamic Arrays, and Strings](https://www.youtube.com/watch?v=TQMvBTKn2p0&list=PLKYEe2WisBTFEr6laH5bR2J19j7sl5O8R&index=3&ab_channel=GregHogg)
