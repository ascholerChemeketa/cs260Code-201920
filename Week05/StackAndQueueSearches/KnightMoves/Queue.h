#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <list>

using namespace std;

///Implements a Queue with a linked list
template <class T>
class Queue {
private:
    list<T> storage;

public:
    void enqueue(const T& value);
    T dequeue();
    bool empty();
    bool full();

    //No memory management

    //Defined inside class to avoid template/friend ugliness
    friend ostream& operator<<(ostream& os, Queue<T>& theQueue) {
        cout << "[" << endl;
        for(auto it = theQueue.storage.begin(); it != theQueue.storage.end(); ++it)
            cout << *it << endl;
        cout << "]" << endl;
        return os;
    }
};


template <class T>
void Queue<T>::enqueue(const T& value) {
    storage.push_back(value);
}

template <class T>
T Queue<T>::dequeue() {
    if( empty() )
        throw out_of_range("Dequeue on empty queue");

    T temp = storage.front();
    storage.pop_front();
    return temp;
}


template <class T>
bool Queue<T>::empty() {
    return storage.empty();
}




#endif // QUEUE_H

