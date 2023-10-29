#ifndef INTROSORTFROMSITE_H
#define INTROSORTFROMSITE_H


class IntroSortFromSite
{
public:
    static void sort(int arr[], int* begin, int* end);

private:
    static void swapValue(int* a, int* b);
    static void InsertionSort(int arr[], int* begin, int* end);
    static int* Partition(int arr[], int low, int high);
    static int* MedianOfThree(int* a, int* b, int* c);
    static void IntrosortUtil(int arr[], int* begin, int* end, int depthLimit);
};

#endif // INTROSORTFROMSITE_H
