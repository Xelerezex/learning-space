## Maximum Number of Prizes

### Problem Introduction:
You are organizing a funny competition for children. As a prize fund you have 𝑛
candies. You would like to use these candies for top 𝑘 places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to find the largest
value of 𝑘 for which it is possible.

### Problem Description:

#### Task.
The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise
distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as
<img src="https://latex.codecogs.com/svg.image?a_1&space;&plus;&space;a_2&space;&plus;&space;\cdots&space;&plus;&space;a_k" title="a_1 + a_2 + \cdots + a_k" /> where <img src="https://latex.codecogs.com/svg.image?a_1&space;,&space;\cdots&space;,&space;a_k" title="a_1 , \cdots , a_k" />
 are positive integers and <img src="https://latex.codecogs.com/svg.image?a_i&space;\neq&space;a_j" title="a_i \neq a_j" /> for all <img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;i&space;<&space;j&space;\leq&space;k" title="1 \leq i < j \leq k" />.

#### Input Format.
The input consists of a single integer 𝑛.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^9." title="1 \leq n \leq 10^9." />

#### Output Format.
In the first line, output the maximum number 𝑘 such that 𝑛 can be represented as a sum
of 𝑘 pairwise distinct positive integers. In the second line, output 𝑘 pairwise distinct positive integers
that sum up to 𝑛 (if there are many such representations, output any of them).

#### Sample 1.

**Input:**

```commandline
6
```

**Output:**

```commandline
3
1 2 3
```

#### Sample 2.

**Input:**

```commandline
8
```

**Output:**

```commandline
3
1 2 5
```

#### Sample 3.

**Input:**

```commandline
2
```

**Output:**

```commandline
1
2
```
