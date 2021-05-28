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
and begin typing numbers and operators.

### Supported Operators
Note: each command is separated from the next one by one or more whitespace characters, newline included

Input | Output 
:---: | :---
```number``` | A number can be: <br> - one of more digits [0-9] <br> - one or more digits followed by a decimal point (e.g. 4., 42.) <br> - one or more digits followed by a decimal, followed by more digits (e.g. 0.111, 10.987654)
```+``` | Pop the top two numbers off the stack, add them together, and push the result onto the top of the stack. This requires a stack with at least two operands.
```-``` | Pop the top two numbers off the stack, subtract the first number popped from the second, and push the result onto the top of the stack. This requires a stack with at least two operands.
```*``` | Pop the top two numbers off the stack, multiply them together, and push the result onto the top of the stack. This requires a stack with at least two operands.
```/``` | Pop the top two numbers off the stack, divide the second value popped by the first number, and push the result onto the top of the stack. This requires a stack with at least two operands. <br> Dividing by zero is not allowed, and an error will be thrown by the program.
```d``` | Duplicate: pop the top item off the stack and push two copies of the number onto the top of the stack. This requires a stack with at least one operand.
```r``` | Reverse: reverses the order of the top two items on the stack. This requires a stack with at least two operands.
```p``` | Print: print the top item on the stack to standard output, followed by a newline. This requires a stack with at least one operand and leaves the stack unchanged.
```c``` | Clear: pop all items from the stack. This input is always valid.
```a``` | Print-All: print all items on the stack in one line, from top-most to bottom-most, each value followed by a single space. The end of the output must be followed by exactly one newline. This input is always valid and leaves the stack unchanged. For an empty stack, for example, only the newline will be printed.
```n``` | Negate: negate the top item on the stack. This requires a stack with at least one operand.
```q``` | Quit: exit the calculator with a 0 exit value. This input is always valid.


### Examples
An RPN calculator is one where the operators appear after after their respective operands, not inbetween them.
To compute the expression (2 + 3) * 5, enter:
  ```bash 
  2 3 + 5 * 
  ```
To compute the expression ((2 - 3)*4)/(-6), enter: 
  ```bash 
  2 3 - 4 * 6 n /
  ```

## Documentation

### List Class
```List.h``` implements a class template of a doubly-linked list which supports an iterator that can search, insert, or delete at any position in the list. 

### Stack Class
```Stack.h``` implements a class template of the stack, making use of the List class to push and pop operations from one end.

### The Calculator
```calc.cpp``` implements the RPN calculator using the ```Stack``` template and standard IO stream.

### Unit Testing
```List_tests.cpp``` is a unit testing suite for the that was used during development for the ```List``` class. 
