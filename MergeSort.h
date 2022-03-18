//
// Created by user on 3/18/22.
//

#include <vector>

namespace mergesort {
    std::vector<int> sequentialMergeSort(std::vector<int> &array);

    std::vector<int> parallelMergeSort(std::vector<int> &array, int threadAmount);

    std::vector<int> parallelThresholdMergeSort(
            std::vector<int> &array,
            int threadAmount,
            int threshold
    );
}