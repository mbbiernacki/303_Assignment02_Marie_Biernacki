#pragma once

#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//using templates to make linked list more versatile

template <typename T>
struct Item_Type {

	//Item_Type constructor
	T data;
	Item_Type(T data) : data(data) {}


	//operator == defined for use in find() function to compare when values are equivalent
	bool operator==(const Item_Type& other) const {
		return this->data == other.data;
	}
};

template <typename T>
struct Node {
	
	//each node will hold nodeData of Item_Type and a pointer to the next node

	Item_Type<T> nodeData;
	Node<T>* next;

	//node constructor
	Node(const Item_Type<T>& data, Node* next_ptr = nullptr) : nodeData(data), next(next_ptr) {}

};

template<typename T>
class Linked {
protected:

	//initializing head pointer, tail pointer, and num_items
	Node<T>* head;
	Node<T>* tail;
	int num_items;

public:
	//default constructor
	Linked() : head(nullptr), tail(nullptr), num_items(0) {}

	//constructor with Item_Type
	Linked(Item_Type<T> d) {
		Node<T>* tempPtr = new Node<T>(d);
		head = tail = tempPtr;
		num_items = 1;
	}

	//destructor to empty list
	~Linked() {
		while (head != nullptr) {
			Node<T>* current = head;
			head = head->next;
			delete current;
		}
		tail = nullptr;
		num_items = 0;
	}


	//inserts a copy of item as first element of list
	void push_front(const Item_Type<T>& item) {
		
		//declare newNode, assign the next pointer of newNode to the head, head is now the newNode
		Node<T>* newNode = new Node<T>(item);
		newNode->next = head;
		head = newNode;

		//if the list was previously empty, then update tail to also point to the added node
		if (tail == nullptr)
				tail = newNode;

		num_items++; //increase num_items
		
	}

	//adds copy of item to end of list
	void push_back(const Item_Type<T>& item) {
		
		//declare newNode
		Node<T>* newNode = new Node<T>(item);
		
		//if the list was empty, both head and tail are assigned to newNode
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			//otherwise, set the tail's next pointer to newNode, reassign the tail to the newNode
			tail->next = newNode;
			tail = newNode;
		}

		num_items++; //increase num_items
	}

	//removes first item from list
	void pop_front() {
		//check if the list is empty
		if (head == nullptr) {
			cout << "ERROR: pop_front() called on empty list" << endl;
		}
		else {
			
			//set removed_node to head, then reassign head to the next node
			Node<T>* removed_node = head;
			head = head->next;

			//after updating head to head->next, if head is now null, update tail to null
			if (head == nullptr)
				tail = nullptr;

			delete removed_node; //delete removed_node and decrease num_items
			num_items--;
		}
		
	}

	//removes last item from list
	void pop_back() {
		
		//check if list is empty
		if (head == nullptr) {
			cout << "ERROR: pop_back() called on empty list" << endl;
		}
		//check if head is the last item in the list, delete if true
		else if (head->next == nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;

			num_items--; //decrease num_items
		}

		else {
			
			//create a tempPtr to iterate through the linked list until the tail is found
			Node<T>* tempPtr = head;
			while (tempPtr->next->next != nullptr) {
				tempPtr = tempPtr->next;
			}
			delete tempPtr->next; 
			tempPtr->next = nullptr;
			tail = tempPtr;

			num_items--; //decrease num_items
		}

		
	
	} 

	//returns first element in the list
	Item_Type<T>& front() {
		//check if list is empty
		if (head == nullptr) {
			cout << "ERROR: front() called on empty list" << endl;
		}
		else {
			return head->nodeData;
		}
	}

	//returns the last element in the list
	Item_Type<T>& back() {
		//check if list is empty
		if (head == nullptr) {
			cout << "ERROR: back() called on empty list" << endl;
		}
		else {
			return tail->nodeData;
		}
		
	}

	//returns true if list is empty
	bool empty() {
		//if head is null (empty) return true, otherwise returns false
		if (head == nullptr)
			return true;
		return false;
	} 


	//inserts item at position index (starting at 0)
	//inserts at the end if the index is beyond the end of the list
	void insert(size_t index, const Item_Type<T>& item) {
		
		//check if list is empty (cant insert on an empty list)
		if (head == nullptr && index != 0) {
			cout<< "ERROR: insert() called on empty list" << endl;
		}
		else {
			Node<T>* newNode = new Node<T>(item);

			//if the index is 0, add the item to the front
			if (index == 0)
				push_front(item);

			//if the index is greater than the size of the list, add item to the end
			else if (index >= num_items) {
				push_back(item);

			}

			else {

				//otherwise create a tempPtr to iterate through the linked list until the appropriate index is found
				Node<T>* temp = head;

				for (size_t i = 0; i < index - 1; i++) {
					temp = temp->next;
				}

				newNode->next = temp->next;
				temp->next = newNode;

				if (newNode->next == nullptr) {
					tail = newNode;
				}

				num_items++; //increase num_items

			}

		}

		
	}
	
	//remove item at position index
	//return TRUE if successful 
	//return FALSE if index is beyond the end of the list
	bool remove(size_t index) {
		//check if list is empty
		if (head == nullptr) {
			cout << "ERROR: remove() called on empty list" << endl;
		}
			
		//if index is greater than the size of the list, return false
		else if (index >= num_items) {
		
			return false;
		
		}
			
		//if index is 0, remove the front, return true
		else if (index == 0) {
			pop_front();
			return true;
		}

		//if index is equal to the last index value, remove the back, return true
		else if (index == num_items - 1) {
			pop_back();
			return true;
		}

		else {
			//otherwise create a temp pointer to iterate through the list until the index value is found, delete and return true

			Node<T>* temp = head;
			Node<T>* prev = nullptr; //used to point to node to be deleted

			for (size_t i = 0; i < index; i++) {
				prev = temp;
				temp = temp->next;
			}

			prev->next = temp->next;
			delete temp;
			temp = nullptr;

			num_items--; //decrease num_items

			return true;

		}
	
	}
	

	//return the position of the first occurrence of item if it is found
	//return the size of the list if it is not found
	size_t find(const Item_Type<T>& item) {
		
		//check if list is empty
		if (head == nullptr) {
			cout << "ERROR: find() called on empty list" << endl;

		}
		
		else if (head->nodeData == item) { 
			//check if the data is located at the head (index 0)
			return 0;
		}
		else {
			//otherwise create a temp pointer to iterate through the list
			Node<T>* temp = head;

			for (size_t i = 0; i < num_items; i++) {

				if (temp->nodeData == item) {
					return i; //return index value of the item
				}
				else {
					temp = temp->next;
				}
			}
			return num_items; //if not found after iteration, return the size of the list
		}
		
	
	}



	//printList iterates through list and prints the data at each node
	void printList() {
		Node<T>* tempPtr = head;
		while (tempPtr != nullptr) {
			cout << tempPtr->nodeData.data << " ";
			tempPtr = tempPtr->next;
		}
		cout << endl;
	}


	//returns the value of num_items
	int getNumItems() const {
		return num_items;
	}
};