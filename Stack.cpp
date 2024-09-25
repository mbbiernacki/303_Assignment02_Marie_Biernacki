#include "Stack.h"

#include <iostream>

bool Stack::empty() {
	return stackVector.empty();
} //returns true or false based on whether the stack is empty

void Stack::insert(int number) {
	stackVector.push_back(number);
} //adds a number to the top of the stack

void Stack::remove() {
	stackVector.pop_back();
} //removes the top number from the stack

int& Stack::top() {
	return stackVector.back();
} //returns the value of the top of the stack

double Stack::average() {
	
	//finds and returns the average of the numbers in the stack
	
	//check if stack is empty
	if (stackVector.empty())
		return 0;
	
	//iterate through stack using for loop
	int total = 0;
	for (int i = 0; i < stackVector.size(); i++) {
		total += stackVector.at(i);
	}
	
	//use static_cast to ensure average is calculated correctly
	return static_cast<double>(total) / stackVector.size();
} 
