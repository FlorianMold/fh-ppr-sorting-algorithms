//
// Created by user on 3/18/22.
//

#include <vector>

namespace quicksort {
    void sequentialQuickSort(std::vector<int> array);

    void parallelQuickSort(std::vector<int> array, int threadAmount);

    void parallelThresholdQuickSort(
            std::vector<int> array,
            int threadAmount,
            int threshold
    );
}