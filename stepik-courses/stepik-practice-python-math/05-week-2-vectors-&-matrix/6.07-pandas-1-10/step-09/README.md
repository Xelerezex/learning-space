## 5

Переменная df содержит DataFrame.

Выведите на печать:

-    число непустых (не null) значений в колонке 'age'
-    75% квантиль для значений в колонке 'age'

***Подсказка.*** Вам может пригодиться функция https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.describe.html

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
```

**Sample Output 1:**

```commandline
8.0
4.625
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
```

**Sample Output 2:**

```commandline
7.0
35.0
```
