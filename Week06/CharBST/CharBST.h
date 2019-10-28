#ifndef CHARBST_H
#define CHARBST_H

#include "BSTNode.h"

class CharBST {
private:
    BSTNode<char>* root;

    ///Helper function for cleaning up memory
    void deleteSubTree(BSTNode<char>* startNode);

public:
    ///Constructor - root inited to null
    CharBST();
    ///Destructor - deletes any child nodes
    ~CharBST();

    ///Make some nodes by hand
    void insertFakeData();

    ///in order print
    void print() const;

    ///check if value is present
    bool containsRecursive(char val) const;
    bool containsIterative(char val) const;

    ///add (a possibly duplicate) value to tree
    void insertRecursive(char val);
    void insertIterative(char val);

    ///Disable copy/assignment - these are declared but not defined
    CharBST(const CharBST& val);
    CharBST& operator=(const CharBST& val);
};

#endif // CHARBST_H

