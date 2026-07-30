---
layout: default
title: C++
parent: Computer Systems
nav_order: 1
---

# C++

C++ is a compiled language. For a program to run, its source text must be processed by a compiler, producing object files combined by a linker, yielding an executable program.

When we talk about portability in C++ programs, we refer to source code portability, i.e. the source code can be successfully compiled and run on various systems.

C++ is a statically typed language. The type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use. The type of an object determines the set of operations applicable to it.

Every C++ program must have exactly one global function named main(). The program starts by executing that function.

## C++ Types

<!-- 

C++ Types measures understanding of basic C++ types and the rules for their declaration and use.

https://en.cppreference.com/w/cpp/language/types

-->

The following types are collectively called fundamental types:

* void
* std::nullptr_t
* integral types
* floating-point types

## C++ Basic Concepts

<!-- C++ Basic Concepts evaluates the basic understanding of writing a C++ program. Also covers lambda functions. -->

## Pointers, Arrays and References

<!-- Pointers and References determines understanding of the usage of pointers and references in C++ including static, dynamic and reinterpret types of casting. -->

An array of elements of type char can be declared like this:

`char v[6]; // array of 6 characters`

A pointer can be declared like this:

`char *p; // pointer to character`

In declarations:

- [] means "array of"
- - means "pointer to".
- the unary suffix & means "reference to"

In an expression:

- prefix unary \* means "contents of"
- prefix unary & means "address of"

Arrays are 0-indexed.

A reference is similar to a pointer, except that you don't need to use a prefix

- to access the value referred to by the reference. Also, a reference cannot be
  made to refer to a different object after its initialization.

A pointer variable can hold the address of an object of the appropriate type:

`char* p = &v[3] // p points to v's fourth element`
`char x = *p; // *p is the object that p points to`

References are useful for specifying function arguments.

`void sort(vector<double>& v); // sort v`

By using a reference, we ensure that for a call sort(my_vec), we do not copy
my_vec and that it really is my_vec that is sorted and not a copy of it.

We ensure that a pointer always points to an object so that dereferencing it
is valid. When we don't have an object to point to or if we need to represent the
notion of "no object available" (e.g., for an end of a list), we give the pointer the
value _nullptr_ ("the null pointer"). There is only one _nullptr_ shared by all
pointer types:

`double* pd = nullptr;`
`Link<Record>* lst = nullptr; // pointer to a Link to a Record`
`int x = nullptr; // error: nullptr is a pointer not an integer`

In older code, 0 or NULL is typically used instead of nullptr. However, using nullptr
eliminates confusion between integers (such as 0 or NULL) and pointers (such as nullptr).

## C++ Const and Volatile Qualifiers

<!-- C++ Const and Volatile Qualifiers measures the knowledge of the const/volatile qualifiers in C++ including purpose, correctness, consistency, conversion and casting. -->

## C++ Templates

<!-- C++ Templates checks basic understanding of function and class templates in C++. -->

A template is a class or a function that we parameterize with a set of types or
values. We use templates to represent concepts that are best understood as something
very general from which we can generate specific types and functions by specifying
arguments.

Templates are powerful features of C++ which allow you to write generic programs.

There are two types of templates: class templates and function templates.

Templates are a compile-time mechanism, so their use incurs no runtime overhead compared to hand-crafted code.

Don't reinvent the wheel; use libraries.

## Exception Processing

<!-- Exception Processing measures understanding of the support of exceptions provided by the C++
Standard Library. This includes the concept, purpose, throwing and handling of exceptions. -->

## Dynamic Memory Allocation

<!-- Dynamic Memory Allocation determines understanding of dynamic memory support provided by the C++
Standard Library. -->

**keywords: new, delete, malloc, free**

```new``` and ```malloc``` are used for dynamic memory allocation on the heap. The main difference
is that ```new``` calls the constructor.

```delete``` and ```free``` are used for deleting dynamic memory from the heap. The main difference
is that ```delete``` calls the destructor.

## Functions

The main way of getting something done in C++ is to call a function. A function can only be called if it has been previously declared.

A function declaration gives the function's name, the type of the value returned (if any) and the number and types of the arguments that must be supplied in a call.

### Overloading

<!-- Overloading assesses knowledge of C++ function and operator overloading. -->

