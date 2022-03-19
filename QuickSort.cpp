//
// Created by user on 3/18/22.
//

#include "QuickSort.h"

using namespace std;

int partition(vector<int> &array, int low, int high, int pivot) {
    int leftStart = low, rightEnd = high;

    while (leftStart <= rightEnd) {
        while (array[leftStart] < pivot) leftStart++;
        while (array[rightEnd] > pivot) rightEnd--;

        if (leftStart <= rightEnd) {
            std::swap(array[leftStart], array[rightEnd]);
            leftStart++;
            rightEnd--;
        }
    }
    return leftStart;
}

std::vector<int> seqQuickSort(vector<int> &array, int low, int high) {
    if (low >= high) return array;

    int pivotElement = array[(low + high) / 2];
    int pivotIndex = partition(array, low, high, pivotElement);
    seqQuickSort(array, low, pivotIndex - 1);
    seqQuickSort(array, pivotIndex, high);

    return array;
}

std::vector<int> quicksort::sequentialQuickSort(vector<int> &array) {
    // https://gist.github.com/iwatakeshi/7f7a7c11cd7a6f76598df18a7ecda507
    // https://github.com/weiaicunzai/CPP_Practice/blob/master/sort/quick_sort.cpp
    return seqQuickSort(array, 0, (int) array.size() - 1);
}

std::vector<int> parQuickSort(vector<int> &array, int low, int high) {
    if (low >= high) return array;

    int pivotElement = array[(low + high) / 2];
    int pivotIndex = partition(array, low, high, pivotElement);

#pragma omp task default(none) shared(array, low, pivotIndex)
    parQuickSort(array, low, pivotIndex - 1);
#pragma omp task default(none) shared(array, high, pivotIndex)
    parQuickSort(array, pivotIndex, high);

    return array;
};

std::vector<int> quicksort::parallelQuickSort(vector<int> &array) {
#pragma omp parallel default(none) shared(array)
    {
#pragma omp single
        parQuickSort(array, 0, (int) array.size() - 1);
    }
    return array;
}

std::vector<int> parThreshQuickSort(vector<int> &array, int low, int high, int threshold) {
    if (low >= high) return array;

    int pivotElement = array[(low + high) / 2];
    int pivotIndex = partition(array, low, high, pivotElement);

    if (high - low > threshold) {
#pragma omp task default(none) shared(array, low, pivotIndex, threshold)
        parThreshQuickSort(array, low, pivotIndex - 1, threshold);
#pragma omp task default(none) shared(array, high, pivotIndex, threshold)
        parThreshQuickSort(array, pivotIndex, high, threshold);
    } else {
        seqQuickSort(array, low, pivotIndex - 1);
        seqQuickSort(array, pivotIndex, high);
    }
    return array;
};

std::vector<int> quicksort::parallelThresholdQuickSort(
        vector<int> &array,
        int threshold
) {
#pragma omp parallel default(none) shared(array, threshold)
    {
#pragma omp single
        parThreshQuickSort(array, 0, (int) array.size() - 1, threshold);
    }
    return array;
}