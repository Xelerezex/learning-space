Возводить в степень можно гораздо быстрее, чем за n умножений! Для этого нужно воспользоваться следующими рекуррентными соотношениями:

<img src="https://latex.codecogs.com/svg.image?a^{n}&space;=&space;(a^{2})^{\frac{n}{2}}" title="a^{n} = (a^{2})^{\frac{n}{2}}" />  при четном n,

<img src="https://latex.codecogs.com/svg.image?a^{n}&space;=&space;a&space;\times&space;a^{n&space;-&space;1}" title="a^{n} = a \times a^{n - 1}" /> при нечетном n.

Реализуйте алгоритм быстрого возведения в степень с помощью рекурсивной функции.

**Формат входных данных**

Вводятся действительное число a и целое неотрицательное число n.

**Формат выходных данных**

Выведите ответ на задачу.

**Sample Input 1:**

```cpp
2.0
1
```


**Sample Output 1:**

```cpp
2
```


**Sample Input 2:**

```cpp
2
2
```


**Sample Output 2:**

```cpp
4
```


