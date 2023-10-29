#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "sortings.h"

class HeapSort
{
public:
    static int* sort(int* array, int start, int length);

private:
    static void heapify(int* array, int st, int length);
    static void sift_down(int* heap, int start, int end);
};


#endif // HEAPSORT_H
