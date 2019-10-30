#ifndef CHARBST_H
#define CHARBST_H

#include <vector>
#include "BSTNode.h"
#include "CharBSTIterator.h"

class CharBST {
public:  ///Public to allow testing of helper functions outside the class
    BSTNode<char>* root;

    ///Helper function for cleaning up memory
    void deleteSubTree(BSTNode<char>* startNode);

public:
    ///Constructors/assignment op
    CharBST();
    //Copy ctor and assignment operator declared to prevent accidental use
    CharBST(const CharBST& other);
    CharBST& operator=(const CharBST& other);

    ///Destructor - deletes any child nodes
    ~CharBST();

    ///Make some nodes by hand
    void insertFakeData();

    ///in order print
    void print();


    ///create a vector with contents of tree
    std::vector<char> toVector();

    ///get iterators to the tree
    CharBSTIterator begin();
    CharBSTIterator end();
};

#endif // CHARBST_H

