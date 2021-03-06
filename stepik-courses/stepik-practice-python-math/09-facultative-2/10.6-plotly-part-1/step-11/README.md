## Задание 4

Воспользуемся данными Федеральной службы государственной статистики о численности населения России в разных возрастных группах с 1926 года https://www.gks.ru/folder/12781

В файле "[Распределение_по_возрастам.csv](https://stepik.org/media/attachments/lesson/360195/%D0%A0%D0%B0%D1%81%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BF%D0%BE_%D0%B2%D0%BE%D0%B7%D1%80%D0%B0%D1%81%D1%82%D0%B0%D0%BC.csv)" уже оставлены только данные без лишних колонок.

Постройте слайдер с графиками по годам количества населения в каждой возрастной группе. Выводите только маркеры (без соединительных линий).

Цвет маркера должен отображать прирост/убыль населения относительно предыдущего периода в этой возрастной группе:

-    зелёный - увеличение населения

-    чёрный - постоянная численность населения

-    красный - убыль населения

Для 1926 года (первый год в данном наборе данных) считать все группы "постоянными" (т.е. использовать чёрные маркеры).

Линия времени должна идти слева-направо по увеличению.

Подпишите оси, заголовок графика и значения по оси времени слайдера.

Анимацию и размер маркеров можно добавить по желанию.

Начальное положение слайдера должно быть в самом крайнем состоянии (т.е. на самых свежих данных). Для этого используется аргумент ```active``` словаря слайдера.

Обязательно задайте начальный интервал по оси Y:

-    график должен начинаться с 0, иначе масштаб может обмануть визуально о соотношении численности разных возрастных групп

-    Верхнюю границу имеет смысл задать чуть выше, чем самое большое значение численности населения 1 группы, чтобы при анимации/прокрутке никакие значения не вышли за пределы видимости и не потребовалось скроллить область.

Оформите подсказку при наведении курсора на точку в формате:

```Возрастная группа: xxxx```

```Численность группы: yyyyyy```

Эталонный результат:

![alt tag](https://github.com/Xelerezex/learning-space/blob/learning-space/stepik-courses/stepik-practice-python-math/09-facultative-2/10.6-plotly-part-1/step-11/Source/1.png)
