Sources:
https://business.linkedin.com/talent-solutions/resources/how-to-hire-guides/software-architect/interview-questions

## Fundamentals

### Key Software Architecture Principles

Solid architecture is built upon key principles:

- **Modularity:** Divide your system into manageable components for easier maintenance.
- **Separation of Concerns:** Isolate different aspects (e.g., UI, business logic) to enhance reusability and maintainability.
- **Abstraction:** Hide complex implementation details behind simple interfaces.
- **Encapsulation:** Restrict access to internal components, reducing unintended interactions.



### Design Patterns and Best Practices

Design patterns are reusable solutions to common design problems. Familiarize yourself with patterns like:

- **Singleton:** Ensures a class has only one instance and provides a global point of access.
- **Factory Method:** Defines an interface for creating objects but lets subclasses decide which class to instantiate.
- **Observer:** Establishes a dependency between objects so that when one changes state, others are notified and updated.



### SOLID Principles and Their Application

SOLID principles guide clean and maintainable design:

- **Single Responsibility Principle (SRP):** Each class/module should have only one reason to change.
- **Open/Closed Principle (OCP):** Software entities should be open for extension but closed for modification.
- **Liskov Substitution Principle (LSP):** Subtypes must be substitutable for their base types without altering program correctness.
- **Interface Segregation Principle (ISP):** Clients should not be forced to depend on interfaces they do not use.
- **Dependency Inversion Principle (DIP):** High-level modules should not depend on low-level modules; both should depend on abstractions.



### Architectural Styles

Different projects demand different architectural styles:

- **Monolithic:** Single codebase and database. Simple to develop but can hinder scalability and maintenance.
- **Microservices:** Divides the application into smaller, independent services that communicate. Offers scalability and isolation but introduces complexity.
- **Service-Oriented Architecture (SOA):** Services communicate over a network, promoting reusability and flexibility.



### Scalability and Performance Considerations

Designing for scalability and performance is a must:

- **Vertical Scaling:** Adding more resources (CPU, RAM) to a single machine.
- **Horizontal Scaling:** Adding more machines to distribute load.
- **Caching:** Storing frequently accessed data in memory for faster retrieval.
- **Load Balancing:** Distributing incoming traffic across multiple servers to prevent overload.



## System Design & Archiecture for a Software Architect

## System Design and Architecture for a Software Architect

Now that you've got a solid grasp of the foundational principles, let's take a deeper dive into system design and architecture concepts.

### High-Level Design Concepts

At the high-level, your architecture should outline the major components of your system and how they interact.

#### Architectural Components and Modules

Break your system into manageable modules:

- **Presentation Layer:** Handles user interaction and UI components.
- **Business Logic Layer:** Contains the core business rules and processes.
- **Data Access Layer:** Manages data storage and retrieval.

#### Data Storage and Management

Choose the right data storage solutions:

- **Relational Databases:** Suitable for structured data and complex queries.
- **NoSQL Databases:** Ideal for unstructured or semi-structured data and high scalability.
- **Caching:** Use caching mechanisms to reduce database load and improve performance.

#### Communication Protocols and APIs

Different components need to communicate effectively:

- **RESTful APIs:** Enable communication between services through HTTP methods.
- **Message Queues:** Facilitate asynchronous communication between distributed components.
- **WebSocket:** Provides real-time, full-duplex communication between the client and server.

**What best practices do you apply to designing software and frameworks?**

- Mention of key principles like simplicity and scalability
- Comprehension of best practices in programming
- Discussion of how to implement these principles in practice

**What is the CAP theorem and why is it important?**

- Familiarity with the theorem and its meaning
- Explanation of the implications of the theorem
- Discussion of how CAP forces necessary compromises

**Why would you want lower application layers not to be aware of higher ones?**

- Explanation of the importance of modularity in design
- Reference to greater comprehensibility and elegance
- Discussion of specific cases where this principle might apply



### Low-Level Design Concepts

Now, let's get into the nitty-gritty of the actual design and interactions of your software components.

#### Class Diagrams and UML

Visualize your software's structure and relationships:

- **Class Diagrams:** Illustrate classes, attributes, methods, and their associations.
- **Sequence Diagrams:** Show interactions between objects over time.
- **Communication Diagrams:** Focus on how objects collaborate to achieve specific tasks.

#### Designing for Extensibility and Maintainability

Plan for the future by designing for change:

- **Dependency Injection:** Promotes loose coupling and allows easier testing and swapping of components.
- **Interfaces and Abstractions:** Create contracts that classes implement, allowing for easier substitutions.
- **Open/Closed Principle:** Ensure new functionality can be added without modifying existing code.
