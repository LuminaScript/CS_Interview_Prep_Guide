##  **Introduction to Computer Organization & Architecture** 

- **functionla units** 

  - **Processor**

    - registers

    - Arithmetic & logic unit

    - Timing & control unit

    - interface

  - **Memory** 

  - **I/O Peripherals**
  - **System Bus**

- <u>**Basic of Computer Architecture**</u> 

  - **Instruction Set Architecture (ISA)**

  - **Hardware System Architecture (HSA)**

- **<u>Classifications of Computer Arhciecture</u>** 

  - **Classification 1: Based on the Data and Instruction Path**

    - <u>Von Neumann Architecture (Princeton Architecture)</u>

      Von Neumann architecture is characterized by **a single memory space that stores both instructions and data.** This architecture operates under a sequential process of fetching an instruction, decoding it, executing it, and then moving on to the next instruction. The simplicity of this model facilitates the design and implementation of general-purpose computers. 

      However, it is limited by the "Von Neumann bottleneck," a limitation on throughput caused by the single path for data and instructions.

    - <u>Non-Von Neumann Architecture</u>

      - <u>Harvard Architecture</u>

        The Harvard architecture features separate memory spaces for instructions and data, allowing the CPU to access instructions and read/write data simultaneously. 

        This separation effectively doubles the potential memory bandwidth and eliminates the Von Neumann bottleneck. It's particularly beneficial for systems where instruction fetch and data operations often occur simultaneously, such as in embedded systems and DSPs (Digital Signal Processors).

        ![Screenshot 2024-03-12 at 2.53.13 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 2.53.13 PM.png)

      - <u>Modified Harvard Architecture</u>

        This architecture is a variation of the Harvard architecture that allows for some level of shared data between the instruction and data spaces, aiming to combine the performance benefits of Harvard architecture with the flexibility of Von Neumann architecture. It might use cache memory to provide a bridge between the two, allowing instructions and data to be cached separately but within a unified interface, facilitating efficient processing while maintaining a degree of separation.

        ![Screenshot 2024-03-12 at 2.53.28 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 2.53.28 PM.png)

  - Classification 2:

    - SISD (single instruction stream, single data stream)

      This classification is essentially a sequential execution model where one operation is completed before the next begins. Most traditional computers, operating under the Von Neumann architecture, fall into this category.

    - SIMD  (Single Instruction stream, Multiple Data streams)

      This model is efficient for tasks with parallelism, such as vector and matrix computations commonly found in scientific computing and graphics processing. 

    - MISD (Multiple Instruction streams, Single Data stream)

    - MIMD (Multiple Instruction streams, Multiple Data streams)

      - -> multiprocessor

## Memory Interfacing and Hierarchy

#### Frequency and Timing

- **Frequency**: 2GHz
- **Time per Cycle**: 1 / Frequency = 0.5 nanoseconds (nsecs)

#### Memory Storage Types

**Fast Memory Storage (Volatile)** Volatile memory storage types retain data only while power is supplied. They are fast but lose their content when the power is off. This category includes:

1. **Primary Memory (Dynamic Random Access Memory - DRAM)**: DRAM is the main type of volatile memory used for primary storage. It's fast but needs to be refreshed frequently to retain data.
2. **Cache**: Cache memory is a small-sized type of volatile computer memory that provides high-speed data access to a processor and stores frequently used computer programs, applications, and data. Cache helps speed the process of data retrieval by reducing the need to access the slower main memory.

**Secondary Memory (Non-Volatile)** Secondary memory is slower than primary memory but retains data permanently, even without power. It's larger in size and more cost-effective for bulk storage. This category includes:

1. **Hard Disk**: A hard disk is a type of non-volatile memory used for storing and retrieving digital information. It is slower than primary memory primarily because access is semi-random, meaning that the time it takes to read or write data can vary significantly depending on the location of the data on the disk.
2. **Why It Is Slower?**: The main reason hard disks are slower than primary memory (like DRAM and Cache) is their semi-random access nature. This means that the read/write head of the disk must physically move to the location where the data is stored, which takes significantly more time than accessing data from electronic memory.

![Screenshot 2024-03-12 at 3.19.58 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 3.19.58 PM.png)



#### Memory Hierarchy & Interfacing 

![Screenshot 2024-03-12 at 3.23.58 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 3.23.58 PM.png)

