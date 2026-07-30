---
layout: default
title: Linked Lists
parent: Data Structures
nav_order: 1
---

# Linked Lists

## **1. Overview**

A linked list is a simple data structure, which is the basis for a surprising number of problem solutions regarding the handling of dynamic data. A linked list is a data structure that represents a sequence of nodes.

<!-- Focus: Reversals, detecting cycles, and merging sorted lists. -->

Linked lists can implement other data structures, such as a dynamic array.

There are two linked lists: a singly-linked list and a doubly-linked list.

The singly-linked list contains nodes that only point to the next node. The doubly-linked list has nodes that can point towards both the next and the previous node.

A node has two parts: the data part and the next part (and the previous part in case of a doubly-linked list). The data part contains the stored data, and the next (and previous) part provides the address of the next node.

The first node of a linked list is called the head, and the last node is called the tail. The list starts traversing from the head, while the tail ends the list pointing at NULL. 

In C, the simplest singly linked list element:

```c
    // The simplest linked list element
    typedef struct Element
    {
        struct Element *next;
        int data;
    } Element;
```

In C++, you could define a class for the list element:

```cpp
    // A singly linked list in C++
    class IntElement {
        public:
            IntElement(int value): next(NULL), data(value) {}
            ~IntElement() {}

            IntElement *getNext() const {return next;}
            int value() const {return data;}
            void setNext(IntElement *elem) {next = elem;}
            void setValue(int value) {data = value;}

        private:
            IntElement *next;
            int data;
    };
```

In C++, it usually makes more sense to define a [template](https://www.geeksforgeeks.org/templates-cpp/) for the list element.

**Hint:** Take care of the pointer-to-pointer structure. Nodes are to be created in memory with dynamic memory allocation.

* **Use Cases:**
  * Example: Efficient searching and sorting (e.g., database indexing).
  * Example: Suitable for priority-based tasks (e.g., heaps for priority queues).

## **2. Operations and Complexities**

| Operation      | Time Complexity | Notes                                      |
|----------------|-----------------|--------------------------------------------|
| Search         | O(n)          |                                            |
| Insert         | O(n)          |                                            |
| Insert (beginning)         | O(1)          |                                            |
| Delete         | O(1)          | Consider that we need to have the reference to the element, else we will have to traverse to the element which would take O(n)             |
| Search         | O(n)          |                                            |
| Traversal      | O(n)          |                                            |

To traverse all the nodes one after another. Always test for the end of a linked list, i.e., NULL pointer, as you traverse it.

---

## **3. Strengths and Weaknesses**

| **Strengths**                | **Weaknesses**                |
|------------------------------|------------------------------|
| Alternative way to store elements (from arrays)      | Access to elements in O(n), i.e., no random access like arrays    |
| You can insert or delete at the beginning of the list in constant time O(1)  |
| Dynamic size, we don't have to know the size at compile time like arrays |

---

## **4. Important Techniques**

* **Sentinels:** a sentinel is a special "dummy" node used to make operations on a linked list easier by removing the need to check for NULL at the start or end of the list.
* **The "Runner" Technique:** the runner (or second pointer) technique means that you have to iterate through the linked list with two pointers simultaneously, with one ahead of the other.
* **Detecting Cycles**

---

## **5. Must-Know Problems**

* **[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/description/)**
<!-- * Check if a linked list is acyclic -->

---

## **7. Cheat Sheet / Key Formulas**

* Singly linked list in Python

```python
class SinglyNode:

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
    
    def __str__(self):
        return str(self.val)
```

* To make a linked list, you generally only have a pointer to the head

```python
Head = SinglyNode(1)
A = SinglyNode(2)
B = SinglyNode(3)
C = SinglyNode(4)

Head.next = A
A.next = B
B.next = C

print(Head)
```

* The most common pattern for linked lists is traversal

```python
# Traverse the list - O(n)

curr = Head

while curr:
    print(curr)
    curr = curr.next
```

* Search for node value - O(n)

```python
def search(head, val):
    curr = head
    while curr:
        if val == curr.val:
            return True
        curr = curr.next
    
    return False


search(Head, 1)
```

* Insert at the beginning of a doubly linked list - O(1)

```python
def insert_at_beginning(head, tail, val):
    new_node = DoublyNode(val, next=head)
    head.prev = new_node
    return new_node, tail

head, tail = insert_at_beginning(head, tail, 3)
display(head)
```

---

## **8. References**

* [Greg Hogg: Linked Lists - Singly & Doubly Linked](https://www.youtube.com/watch?v=dqLHTK7RuIo&list=PLKYEe2WisBTFEr6laH5bR2J19j7sl5O8R&index=4&t=3s&ab_channel=GregHogg)
