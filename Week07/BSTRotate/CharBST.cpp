#include "CharBST.h"

#include <iostream>
#include <vector>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
    root = nullptr;
}

//recursively delete nodes starting from a given node
void CharBST::deleteSubTree(BSTNode<char>* startNode) {
    if(startNode == nullptr)
        return;
    deleteSubTree(startNode->left);
    deleteSubTree(startNode->right);
    delete startNode;
}

CharBST::~CharBST() {
    deleteSubTree(root);
}



void CharBST::insertFakeData() {
    if(root)            //delete any existing nodes
        delete root;

    root = new BSTNode<char>('G');
    root->left = new BSTNode<char>('C');
    root->left->right = new BSTNode<char>('F');
    root->right = new BSTNode<char>('P');
    root->right->right = new BSTNode<char>('Y');
    root->right->left = new BSTNode<char>('J');
}

///----------------------Print----------------------------
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


