## CPP Version

### C++ 11

- [Unified Initialization](https://www.geeksforgeeks.org/uniform-initialization-in-c/)

- [Multithreading](https://www.geeksforgeeks.org/multithreading-in-cpp/)

- [Smart Pointers](https://www.geeksforgeeks.org/smart-pointers-cpp/)

- [Hash Tables](https://www.geeksforgeeks.org/hashing-data-structure/)

- [std::array container](https://www.geeksforgeeks.org/stdarray-in-cpp/)

- [Move semantics](https://www.geeksforgeeks.org/stdmove-in-utility-in-c-move-semantics-move-constructors-and-move-assignment-operators/)

- [Lambda functions included](https://www.geeksforgeeks.org/lambda-expression-in-c/)

- [**auto and decltype**](https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/) added

  

### C++ 14

- [Generalized Lambdas](https://www.geeksforgeeks.org/generalized-lambda-expressions-c14/)
- Reader-Writer Locks
- [**constexpr**](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-c/) included
- Return type deductions extended to all functions



### C++ 17

- The file system library and Network concepts included
- Improved Lambdas
- [Fold Expressions](https://www.geeksforgeeks.org/features-of-c17-with-examples/) included
- [Initializers in if and switch statements](https://www.geeksforgeeks.org/c17-new-feature-else-switch-statements-initializers/)
- Concurrent and Parallel algorithms in Standard Template Library(STL)
- [Nested Namespaces](https://www.geeksforgeeks.org/features-of-c17-with-examples/)
- Transactional memory
- Inline Variables
- Optional header file
- Class Template argument deduction(CTAD)





Run-time

```bash
ubuntu@primary:~/Home$ g++ -std=c++20 helloworld.cpp -o helloworld20
ubuntu@primary:~/Home$ ls
helloworld  helloworld.cpp  helloworld20
ubuntu@primary:~/Home$ ./helloworld20
Hello, World!
ubuntu@primary:~/Home$ g++ -std=c++23 helloworld.cpp -o helloworld23
ubuntu@primary:~/Home$ ls
helloworld  helloworld.cpp  helloworld20  helloworld23
ubuntu@primary:~/Home$ g++ -std=c++25 helloworld.cpp -o helloworld25
```



## Linux Version



## Boost.Asio

#### Introduction

Boost.Asio is a C++ library that provides a set of tools for asynchronous I/O, concurrency, and networking. It is a part of the Boost C++ Libraries collection, which is a well-established and widely-used open-source project. Boost.Asio aims to simplify the process of writing asynchronous networked applications while also offering excellent performance.

#### Features

1. **Asynchronous I/O**: Boost.Asio’s asynchronous model allows you to perform I/O operations without blocking the execution of the program. This feature is especially valuable for networking tasks, as it allows the application to handle multiple connections concurrently.
2. **Networking Protocols**: The library supports a wide range of networking protocols, including TCP, UDP, SSL/TLS, and serial ports. This enables developers to build various networking applications, from simple TCP servers to secure communication channels using SSL/TLS.
3. **Platform Independence**: Boost.Asio abstracts the platform-specific details, making it easier to write portable networking code that works across different operating systems without modification.
4. **Error Handling**: The library provides a robust error handling mechanism, which is essential for writing reliable networking applications. Errors are reported through exceptions or error codes, giving developers the flexibility to choose their preferred error-handling approach.
5. **Timers**: Boost.Asio includes timer functionality, allowing you to schedule tasks to be executed at specific intervals or after a delay. This feature is valuable for implementing time-sensitive operations.

