Напишите функцию super_L(n), находящую n-е число Люка.

Используйте формулы для разложения из предыдущего шага, чтобы увеличить быстродействие вашей функции.

***Примечание 1***. В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

***Примечание 2***. В задаче пришлось скрыть отладочные тесты, т.к. получающиеся в результате числа Люка так велики, что страница зачастую вешает браузер...

Попробуйте:

-    5\*\*1 \* 3\*\*2 \* 2\*\*2
-    5\*\*4 \* 3\*\*4 \* 2\*\*4
-    3\*\*10

Возьмём число <img src="https://latex.codecogs.com/svg.image?5^{1}&space;\cdot&space;3^{2}&space;\cdot&space;2^{2}&space;=&space;180" title="5^{1} \cdot 3^{2} \cdot 2^{2} = 180" />. По формуле упрощения:

<img src="https://latex.codecogs.com/svg.image?L(5^{1}&space;\cdot&space;3^{2}&space;\cdot&space;2^{2})=L(3^{2}&space;\cdot&space;2^{2})^{5}&space;-&space;5&space;\cdot&space;(-1)^{3^{2}&space;\cdot&space;2^{2}}&space;\cdot&space;L(3^{2}&space;\cdot&space;2^{2})^{3}&plus;5&space;\cdot&space;L(3^{2}&space;\cdot&space;2^{2})" title="L(5^{1} \cdot 3^{2} \cdot 2^{2})=L(3^{2} \cdot 2^{2})^{5} - 5 \cdot (-1)^{3^{2} \cdot 2^{2}} \cdot L(3^{2} \cdot 2^{2})^{3}+5 \cdot L(3^{2} \cdot 2^{2})" />

Заметим, что <img src="https://latex.codecogs.com/svg.image?3^{2}&space;\cdot&space;2^{2}&space;=&space;36" title="3^{2} \cdot 2^{2} = 36" />.

36-е число Люка нам известно даже из табличных источников (https://oeis.org/A000032/list) и оно равно 33385282.

То есть:

<img src="https://latex.codecogs.com/svg.image?L(5^{1}&space;\cdot&space;3^{2}&space;\cdot&space;2^{2})=L(36)^{5}&space;-&space;5&space;\cdot&space;(-1)^{36}&space;\cdot&space;L(36)^{3}&plus;5&space;\cdot&space;L(36)^{5}&space;=&space;33385282^{5}&space;-&space;5&space;\cdot&space;33385282^{3}&space;&plus;&space;5&space;\cdot&space;33385282&space;=&space;41473935220454921602871195774259272002" title="L(5^{1} \cdot 3^{2} \cdot 2^{2})=L(36)^{5} - 5 \cdot (-1)^{36} \cdot L(36)^{3}+5 \cdot L(36)^{5} = 33385282^{5} - 5 \cdot 33385282^{3} + 5 \cdot 33385282 = 41473935220454921602871195774259272002" />

**Sample Input 1:**

```commandline
36
```

**Sample Output 1:**

```commandline
33385282
```

**Sample Input 2:**

```commandline
180
```

**Sample Output 2:**

```commandline
41473935220454921602871195774259272002
```
