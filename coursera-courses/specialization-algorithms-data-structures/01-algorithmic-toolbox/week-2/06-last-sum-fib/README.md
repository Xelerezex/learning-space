## Last Digit of the Sum of Fibonacci Numbers

### Last Digit of the Sum of Fibonacci Numbers Problem
*Compute the last digit of <img src="https://latex.codecogs.com/svg.image?F_0&space;&plus;&space;F_1&space;&plus;&space;\cdots&space;F_n" title="F_0 + F_1 + \cdots F_n" />.*

-   **Input:**  Integers <img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;&space;n&space;\leq&space;&space;10^{18}" title="0 \leq n \leq 10^{18}" />.

-   **Output:** *The last digit of <img src="https://latex.codecogs.com/svg.image?F_0&space;&plus;&space;F_1&space;&plus;&space;\cdots&space;F_n" title="F_0 + F_1 + \cdots F_n" />*.

**Hint.** Since the brute force approach for this problem is too slow, try to
come up with a formula for <img src="https://latex.codecogs.com/svg.image?F_0&space;&plus;&space;F_1&space;&plus;&space;\cdots&space;F_n" title="F_0 + F_1 + \cdots F_n" />
. Play with small values of n to get an insight and use a solution for the
previous problem afterwards.

#### Input format.
Integer *n*.

#### Output format.
(<img src="https://latex.codecogs.com/svg.image?F_0&space;&plus;&space;F_1&space;&plus;&space;\cdots&space;F_n" title="F_0 + F_1 + \cdots F_n" />) * mod m*.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;&space;n&space;\leq&space;&space;10^{18}" title="0 \leq n \leq 10^{18}" />

#### Sample 1.

**Input:**

```commandline
3
```

**Output:**

```commandline
4
```
<img src="https://latex.codecogs.com/svg.image?F_0&space;&plus;&space;F_1&space;&plus;&space;\cdots&space;F_n" title="F_0 + F_1 + \cdots F_n" /> *= 0 + 1 + 1 + 2 + 4*

#### Sample 2.

**Input:**

```commandline
100
```

**Output:**

```commandline
5
```

<img src="https://latex.codecogs.com/svg.image?F_{0}&space;&plus;&space;\cdots&space;&plus;&space;F_{100}&space;=&space;927&space;372&space;692&space;193&space;078&space;999&space;175." title="F_{0} + \cdots + F_{100} = 927 372 692 193 078 999 175." />

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
