#### Задание по программированию: Декомпозиция программы ####


***Введение***

В курсе «Белый пояс по С++» у нас была задача «[Автобусные остановки — 1](https://github.com/Xelerezex/learning-space/tree/learning-space/coursera-courses/specialization-the-art-of-development-in-modern-c%2B%2B/1-white-belt/week-2/13.BusStops-1)». В этой задаче вам будет дано её правильное решение, целиком содержащееся внутри функции _main_. Вам надо будет выполнить декомпозицию этого решения на заранее заданные блоки так, чтобы получившаяся программа так же корректно решала задачу. Условие задачи «Автобусные остановки — 1» приведено ниже.

***Исходные файлы***

Авторское решение этой задачи содержится в файле

[correct.cpp](https://d3c33hcgiwev3.cloudfront.net/_ba1e32e3cc261f122b1b272c441bae30_correct.cpp?Expires=1622246400&Signature=kq4T0X9lUJZPWv0VFPEoxdJCSGMr7TO0wF5AJ3A1NSBD27BspTEbkDa4XZAt57jml1KHJ4XeZueNql4uwS34wQrhAZZVhkKOQXwQXq2zfkzDzvIBAgMvkEM6C9ARmG9ilJChqs-A9RZksyYNCdV6nWnNQ5Ghjb3YvvzARKcICIQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Кроме того, вам дан файл

[starter.cpp](https://d3c33hcgiwev3.cloudfront.net/_889d5f03c308eeac67b75b9072b0f0ca_starter.cpp?Expires=1622246400&Signature=feED75Sorf47yXPTq5zOdp1zY-VOm~O50bv7RMqhttPS1hhghnltr~pRgwYy32NYG4o6QJBeRF1hoggreKdj20FrlGONOH4St9UPGz1YSrDygtqNvEYATCChuwf8JCjgH9EvMhXiuJeoj7CA1hxrt~72zhLphWi-ypGrxDdIxNg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

который содержит заготовки классов и функций. __Не меняя функцию main__, вам надо реализовать эти классы и функции так, чтобы получившаяся программа решала задачу «Автобусные остановки — 1».

***Как будет тестироваться ваша программа***

Автоматическая проверяющая система заменит в вашей программе функцию _main_ на ту, которая дана вам в файле _starter.cpp_, скомпилирует получившийся файл и прогонит на тестах для задачи «Автобусные остановки — 1».

***Условие задачи «Автобусные остановки — 1»***

Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

* **NEW_BUS *bus stop_count stop1 stop2 ...*** — добавить маршрут автобуса с названием ***bus*** и ***stop_count*** остановками с названиями ***stop1, stop2, ...***
* **BUSES_FOR_STOP *stop*** — вывести названия всех маршрутов автобуса, проходящих через остановку ***stop***.
* **STOPS_FOR_BUS *bus*** — вывести названия всех остановок маршрута ***bus*** со списком автобусов, на которые можно пересесть на каждой из остановок.
* **ALL_BUSES** — вывести список всех маршрутов с остановками.

***Формат ввода***

В первой строке ввода содержится количество запросов *Q*, затем в *Q* строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса **NEW_BUS *bus stop_count stop1 stop2 ...*** гарантируется, что маршрут ***bus*** отсутствует, количество остановок больше 0, а после числа ***stop_count*** следует именно такое количество названий остановок, причём все названия в каждом списке различны.

***Формат вывода***

Для каждого запроса, кроме **NEW_BUS**, выведите соответствующий ответ на него:

* На запрос **BUSES_FOR_STOP *stop*** выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами **NEW_BUS**. Если остановка ***stop*** не существует, выведите **No stop**.
* На запрос **STOPS_FOR_BUS *bus*** выведите описания остановок маршрута ***bus*** в отдельных строках в том порядке, в котором они были заданы в соответствующей команде **NEW_BUS**. Описание каждой остановки ***stop*** должно иметь вид **Stop *stop: bus1 bus2 ...***, где ***bus1 bus2 ...*** — список автобусов, проезжающих через остановку ***stop***, в порядке, в котором они создавались командами **NEW_BUS**, за исключением исходного маршрута ***bus***. Если через остановку ***stop*** не проезжает ни один автобус, кроме ***bus***, вместо списка автобусов для неё выведите **no interchange**. Если маршрут ***bus*** не существует, выведите **No bus**.
* На запрос **ALL_BUSES** выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута ***bus*** должно иметь вид **Bus *bus: stop1 stop2 ...***, где ***stop1 stop2 ...*** — список остановок автобуса ***bus*** в порядке, в котором они были заданы в соответствующей команде **NEW_BUS**. Если автобусы отсутствуют, выведите **No buses**.

***Предупреждение***

Условие задачи выше содержит много важных деталей. Если вы не уверены в том, что не упустили ни одной, перечитайте условие ещё раз.

#### Example:

##### Input:

```commandline
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
```
##### Output:

```commandline
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
```
