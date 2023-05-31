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

