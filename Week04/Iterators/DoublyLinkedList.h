#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "ListNode.h"
#include "LinkedListIterator.h"

using namespace std;


template <class T>
class DoublyLinkedList
{
protected:
    ListNode<T>* head;
    ListNode<T>* tail;
    int length;

public:

    ///-------------New Iterator Stuff-----------------------

    /**
     * @brief Get iterator pointing to first thing in list (item after dummy head node)
     */
    LinkedListIterator<T> begin();

    /**
     * @brief Get iterator pointing to location after last thing in list (always the dummy)
     */
    LinkedListIterator<T> end();

    /**
     * @brief Find desired value in the list, return an iterator to that value
     *          or to end() if value not found
     */
    LinkedListIterator<T> findValue(const T& value);

    /**
     * @brief Insert given value
     */
    void insert(LinkedListIterator<T> location, const T& value);

    /**
     * @brief Take an iterator and delete the node it points to
     * @return Iterator pointing to node after one deleted
     */
    LinkedListIterator<T> erase(LinkedListIterator<T> location);


    ///---------------Other stuff-------------------------------
    DoublyLinkedList();
    ~DoublyLinkedList();

    int listSize();

    void insertAt(int index, T value);
    void removeAt(int index);
    T retrieveAt(int index);

    template <class R>
    friend ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList);
};



///-------------New Iterator Stuff-----------------------

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::begin() {
    //Construct iterator that points to item after head
    return LinkedListIterator<T>( head->next );
}

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::end() {
    //Construct iterator that points to tail
    return LinkedListIterator<T>( tail );
}

template <class T>
void DoublyLinkedList<T>::insert(LinkedListIterator<T> location, const T& value) {
    //Make a new node with desired value
    ListNode<T>* newNode = new ListNode<T>(value);

    //TODO - hook new node up before location.currentNode
    //should set 4 pointers to new values...

    //Make sure to update the size
}

template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::erase(LinkedListIterator<T> location) {
    if(location.currentNode == tail || location.currentNode == head)     //Don't allow erasure of dummys
        return location;


    //TODO:
    //Get address of next node
    //Update the size of the list
    //Hook up neighbors to each other to remove current from
    //Delete the node
    //Return iterator that points to next node
}


template <class T>
LinkedListIterator<T> DoublyLinkedList<T>::findValue(const T& value) {
    //Get an iterator to head
    LinkedListIterator<T> currentIt = begin();

    //TODO:
    //Walk forward until either the value is found or the iterator reaches end()

    return currentIt;
}



///---------------Other stuff-------------------------------



template <class R>
ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList) {
    cout << "List: ";
    ListNode<R>* current = theList.head->next;
    while(current != theList.tail) {
        cout << current->data;
        if(current->next != theList.tail)
            cout << ", ";
        current = current->next;
    }
    cout << endl;
    return os;
}


template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
int DoublyLinkedList<T>::listSize() {
    return length;
}

template <class T>
T DoublyLinkedList<T>::retrieveAt(int index) {
    if(index >= length)
        throw out_of_range("Bad index in retrieveAt");

    //Start at node after dummy
    ListNode<T>* current = head->next;
    //Advance index times
    for(int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}


template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    //Make dummy nodes for head/tail
    head = new ListNode<T>();
    tail = new ListNode<T>();

    //Connect dummies into a list
    head->next = tail;
    tail->prev = head;

    length = 0;
}


template <class T>
void DoublyLinkedList<T>::insertAt(int index, T value) {
    if(index > length)
        throw out_of_range("Bad index in insertAt");

    //Make a new node to hold new item
    ListNode<T>* newNode = new ListNode<T>(value);

    //Make previousNode point to node that should end up right before the new node
    ListNode<T>* previousNode = head;
    for(int i = 0; i < index; i++)
        previousNode = previousNode->next;

    //Make newNode point to its two neighbors
    newNode->prev = previousNode;
    newNode->next = previousNode->next;

    //Make its two neighhbors point to it
    newNode->next->prev = newNode;
    newNode->prev->next = newNode;

    length++;
}

template <class T>
void DoublyLinkedList<T>::removeAt(int index) {
    if(index >= length)
        throw out_of_range("Bad index in removeAt");

    //Make currentNode point to one we want to get rid of
    ListNode<T>* currentNode = head->next;
    for(int i = 0; i < index; i++)
        currentNode = currentNode->next;

    //Make its neighbors point to each other, skipping currentNode
    currentNode->next->prev = currentNode->prev;
    currentNode->prev->next = currentNode->next;

///This does the same thing as the two lines above, with less navigation
//    ListNode<T>* nodeBefore = currentNode->prev;
//    ListNode<T>* nodeAfter = currentNode->next;
//    nodeBefore->next = nodeAfter;
//    nodeAfter->prev = nodeBefore;

    //Safe to delete node
    delete currentNode;
    length--;
}


#endif // DOUBLYLINKEDLIST_H
