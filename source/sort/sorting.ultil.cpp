#include "../../include/stdafx.h"

void SortingAlgorithm::printArray() {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->arr[i] << ' ';
    }
}
