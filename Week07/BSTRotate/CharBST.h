#ifndef CHARBST_H
#define CHARBST_H

#include "BSTNode.h"

class CharBST {
public:  ///Public to allow testing of helper functions outside the class
    BSTNode<char>* root;

    ///Helper function for cleaning up memory
    void deleteSubTree(BSTNode<char>* startNode);

public:
    ///Constructors/assignment op
    CharBST();
    CharBST(const CharBST& other);
    CharBST& operator=(const CharBST& other);
    ///Destructor - deletes any child nodes
    ~CharBST();

    ///Make some nodes by hand
    void insertFakeData();

    ///in order print
    void print();

};


#endif // CHARBST_H

