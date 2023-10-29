#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H

#include "sortings.h"

class QuickSortMediana
{
public:
    static int* sort(int array[], int left, int right);

private:
    static int partition(int array[], int left, int right);
    static int mediana(int array[], int left, int right);

};

#endif // QUICKSORTMEDIANA_H
