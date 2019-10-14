#include <iostream>
#include <algorithm>

#include "ArrayList.h"
#include "ArrayListIterator.h"
#include "DoublyLinkedList.h"
#include "LinkedListIterator.h"

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

bool isOdd(int x) {
    return x % 2 == 0;
}

int main()
{
    ArrayList<int> myList;
    for(int i = 1; i <= 20; i++)
        myList.insertEnd(i);

    cout << "Iterator based loop:" << endl;
    for( ArrayListIterator<int> it = myList.begin();
         it != myList.end();
         ++it )
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "ArrayList printed with std::for_each:" << endl;
    std::for_each(myList.begin(), myList.end(), print<int>);
    cout << endl;

    cout << "---------Use some other std::algorithms with ArrayListIterator---------" << endl;
    cout << "Max value: " << *std::max_element(myList.begin(), myList.end()) << endl;
    cout << "Sum is: " << std::accumulate(myList.begin(), myList.end(), 0) << endl;

    cout << "Replacing all odd values with 0" << endl;
    std::replace_if(myList.begin(), myList.end(), isOdd, 0);
    std::for_each(myList.begin(), myList.end(), print<int>);
    cout << endl;
    cout << "----------End ArrayList tests--------------" << endl;

////--------------Test basic linkedlist iterator features------------------

//    cout << "---------Test * and ++ operators on LinkedListOperator---------" << endl;
//    DoublyLinkedList<char> myLinkList;
//    for(char c = 'R'; c >= 'A'; c--)
//        myLinkList.insertAt(0, c);   //Make list with A-R

//    cout << "LinkedList printed with iterator:" << endl;
//    for_each(myLinkList.begin(), myLinkList.end(), print<char>);
//    cout << endl;


////--------------Test insert function-----------------
//    cout << "Inserting ? and # after the first item: " << endl;
//    LinkedListIterator<char> location = myLinkList.begin();  //pointer at index 0
//    ++location; //move to index 1
//    myLinkList.insert(location, '?');
//    myLinkList.insert(location, '#');

//    for_each(myLinkList.begin(), myLinkList.end(), print<char>);
//    cout << endl;

////--------------Test erase function-----------------
//    cout << "Attempting to delete 4 elements starting at 0" << endl;
//    LinkedListIterator<char> location2 = myLinkList.begin();
//    location2 = myLinkList.erase(location2);
//    location2 = myLinkList.erase(location2);
//    location2 = myLinkList.erase(location2);
//    location2 = myLinkList.erase(location2);

//    for_each(myLinkList.begin(), myLinkList.end(), print<char>);
//    cout << endl;

    ////--------------Test find function-----------------
//    cout << "Attempting to find/erase D:" << endl;
//    LinkedListIterator<char> location3 = myLinkList.findValue('D');
//    if( location3 != myLinkList.end() )
//        myLinkList.erase(location3);
//    for_each(myLinkList.begin(), myLinkList.end(), print<char>);

    return 0;
}
