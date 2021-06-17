## 19

Переменная df содержит DataFrame.

Переменная column содержит имя колонки, содержащей строковые значения "yes", "no", либо числовые 1 или 0.

Замените в column:

-    "yes" и 1 на True
-    "no" и 0 на False

Выведите df на печать

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
column = "priority"
```

**Sample Output 1:**

```commandline
  animal  age     name  visits  priority
a    cat  2.5   Murzik       1      True
b    cat  3.0   Pushok       3      True
c  snake  0.5      Kaa       2     False
d    dog  NaN    Bobik       3      True
e    dog  5.0  Strelka       2     False
f    cat  2.0    Vaska       3     False
g  snake  4.5     Kaa2       1     False
h    cat  NaN    Murka       1      True
i    dog  7.0     Graf       2     False
j    dog  3.0   Muhtar       1     False
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'on vacation': [1, 1, 0, 0, 0, 1, 0],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
column = "on vacation"
```

**Sample Output 2:**

```commandline
     name  age  on vacation designation
0    Alex   20         True          VP
1     Bob   27         True         CEO
2  Carmen   35        False         CFO
3    Diaz   55        False          VP
4    Ella   18        False          VP
5  Forman   21         True         CEO
6    Glen   35        False          MD
```
