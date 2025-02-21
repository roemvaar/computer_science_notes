---
layout: default
title: Object Oriented Fundamentals
parent: Computer Systems
nav_order: 1
---

# Object Oriented Fundamentals

## Must Know Concepts

```
* Classes
* Objects
* Interfaces
* Inheritance
* Polymorphism
* Encapsulation
* Abstraction
* Inheritance
* Composition
* Inheritance vs Composition
* Flexibility
* Functionality
* Design Pattern
* Loosely coupled
* Delegation
```

"Knowing concepts like abstraction, inheritance, and polymorphism do not make you a good object oriented designer. A design guru thinks about how to create flexible designs that are maintainable and that can cope with change."

**OOP Principles:**

* Encapsulation
* Inheritance
* Polymorphism
* Data Abstraction

Both inheritance and polymorphism relate to duplicate code and encapsulation, so starting out by looking places where you could use encapsulation to better your design is always a good idea.

## Flexibility

Once you've gotten your software to work like it's supposed to, flexibility becomes a big deal. What if the customer wants to add new properties or features to the app? If you've got tons of duplicate code or confusing inheritance structures in your app, making changes is going to be a pain. 

By introducing principles like encapsulation and good class design into your code, it's easier to make these changes, and you application becomes a lot more flexible.

## Inheritance

Is when one class extends another class to reuse or build upon the inherited class's behaviour.

In inheritance, the class being inherited from is called the superclass (or parent class); the class that is doing the inheritance is called the subclass (or child class).

A subclass gets all the behaviour of its superclass automatically.

A subclass can override its superclass's behaviour to change how a method works.

## Polymorphism

**Object-Oriented Design Principles:**

* Program to an interface, not an implementation

* Favor object composition over class inheritance

**Tips:**

* Don't create problems to solve problems

Things to have in mind:

* Where possible, always use accessor functions to read and write the attributes of objects

* All services offered by a module should be available through a uniform notation, which does not betray whether
they are implemented through storage or through computation.

## Encapsulation

## Data Abstraction

## Frequently Asked Questions

* What's a virtual function?

Polymorphism

A virtual function is a member function that you expect to be redefined in derived classes.

Use virtual functions instead of a constructor in order to make a program more flexible, i.e., you can change the classes that get instantiated by making a subclass of the base class and redefining those virtual functions.

## Classes and objects - member functions and data members

## Object Oriented Design

## Delegation vs inheritance

## Object Oriented in C

The Virtual Filesystem (VFS) in Unix is object-oriented. A family of data structures represents the common file model. These data structures are akin to objects. Because the kernel is programmed strictly in C, without the benefit of a language directly supporting object-oriented paradigms, the data structures are represented as C structures. The structures contain both data and pointers to filesystem-implemented functions that operate on the data.

The four primary object types of the VFS are:

* The **superblock** object

* The **inode** object

* The **dentry** object

* The **file** object

People often miss this, or even deny it, but there are many examples of object-oriented programming in the kernel. Although the kernel developers may shun C++ and other explicitly object-oriented languages, thinking in terms of objects is often useful. The VFS is a good example of how to do clean and efficient OOP in C, which is a language that lacks any OOP constructs.
