#include "CharBST.h"

#include <iostream>
#include <stdexcept>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

//Helper used by destructor and assignment operator
void deleteSubTree(BSTNode<char>* startNode) {
    if(startNode == nullptr)
        return;
    deleteSubTree(startNode->left);
    deleteSubTree(startNode->right);
    delete startNode;
}

//Helper used by copy ctor and assignment operator
BSTNode<char>* copySubTree(BSTNode<char>* currentNode) {
    //TODO - FIXME
    return nullptr;
}


CharBST::~CharBST() {
    deleteSubTree(root);
}

CharBST::CharBST(const CharBST& other) {
    root = copySubTree(other.root);
}

CharBST& CharBST::operator=(const CharBST& other) {
    if(this != &other) {
        //remove any existing nodes
        deleteSubTree(root);
        //copying nodes of other tree
        root = copySubTree(other.root);
    }
    return *this;
}

void CharBST::insertFakeData() {
    //delete any existing nodes
    deleteSubTree(root);

    root = new BSTNode<char>('G');
    root->left = new BSTNode<char>('C');
    root->left->right = new BSTNode<char>('F');
    root->right = new BSTNode<char>('P');
    root->right->right = new BSTNode<char>('Y');
    root->right->left = new BSTNode<char>('J');
    root->right->left->right = new BSTNode<char>('M');
}

///----------------------Print/Debugging----------------------------
///Nonmember helper function
void printHelper(BSTNode<char>* curNode) {
    if(curNode == nullptr)
        return;

    printHelper(curNode->left);
    cout << curNode->value << " ";
    printHelper(curNode->right);
}

void CharBST::print() {
    printHelper(root);
}



bool CharBST::isEmpty() {
    return root == nullptr;
}


//Provided to allow test code access to root
BSTNode<char>* CharBST::getRoot() {
    return root;
}


///----------------------Search---------------------------

bool containsHelper(BSTNode<char>* curNode, char valToFind) {
    if(curNode == nullptr)
        return false;
    if(curNode->value == valToFind)
        return true;

    if(curNode->value > valToFind)
        return containsHelper(curNode->left, valToFind);
    else
        return containsHelper(curNode->right, valToFind);
}

///recursive version
bool CharBST::containsRecursive(char valToFind) {
    return containsHelper(root, valToFind);
}



///----------------------RemoveSmallest---------------------------

//Recursive helper function to remove smallest value starting from indicated node
BSTNode<char>* removeSmallestHelper(BSTNode<char>* curNode)
{
    //TODO - FIXME - See worksheet
    return curNode;
}

void CharBST::removeSmallestValue() {
    if( isEmpty() )
        throw out_of_range("Can't remove from empty tree");

    root = removeSmallestHelper(root);
}



///----------------------Smallest---------------------------
//Recursive helper function to return smallest value starting from given node
char smallestValueFrom(BSTNode<char>* curNode)
{
    //TODO - FIXME - See worksheet
    return '?';
}


char CharBST::smallestValue() {
    if( isEmpty() )
        throw out_of_range("Can't get smallest in empty tree");

    return smallestValueFrom(root);
}


///----------------------Removal---------------------------
///Helper function for remove - chains down, until it finds node to
/// remove. Removes that node and repairs pointers on way back up
BSTNode<char>* removeHelper(BSTNode<char>* curNode, char valToRemove) {
    if(curNode == nullptr) {
        return nullptr;     //Value not in tree
    }
    else if(valToRemove < curNode->value) {
        curNode->left = removeHelper(curNode->left, valToRemove);
    }
    else if(curNode->value < valToRemove) {
        curNode->right = removeHelper(curNode->right, valToRemove);
    }
    else {
        //Found the value to remove

        //Case 0: No children - delete & return nullptr. Subcase of #1.
        //Case 1: No right child. Delete and return left child.
        //Handle both here:
        //TODO
        //If no right child, store pointer to left, delete current, return left

        //Case 2: No left child.
        //TODO
        //If no left child, store pointer to right, delete current, return right

        //Case 3: Two children. Swap in value of smallest value to right,
        curNode->value = smallestValueFrom(curNode->right);
        //Now delete that value from right subtree
        curNode->right = removeHelper(curNode->right, curNode->value);
    }

    return curNode;  //This node still exists. Return it back to caller.
}

void CharBST::remove(char value) {
    //new root is root that results from doing removeHelper
    root = removeHelper(root, value);
}
