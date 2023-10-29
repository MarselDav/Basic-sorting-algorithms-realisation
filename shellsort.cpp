#include "shellsort.h"


void ShellSort::sortShellSequence(int array[], int len)
{

    for (int s = len / 2; s > 0; s /= 2) {
            for (int i = s; i < len; ++i) {
                for (int j = i - s; j >= 0 && array[j] > array[j + s]; j -= s) {
                    swap(array, j,j + s);
                }
            }
        }
}

void ShellSort::sortHibbardSequence(int array[], int len)
{
    int h = log(len - 1) / log(2);
    for (int s = h; (1 << s) - 1; s--)
    {
        int step = (1 << s) - 1;
        for (int i = step; i < len; ++i) {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                swap(array, j,j + step);
            }
        }
    }
}

void ShellSort::sortSedgwickSequence(int array[], int len)
{
    int j = 0;
    bool run = true;
    while(run)
    {
        if (j % 2 == 0 && 3 * (9 << j) - (9 << (j / 2)) + 1 > len)
            run = false;

        if (j % 2 != 0 && 3 * (8 << j) - (6 << ((j + 1) / 2)) + 1 > len)
            run = false;
        j++;
    }
    j--;

    for (int s = j; (s % 2 == 0) ? (9 << s) - (9 << (s / 2)) + 1 : (8 << s) - (6 << ((s + 1) / 2)) + 1 > 0; s--)
    {
        int step = (s % 2 == 0) ? (9 << s) - (9 << (s / 2)) + 1 : (8 << s) - (6 << ((s + 1) / 2)) + 1;

        for (int i = step; i < len; ++i) {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                swap(array, j, j + step);
            }
        }
    }
}
