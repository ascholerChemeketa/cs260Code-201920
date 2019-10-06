#include <iostream>

#include "LinkedList.h"

using namespace std;

void testDestructor() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertStart(3);
    myList.insertStart(2);
    myList.insertStart(1);
    cout << "Destroying list of three nodes..." << endl;
}

void testCopyCtor() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertStart(3);
    myList.insertStart(2);
    myList.insertStart(1);

    cout << "Making copy of 1, 2, 3... and adding 5 to copy" << endl;
    LinkedList<int> list2(myList);       //call copy constructor
    list2.insertStart(5);

    cout << "Original (should be 1, 2, 3):" << endl;
    myList.print();
    cout << "Copy (should be 5, 1, 2, 3):" << endl;
    list2.print();
}

void testAssignment() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertStart(3);
    myList.insertStart(2);
    myList.insertStart(1);

    //Make a new list, put things in it
    LinkedList<int> list2;
    list2.insertStart(12);
    list2.insertStart(13);

    cout << "Doing assignment... and adding 5 to copy" << endl;
    list2 = myList;         //should wipe out list2's contents, replace with COPY of nodes from myList
    list2.insertStart(5);

    cout << "Original (should be 1, 2, 3):" << endl;
    myList.print();
    cout << "Copy (should be 5, 1, 2, 3):" << endl;
    list2.print();
}

void testInsertEnd() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertEnd(3);
    cout << "InsertedEnd (should be 3 with 3 as tail):" << endl;
    myList.print();

    myList.insertEnd(5);
    cout << "InsertedEnd (should be 3 5 with 5 as tail):" << endl;
    myList.print();
}


void testRemoveFirst() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertStart(4);
    myList.insertStart(2);

    myList.removeFirst();
    cout << "RemovedFirst (should be 4 with 4 as tail):" << endl;
    myList.print();

    myList.removeFirst();
    cout << "RemovedFirst (should be empty with nullptr as tail):" << endl;
    myList.print();
}

void testInsertAt() {
    cout << "--------------------------------------------" << endl;
    LinkedList<int> myList;
    myList.insertAt(0, 5);
    cout << "Inserted 5 at 0 (should be 5 with 5 as tail):" << endl;
    myList.print();

    myList.insertAt(1, 10);
    cout << "Inserted 10 at 1 (should be 5 10 with 10 as tail):" << endl;
    myList.print();

    myList.insertAt(1, 8);
    cout << "Inserted 8 at 1 (should be 5 8 10 with 10 as tail):" << endl;
    myList.print();
}


int main()
{
    testDestructor();
    testCopyCtor();
    testAssignment();

    testInsertEnd();
    testRemoveFirst();
    testInsertAt();

    return 0;
}
