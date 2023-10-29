#include "heapsort.h"

void HeapSort::sift_down(int* heap, int start, int end)
{
    int root = start;
    while (2 * root + 1 <= end)
    {
        int child = 2 * root + 1;
        if (child + 1 <= end && heap[child] < heap[child + 1])
        {
            child += 1;
        }
        if (heap[root] < heap[child]) {
            //std::swap(heap[root], heap[child]);
            swap(heap, root, child);
            root = child;
        }
        else
        {
            break;
        }
    }
}

void HeapSort::heapify(int* array, int st, int length)
{
    int start = st + (length - 2) / 2;
    while (start >= st)
    {
        sift_down(array, start, length - 1);
        --start;
    }
}

int* HeapSort::sort(int* array, int start, int length)
{
    heapify(array, start, length);

    int end = length - 1;
    while (end > start)
    {
        //std::swap(array[0], array[end]);
        swap(array, 0, end);
        end--;
        sift_down(array, 0, end);
    }

    return array;
}


/*
void HeapSort::sift_down(int* heap, int start, int end)
{
    int root = start;
    while (2 * root + 1 <= end)
    {
        int child = 2 * root + 1;
        if (child + 1 <= end && heap[child] < heap[child + 1])
        {
            child += 1;
        }
        if (heap[root] < heap[child]) {
            std::swap(heap[root], heap[child]);
            root = child;
        }
        else
        {
            break;
        }
    }
}

void HeapSort::heapify(int* array, int length)
{
    int start = (length - 2) / 2;
    while (start >= 0)
    {
        sift_down(array, start, length - 1);
        --start;
    }
}

int* HeapSort::sort(int* array, int length)
{
    heapify(array, length);

    int end = length - 1;
    while (end > 0)
    {
        std::swap(array[0], array[end]);
        end--;
        sift_down(array, 0, end);
    }

    return array;
}*/
