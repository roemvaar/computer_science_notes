---
layout: default
title: Virtual File Systems
parent: Linux Kernel
nav_order: 1
---

# Virtual File Systems (VFS)

## Unix Filesystems

Historically, Unix has provided four basic filesystem-related abstractions: **files**, **directory entries**, **inodes**, and **mount points**.

A **filesystem** is a hierarchical storage of data adhering to a specific structure. A filesystem type determines how information is organized on a device to represent a tree of directories and files. Filesystems contain files, directories, and associated control information. Typical operations performed on filesystems are creation, deletion, and mounting.

In Unix, filesystems are mounted at a specific mount point in a global hierarchy known as a **namespace**. This enables all mounted filesystems to appear as entries in a single tree. Windows break the file namespace up into drive letters, such as `C:`. This breaks the namespace and leaks hardware details into the filesystem abstraction.

A **file** is an ordered string of bytes. Each file has a human-readable name for identification by both the system and the user. Typical file operations are read, write, create, and delete.

Files are organized in directories. A **directory** is analogous to a folder and usually contains related files. Directories can also contain other directories, called subdirectories. In this fashion, directories may be nested to form paths. Each component of a path is called a **directory entry**, or **dentries**. In Unix, directories are actually normal files that simply list the files contained therein. Because a directory is a file to the VFS, the same operations performed on files can be performed on directories.

Unix systems separate the concept of a file from any associated information about it, such as access permissions, size, owner, creation time, and so on. This information is sometimes called **file metadata** (that is, data about the file's data) and is stored in a separate data structure from the file, called the **inode**.

All this information is tied together with the filesystem's own control information, which is stored in the **superblock** (filesystem metadata). The superblock is a data structure containing information about the filesystem as whole (individual files and the filesystem as a whole).

Traditionally, Unix filesystems implement these notions as part of their physical disk layout. Non-Unix filesystems, such as FAT, still work in Linux, but their filesystem code must provide the apperance of these concepts with processing done on-the-fly.

## VFS Objects and Their Data Structures

The VFS is object-oriented.

The four primary object types of the VFS are:

* The **superblock** object, which represents a specific mounted filesystem.

* The **inode** object, which represents a specific file.

* The **denetry** object, which represents a directoy entry, which is a single component of a path.

* The **file** object, which represents an open file as associate with a process.

An **operations** object is contained within each of these primary objects. These objects describe the methods that the kernel invokes against the primary objects. The operations objects are implemented as a structure of pointers to functions that operate on the parent object.

Each registered filesystem is represented by a **file_system_type** structure. This object describes the filesystem and its capabilities.

Each mount point is represented by the **vfsmount** structure. This structure contains information about the mount point, such as its location and mount flags.

Two per-process structures describe the filesystem and files associated with a process. They are, respectively, the **fs_struct** structure and the **file** structure.

## procfs and sysfs

## What are the main files systems supported by the Linux kernel?

* ext4 file system: provides journaling and support for large file sizes and partitions.

* XFS file system: high-performance file system designed for large-scale storage systems.

* Btrfs file system: provides features such as snapshotting and subvolumes.
