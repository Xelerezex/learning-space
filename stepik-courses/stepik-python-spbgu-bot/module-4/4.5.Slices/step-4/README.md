Напиши программу, которая по заданной матрице <img src="https://latex.codecogs.com/svg.image?A&space;=&space;\left\{&space;p_{ij}&space;\right\}" title="A = \left\{ p_{ij} \right\}" /> размерности <img src="https://latex.codecogs.com/svg.image?n&space;\times&space;n" title="n \times n" /> считает подматрицу B по правилу

<img src="https://latex.codecogs.com/svg.image?B&space;=&space;\left\{&space;p_{ij}&space;\right\}" title="B = \left\{ p_{ij} \right\}" />, i, j−четные, если нумерация идет с единицы.

**Входные данные**

В первой строке передается число n (размерность матрицы), далее в n строках идут элементы матрицы.

**Выходные данные**

Элементы подматрицы B

Sample Input:

```commandline
5
1 0 1 0 1
0 1 0 2 0
1 0 1 0 1
0 3 0 4 0
1 0 1 0 1
```

Sample Output:

```commandline
1 2
3 4
```