**Function overloading**: If two functions are defined with the same name but different argument types, the compiler will choose the most appropriate function to invoke for each call. If two functions could be called, but neither is better, the call would be deemed ambiguous, and the compiler would give an error.

**Operator overloading**.

## Types, Variables, and Arithmetic

Every name and every expression has a type that determines the operations that may be
performed on it.

A declaration is a statement that introduces a name into the program. It specifies a
type for the named entity:

* A _type_ defines a set of possible values and a set of operations (for an object)
* An _object_ is some memory that holds a value of some type
* A _value_ is a set of bits interpreted according to a type
* A _variable_ is a named object

C++ fundamental types: bool, char, int, double, unsigned

A char variable is of the natural size to hold a character on a given machine (typically an 8-bit byte), and the sizes of other types are quoted in multiples of the size of a char. The size of a type is implementation-defined and can be obtained
using the `sizeof` operator.

A constant cannot be left uninitialized, and a variable should only be left uninitialized in rare circumstances. Don't introduce a name until you have a suitable value for it.

## Scope and Lifetime

A declaration introduces its name into a scope:

* Local scope: a name declared in a function or lambda.

* Class scope: a name is called a member name (or class member name) if defined in a class, outside any function, lambda, or enum class.

* Namespace scope: a name is called a namespace member name if defined in a namespace outside any function, lambda, class, or enum class.

A name not declared inside any other construct is called a global name and is said to be in the global namespace.

**const**: means roughly "I promise not to change this value." This is used primarily to specify interfaces, so that data can be passed to functions without fear of it being modified. The compiler enforces the promise made by const.

## User-Defined Types

**Structs**

* . (dot): to access struct members through a name (and through a reference)
* ->: to access struct members through a pointer

```c++
    void f(Vector v, Vector & rv, Vector* pv)
    {
        int i1 = v.sz;      // access through name
        int i2 = rv.sz;     // access through reference
        int i4 = pv->sz;    // access through pointer
    }
```

**Classes**.

Having the data specified separately from the operations on it has advantages. However, a tighter connection is something needed. We want to keep the representation inaccessible to users, to ease use, guarantee consistent use of the data, and allow us to improve the representation later.

To accomplish this, we have to distinguish between the interface to a type (to be used by all) and its implementation (which has access to the otherwise inaccessible data). The language mechanism for that is
called a class.

A class is defined as having a set of _members_, which can be data, function, or type members. The interface is defined by the public members of a class, and private members are accessible only through that interface.

Example of a class:

```cpp
    class Vector {
    public:
        Vector(int s) :elem{new double[s]}, sz{s} { } // constr uct a Vector
        double& operator[](int i) { return elem[i]; } // element access: subscripting
        int size() { return sz; }
    private:
        double∗ elem; // pointer to the elements
        int sz; // the number of elements
    };
```

![vector](../../assets/img/vector.jpg)

## Class

### Class Creation and Usage

<!-- Class Creation and Usage evaluates proficiency with user-defined types in C++ (including structures) --
definition, declaration and usage. -->

### Class Access Control

<!-- Class Access Control measures understanding of C++ class access including access levels, base class
member access, access modification and friends. -->

## Declaration vs Definition

The first and most important step is to distinguish between the interface to a part
and its implementation.

* Declaration

At the language level, C++ represents interfaces by declarations. A declaration
specifies all that's needed to use a function or a type.

```cpp
    double sqrt(double num)  // the square root function takes a double and returns a double
```

* Definition

The key point here is that the function bodies, the function definitions, are
"elsewhere", i.e., the implementation is done in another part of the program.

Functions defined in a class are inlined by default.

```cpp
double sqrt(double d) // definition of sqrt()
{
// ... algorithm as found in math textbook ...
}
```

## Modularity

* Header files (\*.h)

Typically, we place the declarations that specify the interface to a module in a
file with a name indicating its intended use.

The declarations would be placed in a file \*.h, and users will include that file,
called a header file, to access that interface.

* Namespaces

In addition to functions, classes, and enumerations, C++ offers namespaces as a
mechanism for expressing that some declarations belong together and that their
names shouldn’t clash with other names.

## Concrete Type vs Abstract Type

* Concrete types: their representation is part of their definition. In that, they
  resemble built-in types.

