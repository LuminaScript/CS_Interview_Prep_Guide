## 02 Memory - Introduction to Memory Allocators

- Process Memory Address Space
  - virtual address space of process
    - **Text**: program code
    - **Data**: static variables
    - **Heap**: dynamically allocated memory, grows upward Stack: automatic memory, grows downward
      - The term “program break” refers to the top of the heap.
      - The brk() system call is used to change the program break.
    - OS kernel code & data, shared by all processes

- **Fragmentation**:
  - Internal Fragmentation: padding bytes 
  - Extermal Fragmentation: the 24 bytes left available are not in one contiguous region (where memory is spread out into smaller pieces, making the allocator unable to satisfy larger requests.)

  ```c
  static void *heap_ptr = NULL:
  static size_t remaining_heap = 0;
  
  static char *mem_heap;     /* Points to first byte of heap */
  static char *mem_brk;      /* Points to last byte of heap plus 1 */
  static char *mem_max_addr; /* Max legal heap addr plus 1*/
  
  void mem_init(void)
  {
      mem_heap = mmap(NULL, MAX_HEAP, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
      if (mem_heap == MAP_FAILED) {
          perror("mmap");
          exit(1);
      }
      mem_brk = (char *) mem_heap;
      mem_max_addr = (char *)(mem_heap + MAX_HEAP);
  }
  void *mem_sbrk(int incr)
  {
      char *old_brk = mem_brk;
  
      if ((incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
          errno = ENOMEM;
          return (void *) -1;
      }
      mem_brk += incr;
      return (void *) old_brk;
  }
  int mm_init(void){
    mem_init();
    if(heap_ptr = mem_sbrk(4096) == -1) return -1;
    assert(heap_ptr % 16 == 0);
    remaining_heap = 4096;
  }
  
  void *mm_malloc(size_t size){
    if(heap_ptr == NULL) mm_init();
    if(size == 0) return NULL;
    
    size_t asize = ((size + 16 - 1)) / 16 * 16;
    if(asize > remaining_heap) {
      size_t sbrk_size = (((asize - remaining_heap) + PAGE_SIZE - 1) / PAGE_SIZE) * PAGE_SIZE;
      if(mem_sbrk(sbrk_size) == -1) return NULL;
      remaining_heap += sbrk_size;
    }
    
    char *p = heap_ptr;
    heap_ptr += asize;
    remaining_heap -= asize;
    return p;
  }
  ```
  
  
  
- **Implicit Free List**
  - Heap block structures (32 bit system)![Screenshot 2024-03-04 at 2.52.31 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-04 at 2.52.31 PM.png)
    - User payload must start an 8-byte boundary 
    - 8-byte headers: block size is always multiple of 8 -> last three bits unused -> allocated bit
  - Prologue & epilogue 
  - Coalescing Free Blocks
    - Solve false fragmentation
    - When free() is called, the allocator can attempt to coalesce the given block with its neighbors, if they are free, creating one larger block with an updated block size. 
    - footer: back traverse in the free list 

