#include <iostream>
#include <omp.h>
#include "MergeSort.h"
#include "QuickSort.h"
#include <cstdlib>
#include <random>

using namespace std;

#define NUM_THREADS 1
#define IS_TESTED false

void print(vector<int> &v) {
    for (int i: v) {
        cout << i << ",";
    }
    cout << endl;
}

vector<int> createRandomNumberArray(int size) {
    vector<int> array(size);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, RAND_MAX);

    for (int i = 0; i < size; i++) {
        array[i] = (int) dist6(rng);
    }
    return array;
}

/**
 * execution = 0 => sequential mergesort
 * execution = 1 => parallel mergesort
 * execution = 2 => threshold parallel mergesort
 * execution = 3 => sequential quicksort
 * execution = 4 => parallel quicksort
 * execution = 5 => threshold parallel quicksort
 */

int main(int argc, char *argv[]) {
    int randomNumberAmount = 500;
    int execution = 0;
    int threadNum = NUM_THREADS;

    if (argc > 3) {
        threadNum = atoi(argv[1]);
        randomNumberAmount = atoi(argv[2]);
        execution = atoi(argv[3]);
    }

    auto arrayToBeSorted = createRandomNumberArray(randomNumberAmount);
//    vector<int> arrayToBeSorted{15, 45, 78, 62, 14, 1, 5};
    vector<int> res;

    double wtime = omp_get_wtime();
//    omp_set_num_threads(threadNum);

    switch (execution) {
        case 0:
            res = mergesort::sequentialMergeSort(arrayToBeSorted);
            break;
        case 1:
            omp_set_num_threads(threadNum);
            res = mergesort::parallelMergeSort(arrayToBeSorted);
            break;
        case 2:
            res = mergesort::parallelThresholdMergeSort(arrayToBeSorted, threadNum, 5);
            break;
        case 3:
            res = quicksort::sequentialQuickSort(arrayToBeSorted);
            break;
        case 4:
            omp_set_num_threads(threadNum);
            res = quicksort::parallelQuickSort(arrayToBeSorted);
            break;
        case 5:
            res = quicksort::parallelThresholdQuickSort(arrayToBeSorted, threadNum, 5);
            break;
        default:
            cout << "Please provide an execution value between 0 and 5." << endl;
            break;
    }

    wtime = omp_get_wtime() - wtime;
    cout << wtime << endl;

//    print(res);

    return 0;
}
