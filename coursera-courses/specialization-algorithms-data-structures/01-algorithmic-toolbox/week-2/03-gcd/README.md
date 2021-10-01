## Last Digit of Fibonacci Number

### Last Digit of Fibonacci Number Problem
*Compute the last digit of the n-th Fibonacci number.*

-   **Input:**  An integer <img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;&space;n&space;\leq&space;&space;10^{5}" title="0 \leq n \leq 10^{5}" />.

-   **Output:** The last digit of the *n*-th Fibonacci number.

To solve this problem, let’s compute F n and simply output its last digit:
<img src="https://latex.codecogs.com/svg.image?F_{n}" title="F_{n}" />

```commandline
FibonacciLastDigit(n):
F[0] ← 0
F[1] ← 1
for i from 2 to n:
    F[i] ← F[i − 1] + F[i − 2]
return F[n] mod 10
```

Note that Fibonacci numbers grow fast. For example,

<img src="https://latex.codecogs.com/svg.image?F_{100}&space;=&space;354&space;224&space;848&space;179&space;261&space;915&space;075." title="F_{100} = 354 224 848 179 261 915 075." />

Therefore, if you use C++ int32_t or int64_t types for storing *F*, you will
quickly hit an integer overflow. If you reach out for arbitrary precision
numbers, like Java’s BigInteger, or Pythons built-in integers, you’ll notice
that the loop runs much slower when the iteration number increases.

To get around this issue, instead of storing the *i*-th Fibonacci number
in *F[i]* we will store just the last digit of <img src="https://latex.codecogs.com/svg.image?F_{i}" title="F_{i}" />,
i.e., we replace the body of the for loop with the following:

```commandline
F[i] ← (F[i − 1] + F[i − 2]) mod 10
```

Afterwards, computing the sum of single digit numbers *F[i − 1]* and *F[i − 2]*
will be fast.

#### Input format.
An integer *n*.

#### Output format.
The last digit of <img src="https://latex.codecogs.com/svg.image?F_{n}" title="F_{n}" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;&space;n&space;\leq&space;&space;10&space;^6" title="0 \leq n \leq 10 ^6" />

#### Sample 1.

**Input:**

```commandline
3
```

**Output:**

```commandline
2
```

<img src="https://latex.codecogs.com/svg.image?F_{3}&space;=&space;2" title="F_{3} = 2" />

#### Sample 2.

**Input:**

```commandline
139
```

**Output:**

```commandline
1
```

<img src="https://latex.codecogs.com/svg.image?F_{139}&space;=&space;50095301248058391139327916261" title="F_{139} = 50095301248058391139327916261" />

#### Sample 3.

**Input:**

```commandline
91239
```

**Output:**

```commandline
6
```

<img src="https://latex.codecogs.com/svg.image?F_{91239}" title="F_{91239}" /> will take more than ten pages to represent, but its last digit
is equal to 6.

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
