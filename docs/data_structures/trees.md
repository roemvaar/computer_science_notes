---
layout: default
title: Trees
parent: Data Structures
nav_order: 1
---

# Trees

## **1. Overview**

A tree is a data structure composed of nodes. Each tree has a root node. The root node has zero or more children. Each child node has zero or more child nodes. The tree cannot contain cycles.

* **Use Cases:** 
  * Git Trees: git uses trees to keep track of commits, branches, and BLOBS.
  * Example: Suitable for priority-based tasks (e.g., heaps for priority queues).

**It's important to understand queues and recursion deeply to solve tree-related problems.**

The height of a tree equals the height of its tallest subtree plus one.

A tree is a connected graph without cycles, i.e., a type of graph, but not all graphs are trees.

Types:
  
* Binary Trees
* Binary Search Trees
* Heaps

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                      |
|----------------|-----------------|--------------------------------------------|
| Search         | O(...)          | Details about the operation if applicable |
| Insert         | O(...)          | Special cases (e.g., balanced or unbalanced)|
| Delete         | O(...)          |                                            |

---

Operations:
  
* Common Searches - Breadth-First Search, Depth-First Search
* Traversals (just like a search, except that instead of stopping when you find a particular target node, you visit every node in the tree) - Preorder, Inorder, Postorder

**Traversal - Preorder:** Operates first on the node itself, then on its left descendants, and finally on its right descendants. In other words, a node is always operated on before its descendants.

**Traversal - Inorder:** Operates first on the node's left descendants, then on the node itself, and finally on its right descendants. In other words, the left subtree is operated on first, then the node itself, and then the node's right subtree.

**Traversal - Postorder:** Operates first on the node's left descendants, then on its right descendants, and finally on the node itself. In other
words, a node is always operated on after all its descendants.

Many tree operations can be implemented recursively. The recursive implementation may not be the most efficient, but it's often the best place to start.

* **Binary Search Tree**

Binary Search Tree is a node-based binary tree data structure which has the following properties:

- The left subtree of a node contains only nodes with keys lesser than the node's key
- The right subtree of a node contains only nodes with keys greater than the node's key
- The left and right subtree each must also be a binary search tree

![bst](../../assets/img/bst.png)

---

## **5. Must-Know Problems**

* **[Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/)**
* **[Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)**

---
