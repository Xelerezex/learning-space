## Number of Inversions

### Problem Introduction:
An inversion of a sequence <img src="https://latex.codecogs.com/svg.image?a_{0},&space;a_{1},&space;\cdots,&space;a_{n&space;-&space;1}" title="a_{0}, a_{1}, \cdots, a_{n - 1}" /> is a pair of indices 0 ≤ 𝑖 < 𝑗 < 𝑛 such
that <img src="https://latex.codecogs.com/svg.image?a_{i}&space;>&space;a_{j}" title="a_{i} > a_{j}" /> . The number of inversions of a sequence in some sense measures how
close the sequence is to being sorted. For example, a sorted (in non-descending
order) sequence contains no inversions at all, while in a sequence sorted in de-
scending order any two elements constitute an inversion (for a total of 𝑛(𝑛 − 1)/2
inversions).

### Problem Description:
#### Task.
The goal in this problem is to count the number of inversions of a given sequence.

#### Input Format.
The first line contains an integer 𝑛, the next one contains a sequence of integers
<img src="https://latex.codecogs.com/svg.image?a_{0},&space;a_{1},&space;\cdots,&space;a_{n&space;-&space;1}" title="a_{0}, a_{1}, \cdots, a_{n - 1}" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^{5};&space;\;&space;0&space;\leq&space;a_{i}&space;\leq&space;10^{9}&space;\;&space;for&space;\;&space;all&space;\;&space;0&space;\leq&space;i&space;\leq&space;n." title="1 \leq n \leq 10^{5}; \; 0 \leq a_{i} \leq 10^{9} \; for \; all \; 0 \leq i \leq n." />

#### Output Format.
Output the number of inversions in the sequence.

#### Sample 1.

**Input:**

```commandline
5
2 3 9 2 9
```

**Output:**

```commandline
2
```
The two inversions here are <img src="https://latex.codecogs.com/svg.image?(1,&space;3)&space;\;&space;(a_{1}&space;=&space;3&space;>&space;2&space;=&space;a_{3})&space;\;&space;and&space;\;&space;(2,&space;3)&space;\;&space;(a_{2}&space;=&space;9&space;>&space;2&space;=&space;a_{3})" title="(1, 3) \; (a_{1} = 3 > 2 = a_{3}) \; and \; (2, 3) \; (a_{2} = 9 > 2 = a_{3})" />.


### What To Do
This problem can be solved by modifying the merge sort algorithm. For this, we change both the *Merge* and
*MergeSort* procedures as follows:
-   *Merge(𝐵, 𝐶)* returns the resulting sorted array and the number of pairs (𝑏, 𝑐) such that 𝑏 ∈ 𝐵, 𝑐 ∈ 𝐶,
and 𝑏 > 𝑐;
-   *MergeSort(𝐴)* returns a sorted array 𝐴 and the number of inversions in 𝐴.
