---
layout: default
title: Object Oriented Analysis and Design
parent: Computer Systems
nav_order: 1
---

# Object Oriented Analysis and Design

Think about the components of the system as objects with data and methods, and the collaboration between
these objects. Key concepts are data abstraction, polymorphism, inheritance, encapsulation.

Object-oriented programs are made up of objects. An object packages both data and the procedures that
operate on that data. The procedures are typically called methods or operations. An object performs an
operation when it receives a request (or message) from a client.

Requests are the only way to get an object to execute an operation. Operations are the only way to change
an object's internal data. Because of these restrictions, the object's internal state is said to be encapsulated;
it cannot be accessed directly, and its representation is invisible from outside the object.

The hard part about object-oriented design is decomposing a system into objects. Many factors come into play:
encapsulation, granularity, dependency, flexibility, performance, evolution, reusability, and on and on.

To design object-oriented software you must find pertinent objects, factor them into classes at the right granularity, define class interfaces and inheritance hierarchies, and establish key relationships among them.

Functionality is a key concept; you need to get things working correctly as demanded by the client. Without functionality, you'll never make the customer happy. No matter how well-designed the application is.

## Object-oriented methodologies:

* Write a problem statement, single out the nouns and verbs, and create corresponding classes and operations.

* Focus on the collaborations and responsibilities in your system.

* Model the real world and translate the objects found during analysis into design.

## Characteristics of a well-designed object-oriented system:

* All well-structured object-oriented architectures are full of patterns.

* Pay careful attention to the common collaborations among its objects.

## Delegation

The act of one object forwarding an operation to another object, to be performed on behalf of the first object.

## Loosely Coupled

Loosely coupled is when the objects in your application each have a specific job to do, and they do only that job. So the functionality of your app is spread over lots of well-defined objects, which each do a single task really well. Loosely coupled applications are usually more flexible, and easy to change. Since each object is pretty independent of the other objects, you can make a change to one object's behaviour without having to change all the rest of your objects. So adding new features or functionality becomes a lot easier.

## Inheritance vs Composition

The two most common techniques for reusing functionality in object-oriented systems are class inheritance and object composition.

## Inheritance

* Define the implementation of one class in terms of another's.

* White-box reuse (reuse by subclassing) - the internals of parent classes are often visible to subclasses.

## Object composition

* Alternative to class inheritance.

* New functionality is obtained by assembling or composing objects to get more complex functionality.

* Requires that the object being composed have well-defined interfaces.

* Black-box reuse - no internal details of objects are visible.

Use a textual description of the problem you're trying to solve to make sure that your design lines up with the intended functionality of your application.

Anytime you see duplicate code, look for a place to encapsulate!

![ooa&d](../../assets/img/ooa&d.png)

![ooa&d2](../../assets/img/ooa&d2.png)

Favor composition over inheritance (design principle)

Take what varies and "encapsulate" it so 
it won't affect the rest of your code.

The result? Fewer unintended consequences
from code changes and more flexibility
in your systems!

**Design Principle:**

* Identify the aspects of your application that vary and separate them from what stays the same.

* Program to an interface, not an implementation.
