#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include "ListNode.h"

//Forward declate DoublyLinkedList so we can make it a friend
template<class T>
class DoublyLinkedList;


template<class T>
class LinkedListIterator
{
    //Give DoublyLinkedList access to private information
    friend class DoublyLinkedList<T>;

private:
    ListNode<T>* currentNode;

public:
    //Constructor - takes pointer to ListNode
    LinkedListIterator(ListNode<T>* const location)
    {
        currentNode = location;
    }

    //Dereference iterator to retrieve data in current node
    // return reference to allow modification
    T& operator*()
    {
        ///TODO - return data from current node
    }

    //Advance iterator position by one
    void operator++()
    {
        ///TODO - advance the iterator to point at next node in list

        //Note: Operator ++ can also be implemented to return the current object by reference
        //      for use in a more complex expression. To do, return type would be "LinkedListIterator<T>&"
        //      and last line would be "return *this;"
    }

    //Compare two iterators with ==
    bool operator==(const LinkedListIterator& other) const
    {
        return currentNode == other.currentNode;
    }

    //Compare two iterators with !=
    bool operator!=(const LinkedListIterator& other) const
    {
        return currentNode != other.currentNode;
    }
};

#endif // LINKEDLISTITERATOR_H
