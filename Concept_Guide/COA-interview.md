1. **Introduction to Computer Architecture**

   - What is computer architecture?

   - What are the three categories of computer architecture?

     - **System Design**

       - Includes all hardware components in the system such as:

         - Data processors
         - Direct memory access
         - Graphics processing unit

         - Data paths
         - Memory controllers
         - Miscellaneous aspects such as virtualization and multiprocessing

     - **Instruction Set Architecture (ISA)**

       - Part of the central processing unit visible to compiler writers and programmers
       - Defines the CPU's capabilities and functions based on:
         - What programming it can process and perform
         - Includes data formats, memory addressing modes, processor register types, word size
         - The instruction set that programmers use

     - **Microarchitecture**

       - Defines:
         - Storage elements
         - Data processing and data paths
       - Details how these elements should be implemented in the ISA

2. **Components and Functionality**

   - What are some of the components of a microprocessor/CPU? 

     ![Screenshot 2024-03-13 at 12.01.24 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-13 at 12.01.24 PM.png)

     - **Control Unit**: reads the instructions, and generates the necessary digital signals to operate the other components. 
     - **I/O Units**:  communicate with the rest of the computer system
     - **Arithmetic Logic Unit (ALU)**: performs arithmetic operations
     - **Storage Unit**:
       - **Registers**: Holds <u>a piece of info</u>, such as a computer instruction or the storage address of any particular information, etc.
       - **Cache**: The cache memory stores <u>all the frequently used data and instructions of a device</u> in it. Thus, it speeds up the overall performance and process of the computer

   - **<u>What is MESI?</u>**

     - MESI stands for the four states of the cache blocks, which are Modified, Exclusive, Shared and Invalid.
     - It's also known as the "Illinois protocol". It's used to maintain cache coherency in hierarchical memory systems. 

   - **<u>What are the different types of fields that are part of instruction?</u>**

     - **Example:** "*An instruction is like a command to a computer to perform a particular operation. The instruction format is composed of various fields in them such as:*
       - **Operation code field.** *Also called the "op-code field", this field is used to specify the operation to be performed for the instruction.*
       - **Address field.** *As the term implies, this field is used to designate the various addresses, such as memory address and register address.*
       - **Mode field.** *This field specifies as to how an operand performs or how effective an address is."*
     - Imagine an instruction meant to add two numbers, where one number is stored in register R1 and the other is directly provided in the instruction (immediate value). The instruction might look something like this in a simplified form:
       - **Op-code field**: "ADD" (indicating addition operation)
       - **Address field #1**: "R1" (indicating the first operand is in register R1)
       - **Address field #2**: "5" (immediate value to be added to the contents of R1)
       - **Mode field for Address field #1**: "Register" (indicating the operand is in a register)
       - **Mode field for Address field #2**: "Immediate" (indicating the operand is directly provided in the instruction)

   - <u>**What are the steps involved in an instruction cycle?**</u>

     - **Example:** *"A program that resides in the memory contains a set of instructions that the computer needs to perform sequentially. The cycle for every instruction is called the instruction cycle, which consists of the following steps:*
       - **Fetch instruction.** *The CPU fetches the instruction from the memory. The computer gets loaded with the address of the instruction.*
       - **Decode.** *This allows the CPU to determine what instruction must be performed and how many operands are needed to fetch to perform an instruction.*
       - **Execute.** *At this step, the instruction is performed. If the instruction has logic or arithmetic, the ALU is utilized. This is the only step of the instruction cycle that's useful from the end user's perspective."*

   - <u>**What are flip-flops?**</u>

     - *Flip-flops, also called "latches", are electronic circuits that have two stable states used to store binary data. The data stored in the states can be modified by using varying inputs. Flip-flops are fundamental components of digital electronic systems used in communications, computers and many other kinds of systems.*

3. **Performance and Efficiency Enhancements**

   - **<u>What are the different hazards?</u>**
     - structural hazards, which occur from resource conflicts when the hardware can't support all possible combinations of instructions in synchronized overlapped execution; 
     - data hazards, which occur when instructions that manifest data dependence change data in different stages of a pipeline; 
     - control hazards, which occur from the pipelining of branches and other instructions that modify the PC.
   - <u>**What is pipelining?**</u>
     - the process of collecting instruction from the processor through a pipeline. It stores and executes instructions in an orderly process
   - <u>**What are the five stages in a DLX pipeline?**</u>
   - <u>**What is the write-through method?**</u>

