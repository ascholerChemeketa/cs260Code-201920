#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <vector>

using namespace std;

template <class T>
class Stack {
private:
    vector<T> store;
public:
    ///No need for special copy ctor/assignment operator/destrcutor
    ///   this class does not directly manage memoy

    void push(T value);
    T top() const;
    T pop();
    bool empty() const;
};


template <class T>
void Stack<T>::push(T value) {
    store.push_back(value);
}

template <class T>
T Stack<T>::top() const {
    return store.at(store.size() - 1);
    //or store.back()
}

template <class T>
T Stack<T>::pop() {
    if(empty())  {
        cout << "Popping empty stack!!!";
        assert(0);
    }

    T temp = store.back();
    store.pop_back();
    return temp;
}

template <class T>
bool Stack<T>::empty() const {
    return store.size() == 0;
}

#endif // STACK_H
