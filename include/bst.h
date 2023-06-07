#pragma once
#include "binarytreenode.h"

class BST {
private:
    Node* root;
    void supportRemove2Children(Node*);
    void supportRemoveNoChild(Node*, int);

public:
    BST();
    ~BST();

    void insert(int);
    void remove(int);

    bool isEmpty();
    bool find(int);

    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);

    Node* getRoot();
};