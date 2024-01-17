### Operating System Basics:

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
        1. When a new process is created, the operating system assigns it a unique Process Identifier (PID) and adds an entry to the process table.
        2. Memory space is allocated for the program, data, stack, and Process Control Block (PCB). PCB is initialized with PID, parent's PID, register values, process state ('New'), and optional priority.
        3. The process is linked to the scheduling queue, and its state changes to 'Ready,' making it eligible for CPU execution.
    
    **Process Deletion:**
    
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

### Process Management:

1. Process State (Five)
    - **New** - The process is in the stage of being created.
    - **Ready** The process has all the resources available that it needs to run, but the CPU is not currently working on this process's instructions.
    - **Running** The CPU is working on this process's instructions.
    - **Waiting** - The process cannot run at the moment, because it is waiting for some resource to become available or for some event to occur. For example the process may be waiting for keyboard input, disk access request, inter-process messages, a timer to go off, or a child process to finish.
    - **Terminated -** The process has completed
2. Describe the process of process scheduling.
3. What are the different scheduling algorithms used in operating systems?
4. Explain the differences between preemptive and non-preemptive scheduling.
5. What is a context switch, and how does it affect the performance of a system?
6. Describe the process of process synchronization using semaphores.
7. Explain the dining philosophers' problem and how it can be solved.
8. What is a critical section, and how is it protected in concurrent programming?
9. Explain the reader-writer problem and how it can be solved.
10. Describe the process of process communication using inter-process communication (IPC).
11. What are the different IPC mechanisms available in operating systems?

### Memory Management:

1. What is virtual memory, and how does it work?
2. Explain the concept of paging and its advantages.
3. What is a page fault, and how is it handled by the operating system?
4. Describe the process of memory allocation and deallocation.
5. Explain the concepts of thrashing and working set model.
6. Describe the different page replacement algorithms, such as LRU, FIFO, and Optimal.
7. What is the purpose of a page table, and how is it used in virtual memory management?
8. Explain the concept of demand paging and its advantages.
9. What is a segmentation fault, and how is it handled by the operating system?
10. Describe the process of process swapping.

### File Systems:

1. What is a file system, and what are its components?
2. Explain the different types of file systems, such as FAT, NTFS, and ext4.
3. Describe the process of file allocation and deallocation.
4. What is a file control block (FCB) or an inode, and how is it used in file systems?
5. Explain the concepts of file descriptors and file descriptor tables.
6. What is a file allocation table (FAT), and how does it work?
7. Describe the differences between sequential, direct, and indexed file allocation methods.
8. Explain the concept of file buffering and its advantages.
9. What is a symbolic link, and how does it work in file systems?
10. Describe the process of file permission management in operating systems.

### Device Management:

1. What is a device driver, and what is its role in an operating system?
2. Explain the process of device allocation and deallocation.
3. What are the different types of device scheduling algorithms used in operating systems?
4. Describe the process of device interrupt handling.
5. What is a device control block (DCB), and how is it used in device management?
6. Explain the concept of spooling and its benefits.
7. What is a device register, and how does it relate to device management?
8. Describe the differences between polling and interrupt-driven I/O.
9. What is a device queue, and how is it used in device management?
10. Explain the concept of device management.
