#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cassert>

#include "CharBST.h"
#include "CharBSTIterator.h"

using namespace std;


void testToVector();
void testIteratorConstructor();
void testIterator();

int main()
{
    testToVector();
    testIteratorConstructor();
    testIterator();
}

void testToVector() {
    cout << "Testing toVector:" << endl;
    CharBST myBST;
    myBST.insertFakeData();
    cout << "The tree: " << endl;
    myBST.print();
    cout << endl;

    vector<char> myList = myBST.toVector();

    cout << "The vector: " << endl;
    for(char c : myList)
        cout << c << " ";

    cout << endl;
    cout << "-----------------------------------------" << endl;
}

void testIteratorConstructor() {
    cout << "Testing iterator constructor. Should show: C G [END]" << endl;
    CharBST myBST;
    myBST.insertFakeData();
    cout << endl;

    CharBSTIterator it = myBST.begin();
    it.printDebug();
    cout << endl;

    cout << "-----------------------------------------" << endl;
}

void testIterator() {
    cout << "Testing iterator - shifting each letter by one:" << endl;
    CharBST myBST;
    myBST.insertFakeData();
    cout << "Starting tree: " << endl;
    myBST.print();
    cout << endl;

    int loopStopper = 0;

    for(CharBSTIterator it = myBST.begin(); it != myBST.end(); ++it) {
        ///----------Debug stuff-------
        cout << "Working with " << *it << " - curent stack is ";
        it.printDebug();
        cout << endl;

        //Prevent infinite loop
        assert(loopStopper++ < 20);  //iterator isn't advancing correctly if we haven't hit end by now...
        ///----------End Debug---------


        *it = static_cast<char>(*it  + 1);  //Shift current letter by one
    }

    cout << "Ending tree: " << endl;
    myBST.print();
    cout << endl;

    cout << endl;
    cout << "-----------------------------------------" << endl;
}
