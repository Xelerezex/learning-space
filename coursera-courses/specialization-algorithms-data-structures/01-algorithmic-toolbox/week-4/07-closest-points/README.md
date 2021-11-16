## Closest Points

### Problem Introduction:
In this problem, your goal is to find the closest pair of points among the given 𝑛
points. This is a basic primitive in computational geometry having applications in,
for example, graphics, computer vision, traffic-control systems.

### Problem Description:
#### Task.
Given 𝑛 points on a plane, find the smallest distance between a √︀
pair of two (different) points. Recall
that the distance between points <img src="https://latex.codecogs.com/svg.image?(x_{1},&space;y_{1})" title="(x_{1}, y_{1})" /> and <img src="https://latex.codecogs.com/svg.image?(x_{2},&space;y_{2})" title="(x_{2}, y_{2})" />
is equal to <img src="https://latex.codecogs.com/svg.image?\sqrt{(x_{1}&space;-&space;x_{2})^{2}&space;&plus;&space;(y_{1}&space;-&space;y_{2})^{2}}" title="\sqrt{(x_{1} - x_{2})^{2} + (y_{1} - y_{2})^{2}}" />.

#### Input Format.
The first line contains the number 𝑛 of points. Each of the following 𝑛 lines defines a point
<img src="https://latex.codecogs.com/svg.image?(x_i,&space;y_i)" title="(x_i, y_i)" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?2&space;\leq&space;n&space;\leq&space;10^{5};&space;-10^{9}&space;\leq&space;x_{i},&space;y_{i}&space;\leq&space;10^{9}" title="2 \leq n \leq 10^{5}; -10^{9} \leq x_{i}, y_{i} \leq 10^{9}" /> are integers.

#### Output Format.
Output the minimum distance. The absolute value of the difference between the answer
of your program and the optimal value should be at most <img src="https://latex.codecogs.com/svg.image?10^{-3}" title="10^{-3}" />. To ensure this, output your answer
with at least four digits after the decimal point (otherwise your answer, while being computed correctly,
can turn out to be wrong because of rounding issues).

#### Sample 1.

**Input:**

```commandline
2
0 0
3 4
```

**Output:**

```commandline
5.0
```
There are only two points here. The distance between them is 5.

#### Sample 2.

**Input:**

```commandline
4
7 7
1 100
4 8
7 7
```

**Output:**

```commandline
0.0
```
There are two coinciding points among the four given points. Thus, the minimum distance is zero.

#### Sample 3.

**Input:**

```commandline
11
4 4
-2 -2
-3 -4
-1 3
23
-4 0
11
-1 -1
3 -1
-4 2
-2 4
```

**Output:**

```commandline
1.414213
```
The smallest distance is <img src="https://latex.codecogs.com/svg.image?\sqrt{2}" title="\sqrt{2}" />. There are two pairs of points at this distance: (−1, −1) and (−2, −2);
(−2, 4) and (−1, 3)..

### What To Do
This computational geometry problem has many applications in computer graphics and vision. A naive
algorithm with quadratic running time iterates through all pairs of points to find the closest pair. Your goal
is to design an 𝑂(𝑛 log 𝑛) time divide and conquer algorithm.
To solve this problem in time 𝑂(𝑛 log 𝑛), let’s first split the given 𝑛 points by an appropriately chosen
vertical line into two halves <img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" /> and <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" />
of size <img src="https://latex.codecogs.com/svg.image?\frac{n}{2}" title="\frac{n}{2}" /> (assume for simplicity that all 𝑥-coordinates of the input
points are different). By making two recursive calls for the sets <img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" /> and <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" /> , we find the minimum distances
<img src="https://latex.codecogs.com/svg.image?d_{1}" title="d_{1}" /> and <img src="https://latex.codecogs.com/svg.image?d_{2}" title="d_{2}" /> in these subsets. Let 𝑑 = min{<img src="https://latex.codecogs.com/svg.image?d_{1}" title="d_{1}" /> , <img src="https://latex.codecogs.com/svg.image?d_{2}" title="d_{2}" /> }.

