## C++ Basic

#### Operator Overloading

You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

```cpp
#include <iostream>
using namespace std;

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }
      
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   return 0;
}
```



#### C vs C++

**C**								 	**C++**

Procedure-oriented 					object-oriented

X support data hiding	     		

a subset of C++

X function & operator overloading.     

X function cannot defined inside structure



#### Template

- **Definition**: A template is a blueprint or formula for creating a generic class or a function.

- **Usage**: Pass data types as parameters, making usage of classes & function easier

- **Example**: There is a single definition of each container, such as **vector**, but we can define many different kinds of vectors for example, **vector <int>** or **vector <string>**.

- **Two Types:**

  1. **Function Template**

  ```cpp
  #include <iostream>
  #include <string>
  
  using namespace std;
  
  template <typename T>
  inline T const& Max (T const& a, T const& b) { 
     return a < b ? b:a; 
  }
  
  int main () {
     int i = 39;
     int j = 20;
     cout << "Max(i, j): " << Max(i, j) << endl; 
  
     double f1 = 13.5; 
     double f2 = 20.7; 
     cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
  
     string s1 = "Hello"; 
     string s2 = "World"; 
     cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
  
     return 0;
  }
  ```

  2. Class Template

  ```cpp
  #include <iostream>
  #include <vector>
  #include <cstdlib>
  #include <string>
  #include <stdexcept>
  
  using namespace std;
  
  template <class T>
  class Stack { 
     private: 
        vector<T> elems;    // elements 
  
     public: 
        void push(T const&);  // push element 
        void pop();               // pop element 
        T top() const;            // return top element 
        
        bool empty() const {      // return true if empty.
           return elems.empty(); 
        } 
  }; 
  
  template <class T>
  void Stack<T>::push (T const& elem) { 
     // append copy of passed element 
     elems.push_back(elem);    
  } 
  
  template <class T>
  void Stack<T>::pop () { 
     if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
     }
     
     // remove last element 
     elems.pop_back();         
  } 
  
  template <class T>
  T Stack<T>::top () const { 
     if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
     }
     
     // return copy of last element 
     return elems.back();      
  } 
  
  int main() { 
     try {
        Stack<int>         intStack;  // stack of ints 
        Stack<string> stringStack;    // stack of strings 
  
        // manipulate int stack 
        intStack.push(7); 
        cout << intStack.top() <<endl; 
  
        // manipulate string stack 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
     } catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
     } 
  } 
  ```

  

#### NameSpace

A namespace is **a declarative region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it**

- Name Space Definition

  ```cpp
  #include <iostream>
  using namespace std;
  
  // first name space
  namespace first_space {
     void func() {
        cout << "Inside first_space" << endl;
     }
  }
  
  // second name space
  namespace second_space {
     void func() {
        cout << "Inside second_space" << endl;
     }
  }
  
  int main () {
     // Calls function from first name space.
     first_space::func();
     
     // Calls function from second name space.
     second_space::func(); 
  
     return 0;
  }
  ```

- Using Directive 

  - The ‘using’ directive can also be used to refer to a particular item within a namespace: ```using std::cout;```

  ```cpp
  #include <iostream>
  using namespace std;
  
  // first name space
  namespace first_space {
     void func() {
        cout << "Inside first_space" << endl;
     }
  }
  
  // second name space
  namespace second_space {
     void func() {
        cout << "Inside second_space" << endl;
     }
  }
  
  using namespace first_space;
  int main () {
     // This calls function from first name space.
     func();
     
     return 0;
  }
  ```

- Nested Namespace

  ```cpp
  #include <iostream>
  using namespace std;
  
  // first name space
  namespace first_space {
     void func() {
        cout << "Inside first_space" << endl;
     }
     
     // second name space
     namespace second_space {
        void func() {
           cout << "Inside second_space" << endl;
        }
     }
  }
  
  using namespace first_space::second_space;
  int main () {
     // This calls function from second name space.
     func();
     
     return 0;
  }
  ```



## Smart Pointers

#### Usage

a smart pointer is a **class template** that you declare on the stack, and initialize by using a raw pointer that points to a heap-allocated object.

