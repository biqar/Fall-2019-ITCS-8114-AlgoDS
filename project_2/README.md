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

## Problem 1: Single Source Shortest Path

### Short description:
In this task, I have implemented Dijkstra’s algorithm for finding the shortest paths from a source node to all the other nodes of the graph. This algorithm will work on both directed and undirected weighted graph. The limitation of this algorithm is that, it will not work on graph contains negative edges.

Dijkstra’s algorithm applies greedy strategy to find shortest path from a single source node. Dijkstra’s algorithm use priority queue to decide (based on the already discovered path-cost) which node to be considered to relax the shortest path from the source node, is typically considered as a greedy approach. By nature, single source shortest path problem has satisfactory optimization substructure since if node `A` is connected to node `B`, node `B` is connected to node `C`, and the path must go through node `A` and node `B` to reach the destination node `C`, then the shortest path from node `A` to node `B` and the shortest path from node `B` to node `C` must be a part of the shortest path from node `A` to node `C`. So, the optimal answers from the subproblems do contribute to the optimal answer for the total problem.

### Data-structure:
In my solution, I have used priority queue from `C++` Standard Template Library with custom comparator, where it will cost `O(log n)` to push/pop an item into/from it (if the total number of elements we push to the priority queue is n). To store graph, I used adjacency list implemented by array of `C++` vector. I have used array to store other supporting data, i.e. graph node visited marking, distance of shortest paths from the sources, and parent information to reconstruct shortest paths, etc.

### Runtime analysis:
Taking input costs `E`. The Dijkstra’s algorithm costs standard `[(V+E) x logV]`. The path construction will cost `(V x V)`. Overall the runtime will be `O(E x logV)`.

## Sample Graphs

<table>
  <tr>
    <td>
       <img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/dir_line.png" alt="dir_line" width="300"/></td>
    <td><img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/undir_random.png" alt="undir_random" width="300"/></td>
    <td><img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/undir_line.png" alt="undir_line" width="300"/></td>
  </tr>
  <tr>
    <td align="middle">(a): Directed line graph</td>
    <td align="middle">(b): Undirected random graph</td>
    <td align="middle">(c): Undirected line graph</td>
  </tr>
  <tr>
    <td><img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/undir_complete.png" alt="undir_complete" width="300"/></td>
    <td><img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/dir_random.png" alt="dir_random" width="300"/></td>
    <td><img align="center" src="https://github.com/biqar/Fall-2019-ITCS-8114-AlgoDS/blob/master/project_2/report/problem_sample.png" alt="problem_sample" width="300"/></td>
  </tr>
  <tr>
    <td align="middle">(d): Undirected complete graph</td>
    <td align="middle">(e): Directed random graph</td>
    <td align="middle">(f): Sample given graph</td>
  </tr>
  <tr>
    <td colspan="3" align="middle">Figure 1: Graphical demonstration of the sample input graphs</td>
  </tr>
</table>

## Problem 2: Minimum Spanning Tree (MST)

### Short description:
For this task, I have implemented Kruskal’s algorithm to find minimum spanning tree of an undirected graph. This algorithm will only work on undirected graph. The working principal of Kruskal’s algorithm is to choose the edge with minimum weight (greedy approach) that connects any two trees in the forest. Eventually it will become a single tree (only if it is a connected graph) which connects all the nodes of the graph.

### Data-structure
I have used disjoint set data-structure to track the set-id of a node. Initially every node assigned to his own set-id. When we found an edge, which connects two nodes from two separate sets, we make a connection between them by applying Union operation. I applied two technique called path-compression in find and union-by-rank to reduce the time complexity of each operation done on disjoint set data-structure. This two techniques actually complement each other and make the amortized time complexity even smaller than O(log n) and becomes constant.

In my solution I used edge list (with the support of vector from `C++` Standard Template Library) to store the edge information. To sort the edge list by weight, I use sort function provided by `C++` standard library which requires `O(E x log(E))` in the worst case scenario (to sort E edges).

### Runtime analysis: 
Taking input costs `E`.

In Kruskal’s algorithm,
* Initialize the disjoint-set costs `V`
* Edge list shorting costs `[E x log(E)]`
* (2 x E) find_set call with total cost approximately `c1 x (2 x E)`, where `c1` is a constant
* V union_by_rank call with total cost approximately `c2 x V`, where `c2` is a constant

Overall running time `O(E x log E)`

## Source Code Execution Instructions
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

## Report

A well-formatted report covering data structures chosen, complexity analysis, results and code is placed in report directory.
