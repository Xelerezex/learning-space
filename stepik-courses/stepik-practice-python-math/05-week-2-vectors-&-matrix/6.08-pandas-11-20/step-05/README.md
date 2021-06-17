## 13.2

Переменная df содержит DataFrame.

Увеличьте значение возраста во всех строках на 1.

Выведите df на печать.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
```

**Sample Output 1:**

```commandline
  animal  age     name  visits priority
a    cat  3.5   Murzik       1      yes
b    cat  4.0   Pushok       3      yes
c  snake  1.5      Kaa       2       no
d    dog  NaN    Bobik       3      yes
e    dog  6.0  Strelka       2       no
f    cat  3.0    Vaska       3       no
g  snake  5.5     Kaa2       1       no
h    cat  NaN    Murka       1      yes
i    dog  8.0     Graf       2       no
j    dog  4.0   Muhtar       1       no
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
```

**Sample Output 2:**

```commandline
     name  age designation
0    Alex   21          VP
1     Bob   28         CEO
2  Carmen   36         CFO
3    Diaz   56          VP
4    Ella   19          VP
5  Forman   22         CEO
6    Glen   36          MD
```
