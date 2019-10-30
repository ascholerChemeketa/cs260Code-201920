
#ifndef CHARBSTITERATOR_H
#define CHARBSTITERATOR_H

#include <vector>
#include "BSTNode.h"

//Forward declate CharBST so we can make it a friend
class CharBST;

class CharBSTIterator
{
    //give CharBST access to private information
    friend class CharBST;

private:
    //Vector used as a stack:
    std::vector< BSTNode<char>* > positionStack;

public:
    //Constructor - takes node to use as root
    // nullptr signifies that this should be an end iterator
    CharBSTIterator(BSTNode<char>* root);

    //Compare two iterators with ==
    bool operator==(const CharBSTIterator& other) const;

    //Compare two iterators with !=
    bool operator!=(const CharBSTIterator& other) const;

    //Dereference iterator to retrieve data in current node
    // return reference to allow modification
    char& operator*();

    //Advance iterator position by one
    CharBSTIterator operator++();

    //Dumps contents of stack to cout
    void printDebug();
};

#endif