- **Explicit Free List**![Screenshot 2024-03-04 at 3.04.30 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-04 at 3.04.30 PM.png)

  ```c
  // data structure
  /*
   * mm.c - A 64-bit port of CSAPP's 32-bit implicit free list allocator.
   *
   * Simple allocator based on implicit free lists, first-fit placement, and
   * boundary tag coalescing, as described in the CS:APP3e text. Blocks must be
   * aligned to doubleword (16 byte) boundaries. Minimum block size is 32 bytes.
   */
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdint.h>
  #include <assert.h>
  
  #include "mm.h"
  #include "mem.h"
  
  #define  WORD_SIZE    8
  #define DWORD_SIZE   16
  #define  PAGE_SIZE 4096
  
  typedef struct {
      uint64_t      size : 60;
      uint64_t    unused :  3;
      uint64_t allocated :  1;
      char payload[];
  } header_t;
  
  typedef struct {
      uint64_t      size : 60;
      uint64_t    unused :  3;
      uint64_t allocated :  1;
  } footer_t;
  
  static char *heap_listp = 0;  /* Pointer to first payload */
  
  // function
  void mm_init(void){
    //Allocate leading padding, prologue, and epilogue (8 * WSIZE
    
    // 8-byte leading padding
    // initialize prologue
    // Set heap_listp to the prologue's zero-byte payload
    
    // Extend the empty heap with a free block of PAGE_SIZE bytes
    
  }
  
  void *mm_malloc(size_t size) {
     /* Search the free list for a fit */
      if ((payload = find_fit(asize)) != NULL) {
          place(payload, asize);
          return payload;
      }
    
    /* No fit found. Get more memory in PAGE_SIZE chunks and place the block */
      (payload = extend_heap(extendsize / WORD_SIZE);
      place(payload, asize);
      return payload;
  }
    
  void mm_free(void *payload)
  {
      if (payload == NULL) {
          return;
      }
  
      header(payload)->allocated = footer(payload)->allocated = 0;
      coalesce(payload);
  }
  static void *extend_heap(size_t words);
  /*
   * place - Place block of asize bytes at start of free block p
   *         and split if remainder would be at least minimum block size
   */
  static void place(void *payload, size_t asize);
       
  /*
   * find_fit - Find a fit for a block with asize bytes
   */
  static void *find_fit(size_t asize);
  static void *coalesce(void *payload);
  ```

  

- Segregated Free List
  
  - We can further optimize free list search time and memory usage by maintaining multiple free lists. Each free list contains blocks of the same or similar size.

## 03 Memory - Caching, Memory Mapping, and Advanced Allocators

- **Cache-conscious Programming**

  - <u>2-d arrays in c</u>

    ```
    +---------+---------+---------+---------+---------+---------+
    | a[0][0] | a[0][1] | a[1][0] | a[1][1] | a[2][0] | a[2][1] |
    +---------+---------+---------+---------+---------+---------+
    ```

  - <u>Example: Matrix Mulplication</u>

    Snap 1:

    ```c
    for (int i = 0; i < N; i++) { 
      for (int j = 0; j < N; j++) {
    		sum = 0;
      	for (int k = 0; k < N; k++) {
          sum += a[i][k] * b[k][j]; 
        }
        c[i][j] += sum; 
      }
    }
    ```

    - a is accessed in stride-1 

    - b is accessed in stride-N
    - two memory loads and zero memory stores (cache sum into register)

    Snap 2:
    ```c
    for (int k = 0; k < N; k++) { 
      for (int j = 0; j < N; j++) {
     		r = b[k][j];
        for (int i = 0; i < N; i++) {
          c[i][j] += a[i][k] * r; 
        }
    	} 
    }
    ```

    - a and c are both accessed in stride-N
    - two memory loads and one memory store (r)

    Snap 3

    ```c
    for (int i = 0; i < N; i++) { 
      for (int k = 0; k < N; k++) {
      	r = a[i][k];
    		for (int j = 0; j < N; j++) {
    			c[i][j] += r * b[k][j]; 
        }
      } 
    }
    ```

    - There are two memory loads and one memory store
    - b and c are both accessed in stride-1

- **Memory Mapping using ```mmap()```**

  - Map a region of the file into the address space and treat it like an array of bytes. 

  - Example of using main memory as a cache for disk

  - Functions

    ```c
    #include <sys/mman.h>
    void *mmap(void *addr, size_t length, int prot, int flag, int fd, off_t offset);
    ```

    - **addr**: The suggested starting address of the new mapping. Prefer to pass NULL and let mmap() decide the starting address and return it  

    - **length & offset**: The length and offset of the mapping

    - **prot**: Protection of the mapped region (e.g., read, write, execute)

    - **flag**: Visibility and other modifiers

      - MAP_SHARED : Updates to the mapping are visible to other processes, and are carried through to the underlying file

      - MAP_PRIVATE : Updates to the mapping are not visible to other processes, and are not carried through to the underlying file

        - In practice, the OS kernel does not eagerly create independent copies of private mappings. Instead, such mappings are marked read-only and shared between the processes until one of them makes a modification. At that point, the OS kernel creates the independent copy of the mapping. This optimization is known as Copy-On-Write (COW). Some mappings will never be modified and remain shared, e.g., program code.

          COW is an especially performant optimization when you consider the fact that fork() is often followed by exec() which will replace the program image anyways.

          The exec() system call also takes advantage of memory mappings. Loading the new program code into memory can be accomplished simply by mapping the executable file into the text region of the process’s address space.

      - MAP_ANONYMOUS : The mapping is not backed by any file. This has the effect of simply allocating memory to the process when used with MAP_PRIVATE

    - **fd**: File descriptor for the file to be mapped. Use -1 for anonymous mapping

