---
layout: default
title: Dynamic Programming
parent: Algorithms
nav_order: 1
---

# Dynamic Programming

## **1. Overview**

Dynamic programming is always remembering answers to the sub-problems you've already solved. We need to break up a problem into a series of overlapping sub-problems and build up solutions to larger and larger sub-problems. If you are given a problem, which can be broken down into smaller sub-problems, and these smaller sub-problems can still be broken into smaller ones - and if you manage to find out that there are some over-lapping sub-problems, then you've encountered a DP problem.

The core idea of dynamic programming is to avoid repeated work by remembering partial results, and this concept finds its application in a lot of real-life situations.

The intuition behind dynamic programming is that we trade space for time, i.e., to say that instead of calculating all the states taking a lot of time but no space; we take up space to store the results of all the sub-problems to save time later.

### Memoization

A common algorithm design tactic is to divide a problem into sub-problems of the same type as the original, solve those sub-problems, and combine the results. This tactic is called divide-and-conquer method; when combined with a lookup table that stores the results of previously solved sub-problems (to avoid solving them repeatedly and incurring extra computation time), it can be referred to as dynamic programming (memoization).

**Memoization** is a term describing an optimization technique where you cache previously computed results and return the cached result when the same computation is needed again.

### Tabulation

---

## **2. Key Concepts**

---

## **3. Applications**
    
* Unix diff for comparing two files
* Bellman-Ford for shortest path routing in networks

---

## **4. Implementation**

---

## **5. Important Techniques**

* **Recursive Backtracking**
* **Memoization** (Top-Down DP)
* **Tabulation** (Bottom-Up DP)
* **Bottom-Up No-Memory DP**

<!-- https://www.instagram.com/reel/DGI74QDsLpY/?utm_source=ig_web_copy_link -->

---

## **6. Common Mistakes**

---

## **7. Must-Study Problems**

---

## **8. References**
