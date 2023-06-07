#include "../../include/stdafx.h"

Node* BST::getRoot() { return this->root; }

void BST::insert(int data) {
    Node* pNode = new Node(data);

    if (this->root == nullptr) {
        this->root = pNode;

        return;
    }

    Node* head = this->root;
    while (head) {
        if (head->data > data) {
            if (head->left != nullptr) {
                head = head->left;
            } else {
                head->left = pNode;
                return;
            }
        } else {
            if (head->right != nullptr) {
                head = head->right;
            } else {
                head->right = pNode;

                return;
            }
        }
    }
}

void BST::supportRemove2Children(
    Node* tRoot) {  // use when delete node has 2 children
    Node* successor = tRoot->right;
    while (successor->left) {
        successor = successor->left;
    }

    std::swap(tRoot->data, successor->data);
    this->remove(successor->data);
}

void BST::supportRemoveNoChild(Node* tParent, int data) {
    if (tParent->left && tParent->left->data == data) {
        Node* tDelete = tParent->left;

        if (!tDelete->left && !tDelete->right) {
            tParent->left = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }
    } else {
        Node* tDelete = tParent->right;

        if (!tDelete->left && !tDelete->right) {
            tParent->right = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }
    }
}

void BST::remove(int data) {
    if (this->root == nullptr) {
        return;
    }

    if (this->root->data == data) {
        // Case 1: No child
        if (!this->root->left && !this->root->right) {
            delete this->root;
            this->root = nullptr;

            return;
        }

        // Case 2: 1 child
        if (!this->root->left) {
            Node* temp = this->root;
            this->root = this->root->right;

            delete temp;
            temp = nullptr;
            return;
        }

        if (!this->root->right) {
            Node* temp = this->root;
            this->root = this->root->left;

            delete temp;
            temp = nullptr;
            return;
        }

        // Case 3: 2 children
        this->supportRemove2Children(this->root);

        return;
    }

    Node* tParentDelete = this->getRoot();

    while (tParentDelete) {
        if (tParentDelete->left && tParentDelete->left->data == data) {
            break;
        }

        if (tParentDelete->right && tParentDelete->right->data == data) {
            break;
        }

        if (tParentDelete->data < data) {
            tParentDelete = tParentDelete->right;
        } else {
            tParentDelete = tParentDelete->left;
        }
    }

    if (!tParentDelete) {
        std::cout << "Not found!\n";
        return;
    }

    Node* tDelete = nullptr;
    if (tParentDelete->left && tParentDelete->left->data == data) {
        tDelete = tParentDelete->left;

        // Case 1: Delete node is a leaf
        this->supportRemoveNoChild(tParentDelete, tDelete->data);

        // Case 2: Delete node has 1 child
        if (!tDelete->left) {
            Node* tChild = tDelete->right;
            tParentDelete->left = tChild;

            tDelete->right = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }

        if (!tDelete->right) {
            Node* tChild = tDelete->left;
            tParentDelete->left = tChild;

            tDelete->left = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }
    } else {
        tDelete = tParentDelete->right;

        // Case 1: Delete node is a leaf
        this->supportRemoveNoChild(tParentDelete, tDelete->data);

        // Case 2: Delete node has 1 child
        if (!tDelete->left) {
            Node* tChild = tDelete->right;
            tParentDelete->right = tChild;

            tDelete->right = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }

        if (!tDelete->right) {
            Node* tChild = tDelete->left;
            tParentDelete->right = tChild;

            tDelete->left = nullptr;
            delete tDelete;
            tDelete = nullptr;

            return;
        }
    }

    // Case 3: Delete node has 2 children
    /*
        Step 1: find successor
        Step 2: swap tDelete->data vs successor->data
        Step 3: call remove(sucessor->data)
    */
    this->supportRemove2Children(tDelete);
}

bool BST::isEmpty() {
    if (this->root == nullptr) {
        return true;
    }

    return false;
}

bool BST::find(int data) {
    if (this->root == nullptr) {
        return false;
    }

    if (this->root->data == data) {
        return true;
    }

    Node* tRoot = this->getRoot();

    while (tRoot) {
        if (tRoot->data == data) {
            return true;
        }

        if (tRoot->data < data) {
            tRoot = tRoot->right;
        } else {
            tRoot = tRoot->left;
        }
    }

    return false;
}

void BST::inorder(Node* _root) {
    // Left Node Right
    if (_root == nullptr) {
        return;
    }

    this->inorder(_root->left);
    std::cout << _root->data << " ";
    this->inorder(_root->right);
}

void BST::preorder(Node*) {}

void BST::postorder(Node*) {}