## 04 - Process Control

- Parent & Child Termination
  -  the parent process terminates before its children?
    - Orphan processes are adopted by the init process which periodically calls a variant of waitpid() .
  -  a child process has terminated, but the parent never calls waitpid() ?
    - The OS kernel keeps around information about a terminated process in order to allow its parent process to perform a wait at a later time. Such processes are said to be in the “zombie” state. Zombie processes should eventually be waited on to free up system resources.

## 05 - Signals

- #### Commands for Job Control

  - **Sending to Background**: To start a process in the background, append `&` to the command (`proc1 | proc2 &`). The shell responds with a job number and PID (`[1] 7106`), indicating the process is running in the background.

  - **Foreground and Background Process Groups**: Each shell session has one foreground process group (interacting with the terminal) and can have multiple background process groups.

  - **Managing Jobs**:

    - `jobs`: Lists all background jobs.

    - `Ctrl-Z`: Suspends the foreground job, allowing it to be moved to the background.

    - `bg <job>`: Resumes a suspended job in the background.

    - `fg <job>`: Brings a background job to the foreground.

      

- #### **Sending Signals**

  - **Functions**:

    - `int kill(pid_t pid, int signo);`
    - `int raise(int signo);`
    - Returns 0 if OK, -1 on error.
    - `kill` sends a signal to a specific process or process group. If `pid < 0`, it sends the signal to the process group `pgid == |pid|`.

  - **Terminal-generated signals**:

    - `Ctrl-C` sends `SIGINT`.
    - `Ctrl-\` sends `SIGQUIT`.
    - `Ctrl-Z` sends `SIGTSTP`.

    - Background process groups don’t receive these signals.

  - **`signal()` signal handler**

    - Sets the disposition of a signal.

      ```c
      typedef void (*sighandler_t)(int);
      sighandler_t signal(int signum, sighandler_t handler);
      ```

      - Handler can be `SIG_IGN` (ignore the signal), `SIG_DFL` (default action), or a custom function.

      - Portability is limited; `SIG_IGN` is the only portable use.

    

- #### Unreliable Signals and `read()`

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/wait.h>
  #include <signal.h>
  
  #define MAXLINE 4096
  
  void sig_int(int signo) {
      /* Signal handler function for SIGINT */
      printf("interrupt\n%% ");
  }
  
  int main(void) {
      char buf[MAXLINE];
      pid_t pid;
      int status;
  
      /* Set up signal handler */
      if (signal(SIGINT, sig_int) == SIG_ERR) {
          perror("signal error");
          exit(1);
      }
  
      printf("%% "); // Print prompt
      while (fgets(buf, MAXLINE, stdin) != NULL) {
          if (buf[strlen(buf) - 1] == '\n') {
              buf[strlen(buf) - 1] = 0; // Replace newline with null terminator
          }
  
          if ((pid = fork()) < 0) {
              perror("fork error");
              exit(1);
          } else if (pid == 0) { // Child process
              execlp(buf, buf, (char *)0);
              fprintf(stderr, "couldn't execute: %s\n", buf);
              exit(127);
          }
  
          // Parent process
          if ((pid = waitpid(pid, &status, 0)) < 0) {
              perror("waitpid error");
              exit(1);
          }
          printf("%% ");
      }
      exit(0);
  }
  
  ```

  1. **Interruption of Slow System Calls**
     - Slow system calls, like `read()`, may get interrupted by signals, setting `errno` to `EINTR` and causing `fgets()` to return `NULL`.
     - **Global Variable**: `errno` is set to the ID of the last error.
     - **Automatic Restart**: Some OS kernels (e.g., FreeBSD, macOS) automatically restart interrupted syscalls.
     - **Hotfix**: Manually check for `EINTR` and restart the syscall. Ideally, specify restart semantics during signal handler installation.

  2. **Signal Loss**

     - The disposition set with `signal()` in Linux resets after handling each signal, which is not the case in some OS kernels like FreeBSD and macOS.

     - **Hotfix**: Reset the disposition after detecting `EINTR`. This introduces a race condition if another signal arrives before resetting the disposition.

     - **Ideal Approach**: Specify disposition reset semantics during signal handler installation to avoid manual resetting.

  3. **Reentrancy Issues**

     - Certain functions (`malloc()`, `free()`, functions with static buffers, standard I/O functions) are unsafe to call from within a signal handler due to reentrancy issues.

       - **Problem**: Calling these functions asynchronously (i.e., reentering in the middle of execution) can cause data corruption.

       - **Solution**: Consult `man 7 signal-safety` for a list of functions that are safe to call from within signal handlers.

         

