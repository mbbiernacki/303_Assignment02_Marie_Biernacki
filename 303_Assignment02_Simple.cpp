//CS303 ASSIGNMENT 02: Singly-Linked List and Stack w/ Vectors
//NAME: Marie Biernacki
//CREATED: September 14th, 2024
//DUE: September 26th, 2024

#include "Linked_List.h"
#include "Stack.h"

#include <iostream>

using namespace std;

int main() {

    //Linked List Functionality

    Linked<int> list; //create a linked list of integers

    cout << "--- LINKED LIST FUNCTIONALITY ---" << endl;

    //test empty
    cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << endl; // Expected output: yes

    //test push_front
    cout << "\nTesting push_front 1, 2, and 3..." << endl;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    cout << "List after push_front operations: ";
    list.printList(); //expected: 3 2 1
    cout << "Number of Items: " << list.getNumItems() << endl; //expected: 3

    //test push_back
    cout << "\nTesting push_back 4 and 5..." << endl;
    list.push_back(4);
    list.push_back(5);

    cout << "List after push_back operations: ";
    list.printList(); //expected: 3 2 1 4 5
    cout << "Number of Items: " << list.getNumItems() << endl; //expected: 5

    //test pop_front
    cout << "\nTesting front and pop_front..." << endl;
    cout << "Front of list: " << list.front().data << endl; //expected: 3
    list.pop_front();
    cout << "List after pop_front: "; //expected: 2 1 4 5
    list.printList();
    cout << "Number of Items: " << list.getNumItems() << endl; //expected: 4

    //test pop_back
    cout << "\nTesting back and pop_back..." << endl;
    cout << "Back of list: " << list.back().data << endl; //expected: 5
    list.pop_back();
    cout << "List after pop_back: "; //expected: 2 1 4 
    list.printList();
    cout << "Number of Items: " << list.getNumItems() << endl; //expected: 3

    cout << "\nInserting value 7 at index 1..." << endl;
    list.insert(1, 7);
    cout << "List after insert at index 1: ";
    list.printList();  //expected: 2 7 1 4

    cout << "\nTesting remove..." << endl;
    cout << "Is removing the number 70 possible (1 = true, 0 = false)? ";
    cout << list.remove(70) << endl;

    cout << "List after remove index 70: ";
    list.printList(); //expected 2 7 1 4


    //test find()
    cout << "\nTesting find..." << endl;
    cout << "What index is value 70 located at? " << list.find(70) << endl; //returns 4 (size of list)
    cout << "What index is value 2 located at? " << list.find(2) << endl; //return 0
    cout << "What index is value 4 located at? " << list.find(4) << endl; //return 3
    cout << "What index is value 7 located at? " << list.find(7) << endl; //return 1

    //test empty
    cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << endl; // Expected output: no



    
    //-----------Stack Functionality-----------

    cout << "\n\n\n--- STACK FUNCTIONALITY ---" << endl;

    //create a stack object
    Stack myStack;

    cout << "\nIs the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //expected: yes

    cout << "\nInserting 5, 10, and 20 onto the stack..." << endl;
    //insert numbers onto the stack
    myStack.insert(5);
    myStack.insert(10);
    myStack.insert(20);

    cout << "\nStack after Insert: ";
    myStack.printStack(); //expected: 20 10 5

    //print top of stack
    cout << "\nTesting top...\nTop of Stack: " << myStack.top() << endl; //expected: 20

    cout << "\nTesting remove..." << endl;
    myStack.remove(); //removes top of stack

    cout << "Stack after calling remove: ";
    myStack.printStack(); //expected: 10 5

    cout << "\nTesting average...\nAverage of the current stack: " << myStack.average() << endl; //expected: 7.5

    cout << "\nIs the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //expected: no

    return 0;
    

}