##### Memory Hierarchy

The memory hierarchy in computer architecture is a structured way of organizing different types of memory based on speed, cost, and capacity. 

It aims to balance the trade-off between high-speed access and economical storage capacity. 

The hierarchy typically includes several levels, ranging from the fastest but most costly types of memory (like CPU registers and cache) to slower, more affordable forms of storage (such as main memory and secondary storage).

- **Levels of Hierarchy**: Memory is organized in levels, where the "nth" level is faster but smaller and more expensive per bit than the "(n + 1)th" level. 

- **Hit Ratio**: the ratio of the number of hits to the total number of memory access attempts. 

  For example, if the total number of instructions is 100 and 80 of them are found in the main memory (first level of cache), the hit ratio for main memory is 80/100 = 0.8. The hit ratio in secondary memory is typically considered 1, as it is the last resort for data lookup.

##### Memory Interfacing

Memory interfacing involves the connection and communication between the memory system and the processor, ensuring data can be read from or written to memory efficiently.

- **Speed Measurement Unit**: MIPS (Million Instructions Per Second), indicating how many million instructions the CPU can process per second. 

- **Effective/Average Memory Access Time (Tavg)**: This can be calculated in two ways:

  - **Way 1**: By considering the hit ratios and access times at different levels of the hierarchy. 

    ```Tavg=H1T1 + ((1−H1)×H2)T2 + ((1−H1)×(1−H2))T3```

  - **Way 2**: By analyzing it level-wise, considering the contribution of each level's hit ratio and access time to the overall average access time.

    ```T_avg = H1T1 + ((1−H1)×H2)(T1 + T2) + ((1−H1)×(1−H2))(T1 + T2 + T3)```



### Introduction to the Cache Memory

#### Cache Levels:

- **Level 1 Cache (L1 Cache)**: This is the smallest and fastest cache layer, located closest to the processor core. L1 cache stores instructions and data for immediate access by the CPU, minimizing latency.
- **Level 2 Cache (L2 Cache)**: Larger than L1, L2 cache serves as a bridge between the ultra-fast L1 cache and the slower L3 cache. It is often shared between two or more cores in modern processors.
- **Level 3 Cache (L3 Cache)**: Also known as Shared Cache, L3 is larger than L1 and L2 caches and is shared across all the cores in the processor. It reduces data access latency for frequently accessed data.

#### Multi-core Processors and MIMD:

- **Dual-Core**: A processor with two cores that can run multiple processes simultaneously, doubling the processing power for applications optimized for multi-threading.
- **Quad-Core**: Features four processing cores, further enhancing multitasking and parallel processing capabilities for supported applications.
- **Octa-Core**: Consists of eight cores, offering superior performance for highly parallelized computing tasks and applications.

#### Terminology:

- **Cache Hit**: Occurs when the requested data is found in the cache, significantly reducing the "hit latency" or the time to access the data.
- **Tag Directory**: A data structure used in caches to quickly determine if a particular piece of data is present in the cache.
- **Cache Miss**: Happens when the requested data is not found in the cache, prompting a "seek in Main Memory (MM)" to retrieve the data.
- **Page Fault**: A type of cache miss that occurs when a data page that is not in memory is accessed, requiring "Page Fault Service Time" to load the data into memory.
- **Page Hit**: Occurs when the data sought is found in the memory, avoiding a page fault.

#### Locality of Reference:

- **Spatial Locality**: The principle that if a particular storage location is accessed, nearby storage locations are likely to be accessed in the near future. 
- **Temporal Locality**: Refers to the tendency of a processor to access the same storage location repeatedly over a short period. 



### Direct Memory Mapping

#### How memory is brought from MM into Cache

![Screenshot 2024-03-12 at 9.15.27 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 9.15.27 PM.png)

**Memory Mapping Summary Notes**

- **Word Size**: Each word in memory is equivalent to 1 byte.
- **Main Memory**:
  - Consists of a physical address space with 16 blocks, each containing 2 words (as inferred from '16 blocks 2').
  - Physical Address (P.A.) bits are split into:
    - Block number (higher bits).
    - Block offset (lower bits, to identify the word within a block).
  - The example shows a physical address of `0111` in binary, which is `7` in decimal, pointing to the block number, and a `3` in decimal as the block offset within that block.
