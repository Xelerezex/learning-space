## Greatest Common Divisor

### Greatest Common Divisor Problem
*CCompute the greatest common divisor of two positive integers.*

-   **Input:**  An integer <img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;&space;n&space;\leq&space;&space;10^{5}" title="0 \leq n \leq 10^{5}" />.

-   **Output:** The last digit of the *n*-th Fibonacci number.

The greatest common divisor GCD(a, b) of two positive integers a and b
is the largest integer d that divides both a and b. The solution of the Great-
est Common Divisor Problem was first described (but not discovered!) by
the Greek mathematician Euclid twenty three centuries ago. But the name
of a mathematician who discovered this algorithm, a century before Euclid
described it, remains unknown. Centuries later, Euclid’s algorithm was re-
discovered by Indian and Chinese astronomers. Now, efficient algorithm
for computing the greatest common

Your goal is to implement Euclid’s algorithm for computing GCD.

#### Input format.
Integers *a* and *b* (separated by a space).

#### Output format.
*GCD(a, b).*

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;a,b&space;\leq&space;2&space;\cdot&space;10^{9}" title="1 \leq a,b \leq 2 \cdot 10^{9}" />

#### Sample 1.

**Input:**

```commandline
28851538 1183019
```

**Output:**

```commandline
17657
```
<img src="https://latex.codecogs.com/svg.image?28851538&space;=&space;17657&space;\cdot&space;1634,&space;\quad&space;1183019&space;=&space;17657&space;\cdot&space;67." title="28851538 = 17657 \cdot 1634, \quad 1183019 = 17657 \cdot 67." />

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
