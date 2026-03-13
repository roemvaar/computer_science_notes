---
layout: default
title: C
parent: Computer Systems
nav_order: 1
---

# C Programming Language

## C Data Types

* char, short, int, float, double

* user-defined (typedef): structs, unions, enums

* C - Fixed-width integers types: C99 adds built-in fixed width integers - int8_t, uint8_t, int16_t, int32_t, int64_t, etc.

To use these fixed-width integers, you need to: `#include <stdint.h>`.

## What's a pointer? What's its size?

It's a variable that holds the address of another variable. In this way, the variable that the pointer variable points to can be modified indirectly. 

The size is system-specific. Typically, it is the same size as the processor word; e.g., in an ARM32 board, the pointers usually have a 4-byte size (32 bits).

## Void Pointer

Void pointers are used as general-purpose pointers. They're good if you need to know what data type to return from a function, such as in malloc. It's important to cast your pointer for you to use.

## Null Pointer

A null pointer is a pointer which points to nothing. Some uses of the null pointer are: 

* To initialize a pointer variable when that pointer variable has yet to be assigned a valid memory address.

* To pass a null pointer to a function argument when we don't want to pass any valid memory address.

## Compilation stages - What happens at each stage?

To compile `hello.c`, the following steps need to be taken:

1) Preprocessor: the preprocessor performs one or many of the following
task on the translation unit (.c file):

* Removes comments
* Expands macros
* Expands included files

It takes care of all the commands that begin with #, such as #define, #include, #pragma, etc.

If you included a header file such as #include <stdio.h>, it will look for the stdio.h file and copy the header file into the source code file.

The preprocessor also generates macro code and replaces symbolic constants defined using #define with their values.

Output: hello.i

2) Compiler: compiling is the second step. It takes the preprocessor's output and generates assembly language, an intermediate human readable language specific to the target processor.

Output: hello.s

3) Assembler: assembly is the third step of compilation. The assembler will convert the assembly code into pure binary code or machine code (zeros and ones). This code is also known as object code.

Output: hello.o

4) Linker: Linking is the final step of compilation. The linker merges all the object code from multiple modules into one. If we use a function from libraries, the linker will link our code with that library function code.

In static linking, the linker copies all used library functions to the executable file.

In dynamic linking, the code is not copied; it is done by just placing the library's name
in the binary file.

![compilation_process](../../assets/img/gcc_compilation_process.png)

## Difference between a switch and an if statement

## Common problems - segmentation fault, memory leaks

## C reserved words - const (in parameters), extern, private, volatile, static (variables), etc. for both variables and functions.

**Static Functions:** Static functions in C are restricted to the same file in which they are defined. The functions in C are, by default, global. If we want to limit the function's scope, we use the keyword static before the function. Doing so restricts the scope of the function in other files, and the function remains callable only in the file in which it is defined.

## Pointers to functions

## Libraries

Libraries are collections of precompiled functions that have been written to be reusable. Typically, they consist of sets of related functions to perform a common task. 

The C compiler (or, more exactly, the linker) needs to be told which libraries to search because, by default, it searches only the standard C library.

A library filename always starts with lib. Then follow the part indicating what library this is (like c for the C library, or m for the mathematical library). The last part starts with a dot (.), and specifies the type of library:

  - .a for static libraries
  - .so for shared libraries

