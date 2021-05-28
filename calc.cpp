#include "Stack.h"
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

//Helper functions:

//Checks to find the first input that is not a number or decimal
bool isDouble(const string input){
	return(input.find_first_not_of(".0123456789") == string::npos);
}

//Operator helper functions:
void add (Stack<double> &s) {
	//check that stack has a least 2 numbers
	assert(s.size() >= 2);
	//pop 2 numbers off stack
	double num1 = s.pop();
	double num2 = s.pop();
	//add together
	double total = num1 + num2;
	//push result on top of stack
	s.push(total);
}

void subtract (Stack<double> &s) {
	//check that stack has a least 2 numbers
	assert(s.size() >= 2);
	//pop 2 number off stack
	double num1 = s.pop();
	double num2 = s.pop();
	//subtract num1 from num2 and push
	double total = num2 - num1;
	//push result back on stack
	s.push(total);
}

void multiply (Stack<double> &s) {
	//check that stack has a least 2 numbers
	assert(s.size() >= 2);
	//pop 2 numbers off stack
	double num1 = s.pop();
	double num2 = s.pop();
	//multiply numbers together and push total on stack
	double total = num1 * num2;
	s.push(total);
}

void divide (Stack<double> &s) {
	assert(s.size());
	//pop 2 numbers off stack
	double num1 = s.pop();
	double num2 = s.pop();
	//if tries to divide by 0
	if (num1 == 0) {
		//push numbers back to stack
		s.push(num2);
		s.push(num1);
		//show error if dividing by zero
		cout << "Error: Division by zero" << endl;
		//return;
	} else {
	//divide num1 from num2 and push total on stack
	double total = num2 / num1;
	s.push(total);
	}
}

void duplicate(Stack<double> &s) {
	//check that the stack has at least one value
	assert(!s.empty());
	//pop 1 number off stack
	double num = s.pop();
	//push it on the stack twice to duplicate
	s.push(num);
	s.push(num);
}

void reverse(Stack<double> &s) {
	//check that stack has a least 2 numbers
	assert(s.size() >= 2);
	//pop 2 numbers off the stack
	double num1 = s.pop();
	double num2 = s.pop();
	//reverse order of numbers pushed onto stack
	s.push(num1);
	s.push(num2);
}

void print(Stack<double> &s) {
	//print the first value of stack
	cout << s.top() << endl;
}

void clear(Stack<double> &s) {
	//pop each item until the stack is empty
	while (!s.empty()) {
		s.pop();
	}
}

void print_all(Stack<double> &s) {
	//print the stack
	cout << s << endl;
}

void negative(Stack<double> &s) {
	//check that there is at least one number
	assert(!s.empty());
	//pop off 1 number
	double neg = s.pop();
	//multiply by -1 to negate and push it back on stack
	neg = -1 * neg;
	s.push(neg);
}


 int main (int argc, char **argv) {
	cout.precision(4);
	Stack<double> s;
	//check stack starts empty
	assert(s.empty());
	string input;
	//Calculator will run into the user enters q to quit
	while (cin >> input && input != "q") {
		//Check if input is a number
		if(isDouble(input)){
			//return the input string as a double
			s.push(stod(input));
		}
		//If input is not a number check the operators and then letters
		//Call on the correspoding helper function
		else{
			switch(input){
				case "+" : 
					add(s);
					break;
				case "-" :
					subtract(s);
					break;
				case "*" : 
					multiply(s);
					break;
				case "/" : 
					divide(s);
					break;
				case "d" :
					duplicate(s);
					break;
				case "r" : 
					reverse(s);
					break;
				case "p" :
					print(s);
					break;
				case "c" :
					clear(s);
					break;
				case "a" :
					print_all(s);
					break;
				case "n" :
					negative(s);
					break;	
			}	
			
		}
		
		/* 
		else if (input == "+") {
			add(s);
		}
		else if (input == "-") {
			subtract(s);
		}
		else if (input == "*") {
			multiply(s);
		}
		else if (input == "/") {
			divide(s);
		}
		else if (input == "d") {
			duplicate(s);
		}
		else if (input == "r") {
			reverse(s);
		}
		else if (input == "p") {
			//print top stack
			print(s);
		}
		else if (input == "c") {
			clear(s);
		}
		else if (input == "a") {
			print_all(s);
		}
		else if (input == "n") {
			negative(s);
		}
		*/
	}
	return 0;
}
