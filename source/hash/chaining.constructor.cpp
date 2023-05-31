#include "../../include/stdafx.h"

HashTableChaining::HashTableChaining(int _capacity) : HashTable(_capacity) {
    this->HT = new Node*[this->capacity];

    for (int i = 0; i < this->capacity; ++i) {
        this->HT[i] = nullptr;
    }
}

HashTableChaining::~HashTableChaining() {
    for (int i = 0; i < this->capacity; ++i) {
        this->deleteList(this->HT[i]);
    }
    delete HT;
}