#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Stack {

protected:
	vector<int>stackVector; //create vector of int

public:

	bool empty(); //returns true or false based on whether the stack is empty

	void insert(int number); //adds a number to the top of the stack

	void remove(); //removes the top number from the stack

	int& top(); //returns the value of the top of the stack

	double average(); //finds and returns the average of the numbers in the stack


	//print function to showcase functionality
	void printStack() {

		for (int i = stackVector.size() - 1; i >= 0; i--) {
			cout << stackVector.at(i) << " ";
		}

		cout << endl;
	}

};



