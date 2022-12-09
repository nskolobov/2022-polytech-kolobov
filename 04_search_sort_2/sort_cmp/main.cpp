#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>

void fill_array_random(int arr[], int n, int a, int b) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(a, b);

  for (int i = 0; i < n; ++i) {
    arr[i] = dist(rng);
  }
}

void swap(int arr[], uint64_t idx_a, uint64_t idx_b)
{
    int temp = arr[idx_a];
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;
}

void selection_sort(int arr[], uint64_t n) {
  for (uint64_t i = 0; i < n - 1; i++) {
    int jmin = i;
    for (uint64_t j = i + 1; j < n; j++) {
      if (arr[j] < arr[jmin]) {
        jmin = j;
      }
    }
    if (jmin != i) {
      swap(arr, i, jmin);
    }
  }
}

int partition(int arr[], int start, int end)
{

    // Опорный элемент — первый элемент
    int pivot = arr[start];

    // Считаем число элементов меньше опорного
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Помещаем опорный элемент в нужное место
    int pivotIndex = start + count;
    swap(arr, pivotIndex, start);

    // Перебрасываем элементы меньше опорного
    // в левую часть, а больше опорного в правую часть
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    // Разбиение массива
    int p = partition(arr, start, end);

    // Сортировка левой части
    quick_sort(arr, start, p - 1);
    // Сортировка правой части
    quick_sort(arr, p + 1, end);
}

int main()
{
    const int count_size = 6;
    uint64_t array_size[count_size] = {10, 100, 1000, 1000000, 1000000000, 1000000000000};
    for (int i = 0; i < count_size; ++i) {
        uint64_t n = array_size[i];
        int arr1[n], arr2[n];
        int a = 0;
        int b = 100;
        fill_array_random(arr1, n, a, b);
        std::copy(arr1, arr1 + n, arr2);
        auto t1 = std::chrono::high_resolution_clock::now();
        selection_sort(arr1, n);
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ss_ms = t2 - t1;
        t1 = std::chrono::high_resolution_clock::now();
        quick_sort(arr2, 0, n - 1);
        t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> qs_ms = t2 - t1;
        std::cout << array_size[i] << ": " << ss_ms.count() << " (ss), " << qs_ms.count() << " (qs)" << std::endl;
    }
    return 0;
}
