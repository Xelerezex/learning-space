Напишите функцию, для нахождения [двойного факториала](https://ru.wikipedia.org/wiki/%D0%A4%D0%B0%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B0%D0%BB#.D0.94.D0.B2.D0.BE.D0.B9.D0.BD.D0.BE.D0.B9_.D1.84.D0.B0.D0.BA.D1.82.D0.BE.D1.80.D0.B8.D0.B0.D0.BB) числа dfactorial(n).

Двойной факториал числа n обозначается n‼ и определяется как произведение всех натуральных чисел в отрезке [1, n], имеющих ту же [чётность](https://ru.wikipedia.org/wiki/%D0%A7%D1%91%D1%82%D0%BD%D1%8B%D0%B5_%D0%B8_%D0%BD%D0%B5%D1%87%D1%91%D1%82%D0%BD%D1%8B%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%B0) , что и n.

    Для **чётного**    n: <img src="https://latex.codecogs.com/svg.image?n!!=2&space;\cdot&space;4&space;\cdot&space;6&space;\cdot&space;...&space;\cdot&space;n" title="n!!=2 \cdot 4 \cdot 6 \cdot ... \cdot n" />
    Для **нечётного**  n: <img src="https://latex.codecogs.com/svg.image?n!!=1&space;\cdot&space;3&space;\cdot&space;5&space;\cdot&space;...&space;\cdot&space;n" title="n!!=1 \cdot 3 \cdot 5 \cdot ... \cdot n" />


***Примечание.***  В этой задаче не нужно ничего считывать и ничего выводить на печать. Только реализовать функцию.

**Sample Input 1:**

```cpp
0
```

**Sample Output 1:**

```cpp
1
```

**Sample Input 2:**

```cpp
1
```

**Sample Output 2:**

```cpp
1
```

**Sample Input 3:**

```cpp
2
```

**Sample Output 3:**

```cpp
2
```

**Sample Input 4:**

```cpp
3
```

**Sample Output 4:**

```cpp
3
```

**Sample Input 5:**

```cpp
4
```

**Sample Output 5:**

```cpp
8
```

**Sample Input 6:**

```cpp
5
```

**Sample Output 6:**

```cpp
15
```

