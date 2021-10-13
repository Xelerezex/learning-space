## Maximum Advertisement Revenue

### Problem Introduction:
You have *𝑛* ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up *𝑛*
slots on your page and estimated the expected number of clicks per day for each
slot. Now, your goal is to distribute the ads among the slots to maximize the
total revenue.

### Problem Description:

#### Task.
Given two sequences <img src="https://latex.codecogs.com/svg.image?a_1,&space;a_2,&space;\cdots,&space;a_n" title="a_1, a_2, \cdots, a_n" /> (<img src="https://latex.codecogs.com/svg.image?a_i" title="a_i" /> is the profit per click of the *𝑖*-th ad) and <img src="https://latex.codecogs.com/svg.image?b_1,&space;b_2,&space;\cdots,&space;b_n" title="b_1, b_2, \cdots, b_n" /> (<img src="https://latex.codecogs.com/svg.image?b_i" title="b_i" /> is
the average number of clicks per day of the *𝑖*-th slot), we need to partition them into *𝑛* pairs (<img src="https://latex.codecogs.com/svg.image?a_i,&space;b_j" title="a_i, b_j" />)
such that the sum of their products is maximized.

#### Input Format.
Output the maximum value of <img src="https://latex.codecogs.com/svg.image?\sum_{i=1}^{n}a_i,&space;c_i" title="\sum_{i=1}^{n}a_i, c_i" /> where <img src="https://latex.codecogs.com/svg.image?c_1,&space;c_2,&space;\cdots,&space;c_n" title="c_1, c_2, \cdots, c_n" /> is a permutation of <img src="https://latex.codecogs.com/svg.image?b_1,&space;b_2,&space;\cdots,&space;b_n" title="b_1, b_2, \cdots, b_n" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^{3};&space;\quad&space;-10^{5}&space;\leq&space;a_i,&space;b_i&space;\leq&space;10^{5}\quad" title="1 \leq n \leq 10^{3}; \quad -10^{5} \leq a_i, b_i \leq 10^{5}\quad" /> for all <img src="https://latex.codecogs.com/svg.image?&space;1&space;\leq&space;i&space;\leq&space;n." title=" 1 \leq i \leq n." />

#### Output Format.

#### Sample 1.

**Input:**

```commandline
1
23
39
```

**Output:**

```commandline
897
```
<img src="https://latex.codecogs.com/svg.image?897&space;=&space;23&space;\cdot&space;39." title="897 = 23 \cdot 39." />

#### Sample 2.

**Input:**

```commandline
3
1 3 -5
-2 4 1
```

**Output:**

```commandline
23
```
<img src="https://latex.codecogs.com/svg.image?23&space;=&space;3&space;\cdot&space;4&space;&plus;&space;1&space;\cdot&space;1&space;&plus;&space;(-5)&space;\cdot&space;(-2)." title="23 = 3 \cdot 4 + 1 \cdot 1 + (-5) \cdot (-2)." />
