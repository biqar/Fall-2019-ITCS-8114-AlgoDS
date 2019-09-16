# Fall-2019-ITCS-8114-AlgoDS
This repository will contains the projects and assignments of course **ITCS 6114/8114: Algorithms and Data Structures**. This course has been taken in Fall 2019 semester, as part of my PhD degree at UNC Charlotte.

### Project 1: Comparison-based Sorting Algorithms
---
Implement the following sorting algorithms and compare them. You can use any programming language (e.g. C/C++, Java, Python, C#). In this project, you can work alone or as team of TWO.

1. Insertion sort
2. Merge sort
3. Heapsort [vector based, and insert one item at a time]
4. In-place quicksort (any random item or the first or the last item of your input can be pivot).
5. Modified quicksort
    * Use median-of-three as pivot.
    * For small sub-problem of size <= 10, use insertion sort.

**Execution instructions:**

1. Run these algorithms for different input sizes (e.g. n = 1000, 2000, 4000, 5000, 10000 .. 40000, 50000). You will randomly generate numbers for your input array. Record the execution time (need to take the average as discussed in the class) and plot them all in a single graph against input size. Note that you will compare these sorting algorithms for the same data set.
2. Also observe and present performance of the following two special cases:
    * Input array is already sorted.
    * Input array is reversely sorted.

**Grading Scheme:**

![image for project_1 grading scheme](https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_1/resource/Rubrics.png)

**Submission instructions:**

* Canvas upload
  1. A well-formatted report covering data structures chosen, complexity analysis, results and code.
  2. Upload program code for execution. Make sure you provide readme for TA.
* In addition, hardcopy of report without code to me in the class.
