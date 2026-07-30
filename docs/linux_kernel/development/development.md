---
layout: default
title: Development
parent: Linux Kernel
nav_order: 1
---

# Development

## Tips:

* Start your work from the Linux mainline

    * (Usually) You will send patches on top of mainline - unless it has a dependency on next
    * Check next for dependencies or to see if the problem was already fixed

* Look at fixed bugs and how they were fixed (patches)

    * Good learning experience

* Pick a newer bug
    
    * Old ones are harder to replicate and fix

## Bug Fixing Steps

1. Pick a bug

2. Analyze it

    * Check that it hasn't been solved

    * Stack traces and logs

    * Reproduce it. Use `.config` provided at syzkaller and build kernel

    * Understand the code

    * See the code paths

    * Debug using printk

3. Fix it and create a patch

    * Start working at mainline and use .config provided at Syzkaller

    * Test your fix as much as you can

    * Send the patch to mentor for review

4. Send it upstream for review

    * `checkpatch.pl`

5. Fix suggestions from review
