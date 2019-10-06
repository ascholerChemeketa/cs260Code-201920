#include "SimpleLinkedList.h"

#include <iostream>

using namespace std;

#define while heckno
#define for youshouldntneedme


//---------------------------------------------
//Basic Functions
//---------------------------------------------
ListNode::ListNode(int value) {
    data = value;
}


void SimpleLinkedList::insertStart(int value) {
    ListNode* newNode = new ListNode(value);

    newNode->next = head;
    head = newNode;
}


//---------------------------------------------

void recursivePrint(ListNode* current) {
    if(current == nullptr)
        cout << endl;
    else {
        cout << current->data << " ";
        recursivePrint(current->next);
    }
}

void SimpleLinkedList::print() {
    recursivePrint(head);
}

//---------------------------------------------

int recursiveGetTotal(ListNode* current) {
    if(current == nullptr)
        return 0;
    else {
        int everyoneElse = recursiveGetTotal(current->next);
        int total = current->data + everyoneElse;
        return total;
    }
}


int SimpleLinkedList::getTotal()
{
    return recursiveGetTotal(head);
}


//---------------------------------------------


int recursiveRetrieveAt(ListNode* current, int stepsLeft) {
    //assert(current != nullptr) would be smart here
    if(stepsLeft == 0)
        return current->data;
    else {
        return recursiveRetrieveAt(current->next, stepsLeft - 1);
    }
}

int SimpleLinkedList::retrieveAt(int index) {
    return recursiveRetrieveAt(head, index);
}


//---------------------------------------------

ListNode* recursiveRemoveLast(ListNode* current) {
    if(current->next == nullptr) {
        delete current;
        return nullptr;
    }
    else {
        current->next = recursiveRemoveLast(current->next);
        return current;
    }
}

void SimpleLinkedList::removeLast() {
    if(head != nullptr)
        head = recursiveRemoveLast(head);
}



//---------------------------------------------
//---------------------------------------------
//---------------------------------------------

void recursiveReversePrint(ListNode* current) {
    cout << "TODO : reversePrint not implemented" << endl;
}

void SimpleLinkedList::reversePrint() {
    recursiveReversePrint(head);
    cout << endl;
}

//---------------------------------------------

int recursiveMax(ListNode* current) {
    cout << "TODO : recursiveMax not implemented" << endl;
    return 0;
}


int SimpleLinkedList::getMaxValue() {
    return recursiveMax(head);
}


//---------------------------------------------

void recursiveDelete(ListNode* current) {
    cout << "TODO : recursiveDelete not implemented" << endl;
}


SimpleLinkedList::~SimpleLinkedList()
{
    recursiveDelete(head);
    head = nullptr;
}


//---------------------------------------------

ListNode* recursiveRemoveAt(ListNode* current, int stepsLeft) {
    cout << "TODO : removeAt not implemented" << endl;
    return current;  //for now just return the head node
}

void SimpleLinkedList::removeAt(int index) {
    head = recursiveRemoveAt(head, index);
}


