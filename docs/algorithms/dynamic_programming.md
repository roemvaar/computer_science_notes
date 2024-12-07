---
layout: default
title: Dynamic Programming
parent: Algorithms
nav_order: 1
---

# Dynamic Programming

Dynamic programming is about always remembering answers to the sub-problems you've already solved. We need to break up a problem
into a series of overlapping sub-problems and build up solutions to larger and larger sub-problems. If you are given a problem,
which can be broken down into smaller sub-problems, and these smaller sub-problems can still be broken into smaller ones - and if
you manage to find out that there are some over-lapping sub-problems, then you've encountered a DP problem.

Some famous Dynamic Programming algorithms are:
    
 - Unix diff for comparing two files
 - Bellman-Ford for shortest path routing in networks

The core idea of Dynamic Programming is to avoid repeated work by remembering partial results, and this concept finds its
application in a lot of real-life situations.

The intuition behind dynamic programming is that we trade space for time, i.e., to say that instead of calculating all the
states taking a lot of time but no space; we take up space to store the results of all the sub-problems to save time later.

## Memoization

**Memoization** is a term describing an optimization technique where you cache previously computed results and return the
cached result when the same computation is needed again.