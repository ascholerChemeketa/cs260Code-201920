#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Queue.h"

using namespace std;


char getChar() {
    static char nextChar = 'A' - 1;

    ++nextChar;
    if(nextChar > 'Z')
        nextChar = 'A';

    return nextChar;
}

int main() {
    Queue<char> q1;


///-----------------------TEST ENQUEUE---------------------------------
    cout << "Placing 6 items on queue..." << endl;
    for(int i = 0; i < 6; i++)
        q1.enqueue( getChar() );

    cout << q1;

///-----------------------TEST DEQUEUE---------------------------------
//    cout << endl << "Removing 5 things..." << endl;
//    for(int i = 0; i < 5; i++)
//        cout << q1.dequeue() << endl;
//    cout << q1;

///-----------------------TEST WRAP--------------------------------
//    cout << endl << "Placing 4 things on queue..." << endl;
//    for(int i = 0; i < 4; i++)
//        q1.enqueue( getChar() );
//    cout << q1;
//    cout << endl << "Removing 4 things..." << endl;
//    for(int i = 0; i < 4; i++)
//        cout << q1.dequeue() << endl;
//    cout << q1;


///-----------------------TEST FULL--------------------------------
//    cout << endl << "Starting empty queue, adding 7 things..." << endl;
//    Queue<char> q2;
//    for(int i = 0; i < 7; i++)
//        q2.enqueue( getChar() );

//    cout << "Should be full: ";
//    cout << (q2.full() ? "PASS" : "FAIL") << endl;

//    cout << "dequeue, should be not full:";
//    q2.dequeue();
//    cout << (!q2.full() ? "PASS" : "FAIL") << endl;

//    cout << "enqueue, should full again";
//    q2.enqueue( getChar() );
//    cout << (q2.full() ? "PASS" : "FAIL") << endl;

//    cout << "dequeue, should be not full ";
//    q2.dequeue();
//    cout << (!q2.full() ? "PASS" : "FAIL") << endl;

//    cout << "enqueue, should full again";
//    q2.enqueue( getChar() );
//    cout << (q2.full() ? "PASS" : "FAIL") << endl;

///-----------------------TEST GROW--------------------------------
//    //Make a new queue with 6 things that wrap around the array - tricky case
//    Queue<char> q3;
//    //Use up first 5 slots of array
//    for(int i = 0; i < 5; i++) {
//        q3.enqueue( getChar() );
//        q3.dequeue();
//    }
//    //Now add 6 items
//    for(int i = 0; i < 6; i++) {
//        q3.enqueue( getChar() );
//    }

//    cout << "Queue with 6 things currently:" << endl;
//    cout << q3;


//    cout << "Adding 4 items to force grow:" << endl;
//    for(int i = 0; i < 4; i++)
//        q3.enqueue( getChar() );
//    cout << q3;

    return 0;
}
