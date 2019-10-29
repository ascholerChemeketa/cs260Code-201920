#ifndef CHARBST_H
#define CHARBST_H

#include "BSTNode.h"

class CharBST {
public:  //public so tester code can do some low level manipulation
    BSTNode<char>* root;

public:
    ///Constructor - root inited to null
    CharBST();
    ///Destructor - deletes any child nodes
    ~CharBST();
    ///Copy constructor and assignment operator do deep copy
    CharBST(const CharBST& val);
    CharBST& operator=(const CharBST& val);


    ///Make some nodes by hand
    void insertFakeData();

    ///in order print
    void print();

    ///check if value is present
    bool containsRecursive(char val);

    ///get smallest char in the tree - throw exception if empty
    char smallestValue();


    ///remove indicated char from tree
    void remove(char val);

    ///remove smallest value from tree
    void removeSmallestValue();

    ///return true if no values in tree
    bool isEmpty();

    //Provided to allow test code access to root
    BSTNode<char>* getRoot();
};


//Non-member helper functions - normally would not be declared in .h
// we are doing so so that the testing code can directly call
char smallestValueFrom(BSTNode<char>* curNode);
void deleteSubTree(BSTNode<char>* startNode);
BSTNode<char>* removeSmallestHelper(BSTNode<char>* startNode);


#endif // CHARBST_H

