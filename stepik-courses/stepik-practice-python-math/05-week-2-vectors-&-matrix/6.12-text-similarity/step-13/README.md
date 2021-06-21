## Шаг 6 - удаление пустых строк из списка

_В данной задаче не надо ничего считывать или печатать!_

Дан список вида:

```commandline
L1 = ['cat', 's', '', 'power', '']
```

Необходимо очистить список от пустых строк и, сохранив порядок, передать новый список в переменную L2.

Тогда:

```commandline
L2 = ['cat', 's', 'power']
```

Для решения этой задачи используйте тот факт, что любая строка ненулевой длины автоматически приводится к значению True в логических выражениях:

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/05-week-2-vectors-%26-matrix/6.12-text-similarity/step-13/Source/1.png)

Пустая строка будет преобразована в False:

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/05-week-2-vectors-%26-matrix/6.12-text-similarity/step-13/Source/2.png)

Подумайте как это можно сделать не в цикле, а с помощью _list comprehension_.
