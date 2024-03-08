## RDBMS and DBMS

<<<<<<< Updated upstream
### Basic Definitions:
  - **Databases**: an organized collection of related data where data is stored and organized to serve some specific purpose
  - **DBMS (Database Management System)**: a collection of applicaton programs which allow the user to organize, restore and retrieve information about data efficiency and as effectively as possible (e.g. MySql, Oracle, Sybase, etc)
  - **RDBMS (Relational Database Management System)**: based on a relational model of dtaa that is stored in database in separate table & related to the use of a common column. Data easily accessed using SQL (Structural Query Language)
### Data & Databases:
  - **Data Redundancy**: <u>duplication of data</u>, causing (1) wastage of storage space; and (2) destruction of the database integrity
  - **Types of Relationship in Database**:
=======
- **Basic Definitions:** 
  - <u>Databases</u>: an organized collection of related data where data is stored and organized to serve some specific purpose
  - <u>DBMS (Database Management System)</u>: a collection of applicaton programs which allow the user to organize, restore and retrieve information about data efficiency and as effectively as possible (e.g. MySql, Oracle, Sybase, etc)
  - <u>RDBMS (Relational Database Management System)</u>: based on a relational model of dtaa that is stored in database in separate table & related to the use of a common column. Data easily accessed using SQL (Structural Query Language)
- **Data & Databases**:
  - <u>Data Redundancy</u>: duplication of data, causing (1) wastage of storage space; and (2) destruction of the database integrity
  - <u>Types of Relationship in Database</u>:
>>>>>>> Stashed changes
    - **One-to-one**: A one-to-one relationship exists when each record in one table corresponds to exactly one record in another table.
    - **One-to-many**: A one-to-many relationship occurs when a single record in one table can be associated with one or multiple records in another table.
    - **Many-to-many**: In a many-to-many relationship, any record in one table can be related to one or more records in another table and <u>vice versa</u>.
- **Terminologies**:
  - **Record**: Record is a collection of values or fields of a specific entity. **For Example,** An employee, Salary account, etc.
  - **Field**: A field refers to an area within a record that is reserved for specific data. 
    - **For Example,** Employee ID.
  - **Table**: Table is the collection of records of specific types. 
    - **For Example,** the Employee table is a collection of records related to all the employees.



## SQL (Structured Query Language)

> - **SQL Basics and Commands**: Covers SQL's role, DDL (Data Definition Language), DML (Data Manipulation Language), and DCL (Data Control Language) commands, including their definitions and purposes.
> - **Query Optimization**: Questions related to index hunting and improving query performance delve into the efficiency of data retrieval and manipulation.

