# Project 1: Comparison-based Sorting Algorithms
This repository will contains the entities of project_1 of course **ITCS 6114/8114: Algorithms and Data Structures**.

**Collaborators**
1. Abdullah Al Raqibul Islam (ID# 801151189)
2. Jawad Chowdhury (ID# 801135477)

**Input & Output Specification:**

1. To compare different sorting algorithms, we considered three types of input set
    * Randomly generated input, placed in input/random directory
    * Input array is already sorted, placed in input/sorted directory
    * Input array is reversely sorted, placed in input/rev_sorted directory
2. Each types of input set contains different input sizes (e.g. n = 5000, 10000, 15000, 20000, 25000 .. 40000, 45000, 50000). You will get the idea of input size from the file name. For example, if the input contains 10,000 numbers then the file name will be in_10K[dot]txt.
3. Each input file contains two lines of inputs. First line of  will contains **N**, the number of elements considered for the sorting. The next line will contains **N** numbers **(0 <= A[i] < 10^8)**.
4. For every input set we write **N** lines of output, each line will contains a single number in sorted manner.

**Source Code Execution Instructions:**

In this project, we have implemented the following sorting algorithms and compare them. For this project, we have used C/C++ as programming language.

1. Insertion sort
    * sourcecode: insertion_sort.cpp
    * to compile: $ g++ insertion_sort.cpp -o insertion_sort
    * to run: $ ./insertion_sort
2. Merge sort
    * sourcecode: merge_sort.cpp
    * to compile: $ g++ merge_sort.cpp -o merge_sort
    * to run: $ ./merge_sort
3. Heapsort
    * sourcecode: heapsort.cpp
    * to compile: $ g++ heapsort.cpp -o heapsort
    * to run: $ ./heapsort
4. In-place quicksort
    * sourcecode: inplace_quicksort.cpp
    * to compile: $ g++ inplace_quicksort.cpp -o inplace_quicksort
    * to run: $ ./inplace_quicksort
5. Modified quicksort
    * sourcecode: modified_quicksort.cpp
    * to compile: $ g++ modified_quicksort.cpp -o modified_quicksort
    * to run: $ ./modified_quicksort

**Time Calculation**

We prepared the following three scripts to check the execution time of the sorting algorithms we have implemented in this project.
1. For random i/o
    * script file name: calculate_time_random_io.sh
    * to run: $ ./calculate_time_random_io.sh
2. For sorted i/o
    * script file name: calculate_time_sorted_io.sh
    * to run: $ ./calculate_time_sorted_io.sh
3. For reversely sorted i/o
    * script file name: calculate_time_rev_sorted_io.sh
    * to run: $ ./calculate_time_rev_sorted_io.sh

If you find these files not executable, you can run the following command to make it executable:
  * $ chmod +x <file_name>

**Report**

A well-formatted report covering data structures chosen, complexity analysis, results and code is placed in report directory.

