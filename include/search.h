#pragma once
#include <iostream>
#include "errordefine.h"

class BinarySearch {
private:
    int* arr;
    int size;
    bool isReady();

public:
    BinarySearch();
    ~BinarySearch();
    BinarySearch(int*, int);

    std::pair<int, MyErr*> binarySearchLinear(int); // Search all array
    // std::pair<int, bool> binarySearchLinear(int, int, int); // Search in segment

    int binarySearchRecursion(int); // Search all array
    int binarySearchRecursion(int, int, int); // Search in segment
 };

/*
find 8 
size = 10
      8  
    7 8 

*/