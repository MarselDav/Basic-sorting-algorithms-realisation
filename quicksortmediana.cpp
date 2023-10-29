#include "quicksortmediana.h"
#include <stack>

int QuickSortMediana::mediana(int array[], int left, int right)
{
    int mid = (right + left) / 2;

        // Сравниваем элементы left, mid и right
    if (array[left] > array[mid]) {
            std::swap(array[left], array[mid]);
    }
    if (array[mid] > array[right]) {
        std::swap(array[mid], array[right]);
    }
    if (array[left] > array[mid]) {
        std::swap(array[left], array[mid]);
    }

        // Теперь array[mid] - это медианное значение из left, mid и right
    return array[mid];
}


int* QuickSortMediana::sort(int array[], int left, int right) {
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

int QuickSortMediana::partition(int array[], int left, int right) {
    int pivot = mediana(array, left, right); // опорный элемент
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
