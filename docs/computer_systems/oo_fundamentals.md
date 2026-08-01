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
* Composition
* Inheritance vs Composition
* Flexibility
* Functionality
* Design Pattern
* Loosely coupled
* Delegation
```

"Knowing concepts like abstraction, inheritance, and polymorphism does not make you a good object-oriented designer. A design guru thinks about how to create flexible designs that are maintainable and that can cope with change."

**OOP Principles:**

* Encapsulation
* Inheritance
* Polymorphism
* Data Abstraction

Both inheritance and polymorphism relate to duplicate code and encapsulation, so starting out by looking places where you could use encapsulation to better your design is always a good idea.

## Flexibility

Once you've gotten your software to work like it's supposed to, flexibility becomes a big deal. What if the customer wants to add new properties or features to the app? If you've got tons of duplicate code or confusing inheritance structures in your app, making changes is going to be a pain. 

By introducing principles like encapsulation and good class design into your code, it's easier to make these changes, and your application becomes a lot more flexible.

## Inheritance

Inheritance is when one class extends another to reuse or build upon its behaviour.

In inheritance, the class being inherited from is called the superclass (or parent class); the class that is doing the inheritance is called the subclass (or child class).

A subclass gets all the behaviour of its superclass automatically.

A subclass can override its superclass's behaviour to change how a method works.

## Polymorphism

**Object-Oriented Design Principles:**

* Program to an interface, not an implementation

* Favor object composition over class inheritance

**Tips:**

* Don't create problems to solve problems

Things to keep in mind:

* Where possible, always use accessor functions to read and write the attributes of objects

* All services offered by a module should be available through a uniform notation, which does not betray whether
they are implemented through storage or through computation.

## Encapsulation

Encapsulation is the practice of **bundling data and the methods that operate on that data into a single unit**, typically a class. It also restricts direct access to the internal state of an object, allowing it to be accessed or modified only through well-defined methods.

By hiding internal implementation details and exposing only a controlled interface, encapsulation helps protect data integrity, reduce unintended interactions, and improve modularity in software systems.

## Data Abstraction

Data abstraction is the concept of **exposing only the essential features of an object while hiding the underlying implementation details**. This allows users of the object to interact with it at a high level without needing to understand how it is internally implemented.

In object-oriented programming, abstraction focuses on **what an object does rather than how it does it**, simplifying complex systems and making programs easier to design, maintain, and extend.

## Frequently Asked Questions

* What's a virtual function?

A virtual function is a member function that you expect to be redefined in derived classes.

Use virtual functions to make a program more flexible. By subclassing the base class and redefining its virtual functions, you can change which classes get instantiated at runtime.

## Classes and objects - member functions and data members

A class defines a blueprint consisting of **data members** (attributes/state) and **member functions** (methods/behavior). An object is an instantiation of a class — a concrete instance with its own copy of the data members, sharing the class's member functions.
- **Data members** hold the state of an object and are typically declared private, accessed only through member functions
- **Member functions** define the operations an object can perform, often split into:
  - **Accessors** (getters) — read state without modifying it
  - **Mutators** (setters) — modify state under controlled conditions
  - **Constructors/destructors** — manage object lifecycle
- Member functions have implicit access to the object's data members via `this` (or the equivalent in the language)

## Object Oriented Design

Good OO design isn't just about using classes and inheritance — it's about producing systems that are flexible, maintainable, and easy to extend.

**Design Principles:**
* Program to an interface, not an implementation
* Favor object composition over class inheritance
* Encapsulate what varies

**Tips:**
* Don't create problems to solve problems
* Where possible, use accessor functions to read and write object attributes rather than exposing them directly
* All services offered by a module should be available through a uniform notation, which does not betray whether they are implemented through storage or through computation

## Delegation vs inheritance

Delegation is an alternative to inheritance for code reuse: instead of a subclass inheriting behavior from a superclass, an object holds a reference to another object and forwards (delegates) certain calls to it.
- **Inheritance**: "is-a" relationship, fixed at compile time, behavior determined by the class hierarchy
- **Delegation**: "has-a" relationship, can be changed at runtime, more flexible since behavior is composed rather than fixed
- Delegation is closely related to the "favor composition over inheritance" principle — it avoids tight coupling and deep, fragile inheritance hierarchies

## Object Oriented in C

The Virtual Filesystem (VFS) in Unix is object-oriented. A family of data structures represents the common file model. These data structures are akin to objects. Because the kernel is programmed strictly in C, without the benefit of a language directly supporting object-oriented paradigms, the data structures are represented as C structures. The structures contain both data and pointers to filesystem-implemented functions that operate on the data.

The four primary object types of the VFS are:

* The **superblock** object

* The **inode** object

* The **dentry** object

* The **file** object

People often miss this, or even deny it, but there are many examples of object-oriented programming in the kernel. Although the kernel developers may shun C++ and other explicitly object-oriented languages, thinking in terms of objects is often useful. The VFS is a good example of how to do clean and efficient OOP in C, which is a language that lacks any OOP constructs.
