## 18

Переменная df содержит DataFrame.

Переменная sort_by содержит список из 2 строк - имён столбцов по которым необходимо провести сортировку.

Отсортируйте сперва по уменьшению 1 поля из списка sort_by, а при равенстве значений по увеличению 2.

Выведите df на печать.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']},
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
sort_by = ["age", "visits"]
```

**Sample Output 1:**

```commandline
  animal  age     name  visits priority
i    dog  7.0     Graf       2       no
e    dog  5.0  Strelka       2       no
g  snake  4.5     Kaa2       1       no
j    dog  3.0   Muhtar       1       no
b    cat  3.0   Pushok       3      yes
a    cat  2.5   Murzik       1      yes
f    cat  2.0    Vaska       3       no
c  snake  0.5      Kaa       2       no
h    cat  NaN    Murka       1      yes
d    dog  NaN    Bobik       3      yes
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'experience': [1, 2, 3, 4, 5, 6, 7],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
sort_by = ["age", "experience"]
```

**Sample Output 2:**

```commandline
     name  age  experience designation
3    Diaz   55           4          VP
2  Carmen   35           3         CFO
6    Glen   35           7          MD
1     Bob   27           2         CEO
5  Forman   21           6         CEO
0    Alex   20           1          VP
4    Ella   18           5          VP
```
