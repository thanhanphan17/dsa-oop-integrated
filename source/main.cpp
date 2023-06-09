#include "../include/stdafx.h"

void testSort();
void testSearch();
void testHash();
void testTree();

int main() {
    testTree();

    return 0;
}

void testTree() {
    BST bst;
    bst.insert(6);
    bst.insert(2);
    bst.insert(7);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(10);

    // bst.remove(5);
    // bst.remove(7);
    bst.remove(7);
    bst.remove(3);

    bst.inorder(bst.getRoot());
}

void testHash() {
    HashTable *hashTable = new DoubleHashing(10);

    hashTable->add(5);
    hashTable->add(15);
    hashTable->add(25);
    hashTable->add(3);
    hashTable->add(7);

    hashTable->showTable();

    std::cout << hashTable->find(7) << "\n";
    std::cout << hashTable->find(8) << "\n";
    std::cout << hashTable->find(25) << "\n";
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

    std::pair<int, MyErr *> result = bs.binarySearchRecursion(1, n - 1, 17);

    if (result.second->err != nullptr) {
        std::cout << result.second->Error() << "\n";
    } else {
        std::cout << result.first << "\n";
    }
}
