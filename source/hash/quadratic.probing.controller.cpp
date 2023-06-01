#include "../../include/stdafx.h"

bool QuadraticProbing::find(int key) {
    int index = this->hash(key);

    if (this->HT[index] == key) {
        return true;
    }

    int i = 0;
    while (this->HT[this->hash(index + i * i)]) {
        if (this->HT[this->hash(index + i * i)] == key) {
            return true;
        }
        ++i;

        if (i >= this->capacity) {
            break;
        }
    }

    return false;
}

void QuadraticProbing::remove(int) {

}

int QuadraticProbing::probing(int key                                                                                                                                                                   ) {
    int index = this->hash(key);
    int i = 0;
    while (this->HT[this->hash(index + i * i)]) {
        ++i;
    }

    return this->hash(index + i * i);
}