# Project 3: Pattern Matching Algorithms

Note: You can work alone or in a team of three max.

For this assignment, you will implement only THREE pattern matching algorithms of your choice from the list given below.

* Brute-Force algorithm
* Boyer-Moore-Horspool algorithm
* Knuth-Morris-Pratt algorithm
* Boyer-Moore algorithm
* Finite automation for pattern matching

**Code Repository Overview**
```
.
├── build
│   ├── 1_brute_force
│   ├── 2_bmh
│   ├── 3_bm
│   ├── 4_finite_automata
│   └── 5_kmp
├── input
│   ├── 0_sample_failed.in
│   ├── 1_sample_success.in
│   ├── 2_sample_correctness_dfa.in
│   ├── 3_sample_correctness_bmh.in
│   ├── 4_sample_correctness_kmp.in
│   ├── 5_sample_correctness_bm.in
│   ├── 6_sample_worst_bf.in
│   ├── 7_sample_worst_bmh.in
│   ├── 8_sample_worst_dfa.in
│   └── 9_sample_worst_kmp.in
├── Makefile
├── README.md
├── report
│   └── report_project_3.docx
└── src
    ├── 1_brute_force.cpp
    ├── 2_bmh.cpp
    ├── 3_bm.cpp
    ├── 4_finite_automata.cpp
    ├── 5_kmp.cpp
    └── template.cpp

4 directories, 24 files
```

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

**Source Code Execution Instructions:**
```
# go to project directory
$ cd project_3

# build the project
$ make

# command to run solution for Brute-Force algorithm
# general instruction: $ ./build/1_brute_force < input_file > output_file
# here is a sample
$ ./build/1_brute_force < input/sample.in > sample_bf.out

# command to run solution for Boyer-Moore algorithm
# general instruction: $ ./build/2_bmh < input_file > output_file
# here is a sample
$ ./build/2_bmh < input/sample.in > sample_bmh.out

# command to run solution for Boyer-Moore-Horspool algorithm
# general instruction: $ ./build/3_bm < input_file > output_file
# here is a sample
$ ./build/3_bm < input/sample.in > sample_bm.out

# command to run solution for Finite automation for pattern matching
# general instruction: $ ./build/4_finite_automata < input_file > output_file
# here is a sample
$ ./build/4_finite_automata < input/sample.in > sample_fa.out

# command to run solution for Knuth-Morris-Pratt algorithm
# general instruction: $ ./build/5_kmp < input_file > output_file
# here is a sample
$ ./build/5_kmp < input/sample.in > sample_kmp.out
```
