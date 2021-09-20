## Maximum Pairwise Product

### Maximum Pairwise Product Problem
*Find the maximum product of two distinct numbers in a sequence of non-negative integers.*

-    **Input :**A sequence of non-negative
integers.

-    **Output:** The maximum value that
can be obtained by multiplying
two different elements from the se-
quence.

Given a sequence of non-negative integers <img src="https://latex.codecogs.com/svg.image?a_1,&space;\cdots,&space;a_2" title="a_1, \cdots, a_2" />, compute

<img src="https://latex.codecogs.com/svg.image?\underset{1\leqslant&space;i&space;\neq&space;&space;j\leqslant&space;n}{\textit{max}}a_i&space;\cdot&space;a_j" title="\underset{1\leqslant i \neq j\leqslant n}{\textit{max}}a_i \cdot a_j" />

Note that i and j should be different, though it may be the case that <img src="https://latex.codecogs.com/svg.image?a_i&space;=&space;a_j&space;" title="a_i = a_j " />.

#### Input format.
The first line contains an integer *n*. The next line contains
*n* non-negative integers <img src="https://latex.codecogs.com/svg.image?a_1,&space;\cdots,&space;a_2" title="a_1, \cdots, a_2" /> (separated by spaces).

#### Output format.
The maximum pairwise product.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?2&space;\leqslant&space;&space;n&space;\leqslant&space;&space;2&space;\cdot&space;10^5;\quad&space;0&space;\leqslant&space;&space;a_1,&space;...,&space;a_n&space;\leqslant&space;&space;2&space;\cdot&space;10^5." title="2 \leqslant n \leqslant 2 \cdot 10^5;\quad 0 \leqslant a_1, ..., a_n \leqslant 2 \cdot 10^5." />

#### Sample 1.

##### Input:

```commandline
3
123
Output:
630
```

#### Sample 2.

##### Input:

```commandline
10
7 5 14 2 8 8 10 1 2 3
```

##### Output:

```commandline
140
```

##### Time limits 1 sec.

##### Memory limit. 512 Mb.

##### Coursera Text:

*In this programming challenge, your goal is to implement a program that works in less than one second even on huge datasets. In section Maximum Pairwise Product of the file week1_programming_challenges/week1_programming_challenges.pdf we walk you through a step-by-step process of solving this challenge. We will encounter several common pitfalls and will show you how to fix them.*

*The archive file with all the statements and starters is available from a separate page (that can be found at the left pane under Resources): https://www.coursera.org/learn/algorithmic-toolbox/resources/3r3Mv*
