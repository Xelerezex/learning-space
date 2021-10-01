## Fibonacci Number

### Fibonacci Number Problem
*Compute the n-th Fibonacci number.*

-   **Input:** An integer n.

-   **Output:** n-th Fibonacci number.

Fibonacci numbers are defined recursively:

<img src="https://latex.codecogs.com/svg.image?F_{n}&space;=&space;\begin{cases}&space;&&space;n&space;\quad&space;\quad&space;\quad&space;\quad&space;\quad&space;\quad&space;\text{&space;if&space;n&space;is&space;0&space;or&space;1&space;}&space;&space;\\&space;&&space;F_{n-1}&space;&plus;&space;F_{n-2}\quad&space;\,\,&space;\text{&space;if&space;n}&space;\geqslant&space;&space;2&space;&space;\end{cases}" title="F_{n} = \begin{cases} & n \quad \quad \quad \quad \quad \quad \text{ if n is 0 or 1 } \\ & F_{n-1} + F_{n-2}\quad \,\, \text{ if n} \geqslant 2 \end{cases}" />

resulting in the following recursive algorithm:

```commandline
Fibonacci(n):
if n ≤ 1:
    return n
return Fibonacci(n − 1) + Fibonacci(n − 2)
```

Implement this algorithm and try to compute <img src="https://latex.codecogs.com/svg.image?F_{40}" title="F_{40}" /> .
You will see that it already takes significant time.
And the Sun may die before your computer returns
<img src="https://latex.codecogs.com/svg.image?F_{150}" title="F_{150}" /> since modern computers
need billions of years to compute this number...


To understand why this algorithm is so slow, try computing <img src="https://latex.codecogs.com/svg.image?F_{20}" title="F_{20}" />
at *[link](http://www.cs.usfca.edu/˜galles/visualization/DPFib.html.)*


Enter “20” and press the “Fibonacci Recursive” button. You will see
a seemingly endless series of recursive calls. Now, press “Skip Forward”
to stop the recursive algorithm and call the iterative algorithm by pressing
“Fibonacci Table”. This will instantly compute <img src="https://latex.codecogs.com/svg.image?F_{20}" title="F_{20}" />.
(Note that the visualization uses a slightly different definition of Fibonacci numbers:
<img src="https://latex.codecogs.com/svg.image?F_{0}&space;=&space;1" title="F_{0} = 1" /> instead of
<img src="https://latex.codecogs.com/svg.image?F_{0}&space;=&space;0" title="F_{0} = 0" /> .)

#### Input format.
An integer *n*.

#### Output format.
<img src="https://latex.codecogs.com/svg.image?F_{n}" title="F_{n}" />.

#### Constraints.
<img src="https://latex.codecogs.com/svg.image?0&space;\leq&space;n&space;\leq&space;45" title="0 \leq n \leq 45" />

#### Sample 1.

**Input:**

```commandline
3
```

**Output:**

```commandline
2
```

#### Sample 2.

**Input:**

```commandline
10
```

**Output:**

```commandline
55
```

##### Time limits:  1 sec.

##### Memory limit: 512 Mb.
