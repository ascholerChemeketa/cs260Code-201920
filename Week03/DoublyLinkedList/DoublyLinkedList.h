#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;

///-----------------------------LIST NODE---------------------------------
template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;

	ListNode() {
	    next = nullptr;
	    prev = nullptr;
	    //Call default constructor for type T
	    //  produces 0 for primitive types
	    data = T();
	}

	ListNode(T value) {
	    next = nullptr;
	    prev = nullptr;
	    data = value;
	}
};


///-----------------------------LINKED LIST---------------------------------

template <class T>
class DoublyLinkedList
{
protected:
    ListNode<T>* head;
    ListNode<T>* tail;
    int length;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    ///Assignment Operator and Copy Ctor not implemented - declared to prevent
    /// use of default versions
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    int listSize() const;

    void insertAt(int index, T value);
    void removeAt(int index);
    T retrieveAt(int index) const;

    template <class R>
    friend ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList);
};

///-----------------------------LINKED LIST FUNCTIONS-----------------------
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
    //Delete all nodes, including dummies
    while(head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
int DoublyLinkedList<T>::listSize() const {
    return length;
}

template <class T>
T DoublyLinkedList<T>::retrieveAt(int index) const {
    if(index >= length || index < 0)
        throw out_of_range("Bad index in retrieveAt");

    //Start at node after dummy
    ListNode<T>* current = head->next;
    //Advance index times
    for(int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}


///-----------------------------TODO-----------------------
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

    //TODO - make dummy nodes, attach to each other
    ListNode<T>* sampleDummy = new ListNode<T>();

}


template <class T>
void DoublyLinkedList<T>::insertAt(int index, T value) {
    if(index > length)
        throw out_of_range("Bad index in insertAt");

    //TODO - implement
}

template <class T>
void DoublyLinkedList<T>::removeAt(int index) {
    ////Don't turn this on until you start implementing the code...
    //if(index >= length || index < 0)
    //    throw out_of_range("Bad index in removeAt");

    //TODO - implement

}


#endif // DOUBLYLINKEDLIST_H
