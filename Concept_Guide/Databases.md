## RDBMS and DBMS

### Basic Definitions:
  - **Databases**: an organized collection of related data where data is stored and organized to serve some specific purpose
  - **DBMS (Database Management System)**: a collection of applicaton programs which allow the user to organize, restore and retrieve information about data efficiency and as effectively as possible (e.g. MySql, Oracle, Sybase, etc)
  - **RDBMS (Relational Database Management System)**: based on a relational model of dtaa that is stored in database in separate table & related to the use of a common column. Data easily accessed using SQL (Structural Query Language)
### Data & Databases:
  - **Data Redundancy**: duplication of data, causing (1) wastage of storage space; and (2) destruction of the database integrity
  - **Types of Relationship in Database**:
    - **One-to-one**: A one-to-one relationship exists when each record in one table corresponds to exactly one record in another table.
    - **One-to-many**: A one-to-many relationship occurs when a single record in one table can be associated with one or multiple records in another table.
    - **Many-to-many**: In a many-to-many relationship, any record in one table can be related to one or more records in another table and vice versa.
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

- **Definition of Normalization & De-normalization**:
  - **<u>Normalization</u>**: removing redundant data from teh database by splitting the table in a well-defined manner in order to maintain data integrity
    - <u>First Normal Form (1NF)</u>: all entities of the table contain unique/atomic values
    - <u>Second Normal Form (2NF)</u>: in 1NF & non-key attrtbiute of the table is fully dependent on the primary key
    - <u>Third Normal Form (3NF)</u>: in 3NF & every non-key attribute of the able is not transitively dependent on the primary key 
    - <u>Boyce Code Normal Form (BCNF)</u>: higher version of 3NF & does jot have any multiple overlappijg candidate keys. 
  - **<u>De-normalization</u>**: adding up redundant data on the table to speed up the complex queries and thus achieve better performance

- **Normalization Forms**: Discusses various normalization forms (1NF, 2NF, 3NF, BCNF) and their significance in reducing redundancy and improving database design.
- **Conceptual Design**: Questions on E-R models, entity, entity types, and relationships focus on the conceptual design of databases.

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

## Database Security and Administration

- **Database Locks**: Different types of database locks and their roles in concurrency control.
- **Backup and Recovery**: Checkpoints and their importance in database recovery and maintenance.

## Miscellaneous

keys (candiate, primary, second, forigen )

- **Views, Indexes, and Joins**: Covers the creation and use of views, the difference between clustered and non-clustered indexes, and various join types in SQL queries.
- **Special Topics**: Addresses specific topics like data dictionary, triggers, stored procedures, B-Trees, and the distinction between DELETE, TRUNCATE, and DROP commands.