```cpp
void UseRawPointer()
{
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars"); 

    // Use pSong...

    // Don't forget to delete!
    delete pSong;   
}

void UseSmartPointer()
{
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));

    // Use song2...
    wstring s = song2->duration_;
    //...

} // song2 is deleted automatically here.
```



## Pointers / Referneces

#### I. Reference

- **Def'n**: an alias name of the variable. 

- **Usage**: You would use it when you wanted to just pass the value around instead of copying the same variable into memory at a different location.

- Examples
  C++ inherited pointers from C, so I couldn't remove them without causing serious compatibility problems. **References are useful for several things, but the direct reason I introduced them in C++ was to support operator overloading.** For example:

  ```cpp
  void f1(const complex* x, const complex* y)    // without references
    {
        complex z = *x+*y;    // ugly
        // ...
    }
  
  void f2(const complex& x, const complex& y)    // with references
  {
        complex z = x+y;    // better
        // ...
  }
  ```



#### II. Reference Vs Pointers

**Basics:** 

1. **Assignment & Initalization**

   - A pointer can ve re-assigned
   - a reference cannot be re-bound, and must be bound at initizliation

2. **Identity**

   - A pointer has its own identity: a distinct, visible memory address, and a certain amount of space (measured with ```sizeof```. 
   - Using those operators on a reference returns a value corresponding to whatever the reference is bound to; the reference’s own address and size are invisible. 

   ```cpp
   int x = 0;
   int &r = x;
   int *p = &x;
   int *p2 = &r;
   
   assert(p == p2); // &x == &r
   assert(&p != &p2);
   ```

3. It is possible to create a pointer to a pointer, but not a pointer to a reference.

   ```cpp
   int **pp; // OK, pointer to pointer
   int &*pr; // ill-formed, pointer to reference
   ```

4. It is possible to create an array of pointers, but not an array of references.

   ```cpp
   int *ap[]; // OK, array of pointers
   int &ar[]; // ill-formed, array of references
   ```

5. You can have arbitrarily nested pointers to pointers offering extra levels of indirection. References only offer one level of indirection because references to references [collapse](https://en.cppreference.com/w/cpp/language/reference#Reference_collapsing).

6. A pointer can be assigned `nullptr`, whereas a reference must be bound to an existing object. If you try hard enough, you can bind a reference to `nullptr`, but this is [undefined](https://stackoverflow.com/questions/2397984/) and will not behave consistently.

   ```cpp
   /* the code below is undefined; your compiler may optimise it
    * differently, emit warnings, or outright refuse to compile it */
   
   int &r = *static_cast<int *>(nullptr);
   
   // prints "null" under GCC 10
   std::cout
       << (&r != nullptr
           ? "not null" : "null")
       << std::endl;
   
   bool f(int &r) { return &r != nullptr; }
   
   // prints "not null" under GCC 10
   std::cout
       << (f(*static_cast<int *>(nullptr))
           ? "not null" : "null")
       << std::endl;
   ```

7. Pointers are *[ContiguousIterators](https://en.cppreference.com/w/cpp/named_req/ContiguousIterator)* (of an array). You can use `++` to go to the next item that a pointer is pointing to, and `+ 4` to go to the 5th element.

8. A pointer needs to be dereferenced with `*` to access the object it points to, whereas a reference can be used directly. A pointer to a class/struct uses `->` to access its members whereas a reference uses a `.`.

9. Const references and rvalue references can be bound to temporaries (see [temporary materialization](https://en.cppreference.com/w/cpp/language/implicit_conversion#Temporary_materialization)). Pointers cannot (not without some indirection)

   ```cpp
   const int &x = int(12); // legal C++
   int *y = &int(12); // illegal to take the address of a temporary.
   ```

**Others**

##### What do you mean by call by value and call by reference?

In call by value method, we pass a copy of the parameter is passed to the functions. For these copied values a new memory is assigned and changes made to these values do not reflect the variable in the main function.

In call by reference method, we pass the address of the variable and the address is used to access the actual argument used in the function call. So changes made in the parameter alter the passing argument.

### III. Smart Pointers

1. ```unique_ptr```
   - Allows exactly one owner of the underlying pointer.
   - Can be moved to a new owner, but not copied or shared.
   - Replaces `auto_ptr`, which is deprecated. Compare to `boost::scoped_ptr`. `unique_ptr` is small and efficient; the size is one pointer and it supports rvalue references for fast insertion and retrieval from C++ Standard Library collections. 
2. ```shared_ptr```
   - Reference-counted smart pointer. Use when you want to assign one raw pointer to multiple owners
   - e.g. when you return a copy of a pointer from a container but want to keep the original. 
   - The raw pointer is not deleted until all `shared_ptr`owners have gone out of scope or have otherwise given up ownership. 
   - **The size is two pointers**; one for the object and one for the shared control block that contains the reference count. 
3. ```weak_ptr```
   - Special-case smart pointer for use in conjunction with `shared_ptr`. 
   - A `weak_ptr` provides access to an object that is owned by one or more `shared_ptr` instances, but does not participate in reference counting.
   - Use when you want to observe an object, but do not require it to remain alive. 
   - Required in some cases to break circular references between `shared_ptr`instances. 

## Functions

#### Inline Function

If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time. One of the important advantages of using an inline function is that it eliminates the function calling overhead of a traditional function.



## OOP IN C++

#### I. Class

- A Class is a user-defined data type that has data members and member functions.
- Data members are the data variables and member functions are the functions used to manipulate these variables together these data members and member functions define the properties and behavior of the objects in a Class.
- In the above example of class Car, the data member will be speed limit, mileage, etc and member functions can apply brakes, increase speed, etc.

#### II. Object

- An Object is an identifiable entity with some characteristics and behavior. An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

> SUMMARY
>
> ##### Class vs Object
>
> - **A class** is a user-defined data type that has data members and member functions. Data members are the data variables and member functions are the functions that are used to perform operations on these variables.
>
> - **An object** is an instance of a class. Since a class is a user-defined data type so an object can also be called a variable of that data type.
>
> ###### Class vs Struct
>
> - **Struct**
>
>   - Members of the structure are public by default.
>
>   - When deriving a struct from a class/struct, default access specifiers for base class/struct are public.
>
> - **Class**
>
>   - Members of the class are private by default.
>
>   - When deriving a class, default access specifiers are private.

#### III. Encapsulation

- **Definition**: In C++, encapsulation involves **combining similar data and functions into a single unit called a class**.
- Benifits: By encapsulating these functions and data, we protect that data from change. This concept is also known as data or information hiding. 

#### IV. Abstraction

- **Definition**: Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
- Ways:
  - **Abstraction using classes**: The class helps us to group data members and member functions using available access specifiers. A Class can decide which data member will be visible to the outside world and which is not.
  - **Abstraction in Header files**:  For example, consider the pow() method present in math.h header file. Whenever we need to calculate the power of a number, we simply call the function pow() present in the math.h header file and pass the numbers as arguments without knowing the underlying algorithm according to which the function is actually calculating the power of numbers.

#### V. Polymorphism

> SUMMARY
>
> **COMPILE-TIME**
>
> - Also known as static or early binding polymorphism.
> - Function calls are resolved by the compiler.
> - Provides less flexibility to programmers as everything is executed during compilation.
> - Implemented through function overloading and operator overloading.
> - Method overloading allows multiple methods/functions with the same name but different arguments or signatures and the same return types.
> - Faster execution rate as methods are called during compile time.
> - Less preferred for handling compound problems as methods and details are known only during compilation.
>
> **RUN-TIME**
>
> - Also known as dynamic or late binding polymorphism.
> - Function calls are not resolved by the compiler.
> - More flexible as everything is executed during run-time.
> - Implemented through virtual functions and function overriding.
> - Method overriding allows functions with the same name, arguments, and return type to accompany different classes of the same structure.
> - Comparatively slower execution rate as methods are called during run-time.
> - Known to be better for dealing with compound problems as methods and details emerge during run-time.

- **Definition**: In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 

- **Compile Time Polymorpism**

  - <u>Function Overloading</u>

    ```cpp
    class FuncOverload {
      public:
      void Func(int a) {}
      void Func(double a) {}
      void Func(int a, int b) {...}
    };
    
    int main() {
      FuncOverload obj;
      obj.Func(1);
      obj.Func(1.1);
      obj.Func(100, 200);
      return 0;
    }
    ```

  - <u>Operator Overloading</u>  (ad-hoc polymorphism)

    ```cpp
    #include <iostream>
    using namespace std;
    class Obj {
      private: 
      	int Var;
      public:
      	Obj(): myVar(8){};
      	void operator ++(){
          Var += 20;
        }
      	void display() {
          cout << "Var: " << Var << endl;
        }
    };
    
    int main(){
      Obj object;
      obj.display();
      return 0;
    }
    ```

    - *Oprator Overload Exception in C++*
      - *.  (dot operator)*
      - *::  (scope operator)*
      - *?: (ternary operator)*
      - *size of* 

- **Runtime Polymorphism**

  - <u>Virtual function</u>

    *Virtual functions are the member functions of the base class which are overridden in a derived class. When you make a call to such a function by using a pointer or reference to the base class, the virtual function is called and the derived class’s version of the function gets invoked.*

    - Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.
    - Virtual functions are always declared with a base class and overridden in a child class
    - Functions are declared with a **virtual** keyword in a base class.
    - The resolving of a function call is done at runtime.

    ```cpp
    // C++ program to illustrate
    // concept of Virtual Functions
    
    #include <iostream>
    using namespace std;
    
    class base {
    public:
    	virtual void print() { cout << "print base class\n"; }
    
    	void show() { cout << "show base class\n"; }
    };
    
    class derived : public base {
    public:
    	void print() { cout << "print derived class\n"; }
    
    	void show() { cout << "show derived class\n"; }
    };
    
    int main()
    {
    	base* bptr;
    	derived d;
    	bptr = &d;
    
    	// Virtual function, binded at runtime
    	bptr->print();
    
    	// Non-virtual function, binded at compile time
    	bptr->show();
    
    	return 0;
    }
    
    //------ output ------
    // print derived class
    // show base class
    ```

  - <u>Function Overriding</u>

    - When derived class and base class both contain a function with same name, same # of arguments, and same return type. 
    - Derived class inherits the member functions and data memebers from its base class
    - Override a certain functionality -> function overriding

    ```cpp
    #include <iostream>
    using namespace std;
    
    class bird {
      public:
      void display(){ cout << "base" << endl;}
    };
    
    class parrot:public bird {
      public:
      void display(){ cout << "derived" << endl;}
    };
    
    int main(){
      bird b;
      parrot p;
      b.display();
      p.display(;)
    }
    ```

#### VI. Inheritance

- **Definition**: The capability of a class to derive properties and characteristics from another class.
- **Features**:
  - <u>Sub Class</u>: The class that inherits properties from another class is called Sub class or Derived Class.
  - <u>Super Class</u>: The class whose properties are inherited by a sub-class is called Base Class or Superclass.
  - <u>Reusability:</u> Inheritance supports the concept of “reusability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.

#### VII. Dynamic Binding

- **Definition**: In dynamic binding, the code to be executed in response to the function call is decided at runtime. C++ has [virtual functions](https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/) to support this. Because dynamic binding is flexible, it avoids the drawbacks of static binding, which connected the function call and definition at build time.

#### VIII. Functions

- **Static member Function**

  - static class variable, space for it is allocated for the lifetime of the program. No matter how many objects of that class have been created, there is only one copy of the static member. So same static member can be accessed by all the objects of that class.

  - static member function can be called even if no objects of the class exist and the static function are accessed using only the class name and the scope resolution operator ::

- **Friend Function**

  - Friend Class:

    - **Definition**: A **friend class** can access private and protected members of other classes in which it is declared as a friend.

    - **Example**: a LinkedList class may be allowed to access private members of Node.

      ```cpp
      	// C++ Program to demonstrate the
      // functioning of a friend class
      #include <iostream>
      using namespace std;
       
      class GFG {
      private:
          int private_variable;
       
      protected:
          int protected_variable;
       
      public:
          GFG()
          {
              private_variable = 10;
              protected_variable = 99;
          }
       
          // friend class declaration
          friend class F;
      };
       
      // Here, class F is declared as a
      // friend inside class GFG. Therefore,
      // F is a friend of class GFG. Class F
      // can access the private members of
      // class GFG.
      class F {
      public:
          void display(GFG& t)
          {
              cout << "The value of Private Variable = "
                   << t.private_variable << endl;
              cout << "The value of Protected Variable = "
                   << t.protected_variable;
          }
      };
       
      // Driver code
      int main()
      {
          GFG g;
          F fri;
          fri.display(g);
          return 0;
      }
      ```

  - **Friend Function**

    - **Definition**: Like a friend class, a friend function can be granted special access to private and protected members of a class in C++. They are the non-member functions that can access and manipulate the private and protected members of the class for they are declared as friends.

    - Examples:

      1. Global Function as  Friend Fuction

         ```cpp
         // C++ program to create a global function as a friend
         // function of some class
         #include <iostream>
         using namespace std;
          
         class base {
         private:
             int private_variable;
          
         protected:
             int protected_variable;
          
         public:
             base()
             {
                 private_variable = 10;
                 protected_variable = 99;
             }
              
               // friend function declaration
             friend void friendFunction(base& obj);
         };
          
          
         // friend function definition
         void friendFunction(base& obj)
         {
             cout << "Private Variable: " << obj.private_variable
                  << endl;
             cout << "Protected Variable: " << obj.protected_variable;
         }
          
         // driver code
         int main()
         {
             base object1;
             friendFunction(object1);
          
             return 0;
         }
         ```

      2. Member Function of Another Class as Friend Function

         ```cpp
         // C++ program to create a member function of another class
         // as a friend function
         #include <iostream>
         using namespace std;
          
         class base; // forward definition needed
         // another class in which function is declared
         class anotherClass {
         public:
             void memberFunction(base& obj);
         };
          
         // base class for which friend is declared
         class base {
         private:
             int private_variable;
          
         protected:
             int protected_variable;
          
         public:
             base()
             {
                 private_variable = 10;
                 protected_variable = 99;
             }
          
             // friend function declaration
             friend void anotherClass::memberFunction(base&);
         };
          
         // friend function definition
         void anotherClass::memberFunction(base& obj)
         {
             cout << "Private Variable: " << obj.private_variable
                  << endl;
             cout << "Protected Variable: " << obj.protected_variable;
         }
          
         // driver code
         int main()
         {
             base object1;
             anotherClass object2;
             object2.memberFunction(object1);
          
             return 0;
         }
         ```

      > SUMMARY
      >
      > - A friend function is a special function in C++ that in spite of not being a member function of a class has the privilege to **access** the **private and protected data** of a class.
      > - A friend function is a non-member function or ordinary function of a class, which is declared as a friend using the keyword “**friend**” inside the class. By declaring a function as a friend, all the access permissions are given to the function.
      > - The keyword “friend” is placed only in the function declaration of the friend function and **not** in the **function definition or call.**
      > - A friend function is called like an ordinary function. It cannot be called using the object name and dot operator. However, it may accept the object as an argument whose value it wants to access.
      > - A friend function can be declared in any section of the class i.e. public or private or protected.

#### VIIII. Access Specifiers 

- **Public**: all data members & meber functions are accessible outside the class

- **Protected**: All data memebers & emmebr functions are accessible inside the class and to the derived class

- **Private**: All data members && member functinos are not accessible outside the class



#### X. Constructors vs Destrutcors

- Constructors 
- Copy Constructors
- Destructors
- Shallow Copy vs 

> SUMMARY
>
> #### C++ Overriding
>
> - In C++, [overriding](https://www.simplilearn.com/tutorials/java-tutorial/overriding-in-java) is the process of creating a new version of a method that already exists in a parent class. This new version of the method can be used to modify or extend the functionality of the parent class.
>
> #### C++ Overloading
>
> - In C++, [overloading](https://www.simplilearn.com/what-is-function-overloading-in-cpp-article) is the process of creating multiple versions of a method that have the same name but different parameters. This allows us to use the same method for different types of parameters.
>
> #### C++ Virtual Function
>
> - A virtual function is a member function of base class which can be redefined by derived class. 
> - A pure virtual function is a member function of base class whose only declaration is provided in base class and should be defined in derived class otherwise derived class also becomes abstract.

*Referneces:*

https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170

*C++ Reference:* https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable/57492#57492?newreg=e9f87ec373e2493aae456ce7e63f0b5e



