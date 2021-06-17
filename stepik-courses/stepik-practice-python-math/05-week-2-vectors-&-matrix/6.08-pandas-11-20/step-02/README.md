## 11

Переменная df содержит DataFrame.

Переменная filter_names содержит список имён столбцов по которым происходит фильтрация

Переменная filter_values содержит список из 2 значений по которым происходит фильтрация. 1 значение проверяется на равенство. 2 значение должно быть меньше указанного в фильтре.

Выведите только те строки датафрейма, которые удовлетворяют условиям обоих фильтров.

В 1 примере мы выводим данные обо всех животных (имя столбца = 'animal'), являющихся кошками (значение = 'cat'), возраст (имя столбца = 'age') которых меньше 3 (значение = 3).

**Sample Input 1:**

```commandline
df = pd.DataFrame({'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
                   'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
                   'name': ['Murzik', 'Pushok', 'Kaa', 'Bobik', 'Strelka', 'Vaska', 'Kaa2', 'Murka', 'Graf', 'Muhtar'],
                   'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
                   'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']})
                 index = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'])
filter_names = ["animal", "age"]
filter_values = ["cat", 3]
```

**Sample Output 1:**

```commandline
  animal  age    name  visits priority
a    cat  2.5  Murzik       1      yes
f    cat  2.0   Vaska       3       no
```

**Sample Input 2:**

```commandline

df = pd.DataFrame({'name' : ["Alex", "Bob", "Carmen", "Diaz", "Ella","Forman", "Glen"],
                   'age' : [20, 27, 35, 55, 18, 21, 35],
                   'designation': ["VP", "CEO", "CFO", "VP", "VP", "CEO", "MD"]})
filter_names = ["designation", "age"]
filter_values = ["VP", 40]
```

**Sample Output 2:**

```commandline
   name  age designation
0  Alex   20          VP
4  Ella   18          VP
```
