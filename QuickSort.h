//
// Created by user on 3/18/22.
//

#include <vector>

namespace quicksort {
    std::vector<int> sequentialQuickSort(std::vector<int> &array);

    std::vector<int> parallelQuickSort(std::vector<int> &array);

    std::vector<int> parallelThresholdQuickSort(
            std::vector<int> &array,
            int threadAmount,
            int threshold
    );
}