It remains to check whether there exist points <img src="https://latex.codecogs.com/svg.image?p_{1}&space;\in&space;S_{1}" title="p_{1} \in S_{1}" />
and <img src="https://latex.codecogs.com/svg.image?p_{2}&space;\in&space;S_{2}" title="p_{2} \in S_{2}" /> such that the distance between them
is smaller than 𝑑. We cannot afford to check all possible such pairs since there are <img src="https://latex.codecogs.com/svg.image?\frac{n}{2}&space;\cdot&space;\frac{n}{2}&space;=&space;\Theta&space;(n^{2})" title="\frac{n}{2} \cdot \frac{n}{2} = \Theta (n^{2})" /> of them.
To check this faster, we first discard all points from <img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" /> and <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" /> whose 𝑥-distance to the middle line is greater
than 𝑑. That is, we focus on the following strip:

Stop and think: Why can we narrow the search to this strip? Now, let’s sort the points of the strip by their
𝑦-coordinates and denote the resulting sorted list by 𝑃 = [<img src="https://latex.codecogs.com/svg.image?p_{1}" title="p_{1}" /> , . . . , <img src="https://latex.codecogs.com/svg.image?p_{k}" title="p_{k}" /> ]. It turns out that if |𝑖 − 𝑗| > 7, then
the distance between points <img src="https://latex.codecogs.com/svg.image?p_{i}" title="p_{i}" /> and <img src="https://latex.codecogs.com/svg.image?p_{j}" title="p_{j}" /> is greater than 𝑑 for sure. This follows from the Exercise Break below.
Exercise break: Partition the strip into 𝑑 × 𝑑 squares as shown below and show that each such square contains at most four input points.

This results in the following algorithm. We first sort the given 𝑛 points by their 𝑥-coordinates and then
split the resulting sorted list into two halves <img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" />
and <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" /> of size <img src="https://latex.codecogs.com/svg.image?\frac{n}{2}" title="\frac{n}{2}" /> . By making a recursive call for each of the
sets <img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" /> and <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" /> , we find the minimum distances <img src="https://latex.codecogs.com/svg.image?d_{1}" title="d_{1}" /> and <img src="https://latex.codecogs.com/svg.image?d_{2}" title="d_{2}" /> in them. Let 𝑑 = min{<img src="https://latex.codecogs.com/svg.image?d_{1}" title="d_{1}" /> , <img src="https://latex.codecogs.com/svg.image?d_{2}" title="d_{2}" /> }. However, we are not
done yet as we also need to find the minimum distance between points from different sets (i.e, a point from
<img src="https://latex.codecogs.com/svg.image?S_{1}" title="S_{1}" /> and a point from <img src="https://latex.codecogs.com/svg.image?S_{2}" title="S_{2}" /> ) and check whether it is smaller than 𝑑. To perform such a check, we filter the initial
point set and keep only those points whose 𝑥-distance to the middle line does not exceed 𝑑. Afterwards, we
sort the set of points in the resulting strip by their 𝑦-coordinates and scan the resulting list of points. For
each point, we compute its distance to the seven subsequent points in this list and compute 𝑑′ , the minimum
distance that we encountered during this scan. Afterwards, we return min{𝑑, 𝑑′}.
The running time of the algorithm satisfies the recurrence relation

<img src="https://latex.codecogs.com/svg.image?T(n)&space;=&space;2&space;\cdot&space;T(\frac{n}{2})&space;&plus;&space;O(n\;log^{2}\;n)" title="T(n) = 2 \cdot T(\frac{n}{2}) + O(n\;log^{2}\;n)" />

The 𝑂(𝑛 log 𝑛) term comes from sorting the points in the strip by their 𝑦-coordinates at every iteration.
Exercise break: Prove that <img src="https://latex.codecogs.com/svg.image?T(n)&space;=&space;O(n\;log^{2}\;n)" title="T(n) = O(n\;log^{2}\;n)" /> by analyzing the recursion tree of the algorithm.
Exercise break: Show how to bring the running time down to 𝑂(𝑛 log 𝑛) by avoiding sorting at each
recursive call.
