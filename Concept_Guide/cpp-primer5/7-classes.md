### 7.1 Define Abstract Data Type

- **Member function**:

  - Functions defined in the class are implicitly ```inline```

  - Every members function must be declared inside its class, but can defined outside. 

  - ```this```:

    - Every member function access the object on which they is called by ```this``` (constant pointer, cannot changevtye address that ```this``` holds)

    - nonconst object: By default, the type of ```this``` is a const pointer to the nonconst version of the class type. 

    - const object:  A const following the parameter list indicates that this is a pointer to const. Member functions that use const in this way are **const** **member functions**.

      ```cpp
      std::string Sales_data::isbn(const Sales_data *const this) { return this->isbn; }
      ```

  - **Class Scope** 

    - <u>Define a member function outside the class</u>: The function name, **Sales_data::avg_price**, uses the **scope operator**

    - <u>Define a Function o Return ```this``` Object:</u>

      ```cpp
      Sales_data& Sales_data::combine(const Sales_data &rhs)
      {
      	units_sold += rhs.units_sold; 
        revenue += rhs.revenue; 
        return *this;
      }
      ```

    - <u>Defining Nonmember Class-Related Functions</u>

      ```cpp
      istream &read(istream &is, Sales_data &item)
      {
      	double price = 0;
      	is >> item.bookNo >> item.units_sold >> price; 
        item.revenue = price * item.units_sold;
        return is;
      } 
      
      ostream &print(ostream &os, const Sales_data &item)
      {
        os << item.revenue << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
        return os;
      }
      ```

      1. both read and write take a **reference** to their respective IO class types. The IO classes are types that cannot be copied, so we may only pass them by reference 
      2. reading or writing to a stream changes that stream, so both functions take ordinary references, not references to **const**.

- **Constructors**

  1. **The  Default Constructor**

     - <u>Default constructors</u>: Classes control default initialization by defining a special constructor. The default constructor is one that takes no arguments.

       ```cpp
       Sales_data() = default;
       ```

       

     - <u>Synthesized default constructor</u>: compiler-generatored constructor:

       - If there is an in-class initializer, use it to initialize the member.
       - Otherwise, default-initialize the member.

     2. Constructor Initializer List

        ```cpp
        Sales_data(const std::string &s): bookNo(s) { }
        Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
        ```

        - Constructor initialzier list:  ```bookNo(s), units_sold(n), revenue(p*n)```

     3. Constructor outside function body

        ```cpp
        Sales_data::Sales_data(std::istream &is)
        {
        	read(is, *this); // read will read a transaction from is into this object 
        }
        ```

- **Copy, Assignment, and Destruction**
  - Objects are copied in several contexts, such as when we initialize a variable or when we pass or return an object by value 
  - Objects are assigned when we use the assignment operator
  - Objects are destroyed when they cease to exist, such as when a local object is destroyed on exit from the block in which it was created

### 7.2 Access Control and Encapsulation

- **Use access specifiers to enforce <u>encapsulation</u>:** 
  - **public**: Members defined after a **public** specifier are accessible to all parts of the program. The public members define the interface to the class.
  - **Private**: Members defined after a **private** specifier are accessible to the member functions of the class but are not accessible to code that uses the class.
- **```class``` vs ```struct``` keywords**
  - difference in <u>default access level</u>:
    -  If we use the struct keyword, the members defined before the first access specifier are public;
    - if we use class, then the members are private.
  - Paradigm
    - when we define a class intending for all of its members to be public, we use struct. 
    - If we intend to have private members, then we use class.
- **Friends**
  - A class can allow another class or function to access its nonpublic members by making that class or function a **friend**. 
  - A friend declaration only specifies access. It is not a general declaration of the function. If we want users of the class to be able to call a friend function, then we must also declare the function separately from the friend declaration.

### 7.3 Additional Class Features

- **Class Members** **Revisited**

  - <u>Defining a Type Member</u>

    ```cpp
    class Screen { 
    public:
    	typedef std::string::size_type pos; 
    private:
      pos cursor = 0;
    	pos height = 0, width = 0; 
      std::string contents;
    };
    ```

    1. Type member <=> Type alias ```using pos = std::string::size_type;```

    2. Unlike ordinary members, members that define types must appear before they are used. As a result, type members usually appear at the beginning of the class.

  - <u>Making members inline</u> 

    - We can explicitly declare a member function as inline as part of its declaration inside the class body. 
    - Alternatively, we can specify inline on the function definition that appears outside the class body:

  - <u>Overloading Member Functions</u>

  - <u>Mutable Data Members</u>

    ```cpp
    class Screen { 
    public:
      void some_member() const; 
    private:
      mutable size_t access_ctr; 
    };
    
    void Screen::some_member() const
    {
    	++access_ctr; 
    }
    ```

    - A **mutable** **data member** is never const
    - Any  member function (including const function) may change a mutable member

  - <u>Initializers for Data Members of Class Type</u>

    ```cpp
    class Window_mgr { 
    private:
    	std::vector<Screen> screens{Screen(24, 80, ' ')};
    };
    ```

    *When we initialize a member of class type, we are supplying arguments to a constructor of that member’s type. In this case, we list initialize our vector member (§ 3.3.1, p. 98) with a single element initializer. That initializer contains a Screen value that is passed to the vector<Screen> constructor to create a one-element vector. That value is created by the Screen constructor that takes two size parameters and a character to create a blank screen of the given size.*

- **Functions That Return** ```*this```

  - <u>Reference return type:</u>

    - <u>reference return type</u>: Functions that return a reference are lvalues, which means that they return the object itself, not a copy of the object. 

    ```cpp
    inline Screen &Screen::set(pos r, pos col, char ch)
    { 
      contents[r*width + col] = ch; 
      return *this;
    }
    ```

    - <u>non-reference return type</u>: then the return value of function would be a copy of ```*this``` 

  - <u>Returning ```*this``` from a const Member Function:</u>

    - A const member function that returns  *```this``` as a reference should have a return type that is a reference to const.

  - <u>Overloading Based on ```const```</u>

  

  

- **Class Types**

  - <u>Basics</u>:

    - Every class defines a unique type. Two different classes define two different types even if they define the same members.
    - We can refer to a class type directly, by using the class name as a type name. Alternatively, we can use the class name following the keyword class or struct:

  - <u>Class Declarations</u>

    - Forward Declaration ``class Screen;``  (Imcommplete Type)

      - Imcommplete Type: After a declaration and before a definition is seen, the type Screen 
      - Limited Usage: We can define pointers or references to such types, and we can declare (but not define) functions that use an incomplete type as a parameter or return type.

      - A class must be defined—not just declared—before we can write code that creates objects of that type. 

      - A class cannot contain members of its own type until it is fully defined, but it can include pointers or references to its own type once its name is declared.

        ```cpp
        class Link_screen { 
          Screen window;
          Link_screen *next; 
          Link_screen *prev;
        };
        ```

        

### 7.4 Class Scope

### 7.5 Constructors Revisited

### 7.6 Static Class Member 

