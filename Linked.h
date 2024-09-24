#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//create Item_Type and Node structs to hold data and pointer
struct Item_Type {
	
	//using integer as Item_Type to test linked list functionality
	int number;
	Item_Type(int value) : number(value) {}
	

	//operator == defined for use in find() function to compare when numbers are equivalent
	bool operator==(const Item_Type& other) const {
		return this->number == other.number;
	}
};

struct Node {
	Item_Type data;
	Node* next;

	//node constructor
	Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}

};

class Linked {
	protected:
		Node* head;
		Node* tail;
		int num_items;

	public:
		Linked();
		Linked(Item_Type);
		~Linked();

		void push_front(const Item_Type& item); //inserts a copy of item as first element of list
		void push_back(const Item_Type& item); //adds copy of item to end of list
		
		void pop_front(); //removes first item from list
		void pop_back(); //removes last item from list

		Item_Type& front(); //returns first element in the list
		Item_Type& back(); //returns the last element in the list

		bool empty(); //returns true if list is empty


		void insert(size_t index, const Item_Type& item);
		//inserts item at position index (starting at 0)
		//inserts at the end if the index is beyond the end of the list

		bool remove(size_t index);
		// remove item at position index
		// return TRUE if successful 
		// return FALSE if index is beyond the end of the list

		size_t find(const Item_Type& item);
		// return the position of the first occurrence of item if it is found
		// return the size of the list if it is not found*/


		//FIXME: below functions for testing only
		void printList();

		int getNumItems() const {
			return num_items;
		}
};