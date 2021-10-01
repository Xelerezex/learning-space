## Fibonacci Number Again

### Fibonacci Number Again Problem
*Compute the n-th Fibonacci number modulo m.*

-   **Input:**  Integers <img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;n&space;\leq&space;10^18" title="0 \leq n \leq 10^18" /> and <img src="https://latex.codecogs.com/svg.image?2&space;\leq&space;m&space;\leq&space;10^5" title="2 \leq m \leq 10^5" />.

-   **Output:** *n*-th Fibonacci modulo *m*.

In this problem, *n* may be so huge that an algorithm looping for
n iterations will be too slow. Therefore we need to avoid such a loop. To
get an idea how to solve this problem without going through all Fibonacci
numbers <img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" /> for *i* from 0 to n,
take a look at the table below:

|  i   | 0   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  |
|:---: |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|<img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" />| 0 |1 |1 |2 |3 |5 |8 |13 |21 |34 |55 |89 |144 |233 |377 |610|
| <img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" /> *mod 2* | 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| <img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" /> *mod 3* | 0 | 1 | 1 | 2 | 0 | 2 | 2 | 1 | 0 | 1 | 1 | 2 | 0 | 2 | 2 | 1 |

> **Stop and Think.** *Do you see any interesting properties of the last two
rows in the table above?*

Both these sequences are periodic! For m = 2, the period is 011 and has
length 3, while for m = 3 the period is 01120221 and has length 8.

|  i   | 0   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  |
|:---: |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|<img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" />| 0 | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55 | 89 |  144 | 233 | 377 | 610 |
|<img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" /> *mod 2*| 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1  |1 | 0 | 1  |1  |0 | 1  | 1  |0 |
|<img src="https://latex.codecogs.com/svg.image?F_i" title="F_i" /> *mod 3*| 0 | 1 | 1 | 2 | 0 | 2 | 2 | 1  |0 | 1 | 1  |2  |0 | 2  | 2  |1 |

Therefore, to compute, say, <img src="https://latex.codecogs.com/svg.image?F_{2015}" title="F_{2015}" /> *mod 3*
we just need to find the remainder of *2015* when divided by *8*. Since *2015 = 251 · 8 + 7*, we conclude
that <img src="https://latex.codecogs.com/svg.image?F_{2015}" title="F_{2015}" /> *mod 3 =* <img src="https://latex.codecogs.com/svg.image?F_7" title="F_7" /> *mod 3 = 1*.

It turns out that for any integer *m ≥ 2*, the sequence <img src="https://latex.codecogs.com/svg.image?F_{n}" title="F_{n}" />
*mod m* is periodic. The period always starts with 01 and is known as *Pisano period*
(Pisano is another name of Fibonacci).

>   **Exercise Break.** *What is the period of <img src="https://latex.codecogs.com/svg.image?F_{i}" title="F_{i}" /> mod 5?*

>   **Exercise Break.** *Prove that <img src="https://latex.codecogs.com/svg.image?F_{i}" title="F_{i}" /> mod m is periodic for every m.*

>   **Exercise Break.** *Prove that the period of <img src="https://latex.codecogs.com/svg.image?F_{i}" title="F_{i}" />  mod m  does not exceed <img src="https://latex.codecogs.com/svg.image?m_{2}" title="m_{2}" /> .*

#### Input format.
Integers *n* and *m*.

#### Output format.
*<img src="https://latex.codecogs.com/svg.image?F_{n}" title="F_{n}" /> mod m*.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;&space;n&space;\leq&space;&space;10^{18}&space;,&space;2&space;\leq&space;&space;m&space;\leq&space;&space;10^{5}&space;." title="1 \leq n \leq 10^{18} , 2 \leq m \leq 10^{5} ." />

#### Sample 1.

**Input:**

```commandline
1 239
```

**Output:**

```commandline
1
```
<img src="https://latex.codecogs.com/svg.image?F_{1}" title="F_{1}" /> *mod 239 = 1 mod 239 = 1*.

#### Sample 2.

**Input:**

```commandline
115 1000
```

**Output:**

```commandline
885
```
<img src="https://latex.codecogs.com/svg.image?F_{115}" title="F_{115}" /> *mod 1000 = 483 162 952 612 010 163 284 885 mod 1000 = 885.*.

#### Sample 3.

**Input:**

```commandline
2816213588 30524
```

**Output:**

```commandline
10249
```
<img src="https://latex.codecogs.com/svg.image?F_{2 816 213 588}" title="F_{2 816 213 588}" />
would require hundreds pages to write it down, but
<img src="https://latex.codecogs.com/svg.image?F_{2 816 213 588}" title="F_{2 816 213 588}" /> *mod 30524 = 10249*

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
