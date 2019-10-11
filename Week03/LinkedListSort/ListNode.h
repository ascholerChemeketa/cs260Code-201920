#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
struct ListNode
{
	T data;
    ListNode<T>* next;

	ListNode() {
        next = nullptr;
	    //Call default constructor for type T
	    //  produces 0 for primitive types
	    data = T();
	}

	ListNode(T value) {
        next = nullptr;
	    data = value;
	}
};


#endif // LISTNODE_H
