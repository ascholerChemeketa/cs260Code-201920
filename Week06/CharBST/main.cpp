#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CharBST.h"

using namespace std;


void testPrint();
void testFindIt();
void testFindRec();
void testInsertIt();
void testInsertRec();

int main()
{
    testPrint();
    ////Uncomment to test indicated function
//    testFindIt();
//    testFindRec();
//    testInsertIt();
//    testInsertRec();

    ///---------------------Clean up---------------------------
    if(BSTNode<char>::nodeCount != 0)
        cout << "You made " << BSTNode<char>::nodeCount << " node(s) of garbage" << endl;
}

void testPrint() {
    CharBST myBST;

    myBST.insertFakeData();

    myBST.print();
    cout << endl;
    cout << "-----------------------------------------" << endl;
}

void testFindIt() {
    CharBST myBST;

    myBST.insertFakeData();

    myBST.print();
    cout << endl;
    cout << "Checking what it contains:" << endl;
    for(char c = 'A'; c <= 'Z'; ++c)
        cout << c << " ";
    cout << endl;
    for(char c = 'A'; c <= 'Z'; ++c)
        cout << myBST.containsIterative(c) << " ";

    cout << endl;
    cout << "-----------------------------------------" << endl;
}

void testFindRec() {
    CharBST myBST;

    myBST.insertFakeData();

    myBST.print();
    cout << endl;
    cout << "Checking what it contains:" << endl;
    for(char c = 'A'; c <= 'Z'; ++c)
        cout << c << " ";
    cout << endl;
    for(char c = 'A'; c <= 'Z'; ++c)
        cout << myBST.containsRecursive(c) << " ";

    cout << endl;
    cout << "-----------------------------------------" << endl;
}

void testInsertIt() {
    CharBST myBST;

    srand(time(nullptr));

    cout << "Inserting into empty BST: " << endl;
    for(int i = 0; i < 10; i++) {
        char randChar = static_cast<char>('A' + rand() % 26);
        cout << randChar << " ";
        myBST.insertIterative(randChar);
    }

    cout << endl;
    cout << "Final contents: " << endl;
    myBST.print();

    cout << endl;
    cout << "-----------------------------------------" << endl;
}

void testInsertRec() {
    CharBST myBST;

    srand(time(nullptr));

    cout << "Inserting into empty BST: " << endl;
    for(int i = 0; i < 10; i++) {
        char randChar = static_cast<char>('A' + rand() % 26);
        cout << randChar << " ";
        myBST.insertRecursive(randChar);
    }

    cout << endl;
    cout << "Final contents: " << endl;
    myBST.print();

    cout << endl;
    cout << "-----------------------------------------" << endl;
}

