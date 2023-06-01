#include "../../include/stdafx.h"


void HashTableChaining::add(int key) {
    int index = this->hash(key);

    this->insert(index, key);
}

void HashTableChaining::insert(int index, int key) {
    Node*& head = this->HT[index];
    Node* pNode = new Node(key);

    if (head == nullptr) {
        head = pNode;
        return;
    }

    pNode->pNext = head;
    head = pNode;
}

bool HashTableChaining::find(int key) {
    int index = this->hash(key);

    return this->find(index, key);
}

void HashTableChaining::remove(int key) {
    int index = this->hash(key);

    Node*& head = this->HT[index];

    if (head == nullptr) {
        return;
    }

    if (head->data == key) {
        Node* pNode = head; 
        head = head->pNext;
        delete pNode;
        pNode = nullptr;

        return;
    }

    Node* pNode = head;
    Node* pPrev = head;
    
    while (pNode) {
        pPrev = pNode;
        pNode = pNode->pNext;

        if (pNode && pNode->data == key) {
            pPrev->pNext = pNode->pNext;
            delete pNode;
            pNode = nullptr;

            return;
        }
    }
}


