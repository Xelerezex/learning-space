Пора объединить полученные знания.

Считайте 1 строку. Она содержит строку с названием типа последующих данных. Возможны 3 типа:

1.    int
2.    str
3.    list

В случае получения другого типа выведите на печать строку "Unknown type".


**Если получен тип 'int':**

Считайте ещё 2 строки. Каждая будет содержать целое число.

-    Если оба числа равны 0, выведите на печать строку "Empty Ints"
-    Иначе выведите на печать сумму этих чисел


**Если получен тип 'str':**

Считайте ещё 1 строку.

-    Если строка пустая, выведите на печать строку "Empty String"
-    Иначе напечатайте эту строку


**Если получен тип 'list':**

Считайте 1 строку и разрежьте её на элементы с помощью split().

-    Если получившийся список пустой, выведите на печать строку "Empty List"
-    Иначе выведите на печать последний элемент списка. *Примечание, используйте* [отрицательный индекс](https://stepik.org/lesson/52796/step/8).


*Используйте приведение типов для определения пустых списков и строк, а так же чисел, равных 0.*

**Sample Input 1:**

```commandline
dict
```


**Sample Output 1:**

```commandline
Unknown type
```


**Sample Input 2:**

```commandline
int
0
0
```


**Sample Output 2:**

```commandline
Empty Ints
```


**Sample Input 3:**

```commandline
int
1
2
```


**Sample Output 3:**

```commandline
3
```


**Sample Input 4:**

```commandline
str
Hello, World!
```


**Sample Output 4:**

```commandline
Hello, World!

```

**Sample Input 5:**

```commandline
str
```


**Sample Output 5:**

```commandline
Empty String
```


**Sample Input 6:**

```commandline
list
1 2 3 4 5
```


**Sample Output 6:**

```commandline
5
```


**Sample Input 7:**

```commandline
list
```


**Sample Output 7:**

```commandline
Empty List

```

