# Project 1: Comparison-based Sorting Algorithms
This repository will contains the entities of project_1 of course **ITCS 6114/8114: Algorithms and Data Structures**.

### Collaborators
1. Abdullah Al Raqibul Islam (ID# 801151189)
2. Jawad Chowdhury (ID# 801135477)

### Input & Output Specification

1. To compare different sorting algorithms, we considered three types of input set
    * Randomly generated input, placed in input/random directory
    * Input array is already sorted, placed in input/sorted directory
    * Input array is reversely sorted, placed in input/rev_sorted directory
2. Each types of input set contains different input sizes (e.g. n = 5000, 10000, 15000, 20000, 25000 .. 40000, 45000, 50000). You will get the idea of input size from the file name. For example, if the input contains 10,000 numbers then the file name will be in_10K[dot]txt.
3. Each input file contains two lines of inputs. First line of  will contains **N**, the number of elements considered for the sorting. The next line will contains **N** numbers **(0 <= A[i] < 10^8)**.
4. For every input set we write **N** lines of output, each line will contains a single number in sorted manner.

### Source Code Execution Instructions

In this project, we have implemented the following sorting algorithms and compare them. For this project, we have used C/C++ as programming language.
```
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
```
### Performance Characterization

#### Test Platform
* Processor: Intel(R) Xeon(R) CPU E5-2620 2.00GHz (12 Core)
* Linux version: 5.0.0-27-generic
* g++ version: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0

#### Sorting Algorithm's Performance Evaluation

Due to the huge scaling difference of the execution time for the sorting algorithms w.r.t. the different cases, we have used the logarithmic scale in the y-axis for the input-size vs time data plotting. For all the figures in this section for the y-axis value, the lower is better.

In figure 1 (a), we can see the time consumption rate for insertion sort is significantly higher than all other sorting algorithms (i.e. merge sort, heapsort, in-place quicksort and modified quicksort). Here, the plotting is being done for randomly ordered inputs. The insertion sorting algorithm takes `O(n^2)` whereas rest of the other algorithm does it in `O(nlogn)` times and this is being reflected in the results of figure 1 (a).

<table>
  <tr>
    <td>
       <img align="left" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_1/plotting/comparison_random.PNG" alt="random_data"/>
    </td>
    <td><img align="left" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_1/plotting/comparison_sorted.PNG" alt="sorted_data"/>
    </td>
    <td><img align="left" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_1/plotting/comparison_rev_sorted.PNG" alt="reverse_sorted_data"/>
    </td>
  </tr>
  <tr>
    <td align="middle">Figure 1 (a): Random data</td>
    <td align="middle">Figure 1 (b): Sorted data</td>
    <td align="middle">Figure 1 (c): Reverse sorted data</td>
  </tr>
  <tr>
    <td colspan="3" align="middle">Figure 1: Comparing performance of different sorting algorithms</td>
  </tr>
</table>

In figure 1 (b), we can see the time consumption rate for in-place quicksort is much higher than all other sorting algorithms (i.e. insertion sort, merge sort, heapsort, and modified quicksort) as this is the worst case for in-place quicksort and it takes `O(n^2)` time. On the other hand, the sorted input data makes the best case scenario for insertion sorting algorithm and it is `O(n)`. For rest of the algorithms (i.e. merge sort, heapsort, and modified quicksort), the running time for this case is `O(nlogn)`. We can see the reflection in figure 1 (b).

In figure 1 (c), we can see the time consumption rate for both insertion and in-place quicksort is much higher than all other sorting algorithms (i.e. merge sort, heapsort, and modified quicksort) as this is the worst case for both of these algorithms and it take `O(n^2)` times. On the other hand, rest of the other algorithms (i.e. merge sort, heapsort, and modified quicksort) take much lower time for this case, having a time complexity of `O(nlogn)`.

### How to Reproduce

We prepared the following three scripts to check the execution time of the sorting algorithms we have implemented in this project.
```
1. For random i/o
    * script file name: calculate_time_random_io.sh, to run:
    $ ./calculate_time_random_io.sh
2. For sorted i/o
    * script file name: calculate_time_sorted_io.sh, to run:
    $ ./calculate_time_sorted_io.sh
3. For reversely sorted i/o
    * script file name: calculate_time_rev_sorted_io.sh, to run:
    $ ./calculate_time_rev_sorted_io.sh
```
If you find these files not executable, you can run the following command to make it executable:
```
$ chmod +x <file_name>
```
### Report

A well-formatted report covering data structures chosen, complexity analysis, results and code is placed in report directory.

