## Last Digit of the Sum of Squares of Fibonacci Numbers

### Problem Description
Task. Compute the last digit of <img src="https://latex.codecogs.com/svg.image?F_{0}^{2}&space;&plus;&space;F_{1}^{2}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}^{2}" title="F_{0}^{2} + F_{1}^{2} + \cdots + F_{n}^{2}" />.

#### Input format.
integer *n*.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;n&space;\leq&space;10^{18}" title="0 \leq n \leq 10^{18}" />

#### Output format.
The last digit of <img src="https://latex.codecogs.com/svg.image?F_{0}^{2}&space;&plus;&space;F_{1}^{2}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}^{2}" title="F_{0}^{2} + F_{1}^{2} + \cdots + F_{n}^{2}" />.

#### Sample 1.

**Input:**

```commandline
7
```

**Output:**

```commandline
3
```

<img src="https://latex.codecogs.com/svg.image?F_{0}^{2}&space;&plus;&space;F_{1}^{2}&space;&plus;&space;\cdots&space;&plus;&space;F_{7}^{2}&space;=&space;0&space;&plus;&space;1&space;&plus;&space;1&space;&plus;&space;4&space;&plus;&space;9&space;&plus;&space;25&space;&plus;&space;64&space;&plus;&space;169&space;=&space;273" title="F_{0}^{2} + F_{1}^{2} + \cdots + F_{7}^{2} = 0 + 1 + 1 + 4 + 9 + 25 + 64 + 169 = 273" />

#### Sample 2.

**Input:**

```commandline
73
```

**Output:**

```commandline
1
```

<img src="https://latex.codecogs.com/svg.image?F_{0}^{2}&space;&plus;&space;\cdots&space;&plus;&space;F_{73}^{2}&space;=&space;1&space;052&space;478&space;208&space;141&space;359&space;608&space;061&space;842&space;155&space;201" title="F_{0}^{2} + \cdots + F_{73}^{2} = 1 052 478 208 141 359 608 061 842 155 201" />

#### Sample 3.

**Input:**

```commandline
1234567890
```

**Output:**

```commandline
0
```

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.


### What To Do

Since the brute force search algorithm for this problem is too slow (*n* may be as large as <img src="https://latex.codecogs.com/svg.image?10^{18}" title="10^{18}" />),
we need to come up with a simple formula for <img src="https://latex.codecogs.com/svg.image?F_{0}^{2}&space;&plus;&space;F_{1}^{2}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}^{2}" title="F_{0}^{2} + F_{1}^{2} + \cdots + F_{n}^{2}" />.
