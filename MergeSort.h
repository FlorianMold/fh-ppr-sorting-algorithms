//
// Created by user on 3/18/22.
//

#include <vector>

namespace mergesort {
    void sequentialMergeSort(std::vector<int> array);

    void parallelMergeSort(std::vector<int> array, int threadAmount);

    void parallelThresholdMergeSort(
            std::vector<int> array,
            int threadAmount,
            int threshold
    );
}