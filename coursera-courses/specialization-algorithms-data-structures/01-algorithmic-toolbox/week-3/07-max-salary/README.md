## Maximum Salary

### Problem Introduction:
As the last question of a successful interview, your boss gives you a few pieces of paper
with numbers on it and asks you to compose a largest number from these numbers. The
resulting number is going to be your salary, so you are very much interested in maximizing
this number. How can you do this?

In the lectures, we considered the following algorithm for composing the largest number out of the given
*single-digit numbers*.

```commandline
LargestNumber(Digits):
answer ← empty string
while Digits is not empty:
    maxDigit ← −∞
    for digit in Digits:
        if digit ≥ maxDigit:
            maxDigit ← digit
    append maxDigit to answer
    remove maxDigit from Digits
return answer
```

Unfortunately, this algorithm works only in case the input consists of single-digit numbers. For example, for
an input consisting of two integers 23 and 3 (23 is not a single-digit number!) it returns 233, while the largest
number is in fact 323. In other words, using the largest number from the input as the first number is *not a
safe move*.
Your goal in this problem is to tweak the above algorithm so that it works not only for single-digit
numbers, but for arbitrary positive integers.

### Problem Description:

#### Task.
Compose the largest number out of a set of integers.

#### Input Format.
The first line of the input contains an integer 𝑛. The second line contains integers
<img src="https://latex.codecogs.com/svg.image?a_1,&space;a_2,&space;\cdots,&space;a_n." title="a_1, a_2, \cdots, a_n." />

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;100;&space;\quad&space;1&space;\leq&space;a_i&space;\leq&space;10^3" title="1 \leq n \leq 100; \quad 1 \leq a_i \leq 10^3" /> for all <img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;i&space;\leq&space;n." title="1 \leq i \leq n." />

#### Output Format.
Output the largest number that can be composed out of <img src="https://latex.codecogs.com/svg.image?a_1,&space;a_2,&space;\cdots,&space;a_n." title="a_1, a_2, \cdots, a_n." />

#### Sample 1.

**Input:**

```commandline
2
21 2
```

**Output:**

```commandline
221
```

Note that in this case the above algorithm also returns an incorrect answer 212.

#### Sample 2.

**Input:**

```commandline
5
9 4 6 1 9
```

**Output:**

```commandline
99641
```

In this case, the input consists of single-digit numbers only, so the algorithm above computes the right
answer.

#### Sample 3.

**Input:**

```commandline
3
23 39 92
```

**Output:**

```commandline
923923
```
As a coincidence, for this input the above algorithm produces the right result, though the input does
not have any single-digit numbers.

#### What To Do
Interestingly, for solving this problem, all you need to do is to replace the check *digit ≥ maxDigit* with a call
*IsGreaterOrEqual(digit, maxDigit)* for an appropriately implemented function *IsGreaterOrEqual*.
For example, *IsGreaterOrEqual(2, 21)* should return *True*.
