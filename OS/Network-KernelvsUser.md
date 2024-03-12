Catelog

- Coding Basics in C/C++

- OS
  - concurrency
- Networking fundamentals✅
- Boundaries, Alignments, Pointers, 
  - bit operation 
  - Pointers 
  - Boundaries 
  - Byte Alignments 
- Protocols ✅
- User Space vs Kernel Space ✅
- Memory
  - Memory Mapping
  - Dynamic Memory Allocations (HW1)

## C Programming Language

- Data Type and initialization

  - Primary Data Types & Range

    ![Screenshot 2024-03-03 at 10.00.21 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-03 at 10.00.21 PM.png)

    ![Screenshot 2024-03-03 at 10.02.09 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-03 at 10.02.09 PM.png)

  - User Defined types

    - struct

      ```c
      struct Person {
          char name[50];
          int age;
          float salary;
      };
      
      int main() {
        	// direct assignment
          struct Person person1;
          strcpy(person1.name, "John Doe"); // Assuming string.h is included
          person1.age = 30;
          person1.salary = 50000.0;
        
        	// direct declaration 
        	struct Person person2 = {"John Doe", 30, 50000.0};
        
       		// designated initializers
          struct Person person3 = {.age = 30, .salary = 50000.0, .name = "John Doe"};
        
        	// zero or null
        	struct Person person3 = {0};
        	memset(&person1, 0, sizeof(person1));
      
      }
      
      ```

    - typedef

      ```c
      typedef unsigned long ulong;
      
      int main() {
          ulong number = 5000;
      }
      
      ```

    - union 

      ```c
      union Data {
          int i;
          float f;
          char str[20];
      };
      
      int main() {
          union Data data;        
          data.i = 10;
      }
      

    - Enum

      ```c
      enum weekday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
      
      int main() {
          enum weekday today = Wednesday;
      }
      
      ```

      

  - **<u>Storage Types</u>**

    > ![Screenshot 2024-03-03 at 10.12.03 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-03 at 10.12.03 PM.png)
    >
    > C Storage Classes are used to describe the features of a variable/function. These features basically include the scope, visibility, and lifetime which help us to trace the existence of a particular variable during the runtime of a program.

    - **auto**: Auto variables can be only accessed within the block/function they have been declared and not outside them (which defines their scope).

    - **extern**: 

      declare a global variable or function in another file.

      ```c
      // File1.c
      extern int globalVar;  // Declaration of a global variable that is defined in File2.c
      
      // File2.c
      int globalVar = 5;  // Definition of globalVar
      ```

    - **static**: 

      `static` variables or functions are local to the block where they are defined, but their values are preserved between function calls.

      ```c
      void function() {
          static int count = 0;  // This variable retains its value between function calls
          count++;
          printf("%d ", count);
      }
      
      int main() {
          function();  // Prints: 1
          function();  // Prints: 2
      }
      ```

    - **Register**: 

      `register` suggests that the variable should be stored in a register instead of RAM to optimize access speed. The keyword is mostly advisory, as the compiler's optimizer can override the suggestion.

      ```c
      int main() {
          register int miles = 100;
      }
      ```

  - qsort

    ```c
    typedef struct {
       char title[50];
       int pages;
       float price;
    } book;
    int compareBook(book b1, book b2){
       if(b1.price < b2.price){
          return 0;
       }
       return 1;
    }
    int main(){
      book book_arr[5];
      qsort((void*)book_arr, 5, sizeof(book_arr[0]), compareBook);
    }
    ```

    

  - Conditionals

    - goto
    - if
    - else
    - case switch
    - default

  - loops & loops controls

    - for
    - do
    - while
    - continue
    - break

  - Others

    - const
    - sizeof
    - Volatile

- Memory allocation

- Struct 

- Union

- Socket & File/IO interface

## Network Engineering

- **Questions**:

  - <u>Router vs Gateway</u>

    - **Gateway** : focus on protocol conversion and facilitating communications <u>across</u> different networks, 
    - **Routers** : focus on data packet forwarding and network traffic management <u>within and between</u> networks.

  - <u>Router vs Switch</u>

    - **Router**: Connects multiple networks and directs data packets between them using IP addresses. It determines the best path for data to travel across networks.	
    - **Switch**: Connects devices within a single network, using MAC addresses to forward data packets directly to the intended device on the local network.

  - <u>what happens when you type a URL into a web browser</u>

    1. **Browser looks up IP address for the domain**

       - Browser sends a request to the DNS (domain name system) server.
       - DNS sends back the sever IP address

    2. **Browser sends the HTTP request to the server**

       - **Initiating Communication (Application Layer)**: The user's request is prepared at the application layer using a protocol like HTTPS, which involves formatting the data packet for transport, often including secure encryption through TLS/SSL to ensure data privacy.

       - **Data Encapsulation (Transport Layer)**: The data is segmented (if necessary) and encapsulated with the necessary headers for transport. TCP or UDP protocols are used, depending on the requirements for reliability and speed. TCP provides error correction and sequence management, while UDP is faster but less reliable.

       - **Data Transmission (Network Layer)**: The data packets are sent across the internet, guided by the Internet Protocol (IP). Packets may travel through multiple routers, each making routing decisions to move the packets closer to their destination based on IP addresses.
         - <u>Packet Transmission in Routers</u>
           - **Receiving Data Packets**: Routers interface with multiple networks and first receive incoming data packets from one of these networks.
           - **Examining Packet Headers**: Each data packet contains header information, including the destination IP address. The router examines this header to determine the packet's destination.
           - **Routing Table Lookup**: The router uses the destination IP address to consult its <u>routing table</u> and find the best next hop towards the packet's destination. Routing tables contain entries for known networks, the directions (or interfaces) in which those networks can be reached, and the distance or metric to those networks, helping the router make efficient routing decisions.
           - **Forwarding Decision**: forwards the packet to the next network on its journey. This decision is based on algorithms that consider factors such as the <u>number of hops</u>, network congestion, and path reliability.
           - **Packet Transmission**: The router sends the packet out through the appropriate interface towards its next hop. This process repeats across multiple routers until the packet reaches its final destination.

       - **Physical and Link Layers**: At the lowest levels, the physical and data link layers handle the actual transmission of data over physical networks and the direct connection between devices, using protocols appropriate to the medium (e.g., Ethernet for LANs).

    3. **Server Processing**: The server receives the request and processes it. This might involve load balancing across multiple servers, database queries, or dynamic content generation before the requested document (webpage) is served back to the client.

    4. **Data Reception and Display**: The client's browser receives the data, which is then rendered as a webpage. This may involve additional requests for resources like images, CSS, or JavaScript files to fully assemble the page.

- **Basic**

  - **A router acts as a gateway to the computer network** and is placed between a modem and a switch or hub
  - **A switch connects devices** such as a desktop, laptop, and access point to the router.
  - **An access point connects a device wirelessly**. Sometimes modem, router, switch, and access point come all bundled in one device.

- **Protcols**

  - <u>**Protocols**</u> are sets of rules for message formats and procedures that allow machines and application programs to exchange information. These rules must be followed by each machine involved in the communication in order for the receiving host to be able to understand the message. 

  - **<u>TCP/IP</u>**: a family of communication protocols used to connect computer systems in a network. It is named after two of the protocols in the family: Transmission Control Protocol (TCP) and Internet Protocol (IP). Hypertext Transfer Protocol (HTTP) is a member of the TCP/IP family.

  - <u>**Layers of protocols**</u>: Application Layer, Transport Layer, Network Layer, Network Interface Layer, and Hardware.	

    ![Screenshot 2024-03-02 at 8.49.14 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-02 at 8.49.14 PM.png)

    - <u>Application Layer</u>: messages or streams of data  **<u>(HTTP)</u>**
    - <u>Transport Layer</u>: packets with a destination address **<u>(TCP or UDP)</u>**
    - <u>Internet Network layer</u>: encloses the packet in an **Internet Protocol** (**IP**) datagram, puts in the datagram header and trailer, decides where to send the datagram (either directly to a destination or else to a gateway) **<u>(IP)</u>**
    - <u>Network Interface layer</u>: accepts **IP** datagrams and transmits them as *frames*over a specific network hardware, such as Ethernet or Token-Ring networks.

  - **<u>Host data transmissions and receptions</u>**:

    ![Screenshot 2024-03-02 at 8.54.37 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-02 at 8.54.37 PM.png)

- **Internet, TCP/IP and HTTP Concepts:**

  - **IP Address**

    - **<u>Defintion</u>**: Each server or client on a TCP/IP internet is identified by a numeric IP (Internet Protocol) address.
    - **<u>Two Types</u>**:
      - **IPv4 (IP version 4) address** 
        - 128-bit addresses, usually expressed in hexadecimal notation
        - ```IP address in colon hexadecimal notation: 1:22:333:4444::abc0:def0 ```
      - **IPv6 (IP version 6) address**
        - 32-bit addresses, usually expressed in dotted decimal notation
        - ```129.126.178.99```

  - **Host names/Domain names**

    - A host, or website, on the Internet is identified by a host name, such as `www.example.com`
    - Host names are mapped to IP addresses
    - a host name and an IP address do not have a one-to-one relationship.

  - **Virtual Hosting**

    - HTTP includes the concept of virtual hosting, where a single HTTP server can represent multiple hosts at the same IP address. 
    - You can use virtual hosting in web support by setting up URIMAP resources.

  - **Port Numbers**

    - In a server, more than one user process can use TCP at the same time. 
    - To identify the data associated with each process, port numbers are used. 
    - Port numbers are 16-bit, and numbers up to 65535 are possible

  - **URL (Components)**

    1. **A scheme.** 

       The scheme identifies the protocol to be used to access the resource on the Internet. It can be HTTP (without SSL) or HTTPS (with SSL).

    2. **A host.** 

       The host name identifies the host that holds the resource. For example, `www.example.com`. A server provides services in the name of the host, but hosts and servers do not have a one-to-one mapping. 

       Host names can also be followed by a **port number**.Well-known port numbers for a service are normally omitted from the URL. Most servers use the well-known port numbers for HTTP and HTTPS , so most HTTP URLs omit the port number.

    3. **A path.** 

       The path identifies the specific resource in the host that the web client wants to access. For example, `/software/htp/cics/index.html`. 

    4. **A query string.**

       If a query string is used, it follows the path component, and provides a string of information that the resource can use for some purpose (for example, as parameters for a search or as data to be processed). T

       The query string is usually a string of name and value pairs; for example, `term=bluebird`. Name and value pairs are separated from each other by an ampersand (&); for example, `term=bluebird&source=browser-search`.

  - **HTTP Protocols**  

    - **<u>Def</u>**: Web clients and srvers interact using a text-based application-level protocol hown as HTTP

    - <u>**HTTP Transactions**</u>

      - Client: **HTTP Request** 

        - Request Line (form: <method> <URI> <version> | example: GET / HTTP/1.1)
          - methods: GET, POST, OPTIONS, HEAD, PUT, DELETE, and TRACE
          - URI: suffix of the URL that includes the filename and optional arguments
        - Request header(s)
        - empty line

      - Server: **HTTP Response**

        - Response line (form: <version> <status-code> <status-message >| example: HTTP/1.0 200 ok)

          ![Screenshot 2024-03-02 at 8.40.00 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-02 at 8.40.00 PM.png)

    - **<u>Web server provide content to clients:</u>**

      - fetch a disk file (serving static content)

      - Run an executable file and return its output (serving dynamic content)

        - **How Does the Client Pass Program Arguments to the Server?**

          ```bash
          GET /cgi-bin/adder?15000&213 HTTP/1.1
          ```

          - Arguments for GET requests are passed in the URI. As we have seen, a ‘?’ character separates the fifilename from the arguments, and each argument is separated by an ‘&’ character. 

          - Spaces are not allowed in arguments and must be represented with the %20 string.

            

- **Socket Interface** 

  - **<u>Definition</u>**: Many TCP/IP implementations provide an application programming interface to the TCP protocol; that is, to the transport layer. This interface is commonly known as the *Sockets interface*.****

- ![Screenshot 2024-03-02 at 8.45.47 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-02 at 8.45.47 PM.png)



## Kernel VS User Space

https://www.form3.tech/blog/engineering/linux-fundamentals-user-kernel-space

- Diagram Illustration
- ![Screenshot 2024-03-03 at 9.35.12 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-03 at 9.35.12 PM.png)
- ![Screenshot 2024-03-03 at 9.34.49 PM](/Users/yizhenzhang/Library/Application Support/typora-user-images/Screenshot 2024-03-03 at 9.34.49 PM.png)



- **Userspace vs Kernalspace**

  - **<u>User Space vs Kernel Space (Memory)</u>**
    - *User space* is that portion of system [*memory*](https://www.linfo.org/memory.html) in which *user processes* run. 
    - This contrasts with [*kernel space*](https://www.linfo.org/kernel_space.html), which is that portion of memory in which the [*kernel*](https://www.linfo.org/kernel.html) executes and provides its services. 

  - **<u>User Mode vs Kernel Mode</u>**
    - <u>User space</u> processes literally run in the user space part of memory. A user space process runs in [user mode](http://www.linfo.org/user_mode.html), which is the non-privileged execution mode that the process' instructions are executed with. 
    - [Kernel space](http://www.linfo.org/kernel_space.html) is the area of system memory reserved for the kernel. It is where the kernel runs and executes kernel mode instructions.[Kernel mode](http://www.linfo.org/kernel_mode.html)is the CPU execution mode of the kernel, which runs in a privileged, root-access mode. 
  - **<u>Mode Switch</u>**
    - User mode processes have to switch to kernel mode when they want to consume services provided by the kernel (e.g. disk I/O, network access). 
    - When a user space application requires the services provided by the kernel, it will signal the kernel to execute a syscall, and switch to kernel mode for the duration of the syscall execution.
  - **<u>Security</u>**: User mode execution of user-run processes ensures that a user space process cannot access or modify memory managed by the kernel, and can't interfere with another process' execution. T

  - Memory: consisted of RAM (randomly accessed memory)
  - Storage (Disk drives) - whose contents are retained after the power is turned off and which usually has a far greater capacity.

- **Syscalls** ```*man syscalls*```
  - **<u>Definition</u>**: [Syscalls](http://www.linfo.org/system_call.html) are functions in the kernel that provide services to a user space application. They are the API that the kernel exposes to user space programs, which allow a program to utilise the functionality the kernel offers.
  - Examples
    - There are a variety of syscalls for socket-based networking (e.g. *socket*, *bind*, *listen*, and *accept*), which combined offer a suite of socket-based functions for user space programs to utilise.