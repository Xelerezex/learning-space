## Majority Element

### Problem Introduction:
Majority rule is a decision rule that selects the alternative which has a majority,
that is, more than half the votes.
Given a sequence of elements <img src="https://latex.codecogs.com/svg.image?a_{1},&space;a_{2},&space;\cdots&space;,&space;a_{n}" title="a_{1}, a_{2}, \cdots , a_{n}" /> , you would like to check whether
it contains an element that appears more than 𝑛/2 times. A naive way to do
this is the following.

```commandline
MajorityElement(𝑎 1 , 𝑎 2 , . . . , 𝑎 𝑛 ):
for 𝑖 from 1 to 𝑛:
    currentElement ← 𝑎 𝑖
    count ← 0
    for 𝑗 from 1 to 𝑛:
        if 𝑎 𝑗 = currentElement:
            count ← count + 1
    if count > 𝑛/2:
        return 𝑎 𝑖
return “no majority element”
```
The running time of this algorithm is quadratic. Your goal is to use the divide-and-conquer technique to
design an <img src="https://latex.codecogs.com/svg.image?O(n&space;\;&space;log&space;\;&space;n)" title="O(n \; log \; n)" /> algorithm.

### Problem Description:
#### Task.
The goal in this code problem is to check whether an input sequence contains a majority element.

#### Input Format.
The first line contains an integer 𝑛, the next one contains a sequence of 𝑛 non-negative
integers <img src="https://latex.codecogs.com/svg.image?a_{0},&space;a_{1},&space;\cdots,&space;a_{n-1}" title="a_{0}, a_{1}, \cdots, a_{n-1}" />

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^{5};&space;\;&space;0&space;\leq&space;a_{i}&space;\leq&space;10^{9}&space;\;&space;for&space;\;&space;all&space;\;&space;0&space;\leq&space;i&space;\leq&space;n." title="1 \leq n \leq 10^{5}; \; 0 \leq a_{i} \leq 10^{9} \; for \; all \; 0 \leq i \leq n." />

#### Output Format.
Output 1 if the sequence contains an element that appears strictly more than 𝑛/2 times,
and 0 otherwise.

#### Sample 1.

**Input:**

```commandline
5
2 3 9 2 2
```

**Output:**

```commandline
1
```
2 is the majority element.

#### Sample 2.

**Input:**

```commandline
4
1 2 3 4
```

**Output:**

```commandline
0
```
There is no majority element in this sequence.

#### Sample 3.

**Input:**

```commandline
4
1 2 3 1
```

**Output:**

```commandline
0
```
This sequence also does not have a majority element (note that the element 1 appears twice and hence
is not a majority element).

### What To Do
As you might have already guessed, this problem can be solved by the divide-and-conquer algorithm in time
𝑂(𝑛 log 𝑛). Indeed, if a sequence of length 𝑛 contains a majority element, then the same element is also
a majority element for one of its halves. Thus, to solve this problem you first split a given sequence into
halves and make two recursive calls. Do you see how to combine the results of two recursive calls?
It is interesting to note that this problem can also be solved in 𝑂(𝑛) time by a more advanced (non-divide
and conquer) algorithm that just scans the given sequence twice.
