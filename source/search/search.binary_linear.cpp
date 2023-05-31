#include "../../include/stdafx.h"

std::pair<int, MyErr*> BinarySearch::binarySearchLinear(int val) {
    if (!this->isReady()) { // array is not in sorting status
        return {-1, new MyErr("Can not search in this array!")};
    }

    int left = 0, right = this->size - 1;

    while (left <= right) {
        int middle = left + ((right - left) / 2);

        if (this->arr[middle] == val) {
            return {middle, new MyErr()};
        }

        if (this->arr[middle] < val) { // ignore left side
            left = middle + 1;
        } else { // ignore right side
            right = middle -1;
        }
    }

    return {-1, new MyErr("Not found")};
}

std::pair<int, MyErr*> BinarySearch::binarySearchLinear(int left, int right, int val) {
    if (!this->isReady()) { // array is not in sorting status
        return {-1, new MyErr("Can not search in this array!")};
    }

    while (left <= right) {
        int middle = left + ((right - left) / 2);

        if (this->arr[middle] == val) {
            return {middle, new MyErr()};
        }

        if (this->arr[middle] < val) { // ignore left side
            left = middle + 1;
        } else { // ignore right side
            right = middle -1;
        }
    }

    return {-1, new MyErr("Not found")};
}

