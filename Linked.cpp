#include "Linked.h"

Linked::Linked() {
    head = nullptr;
    tail = nullptr;
}

Linked::Linked(Item_Type d) {
    Node* tempPtr = new Node(d);
    tempPtr->data = d;
    tempPtr->next = nullptr;
    head = tempPtr;
    tail = tempPtr;
}

Linked::~Linked() {
    
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }

    tail = nullptr;
    num_items = 0;
    
}

void Linked::push_front(const Item_Type& item) {
    Node* newNode = new Node(item);
    newNode->next = head;
    head = newNode;

    //if the list was previously empty, then update tail to also point to the added node
    if (tail == nullptr)
        tail = newNode;

    num_items++;
}

void Linked::push_back(const Item_Type& item) {
    Node* newNode = new Node(item);
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

void Linked::pop_front() {
    if (head == nullptr)
        throw std::invalid_argument("ERROR: pop_front() called on empty list");
    
    Node* removed_node = head;
    head = head->next;
    
    //update tail to nullptr if there was only one node to be deleted
    if (head == nullptr)
        tail = nullptr;

    delete removed_node;
    num_items--;

} 

void Linked::pop_back() {
    if (head == nullptr)
        throw std::invalid_argument("ERROR: pop_back() called on empty list");

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* tempPtr = head;
        while (tempPtr->next->next != nullptr) {
            tempPtr = tempPtr->next;
        }
        delete tempPtr->next;
        tempPtr->next = nullptr;
        tail = tempPtr;
    }
    
    num_items--;
} 


Item_Type& Linked::front() {
    if (head == nullptr)
        throw std::invalid_argument("ERROR: front() called on empty list");
    return head->data;
} 

Item_Type& Linked::back() {
    if (head == nullptr)
        throw std::invalid_argument("ERROR: back() called on empty list");
    
    Node* tempPtr = head;
    while (tempPtr->next != nullptr) {
        tempPtr = tempPtr->next;
    }

    return tempPtr->data;
} 


bool Linked::empty() {
    if (head == nullptr)
        return true;
    return false;

} 

void Linked::insert(size_t index, const Item_Type& item) {
    
    if (head == nullptr)
        throw std::invalid_argument("ERROR: insert() called on empty list");
    
    Node* newNode = new Node(item);

    if (index == 0)
        push_front(item);
    
    //if the index is greater than the size of the list, call push_back to add to end
    else if (index >= num_items) {
        push_back(item);
    
    }

    else {

        Node* temp = head;

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


bool Linked::remove(size_t index) {
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
    
        Node* temp = head;
        Node* prev = nullptr; //used to point to node to be deleted

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


size_t Linked::find(const Item_Type& item) {
    
    if (head == nullptr)
        throw std::invalid_argument("ERROR: find() called on empty list");

    if (head->data == item) {
        return 0;
    }
    

        Node* temp = head;
        
        for (size_t i = 0; i < num_items; i++) {
            
            if (temp->data == item) {
                return i;
            }
            else {
                temp = temp->next;
            }
        }
        return num_items;

    

}




//FIXME printList() for testing purposes only
void Linked::printList() {
    Node* tempPtr = head;
    while (tempPtr != nullptr) {
        cout << tempPtr->data.number << " ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}