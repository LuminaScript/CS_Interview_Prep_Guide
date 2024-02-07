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

## 1. Shared Memory
### Tools

### Question Prototype: 
#### Producer-Consumer Problem*
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


## 2. Message Passing
#### Tools

#### Question Prototype:
```
1. Establish a communication link (if a link already exists, no need to establish it again.)
2. Start exchanging messages using basic primitives.
    We need at least two primitives: 
    – send(message, destination) or send(message) 
    – receive(message, host) or receive(message)

```

# Process vs Thread 
* Resource Allocation: threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
    * Thread: Threads within the same process share the same memory space and resources, such as file handles and open network connections. This sharing allows for faster communication and data sharing between threads but can also lead to synchronization issues.
* Communication:
    * Process: Inter-process communication (IPC) is required for processes to communicate with each other. IPC mechanisms include message passing, sockets, and shared memory.
    * Thread: Threads within the same process can communicate more easily by sharing variables and data structures directly in memory. This makes thread communication faster and more efficient.
 

# Concurrency: 
