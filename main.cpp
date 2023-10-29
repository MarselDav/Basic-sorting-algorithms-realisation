#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "mergesort.h"
#include "quicksort.h"
#include "quicksortmediana.h"
#include "shellsort.h"
#include "heapsort.h"
#include "introsort.h"
#include "timsort.h"

using namespace std;

void printArray(int* array, int length) {
    cout << "Array: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int* generateRandomArray(int size) {
    int* array = new int[size];
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < size; ++i) {
        array[i] = dist(mt);
    }
    return array;
}

int* generateSortedArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
    return array;
}

int* generateHalfSortedArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = i < size / 2 ? i + 1 : size - i;
    }
    return array;
}

int* generateReversedArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
    return array;
}

int main() {
    vector<int* (*)(int)> generators = {generateSortedArray, generateHalfSortedArray, generateReversedArray, generateRandomArray};

    vector<string> algortims_names = {"selectionSort", "insertionSort", "bubbleSort", "MergeSort", "QuickSort", "QuickSortMediana", "sortShellSequence",
                 "sortHibbardSequence", "sortSedgwickSequence", "HeapSort", "TimSort", "IntroSort"};

    vector<int> sizes = {50, 100, 500, 1000, 5000, 10000,
                          25000, 32500, 50000, 60000, 70000,
                          80000, 100000, 150000, 175000, 200000,
                          225000, 250000, 275000, 300000};

    //vector<int> sizes = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500};

    const int NUMBER_OF_MEASUREMENTS = 1;

    for (int size : sizes) {
        for (string algortim_name : algortims_names)
        {
            for (int i = 0; i < generators.size(); ++i)
            {
                std::chrono::microseconds average_result = std::chrono::microseconds(0);
                for (int j = 0; j < NUMBER_OF_MEASUREMENTS; j++)
                {
                    int* array = generators[i](size);
                    auto start = chrono::high_resolution_clock::now();

                    // Выполнение сортировки
                    if (algortim_name == "selectionSort")
                    {
                        selectionSort(array, size);
                    }
                    if (algortim_name == "insertionSort")
                    {
                        insertionSort(array, 0, size);
                    }
                    if (algortim_name == "bubbleSort")
                    {
                        bubbleSort(array, size);
                    }
                    if (algortim_name == "MergeSort")
                    {
                        MergeSort::sort(array, size);
                    }
                    if (algortim_name == "QuickSort")
                    {
                        QuickSort::sort(array, 0, size - 1);
                    }
                    if (algortim_name == "QuickSortMediana")
                    {
                        QuickSortMediana::sort(array, 0, size - 1);
                    }
                    if (algortim_name == "sortShellSequence")
                    {
                        ShellSort::sortShellSequence(array, size);
                    }
                    if (algortim_name == "sortHibbardSequence")
                    {
                        ShellSort::sortHibbardSequence(array, size);
                    }
                    if (algortim_name == "sortSedgwickSequence")
                    {
                        ShellSort::sortSedgwickSequence(array, size);
                    }
                    if (algortim_name == "HeapSort")
                    {
                        HeapSort::sort(array, 0, size);
                    }
                    if (algortim_name == "TimSort")
                    {
                        TimSort::sort(array, size);
                    }
                    if (algortim_name == "IntroSort")
                    {
                        IntroSort::sort(array, size);
                    }

                    auto stop = chrono::high_resolution_clock::now();
                    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                    average_result = average_result + duration;
                    delete[] array;
                }
                cout << algortim_name << " " << size << " " << average_result.count() / NUMBER_OF_MEASUREMENTS << endl;

            }
        }
    }

    return 0;
}
