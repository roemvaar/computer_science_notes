---
layout: default
title: Rust
parent: Computer Systems
nav_order: 1
---

# Rust

This is a list of the core concepts that every Rust programmer should know. For more information, go to the [Rust-Concepts] website.

Test your Rust code online [here](https://play.rust-lang.org/?version=stable&mode=debug&edition=2021).

## Ownership and Borrowing

**Ownership** is a fundamental concept in Rust. Each value in Rust has a single owner. When the owner goes out of scope, the value is dropped (cleaned up).

**Borrowing** allows you to access data owned by another variable without taking ownership. Borrows have rules to prevent data corruption (e.g., multiple mutable borrows at the same time).

**References** are pointers that allow you to access data owned by other variables. They are immutable by default, but you can create mutable references.

## Data Types

**Scalar types**: represent single values:

* Integers: `i8`, `i16`, `i32`, `i64`, `i128`, `isize` (signed), `u8`, `u16`, `u32`, `u64`, `u128`,`usize` (unsigned).
* Floating-Point: `f32`, `f64`.
* Booleans: `bool` (true or false).
* Characters: `char` (Unicode characters).

**Compound types**: combine multiple values:

* Tuples: fixed-size collections of different data types.
* Arrays: fixed-size collections of the same data types.
* Slices: dynamically sized views into arrays.
* Strings: immutable sequences of characters.
* Structs: custom data structures that group related data together.
* Enums: allow you to define a type that can have a fixed set of values.

## Control Flow

`if` statements: execute code blocks conditionally based on a boolean expression.

`else` and `else if`: provide alternative code blocks to execute if the `if` condition is false.

`match` statements: pattern matching, allowing you to compare a value against multiple patterns and execute different code blocks based on the match.

**Loops**:

`loop`: executes a block of code repeatedly.

`while`: executes a block of code as long as a condition is true

`for`: iterates over a sequence of values.

`for in` iterates over the elements of an array or slice.

## Functions

Use the `fn` keyword to define functions. Functions can take input parameters and return values. Functions can return a single value or a tuple of values.

Methods are functions associated with a specific data type (structs, enums).

## Modules and Crates

Modules organize code into logical units.

Crates are the building blocks of Rust projects. They can contain multiple modules.

`use` keyword brings items from other modules into scope.

`extern crate` (deprecated) used to bring external crates into scope.

## Error Handling

`Result` type: represents either a successful value or an error.

`Option` type: represents either a value or the absence of a value.

`unwrap()`: retrieves the value from a `Result` or `Option`, panicking if the value is not present.

`expect`: similar to `unwrap()`, but allows you to provide a custom error message.

`match` for **Error Handling**: use `match` to handle different error cases.

## Traits

**Traits**: define shared behavior for different types.

**Implementing traits**: implement traits for your custom types to provide the specified behavior.

**Generic functions**: functions that can work with different types by using traits.

## Structs and Enums

**Structs** are custom data structures that group related data together.

**Enums** allow you to define a type that can have a fixed set of values.

**Pattern Matching with Enums**: use `match` to handle different enum variants.

## Lifetime Annotations

**Lifetimes** are used to specify the duration of a reference's validity.

**Lifetime Elision**: Rust can often infer lifetimes automatically, but you may need to provide explicit annotations in some cases.

## Macros

**Macros**: code that generates other code.

**Declarative Macros**: define custom syntax.

**Procedural Macros**: more powerful macros that can manipulate the Rust compiler's AST.

## Asynchronous Programming

`async` and `await`: enable asynchronous programming, allowing you to write non-blocking code.

**Futures**: represent the eventual result of an asynchronous operation.

`tokio`: a popular asynchronous runtime for Rust.

## Memory Management

Rust manages memory automatically, using the **stack** for local variables and the **heap** for dynamically allocated data.

**Automatic memory management**. Rust's ownership and borrowing system ensures that memory is freed when it's no longer needed, preventing memory leaks.

## Cargo

**Cargo** is Rust's build system and package manager.

`Cargo.toml` is a file that defines your project's dependencies and metadata.

`Cargo.lock` is a file that locks down the versions of your dependencies.

## Standard Library

`std` is Rust's standard library, providing a wide range of utilities and data structures.

`io`: Input/output operations.

`fs`: File system operations.

`collections`: Data structures like vectors, hash maps, and sets.

`str`: String manipulation.

## Testing

**Unit Tests**: test individual functions or modules.

**Integration Tests**: test how different parts of your code interact.

`#[test]` attribute: mark functions as unit tests.

`cargo test` runs tests using Cargo.

## Documentation

`#[doc]` attribute: add documentation comments to your code.

`cargo doc`: generate documentation for your project.

## Safety

**Memory Safety**: Rust prevents memory leaks and dangling pointers.

**Data Race Prevention**: Rust's ownership system prevents multiple threads from accessing the same data concurrently without proper synchronization.
