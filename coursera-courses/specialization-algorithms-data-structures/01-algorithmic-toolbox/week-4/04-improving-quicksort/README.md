
## Improving Quick Sort

### Problem Introduction:
The goal in this problem is to redesign a given implementation of the random-
ized quick sort algorithm so that it works fast even on sequences containing
many equal elements.

### Problem Description:
#### Task.
To force the given implementation of the quick sort algorithm to efficiently process sequences with
few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
partition procedure should partition the array into three parts: < 𝑥 part, = 𝑥 part, and > 𝑥 part.

#### Input Format.
The first line of the input contains an integer 𝑛. The next line contains a sequence of 𝑛
integers <img src="https://latex.codecogs.com/svg.image?a_{0},&space;a_{1},&space;\cdots,&space;a_{n-1}" title="a_{0}, a_{1}, \cdots, a_{n-1}" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^{5};&space;\;&space;0&space;\leq&space;a_{i}&space;\leq&space;10^{9}&space;\;&space;for&space;\;&space;all&space;\;&space;0&space;\leq&space;i&space;\leq&space;n." title="1 \leq n \leq 10^{5}; \; 0 \leq a_{i} \leq 10^{9} \; for \; all \; 0 \leq i \leq n." />

#### Output Format.
Output this sequence sorted in non-decreasing order.

#### Sample 1.

**Input:**

```commandline
5
2 3 9 2 2
```

**Output:**

```commandline
22239
```
#### Starter Files
In the starter files, you are given an implementation of the randomized quick sort algorithm using a 2-way
partition procedure. This procedure partitions the given array into two parts with respect to a pivot 𝑥: ≤ 𝑥
part and > 𝑥 part. As discussed in the video lectures, such an implementation has Θ(<img src="https://latex.codecogs.com/svg.image?n^{2}" title="n^{2}" />) running time on
sequences containing a single unique element. Indeed, the partition procedure in this case splits the array
into two parts, one of which is empty and the other one contains 𝑛 − 1 elements. It spends 𝑐𝑛 time on this.
The overall running time is then

𝑐𝑛 + 𝑐(𝑛 − 1) + 𝑐(𝑛 − 2) + . . . = Θ(<img src="https://latex.codecogs.com/svg.image?n^{2}" title="n^{2}" />) .

#### What To Do
Implement a 3-way partition procedure and then replace a call to the 2-way partition procedure by a call to
the 3-way partition procedure.
