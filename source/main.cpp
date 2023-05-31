#include "../include/stdafx.h"

void testSort();
void testSearch();
void testHash();

int main() {
    testHash();

    return 0;
}

void testHash() {
    HashTableChaining ht(10);
    ht.add(5);
    ht.add(15);
    ht.add(3);
    ht.add(7);

    ht.showTable();    

    std::cout << ht.find(7) << "\n";
    std::cout << ht.find(8) << "\n";
    std::cout << ht.find(5) << "\n";
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