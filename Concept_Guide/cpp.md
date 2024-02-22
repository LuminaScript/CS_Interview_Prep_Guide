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

#### Friend Function

#### Inline Function

If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time. One of the important advantages of using an inline function is that it eliminates the function calling overhead of a traditional function.



## OOP IN C++

#### I. Class vs Object

- **A class** is a user-defined data type that has data members and member functions. Data members are the data variables and member functions are the functions that are used to perform operations on these variables.

- **An object** is an instance of a class. Since a class is a user-defined data type so an object can also be called a variable of that data type.

#### II. Class vs Struct

- **Struct**

  - Members of the structure are public by default.

  - When deriving a struct from a class/struct, default access specifiers for base class/struct are public.

- **Class**

  - Members of the class are private by default.

  - When deriving a class, default access specifiers are private.

#### III. Constructor vs Destructor

#### 

#### IV. Static member Function

- static class variable, space for it is allocated for the lifetime of the program. No matter how many objects of that class have been created, there is only one copy of the static member. So same static member can be accessed by all the objects of that class.

- static member function can be called even if no objects of the class exist and the static function are accessed using only the class name and the scope resolution operator ::



#### V. C++ Inheritance / Abstraction 

#### C++ Inheritance

- Using inheritance, we can create a parent class containing the common properties and methods of all its children's classes. The child classes can then inherit the properties and methods of the parent class and add their unique properties and methods. 

#### C++ Abstraction

#### C++ Overriding

- In C++, [overriding](https://www.simplilearn.com/tutorials/java-tutorial/overriding-in-java) is the process of creating a new version of a method that already exists in a parent class. This new version of the method can be used to modify or extend the functionality of the parent class.

#### C++ Overloading

- In C++, [overloading](https://www.simplilearn.com/what-is-function-overloading-in-cpp-article) is the process of creating multiple versions of a method that have the same name but different parameters. This allows us to use the same method for different types of parameters.

#### C++ Virtual Function

- A virtual function is a member function of base class which can be redefined by derived class. 
- A pure virtual function is a member function of base class whose only declaration is provided in base class and should be defined in derived class otherwise derived class also becomes abstract.

#### VI. C++ Polmorphism

1. **Compile Time Polymorpism**

   - Function Overloading

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

     

   - Operator Overloading (ad-hoc polymorphism)

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

     - Oprator Overload Exception in C++
       - .  (dot operator)
       - ::  (scope operator)
       - ?: (ternary operator)
       - size of 

2. **Runtime Polymorphism**

   - Virtual function

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

     

   - Function Overriding

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

### Compile-Time vs. Run-Time Polymorphism in C++

**COMPILE-TIME**

- Also known as static or early binding polymorphism.
- Function calls are resolved by the compiler.
- Provides less flexibility to programmers as everything is executed during compilation.
- Implemented through function overloading and operator overloading.
- Method overloading allows multiple methods/functions with the same name but different arguments or signatures and the same return types.
- Faster execution rate as methods are called during compile time.
- Less preferred for handling compound problems as methods and details are known only during compilation.

**RUN-TIME**

- Also known as dynamic or late binding polymorphism.
- Function calls are not resolved by the compiler.
- More flexible as everything is executed during run-time.
- Implemented through virtual functions and function overriding.
- Method overriding allows functions with the same name, arguments, and return type to accompany different classes of the same structure.
- Comparatively slower execution rate as methods are called during run-time.
- Known to be better for dealing with compound problems as methods and details emerge during run-time.



#### VII. Access Specifiers 

- **Def'n**

- **Examples**

  - Public: all data members & meber functions are accessible outside the class

  - Protected: All data memebers & emmebr functions are accessible inside the class and to the derived class

  - Private: All data members && member functinos are not accessible outside the class



*Referneces:*

https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170

*C++ Reference:* https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable/57492#57492?newreg=e9f87ec373e2493aae456ce7e63f0b5e



