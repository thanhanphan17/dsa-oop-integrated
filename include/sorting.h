#pragma once

class SortingAlgorithm {
private:
    int *arr;
    int size;

    void heapify(int, int);
    void merge(int, int, int);
    void mergeSort(int, int);
    int partition(int, int);
    void quickSort(int, int);

public:
    SortingAlgorithm();
    SortingAlgorithm(int[], int);
    ~SortingAlgorithm();

    void printArray();
    void insertionSort();
    void heapSort();
    void mergeSort();
    void quickSort();
};
