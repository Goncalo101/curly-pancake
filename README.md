Introduction
============
This project began with my curiosity to understand how operating systems are made.
To achieve that I followed this [tutorial](https://github.com/cfenollosa/os-tutorial) and improved some of it.

Overview
========
```text
boot/       contains functions that load the C Kernel
    utils/  defines functions to print in 16-bit mode
drivers/    drivers to communicate with the VGA port and to write strings
                    to the screen in 32-bit mode
kernel/     contains the C kernel
```

Requirements
============
Building this OS requires the following packages:
- nasm
- gcc
- ld

Running
=======
In order to run this operating system you should build it with the provided Makefile. And use:
```bash
make run
```
to launch qemu in the process.
