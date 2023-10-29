#include "introsort.h"


void IntroSort::mediana(int array[], int left, int right)
{
    int mid = (right - left) / 2;

    if (array[left] > array[right])
    {
        //std::swap(array[left], array[right]);
        swap(array, left, right);
    }
    if (array[mid] < array[right])
    {
        if (array[mid] > array[left])
            //std::swap(array[mid], array[right]);
            swap(array, mid, right);
        else
            //std::swap(array[left], array[right]);
            swap(array, left, right);
    }
}

void IntroSort::partition(int *array, int start, int len, int depth, int maxdepth)
{
    if (len > 1)
    {
        if (len < 16)
        {
            insertionSort(array, start, start + len);
        }
        else if (depth >= maxdepth)
        {
            HeapSort::sort(array, start, len);
        }
        else
        {
            mediana(array, start, start + len - 1);
            int mainElement = array[start + len - 1];
            int *leftArray = new int[len];
            int leftLen = 0;
            int *rightArray = new int[len];
            int rightLen = 0;

            for (int i = start; i < start + len - 1; i++)
            {
                if (array[i] <= mainElement)
                {
                    leftArray[leftLen] = array[i];
                    leftLen++;
                }
                else
                {
                    rightArray[rightLen] = array[i];
                    rightLen++;
                }
            }

            merge(array, start, leftArray, leftLen, rightArray, rightLen, mainElement);
            delete[] leftArray;
            delete[] rightArray;
            partition(array, start, leftLen, ++depth, maxdepth);
            partition(array, start + leftLen + 1, rightLen, ++depth, maxdepth);
        }
    }
}

void IntroSort::merge(int *array, int start, int* leftArray, int leftLen, int *rightArray, int rightLen, int mainElement)
{
    int arrayIndex = start;
    for (int i = 0; i < leftLen; i++)
    {
        array[arrayIndex] = leftArray[i];
        arrayIndex++;
    }
    array[arrayIndex] = mainElement;
    arrayIndex++;

    for (int i = 0; i < rightLen; i++)
    {
        array[arrayIndex] = rightArray[i];
        arrayIndex++;
    }
}


int* IntroSort::sort(int *array, int len)
{
    int maxdepth = log(len) * 2;
    partition(array, 0, len, 0, maxdepth);
    return array;
}


/*
int IntroSort::partition(int *array, int len, int *leftArray, int& leftLen,  int *rightArray, int &rightLen)
{
    int mainElement = array[len - 1];

    for (int i = 0; i < len - 1; i++)
    {
        if (array[i] <= mainElement)
        {
            leftArray[leftLen] = array[i];
            leftLen++;
        }
        else
        {
            rightArray[rightLen] = array[i];
            rightLen++;
        }
    }
    return mainElement;
}

int* IntroSort::merge(int* leftArray, int leftLen, int *rightArray, int rightLen, int mainElement)
{
    int array[leftLen + rightLen];
    int arrayIndex = 0;
    for (int i = 0; i < leftLen; i++)
    {
        array[arrayIndex] = leftArray[i];
        arrayIndex++;
    }
    array[arrayIndex] = mainElement;
    arrayIndex++;

    for (int i = 0; i < rightLen; i++)
    {
        array[arrayIndex] = rightArray[i];
        arrayIndex++;
    }
    return array;
}

int* IntroSort::sort(int *array, int len)
{
    if (len > 1)
    {
        int *leftArray = new int[len];
        int leftLen = 0;
        int *rightArray = new int[len];
        int rightLen = 0;

        int mainElement = partition(array, len, leftArray, leftLen, rightArray, rightLen);
        leftArray = sort(leftArray, leftLen);
        rightArray = sort(rightArray, rightLen);
        array = merge(leftArray, leftLen, rightArray, rightLen, mainElement);
        delete[] leftArray;
        delete[] rightArray;
    }
    return array;
}z*/
