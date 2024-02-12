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
## Intro
- **Process**
  ```c
  $ cat multiproc.c
  #include<stdio.h> 
  #include<signal.h> 
  #include<wait.h> 
  int val = 10; 
  void handler(int sig) 
  { 
      val += 5; 
  } 
  int main() 
  { 
      pid_t pid; 
      signal(SIGCHLD, handler); 
      if ((pid = fork()) == 0) 
      { 
          val -= 3; 
          exit(0); 
      } 
      waitpid(pid, NULL, 0); 
      printf("val = %d\n", val); 
      exit(0); 
  }
  
  $ make && ./multiproc
  val = 15 
  ```


# Concurrency: 
## Threads
- **Thread**
  - **Retaionship to process**: Thread is an execution unit that is part of a process. A process can have multiple threads, all executing at the same time. It is a unit of execution in concurrent programming.
  - **Why Thread?**: A thread is lightweight and can be managed independently by a scheduler. It helps you to improve the application performance using parallelism.
  - **Shared Resources between Threads**: Multiple threads share information like data, code, files, etc.
  - **3 Implementations of Threads**:
    - Kernel-level threads
      ```c
      #include <linux/module.h>
      #include <linux/kernel.h>
      #include <linux/kthread.h>  // for threads
      #include <linux/sched.h>  // for task_struct
      #include <linux/time.h>   // for using jiffies 
      #include <linux/timer.h>
      
      static struct task_struct *thread1;
      
      
      int thread_fn() {
      
      unsigned long j0,j1;
      int delay = 60*HZ;
      
      printk(KERN_INFO "In thread1");
      j0 = jiffies;
      j1 = j0 + delay;
      
      while (time_before(jiffies, j1))
              schedule();
      
      return 0;
      }
      
      int thread_init (void) {
         
          char  our_thread[8]="thread1";
          printk(KERN_INFO "in init");
          thread1 = kthread_create(thread_fn,NULL,our_thread);
          if((thread1))
              {
              printk(KERN_INFO "in if");
              wake_up_process(thread1);
              }
      
          return 0;
      }
      
      
      
      void thread_cleanup(void) {
       int ret;
       ret = kthread_stop(thread1);
       if(!ret)
        printk(KERN_INFO "Thread stopped");
      
      }
      MODULE_LICENSE("GPL");   
      module_init(thread_init);
      module_exit(thread_cleanup
      ```
      ```bash
      $ cat Makefile
      
      ifneq ($(KERNELRELEASE),)
       obj-m := threads.o
      else
      
      KERNELDIR ?= /lib/modules/$(shell uname -r)/build
      
      PWD := $(shell pwd)
      
      default:
          $(MAKE) -C $(KERNELDIR) M=$(PWD) modules 
      endif
      
      $ make
      $ sudo insmod threads.ko
      
      $ ps -ef | grep thread
      root      2589     2 99 12:43 ?        00:00:19 [thread1]
      
      $ sudo rmmod threads
      ```
    - User-level threads
      ```c
      #include <stdio.h> 
      #include <stdlib.h> 
      #include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
      #include <pthread.h> 
        
      // A normal C function that is executed as a thread  
      // when its name is specified in pthread_create() 
      void *myThreadFun(void *vargp) 
      { 
          sleep(1); 
          printf("Printing GeeksQuiz from Thread \n"); 
          return NULL; 
      } 
         
      int main() 
      { 
          pthread_t thread_id; 
          printf("Before Thread\n"); 
          pthread_create(&thread_id, NULL, myThreadFun, NULL); 
          pthread_join(thread_id, NULL); 
          printf("After Thread\n"); 
          exit(0); 
      }
      ```
      

## Lock
- A lock is just a variable & Exactly one thread holds the lock in the critical section
- Pthread Lock:
  - MUTEX = POSIX Library lock
    ```c
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&lock);
    balance++;
    pthread_mutex_unlock(&lock);
    ```
- **Implementation of Lock** (Hardware Level Pseudo-code)
  - **Test & Set**
    Peterson's Algorithm:
    ```c
    int flag[2];
    int turn;
    
    void init() {
        flag[0] = flag[1] = 0;
        turn = 0;
    }
    
    void lock(int self) {
        int other = 1 - self;
        flag[self] = 1;
        turn = other;
        while (flag[other] == 1 && turn == other) {
            // Spin Wait
        }
    }
    
    void unlock(int self) {
        flag[self] = 0;
    }
    ```
    - multi-core CPU or single-core CPU with preemptive algorithms
  - **Compare & Swap**
    // To-do


