## Maximum Value of the Loot

### Problem Introduction:

A thief finds much more loot than his bag can fit. Help him to find the most valuable combination
of items assuming that any fraction of a loot item can be put into his bag.

### Problem Description:

#### Task.
The goal of this code problem is to implement an algorithm for the fractional knapsack problem.

#### Input Format.
The first line of the input contains the number *𝑛* of items and the capacity *𝑊* of a knapsack.
The next *𝑛* lines define the values and weights of the items. The *𝑖*-th line contains integers <img src="https://latex.codecogs.com/svg.image?v_i" title="v_i" /> and <img src="https://latex.codecogs.com/svg.image?w_i" title="w_i" /> —the
value and the weight of *𝑖*-th item, respectively.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;n&space;\leq&space;10^{-3}" title="1 \leq n \leq 10^{-3}" />

<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;W&space;\leq&space;2\cdot10^{6}" title="0 \leq W \leq 2\cdot10^{6}" />

<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;v_i&space;\leq&space;2\cdot10^{6}" title="0 \leq v_i \leq 2\cdot10^{6}" />

<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;w_i&space;\leq&space;2\cdot10^{6}" title="0 \leq w_i \leq 2\cdot10^{6}" />

for all <img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;i&space;\leq&space;n" title="1 \leq i \leq n" />

All the numbers are integers.

#### Output Format.
Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
<img src="https://latex.codecogs.com/svg.image?10^{-3}" title="10^{-3}" /> . To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues).

#### Sample 1.

**Input:**

```commandline
3 50
60 20
100 50
120 30
```

**Output:**

```commandline
180.0000
```

To achieve the value 180, we take the first item and the third item into the bag.

#### Sample 2.

**Input:**

```commandline
1 10
500 30
```

**Output:**

```commandline
166.6667
```

Here, we just take one third of the only available item.
