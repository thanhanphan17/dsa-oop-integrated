#include "../../include/stdafx.h"

int HashTable::hash(int key) {
    return key % this->capacity;
}

void HashTableChaining::showTable() {
    for (int i = 0; i < this->capacity; ++i) {
        std::cout << i << ": ";
        this->showLinkedList(HT[i]);
        std::cout << "\n";
    }
}

void HashTableChaining::showLinkedList(HashTableChaining::Node *head) {
    if (head == nullptr) {
        return;
    }

    HashTableChaining::Node* pNode = head;

    while (pNode != nullptr) {
        std::cout << pNode->data << " ";
        pNode = pNode->pNext;
    }
}

bool HashTableChaining::find(int index, int key) {
    Node* head = this->HT[index];

    if (head == nullptr) {
        return false;
    }

    while (head != nullptr) {
        if (head->data == key) {
            return true;
        }
        head = head->pNext;
    }

    return false;
}   

void HashTableChaining::deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->pNext;
        delete temp;
        temp = nullptr;
    }
}
