#include <iostream>
#include <cstdlib>
#include <ctime>

#include "LinkedList.h"

using namespace std;

int main()
{
    {
        cout << "Testing slice on even sized list:" << endl;

        LinkedList<int> myList;
        myList.insertEnd(5);
        myList.insertEnd(6);
        myList.insertEnd(2);
        myList.insertEnd(4);

        cout << "Original: ";
        cout << myList;

        LinkedList<int> secondHalf = myList.sliceInHalf();

        cout << "1st Half: ";
        cout << myList;
        cout << "2nd Half: ";
        cout << secondHalf << endl;
    }

    {
        cout << "Testing slice on odd sized list:" << endl;

        LinkedList<int> myList;
        myList.insertEnd(6);
        myList.insertEnd(2);
        myList.insertEnd(4);

        cout << "Original: ";
        cout << myList;

        LinkedList<int> secondHalf = myList.sliceInHalf();

        cout << "1st Half: ";
        cout << myList;
        cout << "2nd Half: ";
        cout << secondHalf << endl;
    }


    ////---------------------Merge-----------------------

//    cout << endl << "Making two sorted lists:" << endl;
//    LinkedList<int> myList2a;
//    for(int i = 3; i <= 18; i += 3 )
//        myList2a.insertEnd(i);

//    LinkedList<int> myList2b;
//    for(int i = 2; i <= 10; i += 2 )
//        myList2b.insertEnd(i);

//    cout << "First: ";
//    cout << myList2a;
//    cout << "2nd : ";
//    cout << myList2b;

//    cout << endl << "Merging 2nd into first..." << endl;
//    myList2a.mergeIn(myList2b);
//    cout << "First: ";
//    cout << myList2a;
//    cout << "2nd: ";
//    cout << myList2b << endl;


    ////-------------MergeSort-----------------

//    cout << endl << "Making a list with random junk and sorting with mergesort:" << endl;
//    LinkedList<int> myList3;
//    for(int i = 0; i < 15; i++) {
//        myList3.insertEnd(rand()%100);
//    }
//    myList3.mergeSort();
//    cout << myList3;


    ////-------------QuickSort-----------------

//    cout << endl << "Making a list with random junk and sorting with quicksort:" << endl;
//    LinkedList<int> myList4;
//    for(int i = 0; i < 15; i++) {
//        myList4.insertEnd(rand()%100);
//    }
//    myList4.qSort();
//    cout << myList4;

    return 0;
}
