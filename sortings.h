#ifndef SORTINGS_H
#define SORTINGS_H

//#include "swap.h"
#include <bits/stdc++.h>


static void swap(int array[], int j, int i)
{
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

static void insertionSort(int *arr, int begin, int end)
{
    for (int i = begin + 1; i <= end - 1; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= begin && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static void selectionSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minimum_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[minimum_index])
            {
                minimum_index = j;
            }
        }
        if (minimum_index != i)
            swap(array, minimum_index, i);
    }
}

static void bubbleSort(int array[], int length)
{

    for (int j = 0; j < length; j++)
    {
        bool isSorted = true;
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i + 1] < array[i])
            {
                swap(array, i + 1, i);
                isSorted = false;
            }

        }
        if (isSorted)
            break;
    }
}

#endif // SORTINGS_H
