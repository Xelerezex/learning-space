## 2. Производная

Напишите функцию derivative(f, x0=0), находящую производную функции <img src="https://latex.codecogs.com/svg.image?f(x)" title="f(x)" />  в точке  <img src="https://latex.codecogs.com/svg.image?x&space;=&space;x_0" title="x = x_0" />

Функция должна принимать 2 параметра:

-    обязательный - f - имя функции (без скобочек)
-    необязательный - x0 - значение аргумента точки в которой вычисляется производная. Если не задан, то значение будет равно 0.

[Про параметры функций](https://stepik.org/lesson/59468/step/5)

Функция должна округлять ответ до 3 знака после запятой.

**Примечание.** В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```commandline
derivative(sin)
```

**Sample Output 1:**

```commandline
1.0
```

**Sample Input 2:**

```commandline
derivative(cos)
```

**Sample Output 2:**

```commandline
0.0
```

**Sample Input 3:**

```commandline
derivative(atan, 1000000)
```

**Sample Output 3:**

```commandline
0.0
```

**Sample Input 4:**

```commandline
derivative(exp, 1)
```

**Sample Output 4:**

```commandline
2.718
```
