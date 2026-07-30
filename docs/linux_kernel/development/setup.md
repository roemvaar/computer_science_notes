---
layout: default
title: Setup
parent: Development
nav_order: 1
---

# Setup

<!-- ## Test Bench

Options:

* Virtual Box, running a Linux-based system
* QEMU
* Dedicated Laptop/PC for development
* Raspberry Pi
* Specialized hardware for your specific development -->

## Linux Kernel Hacking

**Linux:** Mainline (/linux_work/linux_mainline)

**Hardware:** QEMU (qemu-system-x86_64)

## Steps

1. Install necessary tools
    * Build tools: gcc, make
    * Kernel configuration: menuconfig dependencies
    * QEMU: emulator
    * Git: version control

2. Clone Linux [mainline](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git) repository using `git clone`.

3. Configure and build the Kernel

```bash
cd /linux_work/linux_mainline
make mrproper
```

Configure and build the kernel:

```bash
make x86_64_defconfig
make menuconfig
make -j$(nproc)
```

Detailed instructions [here](https://krinkinmu.github.io/2020/07/05/beaglebone-software-update.html).

4. Setup QEMU for kernel testing

Boot on QEMU:

```bash
qemu-system-x86_64 -kernel arch/x86/boot/bzImage -drive file=../qemu.img,index=0,media=disk,format=raw -append "root=/dev/sda console=ttyS0" --enable-kvm --nographic
```

Kill QEMU using `Ctrl-A x`.

## Other

Show and modify contents of qemu-image.img:

```bash
sudo losetup -f --show --partscan qemu.img
```

Detailed instructions [here](https://bootlin.com/doc/training/embedded-linux-qemu/embedded-linux-qemu-labs.pdf).

Is there another process using the image?

```bash
qemu-system-x86_64 -kernel arch/x86/boot/bzImage -drive file=../qemu-image.img,index=0,media=disk,format=raw -append "root=/dev/sda console=ttyS0" --enable-kvm --nographic
qemu-system-x86_64: warning: host doesn't support requested feature: CPUID.80000001H:ECX.svm [bit 2]
qemu-system-x86_64: Failed to get "write" lock
Is another process using the image [../qemu-image.img]?
```

Fix [here](https://stackoverflow.com/questions/5881134/cannot-delete-device-dev-loop0).
