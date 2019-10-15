#include <iostream>

#include "SimpleLinkedList.h"

using namespace std;


int main()
{
    {
        int x = 1;
    }

    x = 2;

    {   //create scope for l to live in

        SimpleLinkedList l;
        l.insertStart(15);
        l.insertStart(3);
        l.insertStart(10);
        l.insertStart(6);


        cout << "Printing list in order:" << endl;
        l.print();

        cout << "Printing total of list: ";
        cout << l.getTotal() << endl;

        cout << "Printing item at index 2: ";
        cout << l.retrieveAt(2) << endl;

        cout << "Removing last..." << endl;
        l.removeLast();
        l.print();

        //---------------------------------------

        cout << "Printing list in reverse order:" << endl;
        l.reversePrint();

        cout << "Printing largest value: ";
        cout << l.getMaxValue() << endl;

        cout << "Removing item at index 1..." << endl;
        l.removeAt(1);
        l.print();

    } //l goes out of scope here - destructor called

}
