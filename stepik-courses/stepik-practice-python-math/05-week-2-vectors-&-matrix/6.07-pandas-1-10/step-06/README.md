## 4

Создайте Dataframe из словаря data. В качестве подписей строк используйте список labels.

Результат сохраните в переменную df.

***Примечание.*** В этой задаче не нужно ничего считывать и ничего выводить на печать.

**Sample Input 1:**

```python
data = {'animal': ['cat', 'cat', 'snake', 'dog', 'dog', 'cat', 'snake', 'cat', 'dog', 'dog'],
        'age': [2.5, 3, 0.5, np.nan, 5, 2, 4.5, np.nan, 7, 3],
        'visits': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
        'priority': ['yes', 'yes', 'no', 'yes', 'no', 'no', 'no', 'yes', 'no', 'no']}

labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']
```

**Sample Output 1:**

```python
  animal  age  visits priority
a    cat  2.5       1      yes
b    cat  3.0       3      yes
c  snake  0.5       2       no
d    dog  NaN       3      yes
e    dog  5.0       2       no
f    cat  2.0       3       no
g  snake  4.5       1       no
h    cat  NaN       1      yes
i    dog  7.0       2       no
j    dog  3.0       1       no
```

**Sample Input 2:**

```python
data = {'name':['john','mary','peter','jeff','bill','lisa'],
    'age':[23,78,22,19,45,33],
    'state':['iowa','dc','california','texas','washington','dc'],
    'num_children':[2,2,0,1,2,1],
    'num_pets':[0,4,0,5,0,0]}
labels = range(6)
```

**Sample Output 2:**

```python
    name  age       state  num_children  num_pets
0   john   23        iowa             2         0
1   mary   78          dc             2         4
2  peter   22  california             0         0
3   jeff   19       texas             1         5
4   bill   45  washington             2         0
5   lisa   33          dc             1         0
```
