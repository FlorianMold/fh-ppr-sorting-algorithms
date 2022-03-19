//
// Created by user on 3/18/22.
//

#include <iostream>
#include "MergeSort.h"
#include <omp.h>

using namespace std;

vector<int> merge(vector<int> &array, vector<int> left, vector<int> right) {
    vector<int> temp;

    // left and right iterators
    int li = 0;
    int ri = 0;

    while (li < left.size() && ri < right.size()) {
        if (left[li] < right[ri]) {
            temp.push_back(left[li]);
            li++;
        } else {
            temp.push_back(right[ri]);
            ri++;
        }
    } // end while

    while (li < left.size()) {
        // push the rest of the values back because they are sorted
        temp.push_back(left[li]);
        li++;
    }

    while (ri < right.size()) {
        // do the same for the right
        temp.push_back(right[ri]);
        ri++;
    }

    array = temp;
    return array;
}

vector<int> mergesort::sequentialMergeSort(vector<int> &array) {
    //https://gist.github.com/piepieninja/b32db6a1345964147fd0
    if (array.size() == 1) {
        return array;
    }

    auto mid = array.begin() + (int) (array.size() / 2);

    vector<int> left(array.begin(), mid);
    vector<int> right(mid, array.end());

    left = sequentialMergeSort(left);
    right = sequentialMergeSort(right);

    return merge(array, left, right);
}

std::vector<int> parMergeSort(vector<int> &array) {
    if (array.size() == 1) {
        return array;
    }

    auto mid = array.begin() + (int) (array.size() / 2);

    vector<int> left(array.begin(), mid);
    vector<int> right(mid, array.end());

#pragma omp task default(none) shared(left)
    left = parMergeSort(left);
#pragma omp task default(none) shared(right)
    right = parMergeSort(right);

#pragma omp taskwait
    return merge(array, left, right);
}

std::vector<int> mergesort::parallelMergeSort(vector<int> &array) {
#pragma omp parallel default(none) shared(array)
    {
#pragma omp single
        parMergeSort(array);
    }

    return array;
}

std::vector<int> parThreshMergeSort(vector<int> &array, int threshold) {
    if (array.size() == 1) {
        return array;
    }

    auto mid = array.begin() + (int) (array.size() / 2);

    vector<int> left(array.begin(), mid);
    vector<int> right(mid, array.end());

    if (array.size() >= threshold) {
#pragma omp task default(none) shared(left, threshold)
        left = parThreshMergeSort(left, threshold);
#pragma omp task default(none) shared(right, threshold)
        right = parThreshMergeSort(right, threshold);
    } else {
        left = mergesort::sequentialMergeSort(left);
        right = mergesort::sequentialMergeSort(right);
    }

#pragma omp taskwait
    return merge(array, left, right);
}

std::vector<int> mergesort::parallelThresholdMergeSort(
        vector<int> &array,
        int threshold
) {
#pragma omp parallel default(none) shared(array, threshold)
    {
#pragma omp single
        parThreshMergeSort(array, threshold);
    }

    return array;
}