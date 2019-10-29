#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CharBST.h"

using namespace std;


void testCopy();
void testFindSmallest();
void testRemoveSmallest();
void demonstrateRemove();

int main()
{

//    testCopy();

//    testFindSmallest();

//    testRemoveSmallest();

////Remove depends on your findSmallest implementation
//    demonstrateRemove();


    ///---------------------Clean up---------------------------
    if(BSTNode<char>::nodeCount != 0)
        cout << "You made " << BSTNode<char>::nodeCount << " node(s) of garbage" << endl;
}


void testCopy() {


    cout << "Testing copy - should see two copies of same tree:" << endl;
    {
        //Nested scope - trees here will disapear early
        CharBST myBST;
        myBST.insertFakeData();
        myBST.print();
        cout << endl;

        CharBST myBST2(myBST);      //Use copy constructor
        myBST2.print();
        cout << endl;


        cout << "Removing all nodes from copy's right side:" << endl;
        deleteSubTree( myBST2.getRoot()->right );
        myBST2.getRoot()->right = nullptr;
        myBST2.print();
        cout << endl;

        cout << "Original should be unaffected" << endl;
        myBST.print();
        cout << endl;

    }
    //Trees destructed here...

    cout << "-----------------------------------------" << endl;
}


void testFindSmallest() {
    CharBST myBST;

    myBST.insertFakeData();

    BSTNode<char>* rootNode = myBST.getRoot();

    cout << "Getting smallest value from tree - should be C:" << endl;
    char smallestFromRoot = smallestValueFrom(rootNode);
    cout << smallestFromRoot << endl;


    cout << "Getting smallest value from right side of tree - should be J:" << endl;
    char smallestFromRight = smallestValueFrom(rootNode->right);
    cout << smallestFromRight << endl;

    cout << "-----------------------------------------" << endl;
}


void testRemoveSmallest() {
    CharBST myBST;

    myBST.insertFakeData();

    cout << "Removing smallest node repeatedly until tree is empty:" << endl;

    while(myBST.getRoot() != nullptr) {
        myBST.removeSmallestValue();
        myBST.print();
        cout << endl;
    }
    cout << "-----------------------------------------" << endl;
}


void demonstrateRemove() {

    cout << "Demonstrating Remove(C)" << endl;
    {
        CharBST myBST;
        myBST.insertFakeData();
        myBST.print();
        cout << endl;
        myBST.remove('C');
        myBST.print();
        cout << endl;
    }

    cout << "Demonstrating Remove(G)" << endl;
    {
        CharBST myBST;
        myBST.insertFakeData();
        myBST.print();
        cout << endl;
        myBST.remove('G');
        myBST.print();
        cout << endl;
        cout << "Root now has " << myBST.getRoot()->value;
        cout << endl;
    }

    cout << "-----------------------------------------" << endl;
}


