#ifndef TIMSORT_H
#define TIMSORT_H

#include <list>
#include "sortings.h"
#include <cstdlib>

class TimSort
{
public:
    static int* sort(int *array, int len);

public:
    static void addRun(int *array,
                       int&len,
                       int &run_len,
                       int &min_run,
                       int&start_run_index,
                       int&increasing,
                       std::list<std::pair<int, int>> &runs,
                       int &i);

    static int GetMinrun(int n);
    static void reverseArray(int* array, int start, int end);
    static std::list<std::pair<int, int>> findRuns(int *array, int len);
    static void merge(int *array, int left_start, int left_end, int right_start, int right_end);
};

#endif // TIMSORT_H;
