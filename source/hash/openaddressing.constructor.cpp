#include "../../include/stdafx.h"


HashTableOpenAddressing::HashTableOpenAddressing(int _capacity) : HashTable(_capacity) {
    this->HT = new int[this->capacity];

    for (int i = 0; i < this->capacity; ++i) {
        this->HT[i] = 0;
    }
}

HashTableOpenAddressing::~HashTableOpenAddressing() {
    delete[] this->HT;
    this->HT = nullptr;
}

LinearProbing::LinearProbing(int _capacity) : HashTableOpenAddressing(_capacity) {}
QuadraticProbing::QuadraticProbing(int _capacity) : HashTableOpenAddressing(_capacity) {};
