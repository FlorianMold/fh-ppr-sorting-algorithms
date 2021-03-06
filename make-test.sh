#!/bin/bash

while getopts i:t:r:f:e:h: flag
do
    case "${flag}" in
        i) iterations=${OPTARG};;
        t) threads=${OPTARG};;
        r) randomNumberAmount=${OPTARG};;
        f) filename=${OPTARG};;
        e) execution=${OPTARG};;
        h) threshold=${OPTARG};;
    esac
done

echo "Running: $iterations iterations of the program";
echo "Algorithm is run with the following execution-mode: $execution and generates $randomNumberAmount random numbers for sorting";
echo "Running: $threads threads";
echo "Running with threshold: $threshold";
echo "Saving to: $filename";

for j in $(seq 1 $iterations);
do
   ./cmake-build-debug/fh_ppr_sorting_algorithms $threads $randomNumberAmount $execution $threshold >> $filename
done