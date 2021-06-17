## 9

Переменная df содержит DataFrame.

Выведите на печать только данные, относящиеся к записям, возраст которых больше, указанного в переменное critical_age.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])

critical_age = 3
```

**Sample Output 1:**

```commandline
  animal  age     name  visits priority
e    dog  5.0  Strelka       2       no
g  snake  4.5     Kaa2       1       no
i    dog  7.0     Graf       2       no
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})

critical_age = 30
```

**Sample Output 2:**

```commandline
     name  age designation
2  Carmen   35         CFO
3    Diaz   55          VP
6    Glen   35          MD
```
