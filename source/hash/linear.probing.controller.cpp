#include "../../include/stdafx.h"


bool LinearProbing::find(int key) {
    int index = this->hash(key);

    if (this->HT[index] == key) {
        return true;
    }

    int i = 0;
    while (this->HT[this->hash(index + i)]) {
        if (this->HT[this->hash(index + i)] == key) {
            return true;
        }
        ++i;

        if (i >= this->capacity) {
            break;
        }
    }

    return false;
}

void LinearProbing::remove(int key) {
    // Not neccessary
    // Suitable for inserting not removing
}

int LinearProbing::probing(int key) {
    int index = this->hash(key);
    int i = 0;
    while (this->HT[this->hash(index + i)]) {
        ++i;
    }

    return this->hash(index + i);
}