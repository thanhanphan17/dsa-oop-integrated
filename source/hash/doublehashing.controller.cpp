#include "../../include/stdafx.h"

bool DoubleHashing::find(int key) {
    int index = this->hash(key);

    if (this->HT[index] == key) {
        return true;
    }

    int i = 0;
    while (this->HT[this->hash(index + i * this->hash2(key))]) {
        if (this->HT[this->hash(index + i * this->hash2(key))] == key) {
            return true;
        }
        ++i;

        if (i >= this->capacity) {
            break;
        }
    }

    return false;
}

void DoubleHashing::remove(int) {}

int DoubleHashing::hash2(int key) { return (key % (this->capacity - 1)) + 1; }

int DoubleHashing::probing(int key) {
    int index = this->hash(key);

    if (this->HT[index] == 0) {
        return index;
    }

    int i = 0;

    while (this->HT[this->hash(index + i * this->hash2(key))] != 0) {
        ++i;
    }

    return this->hash(index + i * this->hash2(key));
}