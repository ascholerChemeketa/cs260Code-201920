#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

struct ListNode {
    ListNode(int value);

    ListNode* next = nullptr;
    int data = 0;
};


class SimpleLinkedList
{
public:
    //Done:
    void insertStart(int value);
    void removeLast();
    int retrieveAt(int index);
    int getTotal();
    void print();

    //To implement:
    void reversePrint();
    int getMaxValue();
    void removeAt(int index);
    ~SimpleLinkedList();

private:
    ListNode* head = nullptr;
};

#endif // SIMPLELINKEDLIST_H
