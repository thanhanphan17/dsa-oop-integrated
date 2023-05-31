#include "../include/stdafx.h"

void testSort();
void testSearch();

int main() {
    testSearch();

    return 0;
}

void testSort() {
    int arr[] = {1, 4, 2, 3, 5, 6, 2, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    SortingAlgorithm sa(arr, n);
    sa.printArray();
    std::cout << "\n";
    sa.radixSort();
    sa.printArray();
}

void testSearch() {
    int arr[] = {1, 2, 3, 5, 6, 9, 12, 17};
    int n = sizeof(arr) / sizeof(int);

    BinarySearch bs(arr, n);

    std::pair<int, MyErr*> result = bs.binarySearchRecursion(1, n - 1, 17);

    if (result.second->err != nullptr) {
        std::cout << result.second->Error() << "\n";
    } else {
        std::cout << result.first << "\n";
    }
}