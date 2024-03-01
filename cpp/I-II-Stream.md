

### I. Purpose of Streams

- **A stream** is an abstraction for input/output (a source/input or destination/output of characters of indefinite length)
- **Types inserted into stream objects**:
  - any primitive type can be inserted into a stream
  - other types miust be explicityly tell 
- **Implementation**
  - Input from user is in text form (string)
  - Output to user is in text form (string)

### II. Output Streams

- **output streams**: can only recieve data

  - All output streams are of type ```std::ostream```
    -  ```std::cout```  an example of output stream
    - ```std::ofstream``` send the data to a file

  - <u>Sending data:</u>
    - sending data using stream insertiong operation: ```<<```
      - Insertion converts data to string and sends to stream

- **Examples**

  ```cpp
  using std::cout;
  using std::endl;
  using std::string;
  
  void writeToStream(std::ostream& anyOutputStream, int favouriteNumber) {
      anyOutputStream << "Writing to stream: "
          << favouriteNumber << endl;
  }
  
  int main() {
      // Write an int to the user's console.
      int favouriteNumber = 1729;
      cout << "Result when writing an int directly to cout: " << favouriteNumber << endl;
  
      // Write an int to a file.
      std::ofstream outputFile("out.txt");
      outputFile << "Result when writing an int to file: " << favouriteNumber << endl;
  
      // Write method to take any ostream
      std::ofstream fileOut("out.txt");
  
      writeToStream(cout, favouriteNumber);
      writeToStream(fileOut, favouriteNumber + 1);
      return 0;
  }
  ```

  1. **Output to Console (stdout)**:
     - "Result when writing an int directly to cout: 1729"
     - "Writing to stream: 1729"
  2. **Output to File ("out.txt")**:
     - "Writing to stream: 1730"

### III. Input Streams

- **Can only give you data**: Extraction gets data from stream as a string and converts it into the appropriate type.

  - Pull out data using stream extraction operator: ```>>```

- **all input streams are of type ```std::istream```**

  - ```std::cin```  stream is an exeample of an inpit stream
  - read data from a file using a ```std::ifstream```

- **Data Extraction from Stream:**

  - <u>Interger Extraction:</u>

    - Extracting an integer will read as many characters as possible from the stream till the while space

  - <u>String Extraction:</u>

    - Read a single string:  using ```>>``` will read a single word

    - To read a whole line, use

      ```cpp
          getline(istream& stream, string& line);
      ```

  - <u>Other methods for using streams</u>

    ```cpp
    input.get(ch); // reads one char at a time
    input.close(); // closes stream
    input.clear(); // resets any fail bits
    input.open("filename"); // open stream on file
    input.seekg(0); // rewinds stream to start
    ```

    

### IV. System

-  **Buffers**

  - The internal sequence of data stored in a stream is called a buffer.:

  - Istreams use them to store data we haven’t used yet

  - Ostreams use them to store data they haven’t passed along yet.

    - If we want to force the contents of the buffer to their destination, we can flush the stream:

      - ```cpp
        stream.flush(ch); // use by default
        stream << std::flush; // use if you are printing
        stream << std::endl; // use if you want a newline
        // This is equivalent to stream << "\n" << std::flush;
        ```

  - Not all streams are buffered (std::cerr is an example).

- **Stream bits** (Streams have four bits to give us information about their state):

  - <u>Types</u>
    - Good bit: No errors, the stream is good to go
    - EOF bit: End-of-file was reached during a previous operation
    - Fail Bit: Logical error on a previous operation
    - Bad bit: Likely unrecoverable error on previous operation

  - <u>Check</u>:

    ```cpp
    while(true) { stream >> temp;
        if(!stream) break; // checks fail or bad bit
        do_something(temp);
    }
    
    // simplified version
    while(stream >> temp) {
        do_something(temp);
    }
    
    // getline
    while(getline(stream, temp)) {
      	do_something(temp);
    }
    ```

    

- **Operators** (The << and >> operators are functions!)

  ```cpp
  std::cout << "hello";
  operator<<(std::cout, "hello");
  ```

  - The << and >> operators return the stream passed as their left argument.

    ```c pp
    (((std::cout << "hello") << 23) << "world");
    ```



- **String Manipulator** (Using these stream manipulators, you can control various aspects of input/output operations in C++, including formatting, precision, and padding)

  - <u>Common Stream Manipulators</u> 

    - **endl**: Inserts a newline character and flushes the stream. 
    - **ws**: Skips all whitespace until it finds another character. 
    - **boolalpha**: Prints "true" and "false" for boolean values instead of numeric representations. 

  - <u>Numeric Stream Manipulators</u> 

    ```cpp
    std::cout << std::hex << 10; // prints a
    std::cout << std::oct << 10; // prints 12
    std::cout << std::dec << 10; // prints 10
    ```

    - **hex**: Prints numbers in hex
    - **setprecision**: Adjusts the precision numbers print with. 

  - <u>Padding Stream Manipulators</u> 

    ```cpp
    #include <iomanip>
    std::cout << "["  << std::left << std::setfill('-')
              << std::setw(10) << "Hi" << "]"  << std::endl;
    // output [Hi----------]
    ```

    - **setw**: Pads output
    - **setfill**: Fills padding with characters

  

### V. stringstream

- Motivation: want to treat a string like a stream

  ```cpp
  #include <sstream>
  Std::string line = "137 2.718 Hello";
  std::stringstream stream(line);
  
  int myInt;
  double myDouble;
  std::string myString;
  stream >> myInt >> myDouble >> myString;
  
  std::cout << myInt <<  std::endl;
  std::cout << myDouble <<  std::endl;
  std::cout << myString <<  std::endl;
  ```

  - Converting between data types
  - Tokenizing a string