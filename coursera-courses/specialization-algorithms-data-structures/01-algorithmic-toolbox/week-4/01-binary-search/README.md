## Binary Search

### Problem Introduction:
In this problem, you will implement the binary search algorithm that allows searching
very efficiently (even huge) lists, provided that the list is sorted.

### Problem Description:
#### Task.
The goal in this code problem is to implement the binary search algorithm.

#### Input Format.
The first line of the input contains an integer <img src="https://latex.codecogs.com/svg.image?n" title="n" />
and a sequence <img src="https://latex.codecogs.com/svg.image?a_0&space;<&space;a_1&space;<&space;\cdots&space;<&space;a_{n-1}" title="a_0 < a_1 < \cdots < a_{n-1}" />
of
<img src="https://latex.codecogs.com/svg.image?n" title="n" />
pairwise distinct positive integers in increasing order. The next line contains an integer <img src="https://latex.codecogs.com/svg.image?k" title="k" /> and <img src="https://latex.codecogs.com/svg.image?k" title="k" />
positive integers <img src="https://latex.codecogs.com/svg.image?b_0,&space;b_1,&space;\cdots,&space;b_{k-1}" title="b_0, b_1, \cdots, b_{k-1}" /> .

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n,&space;k&space;\leq&space;10^{4};&space;1&space;\leq&space;a_{i}&space;\leq&space;10^{9}" title="1 \leq n, k \leq 10^{4}; 1 \leq a_{i} \leq 10^{9}" /> for all
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;i&space;<n;&space;1&space;\leq&space;b_j&space;\leq&space;10^{9}" title="0 \leq i <n; 1 \leq b_j \leq 10^{9}" /> for all
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;j&space;<&space;k;" title="0 \leq j < k;" />

#### Output Format.
For all <img src="https://latex.codecogs.com/svg.image?i" title="i" /> from 0 to 𝑘 − 1, output an index 0 ≤ 𝑗 ≤ 𝑛 − 1 such that <img src="https://latex.codecogs.com/svg.image?a_j&space;=&space;b_j" title="a_j = b_j" /> or −1 if there
is no such index.

#### Sample 1.

**Input:**

```commandline
5 1 5 8 12 13
5 8 1 23 1 11
```

**Output:**

```commandline
2 0 -1 0 -1
```
In this sample, we are given an increasing sequence <img src="https://latex.codecogs.com/svg.image?a_0&space;=&space;1,&space;a_1&space;=&space;5,&space;a_2&space;=&space;8,&space;a_3&space;=&space;12,&space;a_4&space;=&space;13" title="a_0 = 1, a_1 = 5, a_2 = 8, a_3 = 12, a_4 = 13" /> of length
five and five keys to search: 8, 1, 23, 1, 11. We see that <img src="https://latex.codecogs.com/svg.image?a_2&space;=&space;8" title="a_2 = 8" /> and <img src="https://latex.codecogs.com/svg.image?a_0&space;=&space;1" title="a_0 = 1" />, but the keys 23 and 11 do
not appear in the sequence 𝑎. For this reason, we output a sequence 2, 0, −1, 0, −1.
