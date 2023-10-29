#include "quicksort.h"

int* QuickSort::sort(int array[], int left, int right) {
    std::stack<std::pair<int, int>> stack;
    stack.push({left, right});

    while (!stack.empty()) {
        int left = stack.top().first;
        int right = stack.top().second;
        stack.pop();

        if (right <= left) {
            continue;
        }

        int pivotIndex = partition(array, left, right);
        if (pivotIndex - left > right - pivotIndex)
        {
            stack.push({left, pivotIndex - 1});
            stack.push({pivotIndex + 1, right});
        }
        else
        {
            stack.push({pivotIndex + 1, right});
            stack.push({left, pivotIndex - 1});
        }
    }



    return array;
}

int QuickSort::partition(int array[], int left, int right) {
    int pivot = array[(left + right) / 2]; // опорный элемент
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i >= j)
            break;
        swap(array, i++, j--);
    }

    return j;
}



//int* QuickSort::sort(int array[], int len) {
//    std::stack<std::pair<int, int>> stack;
//    stack.push({0, len - 1});

//    while (!stack.empty()) {
//        int left = stack.top().first;
//        int right = stack.top().second;
//        stack.pop();

//        if (left >= right) {
//            continue;
//        }

//        int pivotIndex = partition(array, left, right);
//        stack.push({left, pivotIndex - 1});
//        stack.push({pivotIndex + 1, right});
//    }



//    return array;
//}

//int QuickSort::partition(int array[], int left, int right) {
//    int pivot = array[right]; // опорный элемент
//    int i = left - 1;

//    for (int j = left; j <= right - 1; j++) {
//        if (array[j] <= pivot) {
//            i++;
//            //std::swap(array[i], array[j]);
//            swap(array, i, j);
//        }
//    }


//    //std::swap(array[i + 1], array[right]);
//    swap(array, i + 1, right);
//    return i + 1;
//}
