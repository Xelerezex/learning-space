## 16

Переменная df содержит DataFrame.

-    new_index - индекс для строки, которую надо добавить
-    new_data - значения для строки, которую надо добавить
-    del_index - индекс строки, которую надо удалить

Добавьте новую строку (с индексом new_index и значениями new_data) и удалите одну из старых (del_index)

Выведите df на печать.

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
new_index = "k"
new_data = [5.5, "dog", "Belka", "no", 2]
del_index = "f"
```

**Sample Output 1:**

```commandline
  animal  age     name visits priority
a    cat  2.5   Murzik      1      yes
b    cat    3   Pushok      3      yes
c  snake  0.5      Kaa      2       no
d    dog  NaN    Bobik      3      yes
e    dog    5  Strelka      2       no
g  snake  4.5     Kaa2      1       no
h    cat  NaN    Murka      1      yes
i    dog    7     Graf      2       no
j    dog    3   Muhtar      1       no
k    5.5  dog    Belka     no        2
```

**Sample Input 2:**

```commandline
df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
new_index = 42
new_data = [33, "MD", "Aleksey"]
del_index = 3
```

**Sample Output 2:**

```commandline
      name age designation
0     Alex  20          VP
1      Bob  27         CEO
2   Carmen  35         CFO
4     Ella  18          VP
5   Forman  21         CEO
6     Glen  35          MD
42      33  MD     Aleksey
```
