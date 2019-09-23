#!/bin/bash

#echo "Algorithm: Insertion Sort"
#echo "Input-set: rev_sorted"
input_path="input/rev_sorted/"
g++ -o insertion_sort insertion_sort.cpp
for file in $input_path*; do
  #echo "Input File: ${file##*/}"
  counter=1
  execution_time=0.0
  while [ $counter -le 3 ]
  do
    ./insertion_sort < $input_path${file##*/} > output.txt
    ((counter++))
  done
done

#echo "*****************<>*****************"

#echo "Algorithm: Merge Sort"
#echo "Input-set: rev_sorted"
g++ -o merge_sort merge_sort.cpp
for file in $input_path*; do
  #echo "Input File: ${file##*/}"
  counter=1
  execution_time=0.0
  while [ $counter -le 3 ]
  do
    ./merge_sort < $input_path${file##*/} > output.txt
    ((counter++))
  done
done

#echo "*****************<>*****************"

#echo "Algorithm: Heap Sort"
#echo "Input-set: rev_sorted"
g++ -o heapsort heapsort.cpp
for file in $input_path*; do
  #echo "Input File: ${file##*/}"
  counter=1
  execution_time=0.0
  while [ $counter -le 3 ]
  do
    ./heapsort < $input_path${file##*/} > output.txt
    ((counter++))
  done
done

#echo "*****************<>*****************"

#echo "Algorithm: In-place Quick Sort"
#echo "Input-set: rev_sorted"
g++ -o inplace_quicksort inplace_quicksort.cpp
for file in $input_path*; do
  #echo "Input File: ${file##*/}"
  counter=1
  execution_time=0.0
  while [ $counter -le 3 ]
  do
    ./inplace_quicksort < $input_path${file##*/} > output.txt
    ((counter++))
  done
done

#echo "*****************<>*****************"

#echo "Algorithm: Modified Quick Sort"
#echo "Input-set: rev_sorted"
g++ -o modified_quicksort modified_quicksort.cpp
for file in $input_path*; do
  #echo "Input File: ${file##*/}"
  counter=1
  execution_time=0.0
  while [ $counter -le 3 ]
  do
    ./modified_quicksort < $input_path${file##*/} > output.txt
    ((counter++))
  done
done
