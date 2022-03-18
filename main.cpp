#include <iostream>
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

void print(vector<int> &v) {
    for (int i : v) {
        cout << i << ",";
    }
    cout << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> numbers(5);
    numbers = {34, 23, 56, 79, 53};

    mergesort::sequentialMergeSort(numbers);

    print(numbers);
//    mergesort::parallelMergeSort(numbers, 8);
//    mergesort::parallelThresholdMergeSort(numbers, 8, 5);
//
//    quicksort::sequentialQuickSort(numbers);
//    quicksort::parallelQuickSort(numbers, 8);
//    quicksort::parallelThresholdQuickSort(numbers, 8, 5);


    return 0;
}
