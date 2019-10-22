#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

const int QUEUE_INIT_SIZE = 8;

template <class T>
class Queue {
private:
    T *list;          //array to hold the list elements
    int arraySize;    //capacity of array used for storage

    int start;      //index of the head of the queue
    int end;        //index of the tail of the queue

    //Helper function to add additional space
    void grow();

public:
    void enqueue(const T& value);
    T dequeue();
    bool empty() const;
    bool full() const;

    Queue();

    ~Queue();

    //Disable copy ctor and assignment to avoid accidental use
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);


    //Defined inside class to avoid template/friend ugliness
    friend ostream& operator<<(ostream& os, Queue<T>& theQueue) {
        os << "Start: " << theQueue.start << " End: " << theQueue.end << " arraySize: " << theQueue.arraySize << endl;

        int length = theQueue.end - theQueue.start;
        bool wrapped = false;       //does queue wrap wround back of array?
        if(length < 0)
            wrapped = true;

        for(int i = 0; i < theQueue.arraySize; i++) {
            if( (wrapped && (i < theQueue.end || i >= theQueue.start)) ||
                (!wrapped && (i < theQueue.end && i >= theQueue.start)) )
                os << theQueue.list[i] << " ";
            else
                os << "_ ";
        }
        cout << endl;
        return os;
    }
};


template <class T>
void Queue<T>::enqueue(const T& value) {
    if( full() ) {
        grow();
    }

    ///TODO - fixme
}

template <class T>
T Queue<T>::dequeue() {
    if( empty() ) {
        throw out_of_range("Dequeue on empty queue");
    }


    ///TODO - fixme

    return 0; //FIXME
}


template <class T>
bool Queue<T>::empty() const {
    if(end == start)
        return true;
    else
        return false;
}


template <class T>
bool Queue<T>::full() const {

    ///TODO - return true or false based on logic

    return false;  //FIXME
}

template <class T>
void Queue<T>::grow() {

    ///TODO - allocate new storage, copy over values, update variables, clean up old storage

}






///-------------------Constructors/Destructor----------------
template <class T>
Queue<T>::Queue() {
    arraySize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    list = new T[arraySize];
}

template <class T>
Queue<T>::~Queue() {
    delete [] list;
}


#endif // QUEUE_H

