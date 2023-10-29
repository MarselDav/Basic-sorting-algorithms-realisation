#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <math.h>
#include <iostream>
#include <vector>
#include "sortings.h"

class ShellSort
{
public:
    static void sortShellSequence(int array[], int len);
    static void sortHibbardSequence(int array[], int len);
    static void sortSedgwickSequence(int array[], int len);

};

#endif // SHELLSORT_H
