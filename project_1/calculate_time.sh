#!/bin/sh
start=`date +%s`
g++ -o heapsort heapsort.cpp && ./heapsort < input/rev_sorted/in_rev_sorted_10k.txt > output.txt
end=`date +%s`
runtime=$((end-start))
echo $runtime
start=`date +%s`
g++ -o heapsort heapsort.cpp && ./heapsort < input/rev_sorted/in_rev_sorted_50k.txt > output.txt
end=`date +%s`
runtime=$((end-start))
echo $runtime
start=`date +%s`
g++ -o insertion_sort insertion_sort.cpp && ./insertion_sort < input/random/in_50k.txt > output/insertion_sort/out_50k.txt
end=`date +%s`
runtime=$((end-start))
echo $runtime
g++ -o merge_sort merge_sort.cpp && ./merge_sort < input/random/in_50k.txt > output/merge_sort/out_50k.txt
end=`date +%s`
runtime=$((end-start))
echo $runtime
