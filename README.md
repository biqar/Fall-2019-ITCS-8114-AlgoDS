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

### Project 2: Graph Algorithms (singles-source shortest path and Minimum Spanning Tree)
---
In this project, you will implement two graph algorithms mentioned below. Note: You can work alone or in a team of TWO max.

**Problem 1:**
Find shortest path tree in both directed and undirected weighted graphs for a given source vertex. Assume there is no negative edge in your graph. You will print each path and path cost for a given source.

**Problem 2:**
Given a connected, undirected, weighted graph, find a spanning tree using edges that minimizes the total weight 𝑤(𝑇) = ∑<sub>(u, v)∈T</sub> 𝑤(𝑢, 𝑣). Use Kruskal algorithm to find Minimum Spanning Tree (MST). You will printout the edges of the tree and the total cost of your answer.

**Input format:**
For each problem, you will take input from a text file. Say you want to run algorithm on the following undirected graph. The corresponding file format would be:

```
6  10 U
A  B  1
A  C  2
B  C  1
B  D  3
B  E  2
C  D  1
C  E  2
D  E  4
D  F  3
E  F  3
A
```

Here, the first two numbers represent the number of vertices and edges. The letter U stands for undirected graph (D for directed). From the second line, it mentions all edges and its weight (e.g. *𝑒𝑑𝑔𝑒(𝐴, 𝐵)* and its weight is 1. The last line is optional. If given, it represents the source node.

**Submission instructions:**
* A well-formatted report covering a short description of each algorithm, data structure chosen, runtime of your code, sample input/output, instruction to run your program easily.
* For each problem, run your program for four different graphs of your choice. Use your judgement to define test graphs that you think interesting and reasonable. For example:
* Undirected graph: at least 7 nodes and 12 edges
* Directed graph: at least 7 nodes and 15 edges
* Clean code for TA to execute.
* You can use any programming language (e.g. C/C++, Java, Python, etc.)
* If worked in a team, both members are required to submit everything separately.
* Hardcopy of your report to me directly; one copy per team.

**Grading Scheme:**

![image for project_2 grading scheme](https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/P2-Rubrics.png)

### Project 3: Pattern Matching Algorithms
---
Note: You can work alone or in a team of three max.

For this assignment, you will implement only THREE pattern matching algorithms of your choice from the list given below.

* Brute-Force algorithm
* Boyer-Moore-Horspool algorithm
* Knuth-Morris-Pratt algorithm
* Boyer-Moore algorithm
* Finite automation for pattern matching

**Experiment:**

* Compare three algorithms for several different input text and patterns; at least 10 different cases
* Mention the number of comparisons required in a table for each case, for each algorithm

**Submission:**

* A well-formatted report covering short description of each algorithm, data structure used, runtime of your code, sample input/output, instruction to run your program easily.
* Clean code for TA to execute.
* You can use any programming language (e.g. C/C++, Java, Python, etc.)
* If worked in a team, still both members are required to submit everything separately.
* Hardcopyof your report to me directly; one copy per team.

**Grading Scheme:**

* 3 x 15 = 45 points: For implementing THREE algorithms
* 20 points: for experiment
* 10 points: Report
