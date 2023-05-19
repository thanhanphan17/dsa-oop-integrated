#pragma once

class SortingAlgorithm {
private:
    int *arr;
    int size;

    void heapify(int, int);
    void merge(int, int, int);
    void mergeSort(int, int);

public:
    SortingAlgorithm();
    SortingAlgorithm(int[], int);
    ~SortingAlgorithm();

    void printArray();
    void insertionSort();
    void heapSort();
    void mergeSort();
};
