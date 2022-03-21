# Clear directory
for rNA in 5000 50000 500000; do
rm results/mergesort/sequential/$rNA/*
done

for rNA in 5000 50000 500000; do
rm results/mergesort/parallel/$rNA/*
done

for rNA in 5000 50000 500000; do
rm results/mergesort/threshold/$rNA/*
done

for rNA in 5000 50000 500000; do
rm results/quicksort/sequential/$rNA/*
done
for rNA in 5000 50000 500000; do
rm results/quicksort/parallel/$rNA/*
done

for rNA in 5000 50000 500000; do
rm results/quicksort/threshold/$rNA/*
done

iterations=100
randomNumberAmount=500
threadAmount=8
threshold=200000

# MergeSort

for rNA in 5000 50000 500000; do
  echo "Running sequential mergesort with $rNA numbers"
  ./make-test.sh -i $iterations -t 1 -r $rNA -e 0 -f results/mergesort/sequential/${rNA}/result-t1.txt
done

for rNA in 5000 50000 500000; do
  echo "Running parallel mergesort with $rNA numbers"
  for j in $(seq 1 $threadAmount); do
    ./make-test.sh -i $iterations -t ${j} -r $rNA -e 1 -f results/mergesort/parallel/${rNA}/result-t${j}.txt
  done
done

for rNA in 5000 50000 500000; do
  echo "Running threshold parallel mergesort with $rNA numbers"
  for j in $(seq 1 $threadAmount); do
    ./make-test.sh -i $iterations -t ${j} -r $rNA -e 2 -h $threshold -f results/mergesort/threshold/${rNA}/result-t${j}.txt
  done
done

# Quicksort

for rNA in 5000 50000 500000; do
  echo "Running sequential quicksort with $rNA numbers"
  ./make-test.sh -i $iterations -t 1 -r $rNA -e 3 -f results/quicksort/sequential/${rNA}/result-t1.txt
done

for rNA in 5000 50000 500000; do
  echo "Running parallel quicksort with $rNA numbers"
  for j in $(seq 1 $threadAmount); do
    ./make-test.sh -i $iterations -t ${j} -r $rNA -e 4 -f results/quicksort/parallel/${rNA}/result-t${j}.txt
  done
done

for rNA in 5000 50000 500000; do
  echo "Running threshold parallel quicksort with $rNA numbers"
  for j in $(seq 1 $threadAmount); do
    ./make-test.sh -i $iterations -t ${j} -r $rNA -e 5 -h $threshold -f results/quicksort/threshold/${rNA}/result-t${j}.txt
  done
done
