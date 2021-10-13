## Collecting Signatures

### Problem Introduction:
You are responsible for collecting signatures from all tenants of a certain building.
For each tenant, you know a period of time when he or she is at home.
You would like to collect all signatures by visiting the building as few times as
possible.
The mathematical model for this problem is the following. You are given a set
of segments on a line and your goal is to mark as few points on a line as possible
so that each segment contains at least one marked point.

### Problem Description:

#### Task.
Given a set of *𝑛* segments <img src="https://latex.codecogs.com/svg.image?\left\{[a_0,&space;b_0],&space;[a_1,&space;b_1],&space;\cdots,&space;[a_{n-1},&space;b_{n-1}]\right\}&space;" title="\left\{[a_0, b_0], [a_1, b_1], \cdots, [a_{n-1}, b_{n-1}]\right\} " /> with integer coordinates on a line, find
the minimum number *𝑚* of points such that each segment contains at least one point. That is, find a
set of integers *𝑋* of the minimum size such that for any segment <img src="https://latex.codecogs.com/svg.image?[a_{i},&space;b_{i}]" title="[a_{i}, b_{i}]" /> there is a point *𝑥* ∈ *𝑋* such
that <img src="https://latex.codecogs.com/svg.image?a_{i}&space;\leq&space;x&space;\leq&space;&space;b_{i}" title="a_{i} \leq x \leq b_{i}" />.

#### Input Format.
The first line of the input contains the number *𝑛* of segments. Each of the following *𝑛* lines
contains two integers <img src="https://latex.codecogs.com/svg.image?a_{i}" title="a_{i}" /> and <img src="https://latex.codecogs.com/svg.image?b_{i}" title="b_{i}" /> (separated by a space) defining the coordinates of endpoints of the 𝑖-th
segment.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;100;&space;\quad&space;0&space;\leq&space;a_i&space;\leq&space;b_i&space;\leq&space;10^{9}" title="1 \leq n \leq 100; \quad 0 \leq a_i \leq b_i \leq 10^{9}" /> for all <img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;i&space;<&space;n." title="0 \leq i < n." />

#### Output Format.
Output the minimum number 𝑚 of points on the first line and the integer coordinates
of 𝑚 points (separated by spaces) on the second line. You can output the points in any order. If there
are many such sets of points, you can output any set. (It is not difficult to see that there always exist
a set of points of the minimum size such that all the coordinates of the points are integers.)

#### Sample 1.

**Input:**

```commandline
3
1 3
2 5
3 6
```

**Output:**

```commandline
1
3
```
In this sample, we have three segments: [1, 3], [2, 5], [3, 6] (of length 2, 3, 3 respectively). All of them
contain the point with coordinate 3: <img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;3&space;\leq&space;3,&space;\quad&space;2&space;\leq&space;3&space;\leq&space;5,&space;3&space;\leq&space;3&space;\leq&space;6.&space;" title="1 \leq 3 \leq 3, \quad 2 \leq 3 \leq 5, 3 \leq 3 \leq 6. " />

#### Sample 2.

**Input:**

```commandline
4
4 7
1 3
2 5
5 6
```

**Output:**

```commandline
2
3 6
```

The second and the third segments contain the point with coordinate 3 while the first and the fourth
segments contain the point with coordinate 6. All the four segments cannot be covered by a single
point, since the segments [1, 3] and [5, 6] are disjoint.
