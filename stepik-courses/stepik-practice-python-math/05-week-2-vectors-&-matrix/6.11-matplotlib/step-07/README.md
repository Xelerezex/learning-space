## Изучение функций с помощью MatplotLib

Цель задания - исследование функции

<img src="https://latex.codecogs.com/svg.image?f(x)&space;=&space;\frac{x^{\beta}&space;&plus;&space;\alpha^{\beta}}{x^{\beta}&space;}" title="f(x) = \frac{x^{\beta} + \alpha^{\beta}}{x^{\beta} }" />

при различных значениях α <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> и <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" />.

Для каждой задачи необходимо:

-   Построить график (размер графика должен быть достаточным, чтобы визуально увидеть особенности изучаемых функций), график каждой функции должен быть одного цвета для одного значения <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" />и <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" />.

-   Подписать оси и заголовок

-   Создать легенду

-   Сохранить изображение в svg файл

-   Сделать и записать выводы о поведении графиков (можно использовать наводящие вопросы)

-    Код не должен вызывать ошибки исполнения (например, из-за деления на 0 или корня из отрицательной величины)

-    Код должен выполняться (падение кода с ошибкой у проверяющего на python аналогичной версии - повод не зачесть все пункты соответствующей задачи)

Решение необходимо предоставить в виде Jupyter Notebook файла (ipynb) и загрузить на сервер. После этого ваше решение будут проверять однокурсники, а вы проверите их решения.

[Файл образец](https://stepik.org/media/attachments/lesson/196432/%D0%9E%D0%B1%D1%80%D0%B0%D0%B7%D0%B5%D1%86_-_%D0%98%D0%B7%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D1%84%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D0%B9_%D1%81_%D0%BF%D0%BE%D0%BC%D0%BE%D1%89%D1%8C%D1%8E_MatplotLib.ipynb)

**Рекомендуется указать версию Python в которой вы выполняли работу.**


### Задача №1

**Часть 1**

Построить в общих осях графики для:

-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 1
-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 2, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 1
-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 2

Результат будет похож на следующий график (только не забудьте, что он должен быть крупным и читаемым):

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/05-week-2-vectors-%26-matrix/6.11-matplotlib/step-07/Source/1.png)

**Часть 2**

Построить в общих осях графики для x>0.

На том же графике сделать 2 врезки, демонстрирующие поведение графиков на 2 интервалах:

-   для малых x

-   для больших x

Необходимо продемонстрировать возможность (или невозможность) пересечений и стремление функций.

Цвет линий на врезках и основном графике должен быть одинаковым для одних и тех же значений <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> и <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" />.

**Часть 3**

Построить в общих осях графики для x<0.

На том же графике сделать 1 врезку, демонстрирующую поведение графиков при удалении x от 0 к <img src="https://latex.codecogs.com/svg.image?-&space;\infty" title="- \infty" />.

Необходимо продемонстрировать возможность (или невозможность) пересечений и стремление функций. Так же нанесите на графики прямую f(x) = 0.

Цвет линий на врезках и основном графике должен быть одинаковым для одних и тех же значений <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> и <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" />.


Сделайте выводы о поведении графиков при различных значениях <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> и <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" />.

Изучите возможности пересечения и то к чему стремятся кривые.

Сделайте выводы о возрастании/убывании.

### Задача №2

Построить в общих осях графики для:

-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 0, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 0, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 1
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 0, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 2
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -1
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 2, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -1

Сделайте выводы о поведении графиков

### Задача №3

Построить в общих осях графики для:

-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0.5
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -0.5
-     <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -1.5

Сделайте выводы о поведении графиков, включая возрастание/убывание и выпуклость/вогнутость

### Задача №4

В результате выполнения предыдущей задачи, вы вероятно заметите, что все графики с <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1 проходят через общую точку (1, 2).

Постройте в одном ряду 3 графика, чтобы убедиться в выводах, сделанных по результатам предыдущей задачи.

Каждый график будет содержать 4 кривые. 2 общих:

-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0(в качестве цвета попробуйте использовать 'b--')
-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -1 (в качестве цвета попробуйте использовать 'r--')

И по 2 уникальных для каждого графика:

-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0.5  и  <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = 0.8
-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -0.5 и  <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -0.8
-    <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -1.5 и  <img src="https://latex.codecogs.com/svg.image?\alpha" title="\alpha" /> = 1, <img src="https://latex.codecogs.com/svg.image?\beta" title="\beta" /> = -2.5


Не забудьте добавить легенду на каждый график. Для этого может потребоваться вызвать метод legend() для каждого объекта осей.

Для того чтобы задать общий заголовок для всех 3 графиков используйте метод https://matplotlib.org/api/_as_gen/matplotlib.pyplot.suptitle.html
