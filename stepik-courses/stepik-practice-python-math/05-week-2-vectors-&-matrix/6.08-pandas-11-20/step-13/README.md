## 20

Переменная df содержит DataFrame.

Переменная column содержит имя колонки, значения в которой надо модифицировать.

Переменные old_value и new_value содержат старое и новое значения, соответственно.

Замените все старые значения на новые в соответсвующей колонке.

Выведите df на печать

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
column = 'animal'
old_value = 'snake'
new_value = 'python'
```

**Sample Output 1:**

```commandline
   animal  age     name  visits priority
a     cat  2.5   Murzik       1      yes
b     cat  3.0   Pushok       3      yes
c  python  0.5      Kaa       2       no
d     dog  NaN    Bobik       3      yes
e     dog  5.0  Strelka       2       no
f     cat  2.0    Vaska       3       no
g  python  4.5     Kaa2       1       no
h     cat  NaN    Murka       1      yes
i     dog  7.0     Graf       2       no
j     dog  3.0   Muhtar       1       no
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
column = 'age'
old_value = 35
new_value = 33
```

**Sample Output 2:**

```commandline
     name  age designation
0    Alex   20          VP
1     Bob   27         CEO
2  Carmen   33         CFO
3    Diaz   55          VP
4    Ella   18          VP
5  Forman   21         CEO
6    Glen   33          MD
```
