#include "../include/stdafx.h"

int main() {
    int arr[] = {1, 4, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    SortingAlgorithm sa(arr, n);
    sa.printArray();
    std::cout << "\n";
    sa.mergeSort();
    sa.printArray();

    return 0;
}