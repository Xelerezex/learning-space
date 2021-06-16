## 22 Нормализация

Используйте формулу <img src="https://latex.codecogs.com/svg.image?x_{new}&space;=&space;\frac&space;{x&space;-&space;\mu}{\sigma}" title="x_{new} = \frac {x - \mu}{\sigma}" />,

где

-    x- старое значение
-    <img src="https://latex.codecogs.com/svg.image?x_{new}" title="x_{new}" /> - новое значение
-    <img src="https://latex.codecogs.com/svg.image?\mu" title="\mu" /> - среднее значение (по всей матрице)
-    <img src="https://latex.codecogs.com/svg.image?\sigma" title="\sigma" /> - стандартное отклонение (по всей матрице)

для того чтобы "[нормализовать](https://en.wikipedia.org/wiki/Normalization_(statistics))" матрицу.

_Мы пока не будем углубляться в математическую суть этой операции, важно лишь, что оба значения для матрицы могут быть вычислены стандартными функциями numpy и вам не нужно звать на помощь статистику)_
Пример:

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}&space;1&space;&&space;2\\&space;2&space;&&space;1&space;\end{pmatrix}" title="\begin{pmatrix} 1 & 2\\ 2 & 1 \end{pmatrix}" />

<img src="https://latex.codecogs.com/svg.image?\mu&space;=&space;\frac{1&space;&plus;&space;2&space;&plus;&space;2&space;&plus;&space;1&space;}{4}&space;=&space;1.5" title="\mu = \frac{1 + 2 + 2 + 1 }{4} = 1.5" />

<img src="https://latex.codecogs.com/svg.image?\sigma={\sqrt&space;{{\frac&space;{1}{n}}\sum&space;_{i=1}^{n}\left(x_{i}-&space;\mu&space;\right)^{2}}}&space;=&space;\sqrt&space;{{\frac&space;{1}{4}}&space;\cdot((1-1.5)^2&plus;(2-1.5)^2&plus;(2-1.5)^2&plus;(1-1.5)^2)}&space;=&space;\\&space;=\sqrt&space;{{\frac&space;{1}{4}}&space;\cdot&space;((-0.5)^2&space;&plus;(0.5)^2&space;&plus;(0.5)^2&space;&plus;(-0.5)^2)}&space;=&space;\sqrt&space;{\frac&space;{1}{4}\cdot&space;(\frac&space;{1}{4}&plus;\frac&space;{1}{4}&plus;\frac&space;{1}{4}&plus;\frac&space;{1}{4})}&space;=&space;\\&space;=\sqrt&space;{\frac&space;{1}{4}\cdot&space;(1)}&space;=&space;\sqrt&space;{\frac&space;{1}{4}}&space;=&space;\frac&space;{1}{2}&space;" title="\sigma={\sqrt {{\frac {1}{n}}\sum _{i=1}^{n}\left(x_{i}- \mu \right)^{2}}} = \sqrt {{\frac {1}{4}} \cdot((1-1.5)^2+(2-1.5)^2+(2-1.5)^2+(1-1.5)^2)} = \\ =\sqrt {{\frac {1}{4}} \cdot ((-0.5)^2 +(0.5)^2 +(0.5)^2 +(-0.5)^2)} = \sqrt {\frac {1}{4}\cdot (\frac {1}{4}+\frac {1}{4}+\frac {1}{4}+\frac {1}{4})} = \\ =\sqrt {\frac {1}{4}\cdot (1)} = \sqrt {\frac {1}{4}} = \frac {1}{2} " />

_Естественно, вам не надо пользоваться такими безумными формулами!_

**Переменная Y содержит исходную матрицу**

**В переменную Z сохраните её "нормализованный" вид, округлив каждое значение в матрице до 2 знака после запятой с помощью** [numpy.around](https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.around.html).

***Примечание.*** _В этой задаче не нужно ничего выводить на печать. Только создать матрицу Z._

**Sample Input 1:**

```commandline
1 2
2 1
```

**Sample Output 1:**

```commandline
[[-1.  1.]
 [ 1. -1.]]
```

**Sample Input 2:**

```commandline
99 11 55
33 66 99
```

**Sample Output 2:**

```commandline
[[ 1.19 -1.54 -0.17]
 [-0.85  0.17  1.19]]
```
