#ifndef INTROSORT_H
#define INTROSORT_H

#include <bits/stdc++.h>
#include "sortings.h"
#include "heapsort.h"

class IntroSort
{
public:
    static int* sort(int *array, int len);

private:
    static void partition(int *array, int start, int end, int depth, int maxdepth);
    static void mediana(int array[], int left, int right);
    static void merge(int *array, int start, int* leftArray, int leftLen, int *rightArray, int rightLen, int mainElement);
};

#endif // INTROSORT_H
