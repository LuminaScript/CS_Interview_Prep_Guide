### 



### 

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



#### Template in C++

- Definition: A template is a blueprint or formula for creating a generic class or a function.

- Usage: Pass data types as parameters, making usage of classes & function easier

- Example: There is a single definition of each container, such as **vector**, but we can define many different kinds of vectors for example, **vector <int>** or **vector <string>**.

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

### 

### Kinds of smart pointers

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

### OOP in C++





https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170



