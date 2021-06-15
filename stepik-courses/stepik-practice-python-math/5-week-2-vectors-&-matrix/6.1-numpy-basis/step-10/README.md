## Площадь треугольника по координатам его вершин

Возможно вы успели соскучиться по геометрическим задачам...

Для начала вспомним как найти длину отрезка, если мы знаем координаты его концов (для этого используем [теорему Пифагора](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%9F%D0%B8%D1%84%D0%B0%D0%B3%D0%BE%D1%80%D0%B0)):

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/5-week-2-vectors-%26-matrix/6.1-numpy-basis/step-10/Source/1.png)

А если мы знаем длины всех 3 сторон треугольника, то мы легко можем найти его площадь по [формуле Герона](https://ru.wikipedia.org/wiki/%D0%A4%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%93%D0%B5%D1%80%D0%BE%D0%BD%D0%B0) ([как мы уже делали в начале](https://stepik.org/lesson/52668/step/6))

![alt tag](https://github.com/Xelerezex/learning-space/tree/learning-space/stepik-courses/stepik-practice-python-math/5-week-2-vectors-%26-matrix/6.1-numpy-basis/step-10/Source/2.png)

В этой задаче нам даны 3 переменные: A1, A2, A3. Каждая содержит вектор с 2 координатами соответствующей вершины треугольника.

Найдите площадь треугольника и выведите её на печать.

Если все 3 точки лежат на одной прямой, то площадь треугольника равна 0.

Ответ проверяется с точностью до 4 знака после запятой.

P.S. существует другой способ найти площадь треугольника по координатам вершин, но мы пока не будем его обсуждать.

**Sample Input 1:**

```commandline
A1 = np.array((-1, 1))
A2 = np.array((2, 5))
A3 = np.array((5, -3))
```

**Sample Output 1:**

```commandline
17.999999999999993
```

**Sample Input 2:**

```commandline
A1 = np.array((-1, 2))
A2 = np.array((2, 3))
A3 = np.array((5, 4))
```

**Sample Output 2:**

```commandline
0.0
```