- **Definition**: SQL is an standard programming language that is designed for storing & managing the data in RDBMS using all kinds of data operations. 
- **SQL Statements:**
  - <u>DDL (Data Definition Language)</u>: define the structure that holds the data & auto-committed + changes on DB saved permanently
    - Commands
      - CREATE to create a new table or database.
      - ALTER for alteration.
      - TRUNCATE to delete data from the table.
      - DROP to drop a table.
      - RENAME to rename a table.
  - <u>DML (Data Manipulation Language)</u>: manipulates data of the database & not auto-committed + can be rolled back
    - Commands: 
      - INSERT to insert a new row.
      - UPDATE to update an existing row.
      - DELETE to delete a row.
      - MERGE for merging two rows or two tables
    - **DML Compiler**: DML in query langauge -> Low Level Instruction (that Query Evaulation Enginene understands
  - <u>DCL (Data Control Language)</u>: control the visibility of the data in the DB (e.g. revoke access permission for using data in the database)
    - Commands:
      - COMMIT to permanently save.
      - ROLLBACK to undo the change.
      - SAVEPOINT to save temporarily.
    - **DDL Interpreter**: (1) interprets the DDL statements (2) records the generated statemenets in the table containing metadata

## Database Design and Normalization

> - **Normalization Forms**: Discusses various normalization forms (1NF, 2NF, 3NF, BCNF) and their significance in reducing redundancy and improving database design.
> - **Conceptual Design**: Questions on E-R models, entity, entity types, and relationships focus on the conceptual design of databases.

- **Definition of Normalization & De-normalization**:
  - **<u>Normalization</u>**: removing redundant data from teh database by splitting the table in a well-defined manner in order to maintain data integrity
    - <u>First Normal Form (1NF)</u>: all entities of the table contain unique/atomic values
    - <u>Second Normal Form (2NF)</u>: in 1NF & non-key attrtbiute of the table is fully dependent on the primary key
    - <u>Third Normal Form (3NF)</u>: in 3NF & every non-key attribute of the able is not transitively dependent on the primary key 
    - <u>Boyce Code Normal Form (BCNF)</u>: higher version of 3NF & does jot have any multiple overlappijg candidate keys. 
  - **<u>De-normalization</u>**: adding up redundant data on the table to speed up the complex queries and thus achieve better performance

- **Conceptual Design**: 

  - Functional Dependency:

    - Definition: A relation is said to be in functional dependency when one attribute uniquely defines another attribute.

      - T1[X]=T2[X] and T1[Y]=T2[Y]
      - the value of component X uniquely define the value of component Y.
      - X->Y means Y is functionally dependent on X.

    - When is functional dependency said to be fully dunctional dependent

      - To fulfill the criteria of fully functional dependency, the relation must meet the requirement of functional dependency.

        A functional dependency ‘A’ and ‘B’ are said to be fully functional dependent when removal of any attribute say ‘X’ from ‘A’ means the dependency does not hold anymore.

  - **E-R model**: an Entity-Relationship model which defines the conceptual view of the database. shows the real-world entities and their association/relations. Entities here represent the set of attributes in the database.

  - **Def'n**:

    - **Entity** can be anything, be it a place, class or object which has an independent existence in the real world.
    - **Entity Type** represents a set of entities that have similar attributes.
    - **Entity Set** in the database represents a collection of entities having a particular entity type.
      - <u>Weak Entity Set:</u> Weak Entity set is the one whose primary key comprises its partial key as well as the primary key of its parent entity. This is the case because the entity set may not have sufficient attributes to form a primary key.

  - **Attribute vs Relation**:

    - **Attribute** is described as the properties or characteristics of an entity. **For Example**, Employee ID, Employee Name, Age, etc., can be attributes of the entity Employee.
    - **Relation** is a two-dimensional table containing a number of rows and columns where every row represents a record of the relation. Here, rows are also known as ‘Tuples’ and columns are known as ‘Attributes’.

  - **VDL vs SDL**: 

    - **VDL** is View Definition Language which represents user views and their mapping to the conceptual schema.
    - **SDL** is Storage Definition Language which specifies the mapping between two schemas.

  - Cursor:

    - **Implicit cursors** are declared automatically when DML statements like INSERT, UPDATE, DELETE is executed.
    - **Explicit cursors** have to be declared when SELECT statements that are returning more than one row are executed.

  - Database Transaction: Sequence of operation performed which changes the consistent state of the database to another is known as the database transaction. After the completion of the transaction, either the successful completion is reflected in the system or the transaction fails and no change is reflected.

  - Database Lock: Database lock basically signifies the transaction about the current status of the data item i.e. whether that data is being used by other transactions or not at the present point of time. There are two types of Database lock: **Shared Lock** and **Exclusive Lock.**

  - Data Warehousing:  The storage as well as access to data, that is being derived from the transactions and other sources, from a central location in order to perform the analysis is called Data Warehousing.


## Data Integrity and Transactions

> - **Atomicity, Consistency, Isolation, Durability (ACID) Properties**: Includes atomicity and its significance in transaction management.
> - **Database Transactions**: Examines the definition, importance, and characteristics of database transactions.

- **Data Independence**: ability to modify the schema definition in one level in such a way thatt it does not affect the shcema definition in the next higher level. 

  - <u>**Hirechies**</u>: physical -> conceptual -> view

    - <u>Physical Data Independence</u>: It modifies the schema at the physical level without affecting the schema at the conceptual level.
    - <u>Logical Data Independence</u>: It modifies the schema at the conceptual level without affecting or causing changes in the schema at the view level.

  - **<u>View vs Data Independece</u>**: View is a virtual table that does not have its data on its own rather the data is defined from one or more underlying base tables.

    Views account for logical data independence as the growth and restructuring of base tables are not reflected in views.

    - <u>Advantages</u>
      - As there is no physical location where the data in the view is stored, it generates output without wasting resources.
      - Data access is restricted as it does not allow commands like insertion, updation, and deletion.
    - <u>Disadvantages</u>:
      - The view becomes irrelevant if we drop a table related to that view.
      - Much memory space is occupied when the view is created for large tables.

## Advanced Database Concepts

- **Data Warehousing**: Explores the concept, advantages, and importance of data warehousing in analytical processing and decision-making.

- **Database Partitioning**: Discusses the process and significance of database partitioning for performance improvement and manageability.

- **Join**: the process of deriving the relationship between different tables by combining columns from one or more tables having common values in each. When a table joins with itself, it is known as Self Join.

- **Index hunting**: the process of boosting the collection of indexes which helps in improving the query performance as well as the speed of the database.

  - **improve query performance using Index hunting?**

    - Using a query optimizer to coordinate queries with the workload.

    - Observing the performance and effect of index and query distribution.

- ‘**Cluster**’ vs ‘**Non-cluste**r’ index.

  - Clustered index alters the table and re-order the way in which the records are stored in the table. Data retrieval is made faster by using the clustered index.

  - A Non-clustered index does alter the records that are stored in the table but creates a completely different object within the table.

- **disadvantages of a Query**

  - Indexes are not present.
  - Stored procedures are excessively compiled.
  - Difficulty in interfacing.

- **Fragmentation**

  a feature that controls the logical data units, also known as fragments that are stored at different sites of a distributed database system.

## Database Security and Administration

- **Database Locks**: Different types of database locks and their roles in concurrency control.
- **Backup and Recovery**: Checkpoints and their importance in database recovery and maintenance.

<<<<<<< Updated upstream
=======


**Q #31) What do you understand by Join?**

**Answer:** Join is the process of deriving the relationship between different tables by combining columns from one or more tables having common values in each. When a table joins with itself, it is known as Self Join.

**Q #32) What do you understand by Index hunting?**

**Answer:** Index hunting is the process of boosting the collection of indexes which helps in improving the query performance as well as the speed of the database.

**Q #33) How to improve query performance using Index hunting?**

**Answer: Index hunting help in improving query performance by:**

- Using a query optimizer to coordinate queries with the workload.
- Observing the performance and effect of index and query distribution.

**Q #34) Differentiate between ‘Cluster’ and ‘Non-cluster’ index.**

**Answer:** Clustered index alters the table and re-order the way in which the records are stored in the table. Data retrieval is made faster by using the clustered index.

A Non-clustered index does alter the records that are stored in the table but creates a completely different object within the table.

**Q #35) What are the disadvantages of a Query?**

**Answer: Disadvantages of a Query are:**

- Indexes are not present.
- Stored procedures are excessively compiled.
- Difficulty in interfacing.

**Q #36) What do you understand by Fragmentation?**

**Answer:** Fragmentation is a feature that controls the logical data units, also known as fragments that are stored at different sites of a distributed database system.
>>>>>>> Stashed changes
