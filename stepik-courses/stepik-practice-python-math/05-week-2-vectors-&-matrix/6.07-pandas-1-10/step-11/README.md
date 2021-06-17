## 6.2

Переменная df содержит DataFrame.

Выведите на печать строки с индексами 0, 2, 3.

***Важно.*** Обратите внимание, что хотя у 1-ого Dataframe назначены произвольные строки в качестве индексов, к ним тем не менее можно обратиться и по их порядковым значениям!

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']},
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
```

**Sample Output 1:**

```commandline
  animal  age  visits priority
a    cat  2.5       1      yes
c  snake  0.5       2       no
d    dog  NaN       3      yes
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
0    Alex   20          VP
2  Carmen   35         CFO
3    Diaz   55          VP
```
