---
layout: default
title: Commands
parent: Development
nav_order: 1
---

# Commands

## Useful commands

* find
* grep

You use find to search your system for files, but you use grep to search files for strings.

### GNU toolchain tuple:

```bash
gcc -dumpmachine
arm-linux-gnueabi-gcc -dumpmachine
```

### Cross-compile:

```bash
arm-linux-gnueabi-gcc hello_world.c -o hello_world
```

### Confirm the type of the file, i.e., check that the c file was cross-compiled for your target architecture:

```bash
file hello_world
```

### Display information about the contents of ELF format files:

```bash
readelf -a libtest.a
readelf -a hello_world
```

### Check which libraries have been linked in a program:

```bash
arm-linux-gnueabi-readelf -a hello_world | grep "Shared library"
```

### Check runtime linker

```bash
arm-linux-gnueabi-readelf -a hello_world | grep "program interpreter"
```

### Link all the libraries statically (size of binary is bigger than dynamic linking):

```bash
gcc -static hello_world.c -o hello_world-static
```

### Create static library (as simple as creating an archive of object files using the ar command). Example: If you have two source files "test1.c" and "test2.c", and you want to create a static library named "libtest.a", then:

```bash
gcc -c test1.c
gcc -c test2.c
ar rc libtest.a test1.o test2.o
```

Note: gcc -c option compiles and assembles the translation unit, but does not link

### Link statically compiled library "libtest.a" into "hello_world" program:

```bash
gcc hello_world.c -ltest -L../libs -I../libs -o hello_world
```

### Create shared library (-fPIC stands for position independent):

```bash
arm-linux-gnueabi-gcc -fPIC -c test1.c
arm-linux-gnueabi-gcc -fPIC -c test2.c
arm-linux-gnueabi-gcc -shared -o libtest.so test1.o test2.o
```

### Link application to dynamic library:

```bash
arm-linux-gnueabi-gcc hello_world.c -ltest -L../libs -I../libs -o hello_world
```

### Cross-Compile Linux Kernel - BeagleBoneBlack 

```bash
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabi-
make omap2plus_defconfig
make -j32
```

### Display all running processes

``` bash
ps aux | less
ps aux
```

### Apply patches:

```
patch -p1 < file.patch
```

```
git apply --index file.patch
```

note: Prefer git apply in order to track new files that may be contained in the git patch.

### Compiling a single source file: make path/file.o

```
make drivers/media/test-drivers/vimc/vimc-core.o
```

### Compiling at the directory level: make path

```
make drivers/media/test-drivers/vimc/
```

### Compile file as module, e.g., ```vimc```:

```
make M=drivers/media/test-drivers/vimc
```

note: It's better to use ```make menuconfig``` to configure the file as a module because of all the dependencies.

Useful commands for modules:

```
sudo insmod <module>.ko
sudo insmod args_module.ko name=roberto
sudo modprobe <module>
sudo rmmod <module>
sudo dmesg | tail
```

### Count context switches:

```
sudo perf stat -e sched:sched_switch --timeout 1000
```