4. **Memory Management and Storage**

   - <u>**What is a virtual memory on a computer?**</u>
     - virtual memory is where MM store the memory from RAM
   - <u>**What is a RAID system?**</u>
     - RAID – or Redundant Array of Independent Disks – is a type of storage that writes data across multiple drives within the same system.
   - <u>**What is a cache?**</u>
     - A cache is a small amount of memory, which is a part of the CPU. It's placed closer to the CPU than the RAM. It temporarily holds data and instructions that the CPU is likely to reuse.
   - **<u>What is the easiest way to determine cache locations in which to store memory blocks?</u>**
     - Direct Mapping: maps each block of MM into one one possible cache line

5. **Communication and Synchronization**

   - <u>**What is a snooping protocol?**</u>
     - **Def**: A snooping protocol relies on a shared bus that connects all the caches and the main memory. Whenever a processor writes to its cache, it broadcasts the address of the modified block to the bus. Other processors that have a copy of the same block in their caches can either invalidate or update it, depending on the protocol variant.
     - **Pros**: simplet & fast
     - **Cons**: 
       - the bus can become a bottleneck as the number of processors and cache accesses increase. 
       - the protocol requires all the caches to monitor the bus constantly, which consumes power and bandwidth. 
       - the protocol is not suitable for distributed systems, where the bus is replaced by a network.
   - <u>**Interrupts in a microprocessor system**</u>
     - **Def**: An interrupt is a signal from a device attached to a computer or from a program within the computer that requires the OS to stop and figure out what to do next.
     - **Hardware interrupt**: generated by external devices and I/O devices (e.g. keyboard press ^C)
       - <u>Maskable interrupt</u>: can be delayed when a highest priority interrupt has occurred to the processor.
       - <u>Non maskable interrupt</u>: cannot be delayed 
     - **Software interrupt**: generated when internal devices and software programs need to access any system call
       - <u>Normal interrupt</u>: caused by the software instructions
       - <u>Exception</u>: unplanned interruption when executing a program
     - Processor handle interrupts
   - <u>**What's the difference between interrupt service routine and subroutine?**</u>
   - <u>**What are the two hardware methods to establish a priority? Explain each method.**</u>
     - **Daisy-chaining** is a method that involves connecting all the devices that can request an interrupt in a serial manner. This setting is governed by the priority of the devices, in which the device with the highest priority is placed first.
     - **Parallel priority**, on the other hand, uses a register for which bits are configured separately by the interrupt signal from each device. It may also come with a mask register, which is used to control the status of each interrupt request.
   - <u>**What does wait state mean?**</u>
     - A wait state means that the computer processor experiences a delay when accessing a device or an external memory that is slow in its response. 
     - Wait states are considered wasteful in processor performance, which is why modern-day designs try to either minimize or eliminate wait states. These include pipelines, instruction pre-fetch and pipelines, caches, branch prediction and simultaneous multithreading. While these techniques can't eliminate wait states, they can significantly minimize the problem when they work together.
   - <u>**What is a DMA?**</u>
     - DMA, which stands for Direct Memory Access, is a feature of computer systems that allows an input/output device to receive or send data directly from or to the main memory, bypassing the CPU to boost memory operations. 
     - The process is performed by a chip known as the DMA controller.

6. **Programming and Instruction Set Architecture**

   - Can you state some of the common rules of assembly language?
   - What are the different types of micro-operations?
     - **Example:** *"Micro-operations are executed on data stored in registers. They are basic math operations performed on the information stored in one or more registers. The types of micro-operations are:*
       - **Shift micro-operations:** *They perform shift operations on data stored in registers.*
       - **Logic micro-operations:** *They execute bit manipulation operations on nonnumerical data saved in registers.*
       - **Arithmetic micro-operations:** *They perform arithmetic operations, such as subtractions and additions, on digital data stored in registers.*
       - **Register transfer micro-operations:** *They transfer binary information between registers."*
   - **<u>What is associate mapping?</u>**
     - *The associative mapping technique uses several mapping functions to transfer data from the main memory to the cache memory. This means that any main memory is mapped into any line of the cache. As a result, the cache memory address is not in use. The associative cache controller processes and interprets the request by utilizing the main memory address format.*

7. **Microarchitecture**

   - What is horizontal microcode?
     - In horizontal microcode, each micro-operation is represented by one bit in each microinstruction. Horizontal microcode is generally included in a fairly wide control save it is not exceptional for each work to be 56 bits or more. On each click of a sequencer clock, a microcode word is read, decoded, and used to control the functional components which create up the CPU. The micro-operations and their mnemonics are shown in the table.