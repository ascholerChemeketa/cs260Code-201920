#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList<int> myList;
    myList.insertAt(0, 5);
    myList.insertAt(0, 2);
    myList.insertAt(0, 8);
    myList.insertAt(2, 15);
    cout << myList;         //Expect 8 2 15 5

    myList.removeAt(2);
    cout << myList;         //Expect 8 2 5

    myList.removeAt(0);
    cout << myList;         //Expect 2 5

    return 0;
}
