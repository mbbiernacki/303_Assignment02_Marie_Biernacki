#include "Linked_List.h"
#include "Stack.h"
#include <iostream>


using namespace std;

int main() {

    /*
    //Stack.h Functionality

    //create a stack object
    Stack myStack;

    if (myStack.empty()) {
        cout << "Stack is empty." << endl;
    }

    //insert numbers onto the stack
    myStack.insert(5);
    myStack.insert(10);
    myStack.insert(20);

    //print top of stack
    cout << "Top of Stack: " << myStack.top() << endl;

    //print the entire stack
    myStack.printStack();

    //remove top of stack
    myStack.remove();

    cout << "Stack after removing top element: ";
    myStack.printStack();

    cout << "Average of the current stack: " << myStack.average() << endl;
    
    cout << "\n\n\n";

    */

    //FIXME linked list testing code

    Linked<int> list; // Create a linked list of integers

    // Test push_front
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    cout << "List after push_front operations: ";
    // Expected output: 3 2 1
    cout << list.front().data << " ";
    list.pop_front();
    cout << list.front().data << " ";
    list.pop_front();
    cout << list.front().data << endl;
    list.pop_front();

    // Test push_back
    list.push_back(4);
    list.push_back(5);

    cout << "List after push_back operations: ";
    // Expected output: 4 5
    cout << list.front().data << " ";
    list.pop_front();
    cout << list.front().data << endl;
    list.pop_front();

    // Refill the list for further tests
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    // Test pop_front
    cout << "Popped front: " << list.front().data << endl; // Expected output: 10
    list.pop_front();
    cout << "List after pop_front: ";
    // Expected output: 20 30
    cout << list.front().data << " ";
    list.pop_front();
    cout << list.front().data << endl;
    list.pop_front();

    cout << "Refilling list..." << endl;
    
    // Refill the list
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    
    cout << "\nPRINT LIST" << endl;
    list.printList();

    cout << "\nNUMBER OF ITEMS IN LIST: " << list.getNumItems() << endl;


    // Test pop_back
    cout << "\nPopped back: " << list.back().data << endl; // Expected output: 300
    list.pop_back();
    cout << "\nList after pop_back: ";
    // Expected output: 100 200
    cout << list.front().data << " ";
    list.pop_front();
    cout << list.front().data << endl;
    list.pop_front();

    // Test insert
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);


    cout << "\n\nPRINT LIST" << endl;
    list.printList();


    list.insert(1, 7); // Insert 7 at index 1

    cout << "List after insert at index 1: ";
    // Expected output: 5 7 10 15
    list.printList();

    cout << "\nIs removing the number 70 possible (1 = true, 0 = false)?" << endl;
    cout << list.remove(70) << endl;

    cout << "\nList after remove index 70 (stays the same): ";
    //Expected output: 5 7 10 15
    list.printList();

    cout << "NUMBER OF ITEMS IN LIST: " << list.getNumItems() << endl; // 4

    //test find()
    cout << list.find(70) << endl; // returns 4 (size of list)
    cout << list.find(5) << endl; // return 0
    cout << list.find(10) << endl; //returns 2
    cout << list.find(15) << endl; // return 3



    // Test empty
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl; // Expected output: no

    return 0;
    

}