- #### `alarm()` and `pause()`

  - **<u>Function</u>**:

    - `alarm(unsigned int seconds);` generates `SIGALRM` after the specified number of seconds.
    - `pause(void);` suspends program execution until a signal is caught.

  - These can be used to implement a timeout for `read()`, but race conditions and automatic restarts of system calls must be considered.

    ```c
    static void sig_alrm(int signo) {
        /* Nothing to do, just return to interrupt the read */
    }
    
    int main(void) {
        int n;
        char line[MAXLINE];
    
        if (signal(SIGALRM, sig_alrm) == SIG_ERR) 
            err_sys("signal(SIGALRM) error");
    
        alarm(10); 
        if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0) 
            err_sys("read error");
        alarm(0); // Cancel alarm
    
    		write(STDOUT_FILENO, line, n);
        exit(0);
    }
    
    ```

    1. slow system calls are automatically **<u>restarted</u>**: 

       - **Problem**: after signal interrupt, the `read` operation could simply restart and continue waiting for input.

       - **Solution**: use system-specific mechanisms to ensure that interrupted system calls do not automatically restart. For instance, on some systems, you can use `sigaction` instead of `signal` and specify the `SA_RESTART` flag to control this behavior.

    2. **<u>A Race Condiation</u>**

       - **Problem**: the alram can be missed between alarm(10) and read():  If the signal arrives during this gap, the `read` operation would not be interrupted because it hasn't started yet, leading to potentially indefinite blocking if there's no input available.

       - **Solution**: select() – advanced I/O next week

    

  #### Signal Sets and `sigaction()`

  - **Signal sets**

    - ```sigset_t``` is another opaque type – only manipulate using above functions.
    - **<u>Bit Operation</u>**: 
      - **Turn Bit On**: ```*set |= 1 << (signo - 1);``` 
      - **Turn Bit Off**: ```*set &= ~(1 << (signo - 1));``` 
      - **Check Whetner Bit is Turn On**: ```*set & (1 << (signo - 1))) != 0``` 

    ```c
    #include <signal.h>
    // All four above return: 0 if OK, -1 on error
    int sigemptyset(sigset_t *set);
    int sigfillset(sigset_t *set);
    int sigaddset(sigset_t *set, int signo);
    int sigdelset(sigset_t *set, int signo);
    	
    // Returns: 1 if true, 0 if false, -1 on error
    int sigismember(const sigset_t *set, int signo);
    
    // definitiaons:
    int sigaddset(sigset_t *set, int signo) {
        if (SIGBAD(signo)) {
            errno = EINVAL;
            return -1;
        }
        *set |= 1 << (signo - 1); // Turn bit on
        return 0;
    }
    
    int sigdelset(sigset_t *set, int signo) {
        if (SIGBAD(signo)) {
            errno = EINVAL;
            return -1;
        }
        *set &= ~(1 << (signo - 1)); // Turn bit off
        return 0;
    }
    
    int sigismember(const sigset_t *set, int signo) {
    	if (SIGBAD(signo)) { 
        errno = EINVAL;
        return(-1); 
      }
    	return((*set & (1 << (signo - 1))) != 0); 
    }
    ```

  - **sigaction()**

    ```c
    int sigaction(int signo, const struct sigaction *restrict act, struct sigaction *restrict oact); 
    // Returns: 0 if OK, -1 on error
    
    // Structure definition for sigaction
    struct sigaction {
        void (*sa_handler)(int); /* address of signal handler */
                                 /* or SIG_IGN, or SIG_DFL */
        sigset_t sa_mask;        /* additional signals to block */
        int sa_flags;            /* signal options */
        void (*sa_sigaction)(int, siginfo_t *, void *); /* alternate handler */
    };
    ```

    - sigset_t sa_mask : additional signals to block while signo is being handled with sa_handler signo is blocked for you while in sa_handler
    - int sa_flags : handling options – some notable ones: 
      - **SA_INTERRUPT** : Don’t automatically restart slow system call (default, there may not be a flag)
      - **SA_RESTART** : Automatically restart slow system call 
      - **SA_RESETHAND** : Reset disposition of signo to SIG_DFL



