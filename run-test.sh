# Clear directory
rm results/mergesort/sequential/*
rm results/mergesort/parallel/*
rm results/mergesort/threshold/*

rm results/quicksort/sequential/*
rm results/quicksort/parallel/*
rm results/quicksort/threshold/*

iterations=100
randomNumberAmount=50000
threadAmount=16

# MergeSort

echo "Running sequential mergesort"
./make-test.sh -i $iterations -t 1 -r $randomNumberAmount -e 0 -f results/mergesort/sequential/result-t1.txt

#echo "Running parallel mergesort"
#for j in $(seq 1 $threadAmount);
#do
#   ./make-test.sh -i $iterations -t ${j} -r $randomNumberAmount -e 1 -f results/mergesort/parallel/result-t${j}.txt
#done
#
#echo "Running threshold parallel mergesort"
#for j in $(seq 1 $threadAmount);
#do
#   ./make-test.sh -i $iterations -t ${j} -r $randomNumberAmount -e 2 -f results/mergesort/threshold/result-t${j}.txt
#done

# Quicksort

echo "Running sequential quicksort"
./make-test.sh -i $iterations -t 1 -r $randomNumberAmount -e 3 -f results/quicksort/sequential/result-t1.txt

#echo "Running parallel quicksort"
#for j in $(seq 1 $threadAmount);
#do
#   ./make-test.sh -i $iterations -t ${j} -r $randomNumberAmount -e 4 -f results/quicksort/parallel/result-t${j}.txt
#done
#
#echo "Running threshold parallel quicksort"
#for j in $(seq 1 $threadAmount);
#do
#   ./make-test.sh -i $iterations -t ${j} -r $randomNumberAmount -e 5 -f results/quicksort/threshold/result-t${j}.txt
#done