* Abstract types: a type that completely insulates a user from implementation
  details. Example:

```cpp
    class Container {
    public:
        virtual double& operator[](int) = 0; // pure virtual function
        virtual int size() const = 0; // const member function
        virtual ~Container() {} // destructor
    };
```

This class is a pure interface to specific containers defined later. The word
virtual means "may be redefined later in a class derived from this one."
Unsurprisingly, a function declared virtual is called a virtual function.
The curious =0 syntax says the function is pure virtual; that is, some class
derived from Container must define the function. A class with a pure virtual
function is called an abstract class.

## Class Hierarchy

A class hierarchy offers two kinds of benefits:

* Interface inheritance: An object of a derived class can be used wherever an object of a base class is required. The base class acts as an interface for the derived class.

* Implementation inheritance: A base class provides functions or data that simplifies
  the implementation of derived classes. Such base classes often have data members and
  constructors.

## Inheritance

<!-- Inheritance assesses proficiency in the use of inheritance in C++ as a tool for the reuse, extension and
modification of existing types including inheritance access control and multiple inheritance. -->

## Polymorphism

<!-- Polymorphism determines proficiency in implementing polymorphism in C++ with the use of virtual
functions including dynamic casting and RTTI. -->

## Class - Essential Operations

The construction of objects plays a key role in many designs. This wide variety of uses
is reflected in the range and flexibility of the language features supporting
initialization.

Constructors, destructors, and copy and move operations for a type are not logically
separate. We must define them as a matched set or suffer logical or performance
problems. If a class X has a destructor that performs a nontrivial task, such as
free-store deallocation or lock release, the class is likely to need the full
complement of functions:

```cpp
    class X {
    public:
        X(Sometype); // "ordinary constructor": create an object
        X(); //default constructor
        X(const X&); // copy constructor
        X(X&&); //move constructor
        X& operator=(const X&); // copy assignment: clean up target and copy
        X& operator=(X&&); // move assignment: clean up target and move
        ~X(); //destructor: clean up
        // ...
    };
```

## Class - Constructor and Destructor

Clearly, arranging code into classes and data into objects is a powerful organizing principle. Clearly also, dealing in classes and objects is inherently no less efficient than dealing with functions and data compared with C. Constructors and destructors: in C++, a constructor is a member function that is guaranteed to be called when an object is instantiated or created. This typically means that the compiler generates a constructor call at the point where the object is declared. Similarly, a destructor is guaranteed to be called when an object goes out of scope. So a constructor typically contains any initialization that an object needs, and a destructor does any tidying up needed when an object is no longer needed.

## C++ Containers Library

<!-- C++ Containers Library determines understanding and usage of C++ containers as well as iterators and
algorithms that are applied to them. -->

Check ch. 9 - A C++ Tour.

## C++ Regular Expressions Library

<!-- C++ Regular Expressions Library tests knowledge of built-in facilities in C++, providing a standardized
way to find, extract or modify patterns in text. -->

## C++ Multi-Threading Library

<!-- C++ Multi-Threading Library assesses the understanding of the concepts and issues of multi-threading
and the proper implementation using the C++ Threading support library -->

## C++ Support Libraries

<!-- C++ Support Libraries determines awareness of, and ability to use, helpful utilities provided by the C++
Standard Library. This is separate from the utilities and containers provided by the Standard Template
Library -->

## C++ Optimization

<!-- C++ Optimization assesses knowledge of optimization techniques and practices used with C++, including
optimizations performed by hand on C++ source code, and optimizations performed by C++ compilers. -->

## Frequently Asked Questions

* Memory sections - heap vs stack, pros and cons of using each one, which other section can be used to store data?
Namespaces - why is it a bad idea to use using namespace std (problem with cryptopp) - ambiguous byte https://github.com/weidai11/cryptopp/pull/438

* How does the `new` keyword work? ListNode *res_iter = new ListNode(0)
Prefix vs Postfix operators [https://en.cppreference.com/w/cpp/language/operator_incdec]
 
* What’s an iterator in C++?
An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) and dereference (*) operators).

* What happens when I assign a number larger than INT_MAX to an int?
Implementation-defined: check your compiler.

* C++ vs C, when should I choose one over the other? And how do they compare with each other in terms of running time and the complexity of their runtime needs
