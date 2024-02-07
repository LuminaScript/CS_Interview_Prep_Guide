# Operating System Basics:

1. **What is an operating system?**
    - An operating system (OS) is the program that, after being initially loaded into the computer by a boot program, manages all of the other application programs in a computer.
    - The application programs make use of the operating system by making requests for services through a defined application program interface ([API](https://www.techtarget.com/searchapparchitecture/definition/application-program-interface-API)).
    - In addition, users can interact directly with the operating system through a user interface, such as a command-line interface (CLI) or a graphical UI (GUI).
2. **Explain the main functions of an operating system.**
    1. **Resource Management**:
        - manages the computer's hardware resources: CPU, memory, disk space, input/output devices (such as printers, monitors, and keyboards), and network connections.
        - allocates resources to different applications and users as needed, and ensures that they are used efficiently:
            - tasks: process scheduling, memory management, and input/output management.
    2. **User Interface**:
        - graphical user interfaces (GUIs)
        - command-line interfaces (CLIs)
        - APIs
    3. **File Management:**
        - enables users to store and access data on the computer's storage devices.
        - It manages files and directories, and provides utilities for creating, copying, moving, and deleting files.
        - File Access Permission
    4. **Security**:
        - This includes password protection, access control, antivirus software, and firewall protection.
        - The operating system also logs events and activities to track potential security breaches and detect anomalies.
3. **Describe the difference between a process and a thread:**
    - **Resource Allocation**: threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
        - Thread: Threads within the same process share the same memory space and resources, such as file handles and open network connections. This sharing allows for faster communication and data sharing between threads but can also lead to synchronization issues.
    - **Communication**:
        - Process: Inter-process communication (IPC) is required for processes to communicate with each other. IPC mechanisms include message passing, sockets, and shared memory.
        - Thread: Threads within the same process can communicate more easily by sharing variables and data structures directly in memory. This makes thread communication faster and more efficient.
4. **What are the differences between multiprogramming, multitasking, and multiprocessing?**
    1. **MultiProgramming vs MultiProcessing:**
        - **Multiprogramming** focuses on efficient CPU utilization by rapidly switching between processes on a single CPU
        - **Multiprocessing** uses multiple CPUs or CPU cores to execute tasks concurrently, achieving true parallelism and higher performance.
    2. **Multitasking –** Multitasking is nothing but multiprogramming with a Round-robin scheduling algorithm.
    3. **Multithreading** is an extension of multitasking.
5. **Explain the concept of a context switch.**
    - CONCEPT: 
    Context switching involves saving the state of a running process and loading the state of another process to switch between them.
    - TRIGGERS:
        1. **Interrupts:** Hardware Interruption through signals
        2. **Multitasking:** Involves switching processes on the CPU, retaining the previous state for seamless execution. (Schedule Algorithm)
        3. **Kernel/User Switch:** transitioning between user mode and kernel mode in OS
6. **What are the differences between a monolithic kernel and a microkernel?**
    - Monolithic kernels house all components in kernel space.
    - Microkernels separate core functionalities in kernel space from other services in user space
7. **Describe the process of process creation and termination.**
    - **Process Creation:**
        - When a new process is created, the operating system assigns it a unique Process Identifier (PID) and adds an entry to the process table.
        - Memory space is allocated for the program, data, stack, and Process Control Block (PCB). PCB is initialized with PID, parent's PID, register values, process state ('New'), and optional priority.
        - The process is linked to the scheduling queue, and its state changes to 'Ready,' making it eligible for CPU execution.
    
   - **Process Deletion:**
    
    - Processes can terminate in two ways:
        - Self-termination: A process finishes executing its last statement and uses the **`exit()`** system call. It returns an exit code (typically 0 for success).
        - Termination by the system or parent:
            - Parent may terminate a child if the task is no longer needed, the child exceeds resource limits, or the parent process is exiting (cascaded termination).
    - Upon termination, OS reclaims resources held by the process, including memory and file buffers.
    - Process termination status and execution times are returned to the parent if it is waiting.
    - Orphaned processes, which cannot terminate due to an absent parent, are eventually inherited and terminated by the system (zombies).
        - use wait() in parent proceed to avoid zombie child process.
8. **What is the difference between preemptive and non-preemptive scheduling?**
    - preemptive scheduling allows the operating system to forcibly switch tasks in a more flexible manner, while non-preemptive scheduling relies on tasks voluntarily releasing the CPU.
    - Examples:
        - Preemptive: Round Robin, Priority Scheduling, and Multilevel Queue Scheduling
        - Non-preemptive: First-Come-First-Served (FCFS) and Shortest Job Next (SJN) scheduling
9. **What are system calls, and how are they different from normal function calls?**
    - Sys Call has more privilege than a normal subroutine.
    - Sys Call runs with kernel-mode privilege in the kernel protection domain.
    - Sys Call code and data are located in global kernel memory.
10. **Explain the concept of kernel mode and user mode.**
    - Kernel mode/system mode:  one of the central processing unit (CPU) operating modes. **While processes run in kernel mode, they have unrestricted access to the hardware.**
    - User mode: which is a non-privileged mode for user programs. 
    **A process running in user mode has limited access to the CPU and the memory.**

# Process Management:

1. **Process State (Five)**
    - **New** - The process is in the stage of being created.
    - **Ready** The process has all the resources available that it needs to run, but the CPU is not currently working on this process's instructions.
    - **Running** The CPU is working on this process's instructions.
    - **Waiting** - The process cannot run at the moment, because it is waiting for some resource to become available or for some event to occur. For example the process may be waiting for keyboard input, disk access request, inter-process messages, a timer to go off, or a child process to finish.
    - **Terminated -** The process has completed
      
2. **Process Scheduling**

Process scheduling is crucial for managing how processes are assigned to the CPU. It involves selecting a process from the ready queue and allocating the CPU to it, based on a particular scheduling algorithm. The aim is to optimize system performance metrics like CPU utilization and process turnaround time.

3. **Scheduling Algorithms**

The main scheduling algorithms include:

- First-Come, First-Served (FCFS)
- Shortest Job First (SJF)
- Priority Scheduling
- Round Robin (RR)
- Multilevel Queue Scheduling
- Multilevel Feedback Queue Scheduling

4. **Preemptive vs. Non-Preemptive Scheduling**

- **Preemptive Scheduling**: Allows the OS to interrupt a running process and reallocate the CPU to another process.
- **Non-Preemptive Scheduling**: A process runs until it completes or blocks, without being preempted by other processes.

5. **Context Switch**

A context switch is the operation of saving and restoring the state of the CPU, so that multiple processes can share a single CPU resource. While necessary for multitasking, frequent context switches can negatively impact system performance.

6. **Process Synchronization with Semaphores**

Process synchronization ensures that multiple processes can operate concurrently without conflicts. Semaphores are a synchronization mechanism that use atomic wait (P) and signal (V) operations to manage access to shared resources, ensuring mutual exclusion and deadlock prevention.

7. **The Dining Philosophers Problem**

This problem illustrates synchronization challenges in concurrent programming. Solutions involve strategies to prevent deadlock and ensure fairness, such as semaphore-based chopstick control or ordering rules for resource acquisition.

8. **Critical Section Protection**

A critical section is a code segment that accesses shared variables and must be executed by only one process or thread at a time. Protection mechanisms include locks, semaphores, and monitors, which enforce mutual exclusion.

9. **The Reader-Writer Problem**

This problem addresses managing access to a shared database among readers and writers. Solutions typically involve read-write locks or semaphores, balancing the need for concurrent read access with exclusive write access.

10. **Inter-Process Communication (IPC)**

IPC mechanisms enable processes to exchange data and synchronize their actions. Common IPC techniques include:

- Pipes (named and unnamed)
- Message Queues
- Semaphores
- Shared Memory
- Sockets
- Signals

These mechanisms support various forms of data exchange and coordination among processes, facilitating complex inter-process interactions in modern operating systems.

# Memory Management:
1.  **Virtual Memory**

Virtual memory is a memory management capability of an operating system (OS) that uses hardware and software to allow a computer to compensate for physical memory shortages, by temporarily transferring data from random access memory (RAM) to disk storage. This process creates an illusion for users of a very large (virtual) memory space.

2. **Paging**

Paging is a memory management scheme that eliminates the need for contiguous allocation of physical memory. This scheme translates logical addresses into physical addresses by breaking memory into fixed-size blocks called "pages" in logical memory and "frames" in physical memory. Advantages include:
- Elimination of external fragmentation
- More efficient use of memory
- Simplified memory allocation

3. **Page Fault**

A page fault occurs when a program tries to access a page that is mapped in the virtual address space but not loaded in physical memory. The OS handles a page fault by:
- Pausing the program's execution
- Locating the data in secondary storage
- Loading the data into RAM
- Resuming the program's execution

4. **Memory Allocation and Deallocation**

Memory allocation involves assigning a block of physical memory to a process or file. The OS typically provides mechanisms for dynamic allocation and deallocation, allowing programs to request and release memory at runtime to ensure efficient use of resources.

5. **Thrashing and Working Set Model**

Thrashing occurs when a system spends more time processing page faults than executing transactions. The working set model aims to minimize thrashing by keeping all the pages needed by a process's current working set in memory, adjusting the working set size to balance between too many and too few frames.

6. **Page Replacement Algorithms**

Page replacement algorithms decide which memory pages to page out when a page of memory needs to be allocated. Common algorithms include:
- **Least Recently Used (LRU)**: Replaces the page that has not been used for the longest period.
- **First-In, First-Out (FIFO)**: Pages out the oldest page in memory.
- **Optimal**: Replaces the page that will not be used for the longest time in the future.

7. **Page Table**

The page table is a data structure used by the virtual memory system to store the mapping between virtual addresses and physical addresses. Each process has its own page table, which the OS uses to translate logical to physical addresses during execution.

8. **Demand Paging**

Demand paging is a technique where pages are loaded into memory on demand, i.e., only when a page fault occurs. Advantages include:
- Reduced memory consumption
- Faster program start-up
- More efficient use of memory

9. **Segmentation Fault**

A segmentation fault occurs when a program attempts to access an area of memory that it is not allowed to access. The OS handles segmentation faults by terminating the offending process and, typically, reporting an error to the user or system log.

10. **Process Swapping**

Process swapping involves moving a process from main memory to a secondary storage (disk) and back to main memory. It's used to manage the set of active processes in memory, allowing the OS to share the limited resource of physical memory among a large number of processes by swapping them in and out as needed.

# File Systems

### What is a file system, and what are its components?

A file system is a method and data structure that an operating system uses to control how data is stored and retrieved. Its components include:

- **File Control Block (FCB)/inode**: Metadata about a file.
- **Directory Structure**: Organizes and provides information about all the files.
- **File Allocation Table**: Tracks the locations of files' data.
- **Data Blocks**: The smallest units of storage containing file data.

### Types of File Systems

- **FAT (File Allocation Table)**: An older, simple system that's widely compatible but lacks features like permissions and security.
- **NTFS (New Technology File System)**: Used by Windows, supporting large volumes, file permissions, and encryption.
- **ext4 (Fourth Extended Filesystem)**: Common in Linux, offering large file sizes and volumes, journaling, and extensibility.

### File Allocation and Deallocation

File allocation involves assigning disk space for files, while deallocation frees that space when files are deleted. Methods include contiguous, linked, and indexed allocation.

### File Control Block (FCB) or inode

An FCB or inode stores metadata about a file, such as its size, permissions, and disk location. It's essential for file system operations.

### File Descriptors and Tables

File descriptors are references to open files, managed per-process in file descriptor tables. They abstract file operations and enable access control.

### File Allocation Table (FAT)

FAT is a filesystem and its data structure that maps file clusters to physical locations on the disk. It simplifies file access but is less efficient for larger disks.

### File Allocation Methods

- **Sequential**: Files are stored in contiguous blocks, easy but can lead to fragmentation.
- **Direct**: Non-contiguous storage, offering flexibility at the cost of complexity.
- **Indexed**: Uses an index block to track file fragments, balancing direct access and fragmentation management.

### File Buffering

File buffering is the process of temporarily holding data in memory during input/output operations, enhancing performance and reducing disk access.

### Symbolic Links

Symbolic links are file system references that point to other files or directories, allowing multiple access paths and simplifying file management.

### File Permission Management

File permissions control read, write, and execute access based on user and group ownership, ensuring security and privacy.

# Device Management

### Device Driver

A device driver is software that allows the operating system to communicate with hardware devices, abstracting hardware specifics and providing a standard interface.

### Device Allocation and Deallocation

Device allocation grants a process exclusive access to a device, while deallocation releases it, managed by the OS to prevent conflicts.

### Device Scheduling Algorithms

Algorithms optimize device access, examples include First-Come, First-Served (FCFS), Shortest Seek Time First (SSTF), and Elevator (SCAN).

### Device Interrupt Handling

Interrupts signal device status changes, triggering the OS to pause current tasks and execute relevant interrupt service routines (ISRs).

### Device Control Block (DCB)

A DCB stores information about a device's status, configuration, and control, facilitating device management and operations.

### Spooling

Spooling is the process of queuing data for devices, typically printers, allowing for asynchronous data processing and efficient resource use.

### Device Registers

Device registers are small, fast storage locations within hardware devices, used to control operations or store status information.

### Polling vs. Interrupt-Driven I/O

- **Polling**: The CPU repeatedly checks device status, leading to potential inefficiency.
- **Interrupt-Driven I/O**: Devices notify the CPU via interrupts, reducing unnecessary CPU usage.

### Device Queue

Device queues hold requests for devices, managing them efficiently based on scheduling algorithms to optimize access and performance.

### Concept of Device Management

Device management encompasses the processes and mechanisms that control device allocation, operation, and interaction within an OS, ensuring efficient and safe hardware usage.

