# Postfix (RPN) Calculator
A Reverse-Polish Notation (RPN) calculator written in C++ supporting integers and floating-point values.

## How to Use
### Installation
1. Download the files:

   - List.h
   - Stack.h
   - calc.cpp

2. Compile using
```bash
$ g++ -Wall -Werror -pedantic --std=c++11 -O1 calc.cpp -o calc.exe
```
3. To run the calculator interactively use
```bash 
./calc.exe
```


### Supported Operators


### Examples
An RPN calculator is one where the operators appear after after their respective operands, not inbetween them.

To compute the expression ((2-3)*4)/(-6), enter: 
  ```bash 
  2 3 - 4 * 6 n /
  ```

To compute the expression 



## Documentation

### List Class
```List.h``` implements a class template of a doubly-linked list which supports an iterator that can search, insert, or delete at any position in the list. 

### Stack Class
```Stack.h``` implements a class template of the stack, making use of the List class to push and pop operations from one end.

### The Calculator
```calc.cpp``` implements the RPN calculator using the ```Stack``` template and standard IO stream.

###
```
