#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;


///-----------------------------LIST NODE---------------------------------
template <class T>
struct ListNode
{
    T data;
	ListNode* next;

    //Maintain a count of active nodes for debugging
    static int nodeCount;

    ListNode(T value) {
	    data = value;
	    next = nullptr;
        nodeCount++;    //just for debugging
	}

	~ListNode() {
	    //just for debugging
	    nodeCount--;
        cout << "Destroying a node - currently have " << nodeCount << endl;
	}
};

//Initialize static varaible used for debugging
template <class T>
int ListNode<T>::nodeCount = 0;



///-----------------------------LINKED LIST---------------------------------
template <class T>
class LinkedList
{
protected:
    ListNode<T>* head;
    ListNode<T>* tail;
    int length;

public:
    /**
     * @brief Construct empty linked list
     */
    LinkedList();

    /**
     * @brief Copy constructor - intentionally BROKEN!
     * Declared, but not implemented to prevent accidental use of default copy ctor
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Assignment Operator - intentionally BROKEN!
     * Declared, but not implemented to prevent accidental use of default assignment operator
     */
    LinkedList& operator=(const LinkedList& other);

    /**
      * @brief Destructor - Just prints debug info, does not free memory
      */
    ~LinkedList();

    /**
     * @brief Print contents of list to cout
     */
    void print() const;

    /**
     * @brief Inserts given value at head of the list
     * @param value Integer to insert
     */
    void insertStart(T value);

    /**
     * @brief Inserts given value at end of the list
     * @param value Integer to insert
     */
    void insertEnd(T value);

    /**
     * @brief Remove first item from list
     *        Throws exception if list is empty
     */
    void removeFirst();

    /**
     * @brief Insert given value into list at given location
     * @param index Location to insert value
     *          Throws exception if invalid
     * @param value Integer to insert
     */
    void insertAt(int index, T value);

    /**
     * @brief Remove item at given index from list
     * @param index Location of item to remove
     *          Throws exception if invalid
     */
    void removeAt(int index);

    /**
     * @brief Get the length of the list
     * @return int representing number of values (nodes) in list
     */
    int listSize() const;

    /**
     * @brief Gets value stored at specified index
     * @param index Location we want to retrieve from
     *              Throws excpetion if invalid
     * @return value
     */
    T retrieveAt(int index) const;

};


template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    //TODO - actually delete all nodes

    cout << "Just destroyed a list. There are "
         << ListNode<T>::nodeCount << " total nodes left in the program.\n";
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    //TODO - Write copy constructor...
    //Don't forget to initialize head/tail/length

    assert(0);  //blow up for now - remove this
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if(this != &other) {
        //TODO - delete all existing nodes
        //TODO - copy nodes from other list
        assert(0);  //blow up for now - remove this
    }
    return *this;
}


template <class T>
void LinkedList<T>::print() const {
    //current will point to each element in turn
    ListNode<T>* current = head;

    while(current != nullptr) {
        cout << current->data << " ";   //print current item
        current = current->next;        //advance to next
    }
    cout << endl;

    //Normally wouldn't need this, print to aid with debugging
    cout << "Length is: " << length << endl;
    if(tail)
        cout << "Tail points at: " <<  tail->data << endl;
    else
        cout << "Tail has a nullptr" << endl;
}

template <class T>
void LinkedList<T>::insertStart(T value) {
    ListNode<T>* temp = new ListNode<T>(value);

    temp->next = head;  //old head is what new node points to
    head = temp;        //new node is now head

    //if there is no second node, new node is both head and tail
    if(head->next == nullptr)
        tail = head;

    length++;
}

template <class T>
int LinkedList<T>::listSize() const {
    return length;
}

template <class T>
void LinkedList<T>::insertEnd(T value) {
    //TODO - Fixme
}

template <class T>
void LinkedList<T>::removeFirst() {
    if(head == nullptr)
        throw out_of_range("Can't remove from empty list");

    //TODO - Remove first item in list
    //If removing tail, make sure to null out tail
}

template <class T>
void LinkedList<T>::insertAt(int index, T value) {
    //TODO - Insert value at given location of list
    //index 0 or length are special cases for insertStart/insertEnd
}

template <class T>
void LinkedList<T>::removeAt(int index) {
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in removeAt");

    if(index == 0) {
        //First item is special case... use removeFirst for it
        removeFirst();
        return;
    }

    //Find node BEFORE one we want to delete
    ListNode<T>* current = head;
    for(int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    ListNode<T>* nodeToRemove = current->next;

    //Cut node out of list
    current->next = nodeToRemove->next;

    delete nodeToRemove;    //Delete it from heap

    //Is there nothing left after current node? Then it is the new tail
    if(current->next == nullptr)
        tail = current;

    length--;
}

template <class T>
T LinkedList<T>::retrieveAt(int index) const {
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in retrieveAt");

    ListNode<T>* current = head;
    for(int stepsLeft = index; stepsLeft > 0; stepsLeft--) {
        current = current->next;
    }

    return current->data;
}

#endif
