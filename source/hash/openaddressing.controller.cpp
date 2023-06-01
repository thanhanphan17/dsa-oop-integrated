#include "../../include/stdafx.h"

void HashTableOpenAddressing::add(int key) {
    int index = this->probing(key);
    this->HT[index] = key;
}

void HashTableOpenAddressing::showTable() {
    for (int i = 0; i < this->capacity; ++i) {
        std::cout << i << ": " << this->HT[i] << "\n";
    }
}
