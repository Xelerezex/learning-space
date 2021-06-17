## 7

Переменная df содержит DataFrame.

Выведите на печать только столбцы 'name' и 'age' (гарантируется, что они есть)

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
      name  age
a   Murzik  2.5
b   Pushok  3.0
c      Kaa  0.5
d    Bobik  NaN
e  Strelka  5.0
f    Vaska  2.0
g     Kaa2  4.5
h    Murka  NaN
i     Graf  7.0
j   Muhtar  3.0
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
```

**Sample Output 2:**

```commandline
     name  age
0    Alex   20
1     Bob   27
2  Carmen   35
3    Diaz   55
4    Ella   18
5  Forman   21
6    Glen   35
```
