#include "../../include/search.h"


std::pair<int, MyErr*> BinarySearch::binarySearchRecursion(int val) {
    if (!this->isReady()) { // array is not in sorting status
        return {-1, new MyErr("Can not search in this array!")};
    }
    
    return this->binarySearchRecursion(0, this->size - 1, val);
}

std::pair<int, MyErr*> BinarySearch::binarySearchRecursion(int left, int right, int val) {
    int middle = left + ((right - left) / 2);

    if (left <= right) {
        if (this->arr[middle] == val) {
            return {middle, new MyErr()};
        }

        if (this->arr[middle] > val) {
            return binarySearchRecursion(left, middle - 1, val);
        } else {
            return binarySearchRecursion(middle + 1, right, val);
        }
    }

    return {-1, new MyErr("Not found!")};
}