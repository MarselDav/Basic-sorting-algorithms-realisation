#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stack>
#include "sortings.h"

class QuickSort
{
public:
    static int* sort(int array[], int left, int right);

protected:
    static int partition(int array[], int left, int right);

};

#endif // QUICKSORT_H
