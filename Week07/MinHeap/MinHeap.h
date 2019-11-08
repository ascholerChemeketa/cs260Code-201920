#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

class MinHeap
{
private:
    int* data;      //array containing the heap
    int capacity;   //maximum size
    int heapSize;   //current logical size

    ///--------------Heap helper functions--------------
    int getLeftChildIndex(int index);      //get index of left child
    int getRightChildIndex(int index);     //get index of right child
    int getParentIndex(int index);         //get index of parent

public:
    void clear();
    int getTop();
    int removeTop();
    void add(int value);


    MinHeap();                          //capacity of 100
    MinHeap(int maxItems);
    virtual ~MinHeap();
    MinHeap(const MinHeap& other);
    MinHeap& operator=(const MinHeap& other);

    friend std::ostream& operator<<(std::ostream& os, const MinHeap& theHeap);

};

#endif // MINHEAP_H
