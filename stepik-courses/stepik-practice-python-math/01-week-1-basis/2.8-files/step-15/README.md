-   event - переменная с текстом события
-   file_name - имя файла с логом

Файл с логом содержит записи о некоторых событиях вида:

```commandline
event 3 - 'git log -2'
event 2 - 'git log'
event 1 - 'git status'
```

Пример нового события:

```commandline
git fetch origin
```

Дополните лог в файле так, чтобы новое событие было записано вверху. Не забудьте указать порядковый номер события.

```commandline
event 4 - 'git fetch origin'
event 3 - 'git log -2'
event 2 - 'git log'
event 1 - 'git status'
```

Если файл отсутствует или не содержит записей, начните нумеровать события с 1.

_Не забывайте про переносы строк!_

***Примечание.*** Гарантируется, что путь не указывает на каталог. Т.е. ситуация когда файла нет и его невозможно создать исключена.

***Примечание.*** В логе могут быть пустые строки

**Sample Input 1:**

```commandline
event = "git fetch origin"
file_name = "tmp/git.log"
```


**Sample Output 1:**

```commandline
event 4 - 'git fetch origin'
event 3 - 'git log -2'
event 2 - 'git log'
event 1 - 'git status'
```


**Sample Input 2:**

```commandline
event = "git fetch origin"
file_name = "tmp/empty_git.log"
```


**Sample Output 2:**

```commandline
event 1 - 'git fetch origin'
```


**Sample Input 3:**

```commandline
event = "2020_02_05 15_05_31"
file_name = "tmp/access.log"
```


**Sample Output 3:**

```commandline
event 3 - '2020_02_05 15_05_31'
event 2 - '2020_02_05 15_05_30'

event 1 - '2020_02_01 15_05_31'
```


