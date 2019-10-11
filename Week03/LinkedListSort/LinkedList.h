#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

#include "ListNode.h"

using namespace std;


template <class T>
class LinkedList
{
protected:
  ListNode<T>* head;
  ListNode<T>* tail;
  int length;

public:

  /**
   * @brief Cuts list into two halves.
   *   This linked list retains first half of data,
   *   secondHalfList contains data from midpoint to end
   *
   * @return list containing second half of this list
   */
  LinkedList<T> sliceInHalf();

  /**
   * @brief mergeIn combines otherList into this list to produce one long sorted list.
   * @param otherList sorted LinkedList. Left empty by this function
   *
   * @pre Assumes this list and other List are both sorted lists
   */
  void mergeIn(LinkedList<T>& otherList);

  /**
   * @brief mergeSort Sorts this linked list using mergesort algorithm
   */
  void mergeSort();


  LinkedList();

  LinkedList(const LinkedList<T>& otherList);

  LinkedList<T>& operator=(const LinkedList<T>& otherList);

  ~LinkedList();

  void insertEnd(T value);
  T retrieveStart();
  T removeStart();

  template <class R>
  friend ostream& operator <<(ostream& os, const LinkedList<R>& theList);
};

///-----------------------------SORT RELATED-----------------------



/**
* @brief Cuts list into two halves.
*   This linked list retains first half of data,
*   secondHalfList contains data from midpoint to end
*
* @return list containing second half of this list
*/
template <class T>
LinkedList<T> LinkedList<T>::sliceInHalf() {
  //TODO - FIXME
  //Find node before middle by starting at head
  //Then walk forward (firstHalfLength - 1) steps



  //Create the LinkedList we will return
  LinkedList<T> otherList;


  //TODO - FIXME
  //Set up head, tail and length of other list so it gets everything after the current pointer
  //Break off current from everything else after it
  //Set it to be tail of this list and fix the length


  return otherList;
}


/**
* @brief mergeIn combines otherList into this list to produce one long sorted list.
* @param otherList sorted LinkedList. Left empty by this function
*
* @pre Assumes this list and other List are both sorted lists
*/
template <class T>
void LinkedList<T>::mergeIn(LinkedList<T>& otherList) {

  //Temporary list we will build up results in
  LinkedList<T> mergeList;

  //As long as both lists still have at least one value...
  while(this->length > 0 && otherList.length > 0) {
      //decide which list to pull from next...
      if(this->retrieveStart() < otherList.retrieveStart() ) {
          mergeList.insertEnd(this->removeStart());
      } else {
          mergeList.insertEnd(otherList.removeStart());
      }
  }

  //Now copy any leftover from this list
  while(this->length > 0) {
      mergeList.insertEnd(this->removeStart());
  }
  //And any leftover from other list
  while(otherList.length > 0) {
      mergeList.insertEnd(otherList.removeStart());
  }

  //TODO -
  //Steal all nodes from mergeList back to this
  //Make sure head/tail and length of mergeList are 0'd out so it does not
  // this it also owns the nodes

}



/**
* @brief mergeSort Sorts this linked list using mergesort algorithm
*/
template <class T>
void LinkedList<T>::mergeSort() {
  if(this->length <= 1)
      return;

  //Split so this list retains first half
  // and secondList is second half
  LinkedList<T> secondList = this->sliceInHalf();

  this->mergeSort();          //sort first half
  secondList.mergeSort();    //sort second half

  //Combine them back into one list
  this->mergeIn(secondList);
}


///-----------------------------OTHER LINKED LIST FUNCTIONS-----------------------


template <class T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}


template <class T>
LinkedList<T>::~LinkedList() {
    while(length > 0) {
        removeStart();
    }
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
  head = nullptr;
  tail = nullptr;
  length = 0;

  ListNode<T>* currentInOther = otherList.head;
  while( currentInOther != nullptr ) {
      this->insertEnd(currentInOther->data);
  }
}


template <class R>
ostream& operator <<(ostream& os, const LinkedList<R>& theList) {
  os << "Size: " << theList.length << " List: ";
  ListNode<R>* current = theList.head;
  while(current != nullptr) {
      os << current->data;
      if(current->next != nullptr)
          os << ", ";
      current = current->next;
  }
  os << "\t\t(Tail points to: " << (theList.tail ? to_string(theList.tail->data) : "nullptr") << ")";
  os << endl;
  return os;
}


template <class T>
void LinkedList<T>::insertEnd(T value) {
    ListNode<T>* current = new ListNode<T>(value);
    if(length == 0) {
        head = current;
    } else {
        tail->next = current;
    }
    tail = current;
    length++;
}


template <class T>
T LinkedList<T>::removeStart() {
  if(length == 0) {
      throw out_of_range("Can't removeStart from empty list");
  }

  ListNode<T>* nodeToDelete = head;
  T value = nodeToDelete->data;

  head = head->next;
  delete nodeToDelete;
  length--;

  if(length == 0)
      tail = nullptr;

  return value;
}

template <class T>
T LinkedList<T>::retrieveStart() {
  if(length == 0) {
      throw out_of_range("Can't retrieveStart from empty list");
  }
  return head->data;
}



#endif