- **Lock With Queues** (Sleep instead of spinning)

### Conditional Variable
1. Parent Waiting for a Child
2. The Producer/Consumer (Bounded Buffer) Problem
   ```c
    #include <stdio.h>
    #include <semaphore.h>
    #include <pthread.h>
    
    sem_t empty;
    sem_t full;
    
    void put(int value) {
        // Placeholder for put function
    }
    
    int get() {
        // Placeholder for get function
        return 0; // This should be replaced with actual retrieval logic
    }
    
    void *producer(void *arg) {
        int i;
        for (i = 0; i < loops; i++) {
            sem_wait(&empty); // line P1
            put(i);           // line P2
            sem_post(&full);  // line P3
        }
    }
    
    void *consumer(void *arg) {
        int i, tmp = 0;
        while (tmp != -1) {
            sem_wait(&full);     // line C1
            tmp = get();         // line C2
            sem_post(&empty);    // line C3
            printf("%d\n", tmp); // line C4
        }
    }
    
    int main(int argc, char *argv[]) {
        // Initialize semaphores
        sem_init(&empty, 0, MAX); // Assuming MAX is defined somewhere
        sem_init(&full, 0, 0);
    
        // ... (rest of your main function logic for creating threads and starting producer and consumer)
    
        return 0;
    }

   ```
### Semaphores
- Definition: an integer value that we can manipulate with 2 routines (sem_wait() & sem_post())
  ```c
  int sem_wait (sem_t *s) {
    // decrement the value of semaphore s by one
    // wait if value of semaphore s is negative
  }
  int sem post (sem t *s) {
    // increment the value of semaphore s by one
    // if there are one or more threads waiting, wake one
  }
  ```

## Case Studies
### I. Multi-threading Use Cases
1. **Web Server Handling Multiple Client Requests**
  - **Scenario**: A web server needs to handle multiple incoming HTTP requests concurrently. Each request is relatively lightweight and requires accessing shared resources, like memory caches or file descriptors.
  - **Why Multi-threading**: Threads within the same process share the same memory space, making it efficient for handling each request with minimal overhead. The shared memory facilitates easy access to shared resources, improving response time and resource utilization. Multi-threading in this context allows for high throughput and efficient resource management, especially when dealing with I/O-bound tasks that can benefit from threads being put to sleep and awakened without the heavy overhead of process context switching.

2. **GUI Applications**
  - **Scenario**: Graphical User Interface (GUI) applications often need to perform background tasks (like fetching data, performing calculations, etc.) while keeping the UI responsive to user actions.
  - **Why Multi-threading**: By using a separate thread for background tasks and another for the UI, the application can remain responsive to user interactions. Threads can easily update the UI or manipulate shared data structures because they operate within the same memory space, facilitating smooth and responsive user experiences. This approach is particularly effective for tasks that require frequent access to shared UI components or data structures.

### II. Multi-processing Use Cases
1.**CPU-Intensive Data Processing**
  - **Scenario**: An application needs to perform heavy data processing, utilizing multiple CPU cores to its maximum capacity. The tasks are CPU-bound, such as video encoding, complex calculations in scientific simulations, or large dataset processing.
  - **Why Multi-processing**: Multi-processing allows each process to run on a separate CPU core, enabling true parallelism. Processes do not share memory by default, which eliminates the risks of concurrency issues (like race conditions) without the need for complex synchronization mechanisms. This model maximizes CPU utilization and is beneficial in scenarios where tasks are independent and require isolation from each other to prevent mutual interference.

2. **Fault Isolation and Reliability for Critical Applications**
  - **Scenario**: A critical application that requires high reliability and fault tolerance, such as a system monitoring tool or a service that performs multiple independent tasks where the failure of one task should not affect the others.
  - **Why Multi-processing**: Multi-processing provides a strong isolation level between processes. If one process crashes, it does not directly affect the others, making the overall system more robust and reliable. This isolation also simplifies debugging and recovery, as each process can be monitored, restarted, or replaced independently without impacting other components of the application. This model is particularly useful for services that require compartmentalization for security, stability, or resource management reasons.








# Resources:
https://www.geeksforgeeks.org/multithreading-in-c/

https://www.guru99.com/difference-between-process-and-thread.html#:~:text=Key%20Difference%20Between%20Process%20and%20Thread&text=Process%20takes%20more%20time%20for,isolated%2C%20whereas%20Threads%20share%20memory.

https://tuxthink.blogspot.com/2011/02/kernel-thread-creation-1.html

https://www.geeksforgeeks.org/signals-c-language/
