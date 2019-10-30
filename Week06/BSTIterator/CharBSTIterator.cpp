
#include <iostream>
#include "CharBSTIterator.h"

using namespace std;

//Constructor - takes node to use as root
// nullptr signifies that this should be an end iterator
CharBSTIterator::CharBSTIterator(BSTNode<char>* root)
{
    //nullptr is the last thing we should see - marks the end of the traversal
    positionStack.push_back(nullptr);

    //starting from root, go as far left as we can pushing node pointers
    BSTNode<char>* current = root;
    while( current != nullptr ) {
        positionStack.push_back(current);
        current = current->left;
    }
}

void CharBSTIterator::printDebug() {

    for(int i = positionStack.size() - 1; i >= 0; i--) {
        BSTNode<char>* current = positionStack[i];
        if(current != nullptr)
            std::cout << current->value << " ";
    }
     std::cout << "[END]";  //end
}

//Compare two iterators with ==
bool CharBSTIterator::operator==(const CharBSTIterator& other) const
{
    return positionStack.back() == other.positionStack.back();
}

//Compare two iterators with !=
bool CharBSTIterator::operator!=(const CharBSTIterator& other) const
{
    return positionStack.back() != other.positionStack.back();
}

//Dereference iterator to retrieve data in current node
// return reference to allow modification
char& CharBSTIterator::operator*()
{
    return positionStack.back()->value;
}

//Advance iterator position by one
CharBSTIterator CharBSTIterator::operator++()
{
    //remove top pointer from stack
    BSTNode<char>* oldNode = positionStack.back();
    positionStack.pop_back();

    //if it has a right child, go left from it as far as you can pushing pointers
    BSTNode<char>* current = oldNode->right;
    while(current != nullptr) {
        positionStack.push_back(current);
        current = current->left;
    }

    return *this;
}