## 06 - UNIX File I/O

- **open**

  ```c
  // Need to specify mode if file is being created...
  int open(const char *path, int oflag, mode_t mode); 
  // ...otherwise, mode argument is omitted.
  int open(const char *path, int oflag);
  
  // Example 1
  #include <fcntl.h>
  int fd;
  mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; char *pathname = "/tmp/file";
  fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);
  
  // Example 2:  creating a lock file for distributed synchronization
  fd = open("/var/run/myprog.pid", O_WRONLY | O_CREAT | O_EXCL, 0644);
  
  // Example3: create & open [equivalence]
  creat(path, mode);
  open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
  ```

  - **<u>Parameters</u>**:

    - **oflag**: specify a file access mode optionally bitwise-or’d with other options 

      -  **O_WRONLY**: for writing only
      - **O_TRUNC**: delete the contents of the file if any
      - **O_CREAT**: Create the file with mode if it doesn’t already exist
      - **O_EXCL** : error if O_CREAT and the file exists.
      - **O_APPEND**: the file offset gets set to the end of the file prior to each write
        - setting of the offset and writing happen in an atomic operation (as opposed to calling lseek() then write() ).

    - **mode** : specifies UNIX file permissions via a bitwise-or of user/group/other bit masks – see man chmod .

      - <u>Permission Mode: 0644</u>

        - **Symbolic Notation**: `rw-r--r--`

        - **Octal Notation**: `S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH`

      - <u>Flags Explained:</u>

        - **S_IRUSR (0400)**: Read permission for the file's owner.

        - **S_IWUSR (0200)**: Write permission for the file's owner.

        - **S_IRGRP (0040)**: Read permission for the file's group.

        - **S_IROTH (0004)**: Read permission for others.

      - <u>Detailed Breakdown:</u>

        - The **first digit** (0) indicates no special modes are set.

        - The **second digit** (6) signifies read and write permissions for the owner (`4+2`).

        - The **third and fourth digits** (4) denote read-only access for the group and others (`4` each).

      - <u>Symbolic Representation:</u>

        - **rw-**: Owner has read and write access.

        - **r--**: Group members and others have read access only.

  - **<u>Functions</u>**:

    - Creates an entry in the process’s file descriptor table and returns a file descriptor (the index of the entry in the table). 
    - The entry stores the current offset into the file, the open options, and other metadata.

- **close** 

  - ```int close(int fildes);```

  - Deletes the file descriptor table entry at index fildes .

    

- **lseek**
  - ```off_t lseek(int fildes, off_t offset, int whence)```
  - Note that lseek() <u>doesn’t actually do file I/O</u> – it only modifies the file table entry. read
  - <u>Whence</u>: 
    - **SEEK_SET** , the file offset shall be set to offset bytes.
    - **SEEK_CUR** , the file offset shall be set to its current location plus offset. 
    - **SEEK_END** , the file offset shall be set to the size of the file plus offset.
