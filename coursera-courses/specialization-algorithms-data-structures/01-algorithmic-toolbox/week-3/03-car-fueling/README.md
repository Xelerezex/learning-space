## Car Fueling

### Problem Introduction:
You are going to travel to another city that is located *𝑑* miles away from your home city. Your can can travel
at most *𝑚* miles on a full tank and you start with a full tank. Along your way, there are gas stations at
distances <img src="https://latex.codecogs.com/svg.image?stop_1,&space;stop_2,&space;\cdots,&space;stop_n" title="stop_1, stop_2, \cdots, stop_n" /> from your home city. What is the minimum number of refills needed?

### Problem Description:
The first line contains an integer *𝑑*. The second line contains an integer *𝑚*. The third line
specifies an integer *𝑛*. Finally, the last line contains integers <img src="https://latex.codecogs.com/svg.image?stop_1,&space;stop_2,&space;\cdots,&space;stop_n" title="stop_1, stop_2, \cdots, stop_n" />.

#### Input Format.
Assuming that the distance between the cities is *𝑑* miles, a car can travel at most *𝑚* miles
on a full tank, and there are gas stations at distances <img src="https://latex.codecogs.com/svg.image?stop_1,&space;stop_2,&space;\cdots,&space;stop_n" title="stop_1, stop_2, \cdots, stop_n" /> along the way, output the
minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
reach the destination, output −1.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?1&space;\leq&space;d&space;\leq&space;10^{5}.&space;\quad&space;1&space;\leq&space;m&space;\leq&space;400.&space;\quad&space;1&space;\leq&space;n&space;\leq&space;300.&space;\quad&space;0&space;<&space;stop_{1}&space;<&space;stop_{2}&space;\cdots&space;<&space;stop_{n}&space;<&space;m." title="1 \leq d \leq 10^{5}. \quad 1 \leq m \leq 400. \quad 1 \leq n \leq 300. \quad 0 < stop_{1} < stop_{2} \cdots < stop_{n} < m." />


#### Sample 1.

**Input:**

```commandline
950
400
4
200 375 550 750
```

**Output:**

```commandline
2
```
The distance between the cities is 950, the car can travel at most 400 miles on a full tank. It suffices
to make two refills: at points 375 and 750. This is the minimum number of refills as with a single refill
one would only be able to travel at most 800 miles.

#### Sample 2.

**Input:**

```commandline
10
3
4
1 2 5 9
```

**Output:**

```commandline
-1
```
One cannot reach the gas station at point 9 as the previous gas station is too far away.

#### Sample 3.

**Input:**

```commandline
200
250
2
100
150
```

**Output:**

```commandline
0
```
There is no need to refill the tank as the car starts with a full tank and can travel for 250 miles
whereas the distance to the destination point is 200 miles.
