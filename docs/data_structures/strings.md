---
layout: default
title: Strings
parent: Data Structures
nav_order: 1
---

# Strings

## **1. Overview**

Strings are used for storing text. A string variable contains a collection of characters surrounded by double quotes. Strings are written in between `" "`.

Strings are immutable (unchangeable) objects.

In Python, you can't add a new character at the end of a string; instead, you have to create a new string, copy the elements of the original string, and append the character to the end of the new string. This will take O(n).

* **Use Cases:** 
  * Example: Efficient searching and sorting (e.g., database indexing).
  * Example: Suitable for priority-based tasks (e.g., heaps for priority queues).

---

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                      |
|----------------|-----------------|--------------------------------------------|
| Search         | O(n)          | Linear search, i.e., you have to go through all the elements of the string|
| Insertion         | O(...)          | Special cases (e.g., balanced or unbalanced)|
| Deletion         | O(...)          |                                            |

Indexing is constant time.

---

## **5. Must-Know Problems**

* **[Camel Case 4](https://www.hackerrank.com/challenges/three-month-preparation-kit-camel-case/problem)**

---

## **7. Cheat Sheet / Key Formulas**

* Check if a character is in a string:

```python
if 'f' in s:
    Sprint(True)
```

---

## **8. References**

* [Greg Hogg: Static Arrays, Dynamic Arrays, and Strings](https://www.youtube.com/watch?v=TQMvBTKn2p0&list=PLKYEe2WisBTFEr6laH5bR2J19j7sl5O8R&index=3&ab_channel=GregHogg)
