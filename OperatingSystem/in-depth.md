# Inter-Process Communication (IPC)
IPC mechanisms enable processes to exchange data and synchronize their actions. Common IPC techniques include:
* Pipes (named and unnamed)
* Message Queues
* Semaphores
* Shared Memory
* Sockets
* Signals


## Intro
IPC enables processes to communicate and synchronize their actions, serving as a foundation for cooperation among them. It's vital for enhancing computational speed, convenience, and modularity in operating systems. IPC can be broadly classified into two categories:
- Shared Memory
- Message Passing
<img width="460" alt="Screenshot 2024-02-07 at 3 12 58 PM" src="https://github.com/LuminaScript/CS_Interview_Prep_Guide/assets/98562104/b9ef98ee-ad08-4b35-afe0-6f8cf772b906">

## prototype
### Producer-Consumer Problem*
> Idea: Producer process produces items & Consumer process consumes that item
>
> IPC: a buffer where both processes have access to

- **Two Versions**
  - V1 (Unbounded Buffer Problem): Producer can keep on producing items and there is no limit on the size of the buffer
  - V2 (Bounded Buffer Problem)Producer can produce up to a certain number of items before it starts waiting for Consumer to consume it. 

- **Algorithms**:
  ```
  1. Producer & Consumer share some common memory (buffer)
  2. Two parallel Behaviors:
      - Producer start producing item
        - If total produced item is equal to the buffer's size, producer wait to get it consumed by the Consumer.
        - Otherwise, produce items. 
      - Consumer start consuming item
        - If buffer is empty, wait till producer produced items.
        - Otherwise, consume items. 
  ```


## Types
### 1. Memory Space 
> Memory space IPC involves direct or indirect memory access by multiple processes to facilitate communication or data sharing.
- **File**: A record stored on disk, or a record synthesized on demand by a file server, which can be accessed by multiple processes.
- **Shared memory**: Multiple processes are given access to the same block of memory, which creates a shared buffer for the processes to communicate with each other.
- **Memory-mapped file**: a file mapped to RAM and can be modified by changing memory addresses directly instead of outputting to a stream. 

### 2. Message Passing
> Memory space IPC involves direct or indirect memory access by multiple processes to facilitate communication or data sharing.
- **Signal**: a system message sent from one process to another
- **Socket**: data sent over a network interface (stream-oriented [tcp] | message-oriented [UDP])
- **Unix Domain Socket**: similar to internet socket but communications occurs within the kernel
  - use the file system as their address space (process reference a domain socket as an inode)
  - multiple process can communicate with one socket
- **Message Queue**:
  - a data stream similar to a socket, but usually preserves message boundaries.
    - Allow multiple processes to read & write to the messaage queue without being directly connected to each other
- **Anonymous pipe**:
  - A unidirectional data channel using STDIN/STDOUT
    - One-way communication: Product & Consumer Prototype implemented by OS
    - Two-way communication: using 2 pipes in opposite directions
- **Named Pipe**:
  - A pipe that is treated like a file (write & read from a named pipe)


# Process vs Thread 
* Resource Allocation: threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
    * Thread: Threads within the same process share the same memory space and resources, such as file handles and open network connections. This sharing allows for faster communication and data sharing between threads but can also lead to synchronization issues.
* Communication:
    * Process: Inter-process communication (IPC) is required for processes to communicate with each other. IPC mechanisms include message passing, sockets, and shared memory.
    * Thread: Threads within the same process can communicate more easily by sharing variables and data structures directly in memory. This makes thread communication faster and more efficient.
 

# Concurrency: 
