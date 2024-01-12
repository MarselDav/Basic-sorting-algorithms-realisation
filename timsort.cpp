#include "timsort.h"

int TimSort::GetMinrun(int n)
{
        int r = 0;           /* станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой */
        while (n >= 64) {
            r |= n & 1;
            n >>= 1;
        }
        return n + r;
}

void TimSort::reverseArray(int* array, int start, int end)
{
    if (array == nullptr || start < 0 || end < 0 || start >= end) {
        std::cout << "Incorrect: " << start << " " << end << std::endl; // Проверка на некорректные входные данные
        return;
    }

    while (start < end) {
        std::swap(array[start], array[end]); // Обмен элементов местами

        // Перемещаемся к середине массива
        start++;
        end--;
    }
}


void TimSort::addRun(int *array,
                   int&len,
                   int &run_len,
                   int &min_run,
                   int&start_run_index,
                   int&increasing,
                   std::list<std::pair<int, int>> &runs,
                   int &i)
{
    if (run_len < min_run)
    {
        i += min_run - run_len;
        if (i > len)
            i = len;
        run_len = i - start_run_index;
        increasing = -1;
        insertionSort(array, start_run_index, start_run_index + run_len);
    }
    else
    {
        increasing = 1;
    }
    runs.push_back(std::make_pair(start_run_index, run_len));
    run_len = 0;
    start_run_index = i;
}


std::list<std::pair<int, int>> TimSort::findRuns(int *array, int len)
{
    int min_run = GetMinrun(len);

    //std::list<std::pair<int, int>> runs;
    std::list<std::pair<int, int>> runs;

    int start_run_index = 0;
    int run_len = 1;
    int increasing = -1;

    int i = 1;
    while (i < len)
    {
        if (array[i] >= array[i - 1])
        {
            if (increasing == -1)
            {
                increasing = 1;
            }
            if (increasing == 0)
            {
                addRun(array, len, run_len, min_run, start_run_index, increasing, runs, i);
            }
        }
        else
        {
            if (increasing == -1)
            {
                increasing = 0;
            }
            if (increasing == 1)
            {
                reverseArray(array, start_run_index, start_run_index + run_len);

                addRun(array, len, run_len, min_run, start_run_index, increasing, runs, i);
            }
        }
        if (i < len)
            run_len++;
        i++;
    }

    if (run_len > 0)
    {
        if (!increasing) {
            reverseArray(array, start_run_index, len - 1);
        }
        if (run_len < min_run) {
            insertionSort(array, start_run_index, len);
        }
        //runs.push_back(std::make_pair(start_run_index, run_len));
        runs.push_back(std::make_pair(start_run_index, run_len));
    }

    return runs;
}

void TimSort::merge(int *array, int left_start, int left_end, int right_start, int right_end) {
    int len = right_end - left_start + 1;
    int *temp = new int[len];
    int left_index = left_start;
    int right_index = right_start;
    int temp_index = 0;


    while (left_index <= left_end && right_index <= right_end)  // Объединяем два подмассива во временный массив
    {
        if (array[left_index] <= array[right_index]) {
            temp[temp_index++] = array[left_index++];
        } else {
            temp[temp_index++] = array[right_index++];
        }
    }

    while (left_index <= left_end) // Добавляем оставшиеся элементы из левого подмассива, если они есть
    {
        temp[temp_index++] = array[left_index++];
    }

    while (right_index <= right_end) // Добавляем оставшиеся элементы из правого подмассива, если они есть
    {
        temp[temp_index++] = array[right_index++];
    }


    for (int i = 0; i < len; ++i) // Копируем отсортированные значения из временного массива обратно в исходный массив
    {
        array[left_start + i] = temp[i];
    }

    delete[] temp;
}



int* TimSort::sort(int *array, int len)
{
    std::list<std::pair<int, int>> runs = findRuns(array, len);
    std::list<std::pair<int, int>>::iterator runs_iterator = runs.begin();
    int i = 0;
    while (runs.size() > 2)
    {
        if (i >= runs.size() || (runs.size() - i) < 3)
        {
            runs_iterator = runs.begin();
            i = 0;
            continue;
        }

        std::pair<int, int> &X = *runs_iterator;
        std::pair<int, int> &Y = *std::next(runs_iterator, 1);
        std::pair<int, int> &Z = *std::next(runs_iterator, 2);

        int len_x = X.second;
        int len_y = Y.second;
        int len_z = Z.second;

        if (!(len_z > len_y + len_x) || !(len_y > len_x))
        {
            if (len_x <= len_z) // x and y
            {
                int x_start = X.first;
                int x_end = x_start + X.second;
                int y_start = Y.first;
                int y_end = y_start + Y.second;
                merge(array, x_start, x_end - 1, y_start, y_end - 1);
                Y.first = x_start;
                Y.second = len_x + len_y;

                //std::cout << "merge: " << len_y << " " << len_x << std::endl;
            }
            else
            {
                int temp_first = X.first;
                int temp_second = X.second;

                int y_start = Y.first;
                int y_end = y_start + Y.second;
                int z_start = Z.first;
                int z_end = z_start + Z.second;
                //std::cout << "merge: " << len_y << " " << len_z << std::endl;

                merge(array, y_start, y_end - 1, z_start, z_end - 1);
                Z.first = y_start;
                Z.second = len_y + len_z;
                Y.first = temp_first;
                Y.second = temp_second;
            }
            runs_iterator = runs.erase(runs_iterator);

        }
        if (runs_iterator != runs.end())
        {
            runs_iterator++;
        }
        i++;
    }

    if (runs.size() == 2)
    {
        auto runs_it = runs.begin();
        auto X = *(runs_it);
        auto Y = *(++runs_it);
        int x_start = X.first;
        int x_end = x_start + X.second;
        int y_start = Y.first;
        int y_end = y_start + Y.second;
        merge(array, x_start, x_end - 1, y_start, y_end - 1);
    }
    return array;
}
