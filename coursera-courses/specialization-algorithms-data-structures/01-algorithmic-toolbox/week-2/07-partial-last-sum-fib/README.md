## Last Digit of the Sum of Fibonacci Numbers Again

### Problem Introduction
Now, we would like to find the last digit of a partial sum of Fibonacci numbers:
<img src="https://latex.codecogs.com/svg.image?F_{m}&space;&plus;&space;F_{n&plus;1}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}&space;." title="F_{m} + F_{n+1} + \cdots + F_{n} ." />

### Problem Description
**Task.** Given two non-negative integers 𝑚 and 𝑛, where 𝑚 ≤ 𝑛, find the last digit of the sum <img src="https://latex.codecogs.com/svg.image?F_{m}&space;&plus;&space;F_{n&plus;1}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}&space;." title="F_{m} + F_{n+1} + \cdots + F_{n} ." />.


#### Input format.
The input consists of two non-negative integers 𝑚 and 𝑛 separated by a space.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;m&space;\leq&space;n&space;\leq&space;10^{18}" title="0 \leq m \leq n \leq 10^{18}" />

#### Output format.
Output the last digit of <img src="https://latex.codecogs.com/svg.image?F_{m}&space;&plus;&space;F_{n&plus;1}&space;&plus;&space;\cdots&space;&plus;&space;F_{n}&space;." title="F_{m} + F_{n+1} + \cdots + F_{n} ." />

#### Sample 1.

**Input:**

```commandline
3 7
```

**Output:**

```commandline
1
```

<img src="https://latex.codecogs.com/svg.image?F_{3}&space;&plus;&space;F_{4}&space;&plus;&space;F_{5}&space;&plus;&space;F_{6}&space;&plus;&space;F_{7}&space;=&space;2&space;&plus;&space;3&space;&plus;&space;5&space;&plus;&space;8&space;&plus;&space;13&space;=&space;31" title="F_{3} + F_{4} + F_{5} + F_{6} + F_{7} = 2 + 3 + 5 + 8 + 13 = 31" />

#### Sample 2.

**Input:**

```commandline
10 10
```

**Output:**

```commandline
5
```

<img src="https://latex.codecogs.com/svg.image?F_{10}&space;=&space;55" title="F_{10} = 55" />

#### Sample 3.

**Input:**

```commandline
10 200
```

**Output:**

```commandline
2
```

<img src="https://latex.codecogs.com/svg.image?F_{10}&space;&plus;&space;F_{11}&space;&plus;&space;\cdots&space;&plus;&space;F_{200}&space;=&space;734&space;544&space;867&space;157&space;818&space;093&space;234&space;908&space;902&space;110&space;449&space;296&space;423&space;262" title="F_{10} + F_{11} + \cdots + F_{200} = 734 544 867 157 818 093 234 908 902 110 449 296 423 262" />

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
