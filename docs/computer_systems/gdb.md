---
layout: default
title: GDB
parent: Computer Systems
nav_order: 1
---

# GDB (GNU Debugger)

GDB is a powerful debugger for programs written in languages such as C, C++, and Fortran. It allows developers to inspect the behavior of a program during execution, find bugs, and analyze crashes by providing interactive debugging tools.

## Key Features

- **Breakpoints**: Pause program execution at specific lines or functions.
- **Step Execution**: Step through code line-by-line (`next` and `step` commands).
- **Variable Inspection**: Inspect and modify variable values during runtime.
- **Backtraces**: View the call stack to understand the sequence of function calls.
- **Core Dumps**: Analyze the state of a crashed program using core dump files.
- **Remote Debugging**: Debug programs running on remote systems.

## Common Commands

- `gdb program` - Start GDB with the specified program.
- `run` (or `r`) - Run the program.
- `break` (or `b`) - Set a breakpoint (e.g., `break main` or `b 42` for line 42).
- `next` (or `n`) - Execute the next line, skipping into function calls.
- `step` (or `s`) - Execute the next line, stepping into function calls.
- `continue` (or `c`) - Resume program execution.
- `print` (or `p`) - Print the value of a variable (e.g., `print var`).
- `info` - Show information (e.g., `info breakpoints`, `info variables`).
- `bt` - Display the backtrace of the current thread.
- `quit` (or `q`) - Exit GDB.

## Example Workflow

1. **Compile with Debug Symbols**: Use the `-g` flag during compilation:
    ```bash
    gcc -g -o program program.c
    ```

2. **Start Debugging**:
    ```bash
    gdb program
    ```

3. **Set a Breakpoint**:
    ```bash
    break main
    ```

4. **Run the Program**:
    ```bash
    run
    ```

5. **Inspect and Debug**:
    - Step through code using `step` or `next`.
    - Print variable values with `print var_name`.
    - Use `bt` to view the call stack.

## Key Concepts

- **Breakpoints**: Points where execution stops for inspection.
- **Watchpoints**: Stop execution when a variable's value changes.
- **Core Dumps**: Analyze the state of a program when it crashes using `gdb program core`.

## Debugging a Core Dump

1. Enable core dumps:
    ```bash
    ulimit -c unlimited
    ```
2. Run the program and let it crash to generate a `core` file.
3. Debug the core file:
    ```bash
    gdb program core
    ```

## Useful Resources

- **GDB Documentation**: [gnu.org/software/gdb](https://www.gnu.org/software/gdb)
- **Cheat Sheets**: Search for "GDB cheat sheet" for quick command references.
- **Online Tutorials**: Websites like [cs.cmu.edu/~gilpin/gdb.html](https://www.cs.cmu.edu/~gilpin/gdb.html) offer step-by-step guides.

## Debugging using GDB

The debugger is a good tool for tracing bugs.

`gdb` is the GNU debugger.

In order to run a C program with gdb, we must compile it
with the -g option which tells the compiler to embed debugging
information for the debugger to use.

Compile with debug information:

```
$ gcc -g -o program program.c
```

Use `-g3 -O0` when compiling your code. This will include
extra debug information and avoid code optimization.

```
$ gcc -g3 -O0 -o program program.c
```

Run gdb:

```
$ gdb program
```

```
$ gdb -q program
```

Passing arguments with the `--args` option

```
$ gdb -q --args program 1 2 3 4
```

If an application is already running and gets "stuck," you might want to
look inside to find out why. Just give GDB the process ID of your application
with `--pid`:

```
$ sleep 100000 &
[1] 1591979
$ gdb -q --pid 1591979
```

**Inside gdb (commands):**

* run - starts the program. Runs until termination, breakpoint
or core dumps.
* start - stop at the beginning.
* step - step to the next line.
* backtrace - list all the function calls (that lead to a
crash) in the stack frame.
* back program.c:22 - set a break point. Stop in crash.c line
22.
* print <variable> - used to retrieve the values of variables.
* continue - resume execution
* break program.c:12
  condition 1 num==50
  run
* x <address> - prints the content at address
* clear <function_name> - deletes the break points set in the
function
* delete [n] - no argument, deletes all break points, otherwise
deletes break point number n.
* list [line#] - prints line from the source code around line#.
* list - find out where you are.
* file [./program] - inside gdb, restarts the program
* info frame - inspect the stack frame. See information on the current
  stack frame.
* info locals - see the local variables and their values in the stack frame.
* info args - see the arguments to the function.
* watch <variable> - watchpoint works like breakpoints, but instead
of always stopping at a line or function call, it stops the execution when
the content of the variable changes.

Once our program has reached a break point, we can see the
execution by using the following commands:

* n - for next
* s - for step
* u - for until

## Errors

* Segmentation fault: some kind of invalid memory access.
    SIGSEGV - signal segmentation violation is an error signal
    in Unix systems (Linux). The error appears when a program
    or code tries to access an invalid memory location.

In toronto/crash.c, we're trying to copy stuff into a buffer
pointed to by buf, which hasn't been allocated, resulting in a
segmentation fault.

```
Breakpoint 2, print_sum () at crash.c:34
34	    sprintf(buf, "sum = %d", sum_to_n(atoi(line)));
(gdb) print line
$1 = "10\000\000\000\000\000\000\000"
(gdb) print buf
$2 = 0x0
```

We were lucky in this case: because buf is a global variable
and was automatically initialized to 0 (null pointer). If it
were not, it might have contained an arbitrary value like
0xbffff580, then it would no longer be obvious that the address
points to in memory is invalid.

Bugs like this are a real pain to track down.
