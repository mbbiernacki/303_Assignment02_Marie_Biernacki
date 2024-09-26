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
    cout << "\n--- TESTING ON EMPTY LIST ---" << endl;
    cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << endl; //expected: yes

    cout << "\nTesting pop_front and pop_back..." << endl;
    list.pop_front(); //expected: error message
    list.pop_back(); //expected: error message

    cout << "\nTesting front and back..." << endl;
    list.front(); //expected: error message
    list.back(); //expected: error message

    cout << "\nTesting remove..." << endl;
    list.remove(0); //expected: error message

    cout << "\nTesting find..." << endl;
    list.find(0); //expected: error message


    cout << "\n\n--- TESTING INSERT ---" << endl;
    cout << "\nInserting value 333 at index 1..." << endl;
    list.insert(1, 333); //expected: error message

    cout << "\nInserting value 333 at index 0..." << endl;
    list.insert(0, 333);
    cout << "Current List: ";
    list.printList(); //expected: 333

    cout << "\nInserting value 666 at index 10..." << endl;
    list.insert(10, 666);
    cout << "Current List: ";
    list.printList(); //expected: 333 666, inserts at the end when index is out of bounds

    cout << "\nInserting value 50 at index 1..." << endl;
    list.insert(1, 50);
    cout << "Current List: ";
    list.printList(); //expected: 333 50 666

    cout << "\nInserting value 1000 at index 3..." << endl;
    list.insert(3, 1000);
    cout << "Current List: ";
    list.printList(); //expected: 333 50 666 1000

    cout << "\n\n--- TESTING REMOVE ---" << endl;
    cout << "\nRemoving index 5..." << endl;
    list.remove(5);
    cout << "Current List: ";
    list.printList(); //expected: 333 50 666 1000, stays the same when index is out of bounds

    cout << "\nRemoving index 0..." << endl;
    list.remove(0); 
    cout << "Current List: ";
    list.printList(); //expected: 50 666 1000

    cout << "\nRemoving index 1..." << endl;
    list.remove(1); 
    cout << "Current List: ";
    list.printList(); //expected: 50 1000

    cout << "\nRemoving index 1 (last index)..." << endl;
    list.remove(1); 
    cout << "Current List: ";
    list.printList(); //expected: 50 

    
    cout << "\n\n--- TESTING PUSH FRONT AND PUSH BACK ---" << endl;
    
    cout << "\nCurrent List: ";
    list.printList(); //expected: 50 


    //test push_front
    cout << "\nTesting push_front 5, 10, and 25..." << endl;
    list.push_front(5);
    list.push_front(10);
    list.push_front(25);

    cout << "Current List: ";
    list.printList(); //expected: 25 10 5 50 

    //test push_back
    cout << "\nTesting push_back 5 and 4..." << endl;
    list.push_back(5);
    list.push_back(4);
    cout << "Current List: ";
    list.printList(); //expected: 25 10 5 50 5 4


    cout << "\n\n--- TESTING FRONT, POP FRONT, BACK, AND POP BACK ---" << endl;
    
    cout << "\nCurrent List: ";
    list.printList(); //expected: 25 10 5 50 5 4
    
    //test pop_front
    cout << "\nFront: " << list.front().data << endl; //expected: 25
    list.pop_front();
    cout << "Current List (after pop_front): "; //expected: 10 5 50 5 4
    list.printList();

    //test pop_back
    cout << "\nBack: " << list.back().data << endl; //expected: 4
    list.pop_back();
    cout << "Current List (after pop_back): "; //expected: 10 5 50 5 
    list.printList();



    cout << "\n\n--- TESTING REMOVE AND FIND ---" << endl;

    cout << "\nCurrent List: "; //expected: 10 5 50 5 
    list.printList();
    
    cout << "\nIs removing the value at index 70 possible (1 = true, 0 = false)? ";
    cout << list.remove(70) << endl;
    cout << "List after remove index 70 (stays the same): ";
    list.printList(); //expected: 10 5 50 5
    
    cout << "\nIs removing the value at index 2 possible (1 = true, 0 = false)? ";
    cout << list.remove(2) << endl;
    cout << "List after remove index 2: ";
    list.printList(); //expected: 10 5 5


    //test find()
    cout << "\nWhat index is value 70 located at (size of list)? " << list.find(70) << endl; //returns 3 (size of list)
    cout << "What index is value 5 located at? " << list.find(5) << endl; //returns 1 (first occurence of 5)
    cout << "What index is value 10 located at? " << list.find(10) << endl; //returns 0

    //test empty
    cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << endl; //expected: no



    
    //-----------Stack Functionality-----------

    cout << "\n\n\n\n--- STACK FUNCTIONALITY ---" << endl;

    //create a stack object
    Stack myStack;

    cout << "\nIs the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //expected: yes

    cout << "\nInserting 5, 10, and 20 onto the stack..." << endl;
    //insert numbers onto the stack
    myStack.insert(5);
    myStack.insert(10);
    myStack.insert(20);

    cout << "\nCurrent Stack: ";
    myStack.printStack(); //expected: 20 10 5

    //print top of stack
    cout << "\nTesting top...\nTop of Stack: " << myStack.top() << endl; //expected: 20

    cout << "\nTesting remove..." << endl;
    myStack.remove(); //removes top of stack

    cout << "Current Stack: ";
    myStack.printStack(); //expected: 10 5

    cout << "\nTesting average...\nAverage of the current stack: " << myStack.average() << endl; //expected: 7.5

    cout << "\nIs the stack empty? " << (myStack.empty() ? "Yes" : "No") << endl; //expected: no

    return 0;
    

}
