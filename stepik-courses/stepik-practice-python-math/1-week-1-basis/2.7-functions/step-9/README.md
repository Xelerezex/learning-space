Напишите функцию для нахождения [кратного факториала](https://ru.wikipedia.org/wiki/%D0%A4%D0%B0%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B0%D0%BB#.D0.9A.D1.80.D0.B0.D1.82.D0.BD.D1.8B.D0.B9_.D1.84.D0.B0.D0.BA.D1.82.D0.BE.D1.80.D0.B8.D0.B0.D0.BB) числа Kfactorial.

Функция factorial должна иметь 2 параметра:

1.    n - число для которого вычисляется факториал (обязательный)
2.    k - кратность факториала (необязательный, значение по-умолчанию - 1)

По сути кратный факториал это продолжение идеи двойного факториала. Только теперь "шаг" при вычислении не 2, а k.

**Математика:**

<img src="https://latex.codecogs.com/svg.image?n&space;\underset{m}{\underbrace{!!...!}}&space;=&space;\prod_{i=1}^{k}&space;=(m&space;\cdot&space;1-r)&space;\cdot&space;(m&space;\cdot&space;2-r)&space;\cdot&space;(m&space;\cdot&space;3-r)&space;\cdot&space;\cdots(m&space;\cdot&space;(k&space;-&space;1)&space;-&space;r)&space;\cdot&space;(m&space;\cdot&space;k&space;-&space;r)" title="n \underset{m}{\underbrace{!!...!}} = \prod_{i=1}^{k} =(m \cdot 1-r) \cdot (m \cdot 2-r) \cdot (m \cdot 3-r) \cdot \cdots(m \cdot (k - 1) - r) \cdot (m \cdot k - r)" />

где, <img src="https://latex.codecogs.com/svg.image?r" title="r" /> - число из множества <img src="https://latex.codecogs.com/svg.image?\begin{Bmatrix}0,&space;1,&space;...&space;,&space;m-1\end{Bmatrix}" title="\begin{Bmatrix}0, 1, ... , m-1\end{Bmatrix}" />, т.е. "остаток" от <img src="https://latex.codecogs.com/svg.image?k" title="k" /> уменьшений исходного числа <img src="https://latex.codecogs.com/svg.image?n" title="n" /> на <img src="https://latex.codecogs.com/svg.image?m" title="m" /> за 1 шаг.

Тогда легко показать, что для числа <img src="https://latex.codecogs.com/svg.image?n-m" title="n-m" /> аналогичный кратный факториал будет:

<img src="https://latex.codecogs.com/svg.image?(n-m)&space;\underset{m}{\underbrace{!!...!}}&space;=&space;\prod_{i=1}^{k-1}(mi-r)&space;=(m&space;\cdot&space;1-r)&space;\cdot&space;(m&space;\cdot&space;2-r)&space;\cdot&space;(m&space;\cdot&space;3-r)&space;\cdot&space;\cdots(m&space;\cdot&space;(k&space;-&space;1)&space;-&space;r)" title="(n-m) \underset{m}{\underbrace{!!...!}} = \prod_{i=1}^{k-1}(mi-r) =(m \cdot 1-r) \cdot (m \cdot 2-r) \cdot (m \cdot 3-r) \cdot \cdots(m \cdot (k - 1) - r)" />

Это позволяет нам получить связь между "шагами" факториала:

<img src="https://latex.codecogs.com/svg.image?n&space;\underset{m}{\underbrace{!!...!}}&space;=&space;(n-m)&space;\underset{m}{\underbrace{!!...!}}&space;\cdot&space;(m&space;\cdot&space;k&space;-&space;r)&space;" title="n \underset{m}{\underbrace{!!...!}} = (n-m) \underset{m}{\underbrace{!!...!}} \cdot (m \cdot k - r) " />

При этом легко заметить, что последним шагом будет:

<img src="https://latex.codecogs.com/svg.image?\tilde{n}&space;\underset{m}{\underbrace{!!...!}}&space;=&space;(m&space;-&space;r)" title="\tilde{n} \underset{m}{\underbrace{!!...!}} = (m - r)" />, при условии, что <img src="https://latex.codecogs.com/svg.image?\tilde{n}&space;\textless&space;m" title="\tilde{n} \textless m" />

**Пример:**

<img src="https://latex.codecogs.com/svg.image?5!!&space;=&space;(2&space;\cdot&space;1&space;-&space;1)&space;\cdot&space;(2&space;\cdot&space;2&space;-&space;1)&space;\cdot&space;(2&space;\cdot&space;3&space;-&space;1)&space;=&space;1&space;\cdot&space;3&space;\cdot&space;5&space;" title="5!! = (2 \cdot 1 - 1) \cdot (2 \cdot 2 - 1) \cdot (2 \cdot 3 - 1) = 1 \cdot 3 \cdot 5 " />

<img src="https://latex.codecogs.com/svg.image?5!!!&space;=&space;(3&space;\cdot&space;1&space;-&space;1)&space;\cdot&space;(3&space;\cdot&space;2&space;-&space;1)&space;=&space;2&space;\cdot&space;5&space;" title="5!!! = (3 \cdot 1 - 1) \cdot (3 \cdot 2 - 1) = 2 \cdot 5 " />


**Отсюда легко сформулировать 2 правила:**

-    Условие остановки рекурсии - Kfactorial(n, k) = n, если n <= k
-    Шаг рекурсии -  Kfactorial(n, k) = n *  Kfactorial(n-k, k), если n > k


***ВАЖНО!***

Не забываем про числа, кратные степени факториала:

<img src="https://latex.codecogs.com/svg.image?6!!!&space;=&space;(3&space;\cdot&space;1&space;-&space;0)&space;\cdot&space;(3&space;\cdot&space;2&space;-&space;0)&space;=&space;3&space;\cdot&space;6&space;" title="6!!! = (3 \cdot 1 - 0) \cdot (3 \cdot 2 - 0) = 3 \cdot 6 " />

***Примечание.*** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
0
```

**Sample Output 1:**

```commandline
1
```

**Sample Input 2:**

```commandline
0 10
```

**Sample Output 2:**

```commandline
1
```

**Sample Input 3:**

```commandline
10 1
```

**Sample Output 3:**

```commandline
3628800
```

**Sample Input 4:**

```commandline
8 3
```

**Sample Output 4:**

```commandline
80
```

**Sample Input 5:**

```commandline
8
```

**Sample Output 5:**

```commandline
40320
```

**Sample Input 6:**

```commandline
6 3
```

**Sample Output 6:**

```commandline
18
```