The simplest form of library is just a collection of object files kept together in a ready-to-use form.
When a program needs to use a function stored in the library, it includes a header file that declares the function. The compiler and linker take care of combining the program code and the library into a single executable program. You must use the -l option to indicate which libraries other than
the standard C runtime library are required.

  - **Static libraries**, also known as archives, conventionally have names that end with .a. Example,
    /usr/lib/libc.a for the standard C library. You can create your own static libraries using ar (for archive) program 
    and compiling functions separately with gcc -c. [Example of a static library](). For futher information how to
    create a shared library check Introduction to Programming Linux book p.11. One disadvantage of static libraries is that
    when you run many applications at the same time and they all use functions from the same library, you may end up with many
    copies of the same functions in memory and indeed many copies in the program files themselves. This can consume a large
    amount of valuable memory and disk space. Shared libraries can overcome this disadvantage.

  - **Shared Libraries** have the so suffix, e.g., the shared version of the standard math library is /lib/libm.so. When a
    program uses a shared library, it is linked in such a way that it doesn't contain function code itself, but references to
    shared code that will be made available at run time. When the resulting program is loaded into memory to be executed, the
    function references are resolved and calls are made to the shared library, which will be loaded into memory if needed. In
    this way, the system can arrange for a single copy of a shared library to be used by many applications at once and stored
    just once on the disk. An additional benefit is that the shared library can be updated independently of the applications
    that rely on it.

    In Linux, the program (dynamic loader) that takes care of loading shared libraries and resolving client program functions
    references is called ld.so.

    You can verify which libraries have been linked in this or any other program by using the
    readelf command:

    ``` $ readelf -a myprog | grep "Shared library" ```

    Shared libraries need a runtime linker, which you can expose using this:

    ``` $ readelf -a myprog | grep "program interpreter" ```

## The C Library

The C library is not a single library file. It is composed of four main parts that together implement the POSIX API:

  - libc: The main C library that contains the well-known POSIX functions such as printf, open, close, read, write, and so on.
  - libm: Contains math functions such as cos, exp, and log
  - libpthread: Contains all the POSIX thread functions with names beginning with pthread_
  - librt: Has the real-time extensions to POSIX, including shared memory and asynchronous I/O

The first one, libc, is always linked, in but the others have to be explicitly linked with the -l option.

## main() arguments

When a Linux program written in C runs, it starts at the function main. For these programs, main is declared as

```int main(int argc, char *argv[])```

where argc is a count of the program arguments and argv is an array of character strings representing the arguments themselves.

## How to start a C program withouth main() function?

## Macros

A macro is a fragment of code which has been given a name. Whenever the name is used, it is replaced by the contents of the macro.

## Using macros vs constants, what's the difference?

Macros are handled by the pre-processor - the pre-processor does text replacement in your source file, replacing all occurances of 'A' with the literal 8.

Constants are handled by the compiler. They have the added benefit of type safety.

For the actual compiled code, with any modern compiler, there should be zero performance difference between the two.

### Inline Functions

Both C99 and GNU C support inline functions. An inline functions is, as its name suggests, inserted inline into each function call site. 

Developers use inline functions for small time-critical functions.

Making large functions inline, specially those used more than once or that are not exceedingly time critical, is frowned upon.

An inline function is declared when the keywords ```static``` and ```inline``` are used as part of the function definition. For example:

```c
    static inline void wolf(unsigned long tail_size);
```

## Frequently Asked Questions

Pointers provide for machine-independent address arithmetic.

Compiling a C program - steps:

Preprocessing - this step performs macro substitution on program text, inclusion of other source files, and conditional compilation
Compiling
Assembling
Linking

https://stackoverflow.com/questions/18840422/do-negative-numbers-return-false-in-c-c

Macros: 1) Object Like 2) Function Like https://gcc.gnu.org/onlinedocs/cpp/Macros.html
Where are (automatic) local variables stored in C?
On the stack

How can you run a program without main?
How pointers know to which kind of data are they pointing to?

What’s the size of an int, float, char?
Machine-dependent

Where are dynamic allocated variables stored in C?
On the heap

Which is better for a for loop, count up or count down? Hint: count down - some processors are faster comparing to zero

Dynamic memory allocation - safest way to check that a pointer was created successfully with malloc and it’s not a NULL pointer
assert(p != NULL);
if(p == NULL) return(-1);

Malloc - Own implementation of malloc, then they increased the difficulty by saying that the memory had to be aligned to 16.

* C libraries: uClibc is much smaller than glibc, and the C library is normally used with Linux distributions. While glibc is intended to fully support all relevant C standards across a wide range of hardware and kernel platforms, uClibc specifically focuses on embedded Linux systems.

Macro, function debug, bit manipulation, state machine, interpolation.

https://www.learn-c.org/en/Variables_and_Types

Virtual Address Space of a C Program

.stack:
.data:
.heap:

## Static vs global (variables)?

While static variables have scope over the file, making them accessible only inside a given file, global variables can also be accessed outside the file.
