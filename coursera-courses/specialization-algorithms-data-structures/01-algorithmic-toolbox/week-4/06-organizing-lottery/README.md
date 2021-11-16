## Organizing a Lottery

### Problem Introduction:
You are organizing an online lottery. To participate, a person bets on a single
integer. You then draw several ranges of consecutive integers at random.
A participant’s payoff then is proportional to the number of ranges that
contain the participant’s number minus the number of ranges that does not
contain it. You need an efficient algorithm for computing the payoffs for all
participants. A naive way to do this is to simply scan, for all participants, the
list of all ranges. However, you lottery is very popular: you have thousands
of participants and thousands of ranges. For this reason, you cannot afford
a slow naive algorithm.

### Problem Description:
#### Task.
You are given a set of points on a line and a set of segments on a line. The goal is to compute, for
each point, the number of segments that contain this point.

#### Input Format.
The first line contains two non-negative integers 𝑠 and 𝑝 defining the number of segments
and the number of points on a line, respectively. The next 𝑠 lines contain two integers <img src="https://latex.codecogs.com/svg.image?a_{i},&space;b_{j}" title="a_{i}, b_{j}" /> defining
the 𝑖-th segment <img src="https://latex.codecogs.com/svg.image?\left&space;[&space;a_{i},&space;b_{j}&space;\right&space;]" title="\left [ a_{i}, b_{j} \right ]" />. The next line contains 𝑝 integers defining points <img src="https://latex.codecogs.com/svg.image?x_{1},&space;x_{2},&space;\cdots,&space;x_{p}." title="x_{1}, x_{2}, \cdots, x_{p}." />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;s,p&space;\leq&space;50000;&space;-10^{8}&space;\leq&space;a_{i}&space;\leq&space;b_{i}&space;\leq&space;10^{8}&space;\;for&space;\;&space;all&space;\;&space;0&space;\leq&space;i&space;<&space;s;&space;-10^{8}&space;\;&space;for&space;\;&space;all&space;\;&space;0&space;\leq&space;j&space;<&space;p" title="1 \leq s,p \leq 50000; -10^{8} \leq a_{i} \leq b_{i} \leq 10^{8} \;for \; all \; 0 \leq i < s; -10^{8} \; for \; all \; 0 \leq j < p" />

#### Output Format.
Output 𝑝 non-negative integers <img src="https://latex.codecogs.com/svg.image?k_{0},&space;k_{1},&space;\cdots,&space;k_{p-1}" title="k_{0}, k_{1}, \cdots, k_{p-1}" /> where <img src="https://latex.codecogs.com/svg.image?k_{i}" title="k_{i}" /> is the number of segments which
contain <img src="https://latex.codecogs.com/svg.image?x_{i}" title="x_{i}" /> . More formally,
<img src="https://latex.codecogs.com/svg.image?k_{i}&space;=&space;\left|&space;\left\{&space;j:&space;a_{j}&space;\leq&space;x_{i}&space;\leq&space;b_{j}&space;\right\}\right|" title="k_{i} = \left| \left\{ j: a_{j} \leq x_{i} \leq b_{j} \right\}\right|" />

#### Sample 1.

**Input:**

```commandline
2 3
0 5
7 10
1 6 11
```

**Output:**

```commandline
1 0 0
```
Here, we have two segments and three points. The first point lies only in the first segment while the
remaining two points are outside of all the given segments.

#### Sample 2.

**Input:**

```commandline
1 3
-10 10
-100 100 0
```

**Output:**

```commandline
0 0 1
```

#### Sample 3.

**Input:**

```commandline
3 2
0 5
-3 2
7 10
1 6
```

**Output:**

```commandline
2 0
```