- **Cache Memory**:
  - Total cache size is 16 words.
  - Cache is organized into lines, with each line capable of holding 4 words.
  - The total number of lines in the cache is 4.
  - Addressing requires 2 bits to identify any of the 4 words within a line (`2^2` words per line).
- **Mapping Technique**:
  - Round-robin mapping (probably referring to a cyclic replacement policy), which allows one block in memory to map to many lines in the cache (one-to-many relationship).
- **Address Splitting**:
  - P.A. bits are split into two parts:
    - Block number: Identifies which block of main memory is being referred to.
    - Block/Line offset: Identifies the specific word within the block or line.
- **Tagging**:
  - It involves using tags to identify which block of main memory a line of cache corresponds to, ensuring correct data retrieval.

**Example 1:**

![Screenshot 2024-03-12 at 9.51.37 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 9.51.37 PM.png)

###### ![Screenshot 2024-03-12 at 9.52.08 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 9.52.08 PM.png)

###### Example 2

![Screenshot 2024-03-12 at 9.52.21 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 9.52.21 PM.png)

##### Example 3

![Screenshot 2024-03-12 at 9.52.43 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-12 at 9.52.43 PM.png)



### Cache Replacement Policies

- **Random Replacement**: Selects a random cache line to replace.
- **FIFO & LIFO**: First-In-First-Out and Last-In-First-Out strategies for replacing cache lines.
- **Recency-Based Policies**: Replace cache lines based on how recently they were accessed.
- **Frequency-Based Policies**: Replace cache lines based on how frequently they are accessed.

### Write Strategy: Handling Data Modification

When the processor needs to modify a data word, it encounters two situations:

1. **Write Hit**: The data is already present in the cache.
   - Write Through (Slower, but reliable & enables easy data recovery):
     - Cache and main memory are updated simultaneously.
     - Preferable for scenarios with fewer write operations.
   - Write Back / Write Deferred (Faster, but complicates data recovery):
     - Only the cache is updated in real-time, utilizing a "Dirty-bit" to track modified lines.
     - Main memory is updated when the cached data is replaced, not immediately.
2. **Write Miss**: The data is absent from the cache.
   - Write Allocate:
     - The missing data is loaded into the cache and then updated.
     - Compatible with both write-through and write-back strategies.
   - No-Write Allocate:
     - The data is directly updated in the Main Memory without caching it first.

### Cache Coherence Problem

#### Problems in Cache Coherence

- System architecture includes cache connected to the system bus and Main Memory (MM).
- L3 cache acts as shared memory between cache layers and MM.
- Storage can be independent or shared.

#### Cache States for a Particular Cache Line

- **Modified**: The cache line has been modified by the owning processor only.
- **Shared**: The cache line holds unmodified data and may be stored in caches of multiple processors.
- **Invalid**: The cache line's data has been invalidated due to a write operation by another processor.
- **Exclusive**: The cache line is only in the current cache.
- **Owned**: Indicates a special state where the cache line can be modified by its owner.
- **Forward**: A state used to denote that the cache line can be used to service read requests from other caches.

#### Cache Coherence Overview

- **Cache Coherence**: Ensures uniformity of shared resource data that ends up stored in multiple local caches.
- **Cache Coherence Problem**: The challenge of keeping multiple local caches synchronized when one of the processors updates its local copy of data, which is shared.

#### Cache Coherency Protocols

Solutions are hardware-based to ensure coherency among caches.

- **Snooping-Based Protocols / Bus-Based Protocols**:

  - Utilize a broadcast system over a shared bus (<u>bottleneck</u> if multiple cache place broadcast request on shared bus)
  - **Write Update**: Either with write-through or write-back, where updates are propagated.
  - **Write Invalidate**: Either with write-through or write-back, where updates lead to invalidation in other caches.
  - Coherence Miss

- **Directory-Based Protocols**:

  - Employ a <u>point-to-point</u> between every nodes (cache) instead of broadcasting.

  - Use a central directory to maintain the state of each cache line and manage coherence.

  - Coverage Miss

    



## Primary Memory/Main Memory Overview

Primary memory, also known as main memory, plays a crucial role in a computer's performance and functionality. It includes two main types of memory: Read-Only Memory (ROM) and Random Access Memory (RAM). Each type serves distinct purposes, from storing essential firmware to providing temporary data storage for operations.

