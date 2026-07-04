---
layout: default
title: Heap Sort
parent: Sorting
nav_order: 1
---

# Heap Sort

Time complexity: O(n log n).

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure (typically a max-heap) to sort elements. The algorithm works in two main phases: first, it builds a max-heap from the input array in **O(n)** time; second, it repeatedly extracts the maximum element (the root of the heap) and places it at the end of the array, restoring the heap property each time in **O(log n)**. Since this extraction process is performed `n` times, the overall time complexity is **O(n log n)** in the best, average, and worst cases. Heap Sort is performed in-place with **O(1)** extra space, but it is **not stable**, meaning it does not preserve the relative order of equal elements.