- **read**
  - ```ssize_t read(int files, void *buf, size_t nbyte);```
  - <u>Return value:</u> 
    - Returns number of bytes read (Number of bytes read may be less than the requested nbyte – check return value.)
    - 0 if end of file
    - -1 on error. 
  - <u>Slow System Call</u>
    - read() may **block forever** on a “slow” read from <u>pipes</u>, <u>FIFOs</u> (aka named pipes), <u>sockets</u>, or <u>keyboard</u>.
    - performing disk I/O blocks the process and is timewise-slow, we don’t consider that kind of read as a “slow” read – we know it will eventually return.
  - <u>Sockets</u>:
    - read(socket, buf, nbyte) = recv(socket, buf, nbyte, 0) 
    - ```ssize_t recv(int socket, void *buffer, size_t length, int flags);```
      - normally, recv() blocks until it has <u>received at least 1 byte</u>
      - returns num bytes received, <u>0</u> if connection closed, <u>-1</u> if error

- **write**
  - ```ssize_t write(int fildes, const void *buf, size_t nbytes);```
  - <u>Return Value</u>:
    - number of bytes written (Number of bytes written may be less than the requested nbyte (e.g. filling up a disk).
    - -1 on error. 
  - <u>Slow System Call</u>
    - read() may **block forever** on a “slow” write into <u>pipes</u>, <u>FIFOs</u> (aka named pipes), <u>sockets</u>.
  - <u>Sockets</u>:
    -  write(socket, buf, nbyte) = send(socket, buf, nbyte, 0)
    - ```ssize_t send(int socket, void *buffer, size_t length, int flags);```
      - normally, send() blocks until it <u>sends all bytes requested</u>
      - returns num bytes sent,  <u>-1</u> if error

- **Atomicity**
  - given an operation with multiple steps, either all steps are performed (on success) of none are performed (on failure). Not possible to observe a subset of steps performed.

- **C Standard I/O Library**

  ```c
  FILE *fopen(const char *pathname, const char *mode); // open()
  int fclose(FILE *stream); // close()
  int fseek(FILE *stream, long offset, int whence); // lseek()
  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); // read() 
  size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream); // write
  ```

  - **<u>Opague Type</u>**: 

    - FILE * is an “opaque object” – not meant to be inspected, just passed into API.
    - Contains int fd , lock, buffer pointer/metadata, stream status, etc.

  - **<u>Buffering</u>**

    - <u>Goal</u>: reduce read/write syscalls

    - <u>Solution</u>: fread() / fwrite() call read() / write() once in a while, then use

      underlying buffer.

- **File Sharing**
  - **kernel data structures for open files <u>(3)</u>**
    1. Per-process file descriptor table
    2. File table entry (possibly shared, see later examples). 
    3. Instance of opened file Inode (kernel representation of file)
  - **Cases**
    - **CASE I**: two independent processes with the same file open (fork-then-open) 
      - Different file descriptor table, file table entries
      -  Same inode
    - **Case II**: after dup(1)
      - New <u>file descriptor table slot</u> points to the same file table entry/ same inode
    - **CASE III:** Sharing of open files between parent and child after (open-then-fork)
      - Similar to dup() – child file descriptor table is constructed as if it were dup() ‘d – references parent file table entries.



## 07 - POSIX Threads 

- Processes vs. threads:

  - Processes DO NOT share virtual memory address space
  - Threads DO share virtual memory address space but each thread has its own stack 

- **Thread synchronization problem**:

  - **Race condition**: i++ is not an atomic operation:

  - **<u>Solution</u>**:

    - **Mutex lock**

      ```c
      pthread_mutex_t balance_lock = PTHREAD_MUTEX_INITIALIZER;
      
      pthread_mutex_lock(&balance_lock); 
      ++balance; // critical area 
      pthread_mutex_unlock(&balance_lock);
      ```

      POSIX Mutex API

      ```c
      #include <pthread.h>
      #include <time.h>
      
      int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
      // Both return: 0 if OK, error number on failure
      
      int pthread_mutex_destroy(pthread_mutex_t *mutex);
      
      int pthread_mutex_lock(pthread_mutex_t *mutex);
      int pthread_mutex_trylock(pthread_mutex_t *mutex);
      int pthread_mutex_unlock(pthread_mutex_t *mutex);
      // All return: 0 if OK, error number on failure
      
      int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex, const struct timespec *restrict tsptr);
      // Returns: 0 if OK, error number on failure
      ```

    - **Deadlock**

      - <u>Deadlock condition</u>:
        1. a thread tries to lock the same mutex twice
        2. a thread holds mutex A and tries to lock mutex B, and another thread hold mutex B and tries to lock mutex A
      - <u>Solution</u>: strict order to avoid dead lock

    - **Conditional Variables**

      ```c
      #include <pthread.h>
      
      struct msg {
          struct msg *m_next;
          /* ... more stuff here ... */
      };
      
      struct msg *workq;
      
      //  A condition variable used to signal when there is work to be done (i.e., when a message is added to the queue). It's used to avoid busy waiting, allowing threads to sleep until there's a message to process.
      pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
      
      //  A mutex that protects access to the shared work queue, ensuring that only one thread can modify the queue at a time.
      pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;
      
      void process_msg(void) {
          struct msg *mp;
          for (;;) {
            	//  Locks the mutex to gain exclusive access to the work queue.
              pthread_mutex_lock(&qlock);
              while (workq == NULL){
                	// eleases the mutex and waits for the condition variable qready to be signaled (indicating that a message is available), then re-acquires the mutex upon waking.
                  pthread_cond_wait(&qready, &qlock);
              }
              mp = workq;
              workq = mp->m_next;
              pthread_mutex_unlock(&qlock);
              /* now process the message mp */
          }
      }
      
      void enqueue_msg(struct msg *mp) {
          pthread_mutex_lock(&qlock);
          mp->m_next = workq;
          workq = mp;
          pthread_cond_signal(&qready);
          pthread_mutex_unlock(&qlock);
      }
      ```

    - **Semaphores**

      - an interger value manipulated by two methods

        1. Increment:increasetheinteger
        2. Decrement:waituntilvalue>0,thendecreasetheintegervalue

      - **Types**:

        - <u>Binary Semaphore</u> (a.k.a lock): initial value 1, protecting one resource

          > 1. Before acquiring resource, run sem_wait() . Value decremented to 0. 
          > 2. Useresource
          > 3. Run sem_post() to release the resource. Value incremented to 1.

          * *concurrent access sleeps when mutex is 0, wakeup when value is 1.*

        - <u>Counting Semaphore</u>: initial value N > 1, protecting N resources

          > 1. Before acquiring resource, run sem_wait() . Value is decremented by 1. 
          > 2. Use resource
          > 3. Run sem_post() to release the resource. Value incremented by 1.

          - *Since there are N resources, concurrent access is blocked only after N concurrent accesses (i.e. when the value hits 0). N + 1 th concurrent access sees value of 0, blocks, is woken up when the value becomes positive again (i.e. some users posted the semaphore).*

        - <u>Ordering Semaphore</u>

          Ensure Order: A  -> B

          ```c
          sem = 0  // initial value is 0
          
          P1: sem_wait() -> B
          
          P2: A -> sem_post()
          ```

      - **POSIX API**

        - **<u>unamed semaphores</u>**

          ```c
          #include <semaphore.h>
          int sem_init(sem_t *sem, int pshared, unsigned int value); 		
          	// Returns: 0 if OK, –1 on error
          
          int sem_destroy(sem_t *sem);
          	// Returns: 0 if OK, –1 on error
          ```

          - <u>int pshared</u>: If semaphore is meant to be shared with child <u>processes</u>, pass in non-zero value. Otherwise (i.e., shared among threads), pass in 0. 

          - <u>unsigned int value</u>: Initial value for the semaphore.

        - **<u>Named Semaphores</u>**

          - Named semaphores are meant to be used by unrelated processes, using the file name as a “redezvous” point. 

          ```c
          #include <semaphore.h>
          sem_t *sem_open(const char *name, int oflag, ...
          	/* mode_t mode, unsigned int value */ );
          	// Returns: Pointer to semaphore if OK, SEM_FAILED on error
          
          int sem_close(sem_t *sem);
          	// Returns: 0 if OK, –1 on error
          
          int sem_unlink(const char *name);
          	// Returns: 0 if OK, –1 on error
          ```

        - **<u>Incrementing/Decrementin Semaphores</u>**

          ```c
          #include <semaphore.h> 
          #include <time.h>
          
          // never blocks
          int sem_post(sem_t *sem); 
          
          // blocks until semaphore value is positive (Sets errno to EINTR if interrupted by a signal)
          int sem_wait(sem_t *sem); 
          
          // does NOT block, fails immediately if semaphore value is 0 (Sets errno to EAGAIN if the semaphore is unavailable)
          int sem_trywait(sem_t *sem); 
          
          // but with a timeout value (Sets errno to ETIMEDOUT if sem_timedwait() returns due to the timeout)
          int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict tsptr); 
          
          // All functions return 0 if OK, –1 on error
          ```

        - **Examples: Producer-Consumer Problem**

          ```c
          #include <stdio.h>
          #include <stdlib.h>
          #include <stdint.h>    // For uint32_t
          #include <semaphore.h> // For sem_t and semaphore operations
          #include <pthread.h>   // For threading, if needed
          
          #define N 10 // Define the size of the buffer
          
          uint32_t buffer[N];
          sem_t empty; // Number of empty slots
          sem_t full;  // Number of filled slots
          sem_t guard; // Mutex for ring buffer access
          
          uint32_t pi = 0; // Producer index
          uint32_t ci = 0; // Consumer index
          
          void enqueue(uint32_t piece) {
              sem_wait(&empty);
              sem_wait(&guard);
              
              buffer[pi] = piece;
              pi = (pi + 1) % N; // circular buffer
              
              sem_post(&guard);
              sem_post(&full);
          }
          
          uint32_t dequeue() {
              uint32_t piece;
              
              sem_wait(&full);
              sem_wait(&guard);
              
              piece = buffer[ci];
              ci = (ci + 1) % N;
              
              sem_post(&guard);
              sem_post(&empty);
              
              return piece;
          }
          ```


- **Pros and Cons of Synchronization Mechanisms**

  - **<u>Mutex</u>**

    - **Pros**

      - Mutual exclusivity ensures no deadlock from mutual exclusion.

      - Sleeping threads save CPU resources.


    - **Cons**

      - Starvation if a thread in the critical area procrastinates.

      - Sleep overhead.

      - Potential for deadlocks if a mutex is locked twice, or if there's a scenario where "A locks B and B locks A".


  - **<u>Semaphores</u>**

    - **Pros**

      - Allows ordering of access to resources.

      - Allows multiple accesses (N) to a resource, providing flexibility.

      - Idle wait mechanism saves CPU resources.


    - **Cons**

      - Potential for deadlocks.

      - Sleep overhead.


  - <u>**Conditional Variables**</u>

    - **Pros**

      - Suitable for cases where threads need to wait for specific events or states, allowing for efficient wake-up calls.

    - **Cons**

      - Race conditions can occur if not used properly with mutexes.

      - Sleep overhead.


  - **<u>Spin Lock</u>**



## 08 - Interprocess communicatuon in UNIX





Binary

- print binary representation of an integer 

  ```c
  // print binary representation of an interger
  void pr_binary(int num){
      for(int i=10;i>=0;i--) 
      	cout<<((num>>i)&1);
      cout<<endl;
  }
  
  // check if the ith bit is set or not
  bool check(int n, int i){
    return n & (0x1 << i);
  }
  
  // count the number of set bits
  int count(int n){
    int cnt = 0;
    while(n){
      if(n & 0x1) cnt++;
      n = n >> 1;
    }
    return cnt;
  }
  
  // how to check if a given number is a power of 2
  bool isPowTwo(int n){
    return !(n & (n - 1)); // 16 -> 10000, 15 -> 1111, 16 & 15 -> 00000
  }
  
  n =>> 1; // divide n by 2
  n =<< 1; // multiply n by 2
  
  // clearing the set bits upto ith bit
  a = a & ~(1 << i + 1) - 1 //clearing the lsb upto ith bit;
  a = a & (1 << i + 1) - 1 
  ```

  