### Read-Only Memory (ROM)

**ROM** is non-volatile memory, meaning it retains its data even when the power is turned off. It's primarily used to store firmware, such as the Basic Input/Output System (BIOS), which is crucial for the computer's boot process.

- **Characteristics and Classification of ROM**:

  - **Programmable ROM (PROM)**: Designed to be programmed once after manufacturing. It cannot be modified or erased by standard means once programmed.
  - **Erasable Programmable ROM (EPROM)**: Allows for the data to be erased (typically using ultraviolet light) and reprogrammed, providing flexibility for updates.
  - **Electrically Erasable Programmable ROM (EEPROM)**: Similar to EPROM, but can be erased and reprogrammed electronically, allowing for easier and more frequent updates.

- **BIOS and the Boot Process**:

  - The BIOS is foundational firmware that initiates the computer's boot process, leading to the loading of the operating system into RAM.

  - Boot Process Overview:

    - **Power-On Self-Test (POST)**: This initial test checks the BIOS's integrity, verifies the CMOS chip, initializes the processor, and tests essential hardware components like the mouse.
- **Loading the Operating System**: After POST, the BIOS searches for a valid boot disk and loads the operating system onto RAM, preparing the computer for use.

### Random Access Memory (RAM)

**RAM** is volatile memory, which means it only retains data while the computer is powered on. It's used for storing data temporarily during operation, making it essential for the computer's processing capabilities.

- **Architecture and Interfaces**:
  - RAM includes a decoder to access specific data locations efficiently.
  - It commonly uses the Dual Inline Memory Module (DIMM) interface, characterized by two rows of pins with variations including 168, 184, 240, and 288 pins.
- **Types of RAM**:
  - **DRAM (Dynamic RAM)**: Operates asynchronously, requiring periodic refreshing to maintain data.
  - **SDRAM (Synchronous DRAM)**: Operates in synchronization with the system clock, making it faster than asynchronous DRAM by aligning data transfers to the clock pulses.

## Secondary Memory / Hard Disk



![Screenshot 2024-03-13 at 5.33.43 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-13 at 5.33.43 PM.png)



### RAM: The Direct Access Bridge

- **RAM (Random Access Memory)**: often referred to as the physical address space by the CPU, which contrasts with secondary memory. The distinction arises because the CPU directly accesses RAM for processing tasks, whereas secondary memory serves as long-term storage, indirectly accessed by the CPU.
- **RAM's Role**: Acts as a crucial intermediary between the fast, but limited, CPU registers and the slower, but larger, secondary memory.
- **Functionality**: Enables rapid access to data and program instructions that the CPU needs for current operations, ensuring efficient processing without direct reliance on slower secondary storage.

### Categories of Secondary Memory

Secondary memory is essential for long-term data storage, categorized broadly into removable and fixed auxiliary storage, each with unique characteristics and uses.

#### Removable Auxiliary Storages

- **Magnetic Tapes**:
  - **Usage**: Predominantly in mainframe environments and for tape vaulting, a method of offline storage.
  - **Architecture**: Data is recorded and read using tape drives.
  - **Capacity**: Can store up to 185 TB per cartridge, making them suitable for massive data backup.
- **Floppy Disk**:
  - **Construction**: Consists of a plastic housing enclosing a polyester fabric that houses the magnetic disk.
  - **Historical Significance**: Once a staple for data transfer and storage, though now largely obsolete.
- **Optical Discs**:
  - Includes CDs, DVDs, and Blu-ray discs, using laser technology to read and write data.
- **Memory Cards and Flash Drives**:
  - **Technology**: Utilize flash memory, a type of non-volatile storage that can be electrically erased and reprogrammed.
  - **Portability**: Both are highly portable, making them ideal for transferring data between devices.

#### Fixed Auxiliary Storage

- Hard Disk Drives (HDDs):
  - **Components**: Comprise multiple platters coated with magnetic material.
  - **Architecture**:
    - **Tracks and Cylinders**: Data is organized into tracks on the platters. A stack of aligned tracks across all platters forms a cylinder.
    - **Sectors**: The smallest unit of data storage, traditionally 512 bytes in size.
  - **Capacity Calculation**: The capacity of a disk is determined by the formula: Number of Tracks × Number of Sectors per Track × Number of Bytes per Sector.



## Pipelines



## GPU