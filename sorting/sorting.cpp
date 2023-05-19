#include "stdafx.h"

SortingAlgorithm::SortingAlgorithm() {
    this->arr = new int[CAPACITY];
    this->size = 0;
}

SortingAlgorithm::~SortingAlgorithm() {
    delete[] this->arr;
    this->arr = nullptr;
}

SortingAlgorithm::SortingAlgorithm(int arr[], int size) {
    if (size > CAPACITY) {
        this->arr = new int[CAPACITY];
        for (int i = 0; i < CAPACITY; ++i) {
            this->arr[i] = arr[i];
        }

        this->size = CAPACITY;
        return;
    }
    this->arr = new int[size];
    for (int i = 0; i < size; ++i) {
        this->arr[i] = arr[i];
    }

    this->size = size;
}

void SortingAlgorithm::printArray() {
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->arr[i] << ' ';
    }
}

void SortingAlgorithm::insertionSort() {
    for (int i = 1; i < this->size; ++i) {
        int j = i;
        while (j > 0 && this->arr[j] < this->arr[j - 1]) {
            std::swap(this->arr[j], this->arr[j - 1]);
            j -= 1;
        }
    }
}

void SortingAlgorithm::heapify(int i, int _size) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < _size && arr[largest] < arr[left]) {
        largest = left;
    }

    if (right < _size && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        this->heapify(largest, _size);
    }
}

void SortingAlgorithm::heapSort() {
    for (int i = this->size / 2 - 1; i >= 0; --i) {
        this->heapify(i, this->size);
    }

    for (int i = this->size - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);

        this->heapify(0, i);
    }
}
