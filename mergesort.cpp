#include "mergesort.h"

MergeSort::MergeSort(){}


int* MergeSort::merge(int left_array[], int right_array[], int left_len, int right_len)
{
    int array_len = 0;
    int* array = new int[left_len + right_len];

    int a = 0, b = 0;
    while (a < left_len && b < right_len)
    {
        if (left_array[a] <= right_array[b])
        {
            array[array_len] = left_array[a];
            a++;
        }
        else
        {
            array[array_len] = right_array[b];
            b++;
        }
        array_len++;
    }
    while (b < right_len)
    {
        array[array_len] = right_array[b];
        b++;
        array_len++;
    }
    while (a < left_len)
    {
        array[array_len] = left_array[a];
        a++;
        array_len++;
    }

    return array;
}

int* MergeSort::sort(int *array, int len)
{
    if (len == 1)
            return array;

    int mid = int(len / 2);

    int left_len = 0;
    int* left_array = new int[len];

    int right_len = 0;
    int* right_array = new int[len];

    for (int i = 0; i < len; i++)
        {
            if (i < mid)
            {
                left_array[left_len] = array[i];
                left_len++;
            }
            else
            {
                right_array[right_len] = array[i];
                right_len++;
            }
        }

    left_array = sort(left_array, left_len);
    right_array = sort(right_array, right_len);

    int* sorted_array = merge(left_array, right_array, left_len, right_len);

    delete[] left_array;
    delete[] right_array;

    return sorted_array;
}
