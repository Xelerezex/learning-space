## Поиск минимума функции с помощью  scipy.optimize.golden()

_scipy.optimize.golden()_ - находит минимум функции. Как было показано в конце предыдущего шага, если не передавать в неё никаких параметров кроме функции, минимум которой ищется, то возвращён будет **аргумент**, при котором этот минимум достигается. Более подробно с функцией можно ознакомиться в [документации](https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.golden.html#scipy.optimize.golden).

1) реализуйте 2 функции:

-   <img src="https://latex.codecogs.com/svg.image?f(x)&space;=&space;(x&plus;a)^2&space;-&space;b" title="f(x) = (x+a)^2 - b" />
-   <img src="https://latex.codecogs.com/svg.image?g(x)&space;=&space;|f(x)|" title="g(x) = |f(x)|" />

***Примечание.*** Считайте, что переменные <img src="https://latex.codecogs.com/svg.image?a" title="a" /> и <img src="https://latex.codecogs.com/svg.image?b" title="b" /> заданы выше в коде, не надо передавать их параметры функции.

2) Импортируйте функцию golden из модуля scipy.optimize.

2) Найдите аргументы, при которых достигается минимум функций <img src="https://latex.codecogs.com/svg.image?f(x)" title="f(x)" /> и <img src="https://latex.codecogs.com/svg.image?g(x)" title="g(x)" />, ответ запишите через пробел.


Примечание. Пример дан для <img src="https://latex.codecogs.com/svg.image?a=3" title="a=3" />, <img src="https://latex.codecogs.com/svg.image?b=4" title="b=4" />

**Sample Input:**

```commandline

```

**Sample Output:**

```commandline
-3.0 -0.9999999987819608
```
