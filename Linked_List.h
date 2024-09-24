#pragma once

#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
struct Item_Type {

	//using integer as Item_Type to test linked list functionality
	T data;
	Item_Type(T data) : data(data) {}


	//operator == defined for use in find() function to compare when numbers are equivalent
	bool operator==(const Item_Type& other) const {
		return this->data == other.data;
	}
};

template <typename T>
struct Node {
	Item_Type<T> nodeData;
	Node<T>* next;

	//node constructor
	Node(const Item_Type<T>& data, Node* next_ptr = nullptr) : nodeData(data), next(next_ptr) {}

};

template<typename T>
class Linked {
protected:
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
		num_items = 1; //FIXME make sure this isn't messing it up
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
		Node<T>* newNode = new Node<T>(item);
		newNode->next = head;
		head = newNode;

		//if the list was previously empty, then update tail to also point to the added node
		if (tail == nullptr)
				tail = newNode;

		num_items++;
		
	}

	//adds copy of item to end of list
	void push_back(const Item_Type<T>& item) {
		Node<T>* newNode = new Node<T>(item);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}

		num_items++;
	}

	//removes first item from list
	void pop_front() {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: pop_front() called on empty list");

		Node<T>* removed_node = head;
		head = head->next;

		//update tail to nullptr if there was only one node to be deleted
		if (head == nullptr)
			tail = nullptr;

		delete removed_node;
		num_items--;
	}

	//removes last item from list
	void pop_back() {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: pop_back() called on empty list");

		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<T>* tempPtr = head;
			while (tempPtr->next->next != nullptr) {
				tempPtr = tempPtr->next;
			}
			delete tempPtr->next;
			tempPtr->next = nullptr;
			tail = tempPtr;
		}

		num_items--;
	
	} 

	//returns first element in the list
	Item_Type<T>& front() {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: front() called on empty list");
		return head->nodeData;
	}

	//returns the last element in the list
	Item_Type<T>& back() {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: back() called on empty list");

		return tail->nodeData;
	}

	//returns true if list is empty
	bool empty() {
		if (head == nullptr)
			return true;
		return false;
	} 


	//inserts item at position index (starting at 0)
	//inserts at the end if the index is beyond the end of the list
	void insert(size_t index, const Item_Type<T>& item) {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: insert() called on empty list");

		Node<T>* newNode = new Node<T>(item);

		if (index == 0)
			push_front(item);

		//if the index is greater than the size of the list, call push_back to add to end
		else if (index >= num_items) {
			push_back(item);

		}

		else {

			Node<T>* temp = head;

			for (size_t i = 0; i < index - 1; i++) {
				temp = temp->next;
			}

			newNode->next = temp->next;
			temp->next = newNode;

			if (newNode->next == nullptr) {
				tail = newNode;
			}

			num_items++;

		}
	
	}
	
	//remove item at position index
	//return TRUE if successful 
	//return FALSE if index is beyond the end of the list
	bool remove(size_t index) {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: remove() called on empty list");

		if (index >= num_items)
			return false;

		else if (index == 0) {
			pop_front();
			return true;
		}

		else if (index == num_items - 1) {
			pop_back();
			return true;
		}

		else {

			Node<T>* temp = head;
			Node<T>* prev = nullptr; //used to point to node to be deleted

			for (size_t i = 0; i < index; i++) {
				prev = temp;
				temp = temp->next;
			}

			prev->next = temp->next;
			delete temp;
			temp = nullptr;

			num_items--;

			return true;

		}
	
	}
	

	//return the position of the first occurrence of item if it is found
	//return the size of the list if it is not found
	size_t find(const Item_Type<T>& item) {
		if (head == nullptr)
			throw std::invalid_argument("ERROR: find() called on empty list");

		if (head->nodeData == item) {
			return 0;
		}


		Node<T>* temp = head;

		for (size_t i = 0; i < num_items; i++) {

			if (temp->nodeData == item) {
				return i;
			}
			else {
				temp = temp->next;
			}
		}
		return num_items;

	
	}



	//FIXME: below functions for testing only
	void printList() {
		Node<T>* tempPtr = head;
		while (tempPtr != nullptr) {
			cout << tempPtr->nodeData.data << " ";
			tempPtr = tempPtr->next;
		}
		cout << endl;
	}

	int getNumItems() const {
		return num_items;
	}
};