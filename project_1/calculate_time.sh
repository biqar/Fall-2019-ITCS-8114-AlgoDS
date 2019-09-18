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
