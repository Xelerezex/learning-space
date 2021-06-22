## Поиск минимума функции с помощью scipy.optimize.golden() - Часть 2

**Научимся работать с параметрами функций оптимизации на примере ** [scipy.optimize.golden()](https: // docs.scipy.org / doc / scipy / reference / generated / scipy.optimize.golden.html  # scipy.optimize.golden).

**Рассмотрим 2 параметра**:

    **brack ** - первичное ограничение аргумента для поиска минимума(найденное решение может быть за пределами интервала, однако имеет смысл использовать его, например, для предотвращения скатывания в локальный минимум)
    ** full_output ** - если равен True, то функция возвращает кортеж вида(аргумент_минимума, значение_минимума_функции, число итераций)

**Пример:**

```python
from scipy.optimize import golden

def f(x):
    return (x + 10)**2
golden(f, brack=(4, 10), full_output=True)
```

Вернёт:

```python
(-10.000000000000002, 3.1554436208840472e-30, 44)
```

### Задача

1) реализуйте 2 функции:

-   <img src="https://latex.codecogs.com/svg.image?f(x)&space;=&space;(x&space;&plus;&space;a)&space;^&space;2&space;-&space;b" title="f(x) = (x + a) ^ 2 - b" />
-   <img src="https://latex.codecogs.com/svg.image?g(x)&space;=&space;|f(x)|" title="g(x) = |f(x)|" />

***Примечание.*** _Считайте, что переменные <img src="https://latex.codecogs.com/svg.image?a" title="a" /> и <img src="https://latex.codecogs.com/svg.image?b" title="b" /> заданы выше в коде, не надо передавать их параметры функции._

2) Импортируйте функцию golden из модуля scipy.optimize.

3) Найдите значения **функций** (не аргументов!) в точке минимума <img src="https://latex.codecogs.com/svg.image?f(x)" title="f(x)" /> и <img src="https://latex.codecogs.com/svg.image?g(x)" title="g(x)" />, в качестве дополнительного параметра укажите brack=(-10, -4), ответ запишите через пробел.

Примечание. Пример дан для <img src="https://latex.codecogs.com/svg.image?a=3,&space;b=4" title="a=3, b=4" />

**Sample Input:**

```commandline

```

**Sample Output:**

```commandline
-4.0 1.0706354913736504e-08
```
