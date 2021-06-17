## 12

Переменная df содержит DataFrame.

Переменная age_between содержит 2 числа

Выведите только те строки датафрейма, возраст в которых находится в интервале между числами age_between (включая границы).

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
age_between = [2, 4]
```


**Sample Output 1:**

```commandline

  animal  age    name  visits priority
a    cat  2.5  Murzik       1      yes
b    cat  3.0  Pushok       3      yes
f    cat  2.0   Vaska       3       no
j    dog  3.0  Muhtar       1       no
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
age_between = [21, 55]
```

**Sample Output 2:**

```commandline
     name  age designation
1     Bob   27         CEO
2  Carmen   35         CFO
3    Diaz   55          VP
5  Forman   21         CEO
6    Glen   35          MD
```
