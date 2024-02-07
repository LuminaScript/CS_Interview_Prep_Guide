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
      
 

# Concurrency: 




# Resources:
https://www.geeksforgeeks.org/multithreading-in-c/

https://www.guru99.com/difference-between-process-and-thread.html#:~:text=Key%20Difference%20Between%20Process%20and%20Thread&text=Process%20takes%20more%20time%20for,isolated%2C%20whereas%20Threads%20share%20memory.

https://tuxthink.blogspot.com/2011/02/kernel-thread-creation-1.html
