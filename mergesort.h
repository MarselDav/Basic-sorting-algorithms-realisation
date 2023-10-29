#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>

class MergeSort
{
public:
    MergeSort();
    static int* sort(int *array, int len);
    static int* merge(int* left_array, int* right_array, int left_len, int right_len);


};

#endif // MERGESORT_H
