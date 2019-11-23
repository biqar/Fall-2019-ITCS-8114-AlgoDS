# Project 2: Graph Algorithms (singles-source shortest path and Minimum Spanning Tree)

In this project, I have implemented two graph algorithms mentioned below. Note: I have worked alone in this project.

**Problem 1:**
Find shortest path tree in both directed and undirected weighted graphs for a given source vertex. Assume there is no negative edge in the input graph. Need to print each path and path cost for a given source.

**Problem 2:**
Given a connected, undirected, weighted graph, find a spanning tree using edges that minimizes the total weight 𝑤(𝑇) = ∑<sub>(u, v)∈T</sub> 𝑤(𝑢, 𝑣). Use Kruskal's algorithm to find Minimum Spanning Tree (MST). Need to print the edges of the tree and the total cost of MST.

**Input format:**
For each problem, I have taken input from a text file. For example, to run an algorithm on a undirected graph, the corresponding file format would be:

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

**Submission Contains:**
* Solution for the problems (implemented in C++) mentioned above.
* A well-formatted report covering a short description of each algorithm, data structure chosen, runtime of your code, sample input/output, instruction to run the programs easily.

**Source Code Execution Instructions:**
```
# go to project directory
$ cd project_2

# build the project
$ make

# command to run solution for problem 1
# general instruction: $ ./build/sss_path < input_file > output_file
# here is a sample
$ ./build/sss_path < input/sample.in > sample_sssp.out

# command to run solution for problem 2
# general instruction: $ ./build/mst < input_file > output_file
# here is a sample
$ ./build/mst < input/sample.in > sample_mst.out
```
