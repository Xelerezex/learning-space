## Final Project

В курсе «Белый пояс по С++» [финальным заданием](https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa) была разработка базы
данных, которая работала с парами (дата, событие). В этой задаче вам
нужно развить эту базу данных, научив её выбирать и удалять события,
удовлетворяющие заданному условию, а также разделив её код на несколько файлов.

Более подробно, ваша программа должна уметь обрабатывать набор команд:

-    **Add** ***dateevent*** — добавить в базу данных пару (***date***, ***event***);

-    **Print** — вывести всё содержимое базы данных;

-    **Find** ***condition*** — вывести все записи, содержащиеся в базе данных, которые удовлетворяют условию ***condition***;

-    **Del** ***condition*** — удалить из базы все записи, которые удовлетворяют условию ***condition***;

-    **Last** ***date*** — вывести запись с последним событием, случившимся не позже данной даты.

Условия в командах **Find** и **Del** накладывают определённые ограничения на даты и события, например:

-    **Find date < 2017-11-06** — найти все события, которые случились раньше 6 ноября 2017 года;

-    **Del event != "holiday"** — удалить из базы все события, кроме «**holiday**»;

-    **Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event"** — найти всё события «**sport event**»,
     случившиеся в первой половине 2017 года;

-    **Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")** — удалить из базы все события «**holiday**»
     и «**sport event**», случившиеся до 2017 года.

В командах обоих типов условия могут быть пустыми: под такое условие попадают все события.

### Programm structure:

Ниже вам даны заготовки для файлов

-    condition_parser.h/cpp — в видеолекции «Задача разбора арифметического выражения.
     Описание решения» мы продемонстрировали построение абстрактного синтаксического дерева для арифметических выражений.
     Реализация этого алгоритма для разбора условий в командах **Find** и **Del** содержится в функции ParseCondition,
     объявленной и полностью реализованной в файлах condition_parser.h/cpp;

-    token.h/cpp — содержат готовый токенизатор, который используется в функции ParseCondition;

-    main.cpp — содержит готовую функцию main.

Вам нужно проанализировать выданный код и разработать недостающие классы и функции:

-    класс Database, который представляет собой базу данных, — вы должны сами создать
     его публичный интерфейс, основываясь на том, как он используется в функции main;

-    классы Node, EmptyNode, DateComparisonNode, EventComparisonNode и LogicalOperationNode —
     сформировать их иерархию и публичный интерфейс вам поможет анализ функций main и ParseCondition;

-    класс Date, а также функцию ParseDate и оператор вывода в поток для класса Date.

На проверку вы должны прислать архив, состоящий из файлов:

-    date.h/cpp — эти файлы должны содержать объявления и определения класса Date, функции ParseDate и оператора вывода в поток для класса Date;

-    database.h/cpp — эти файлы должны содержать объявление и определение класса Database;

-    node.h/cpp — эти файлы должны содержать объявления и определения класса Node,
     а также всех его потомков (см. выше), которые представляют собой узлы абстрактного синтаксического дерева,
     формируемого функцией ParseCondition;

-    condition_parser.h/cpp;

-    token.h/cpp;

-    main.cpp;

-    другие .h- и .cpp-файлы, которые вы посчитаете нужным создать в своём решении.

### How solution will be test:

Тестирование вашего решения будет выполняться в два этапа. На первом этапе автоматическая тестирующая
система распакует присланный вами архив и соберёт извлечённые файлы в исполняемый файл.
Затем этот исполняемый файл будет запущен на наборе тестов. Тестирование выполняется так же, как и для
большинства задач на нашем курсе — тест подаётся в stdin, замеряется время выполнения программы, а затем анализируется stdout.

На втором этапе будет выполняться тестирование отдельных файлов вашего проекта.
Проверяется, что файл date.h действительно содержит объявление класса Date, что Database::FindIf корректно
выполняет поиск по переданному предикату и т.д. Мы ожидаем от ваших классов интерфейс,
который зафиксирован в функции main. Поэтому в классах Database и Node делайте у методов именно те сигнатуры,
которые используются в функции main.

### Input & Output Format:

В стандартном вводе содержатся команды для работы с базой данных, по одной команде в строке.
Ваша программа должна считать их и вывести результаты обработки в стандартный вывод.
Правила обработки команд приведены ниже.

#### Команда **Add**:

Встретив команду **Add** ***dateevent***, ваша программа должна добавить пару (***date***, ***event***) в базу данных
и затем показывать её при поиске (команда ***Find***) или печати (команда ***Print***). Одинаковые события,
произошедшие в один и тот же день, сохранять не нужно: добавление в базу уже существующей пары (date, event) должно игнорироваться.
В одну и ту же дату может произойти много разных событий, БД должна суметь их все сохранить.

Гарантируется, что поле ***date*** в команде **Add** имеет формат «_Год-Месяц-День_», где _Год_ — это целое
число от 0 до 9999, _Месяц_ — это номер месяца от 1 до 12 включительно, _День_ — это номер дня от 1 до 31 включительно.
После даты обязательно следует пробел, отделяющий её от события. Примеры корректных дат: 2017-11-07, 0-2-31.

Вся остальная часть строки в команде **Add** задаёт событие. Оно может содержать пробелы,
поэтому для его считывания удобно воспользоваться функцией getline. При этом гарантируется,
что название события не может содержать символ кавычки ("). Таким образом, этот символ может встретиться лишь
в условии в командах Find и Del, являясь ограничителем названия события.

##### Example:

Для команды **Add 2017-11-07 big sport event** программа должна добавить в базу данных пару (**2017-11-07, big sport event**).

#### Команда **Del**:

Встретив команду **Del** ***condition***, ваша программа должна удалить из базы данных все события,
удовлетворяющие условию ***condition***, и вывести в стандартный вывод количество удалённых записей ***N***
в формате «***Removed N entries***». Если условие пусто, результатом выполнения команды должна стать очистка всей базы данных.

##### Example:

###### Input:

```commandline
Add 2017-06-01 1st of June
Add 2017-07-08 8th of July
Add 2017-07-08 Someone's birthday
Del date == 2017-07-08
```

###### Output:

```commandline
Removed 2 entries
```
#### Команда **Print**:

Встретив команду **Print**, ваша программа должна вывести все пары (_дата_, _событие_),
которые в данный момент содержатся в базе данных. Пары надо выводить по одной в строке.
Они должны быть отсортированы по дате по возрастанию. События в рамках одной даты необходимо выводить
в порядке добавления (за исключением уже удалённых и попыток добавления повторов).

Даты надо выводить в формате **ГГГГ-ММ-ДД**, где Г, М, Д — это цифры чисел года, месяца и дня соответственно.
Если какое-то число имеет меньше разрядов, чем нужно, его надо дополнить нулями, например:
**0001-01-01** — первое января первого года.

##### Example:

###### Input:

```commanline
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-1-1 New Year
Add 2017-1-1 New Year
Print
```

###### Output:

```commanline
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
```

***Note:*** _Обратите внимание, что событие "New Year" выведено только один раз, несмотря на то, что оно добавлено дважды.
Как сказано в описании команды Add, одинаковые события, произошедшие в один и тот же день, сохранять не нужно._

#### Команда **Find**:

Встретив команду **Find** ***condition***, ваша программа должна вывести все пары (_дата_, _событие_), которые в данный момент
содержатся в базе данных и удовлетворяют условию **condition**. Формат вывода аналогичен команде **Print**. Поиск с пустым
условием эквивалентен команде **Print**. В конце команда должна вывести строку **Found** ***N entries***, где **N** — количество найденных пар.

##### Example:

###### Input:

```commandline
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-01-01 New Year
Find event != "working day"
Add 2017-05-09 Holiday
```

###### Output:

```commandline
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
Found 3 entries
```

#### Команда **Last**:

По команде **Last** ***date*** нужно вывести последнее из событий, случившихся к дате ***date***. Более формально:

-   среди всех имеющихся дат событий нужно найти наибольшую, не превосходящую ***date***;

-   из всех событий с такой датой нужно выбрать **последнее добавленное** и вывести в формате, аналогичном формату команды **Print**;

-   если ***date*** меньше всех имеющихся дат, необходимо вывести «**No entries**».

##### Example:

###### Input:

```commanline
Add 2017-01-01 New Year
Add 2017-03-08 Holiday
Add 2017-01-01 Holiday
Last 2016-12-31
Last 2017-01-01
Last 2017-06-01
Add 2017-05-09 Holiday
```

###### Output:

```commanline
No entries
2017-01-01 Holiday
2017-03-08 Holiday
```

### Example:

###### Input:

```commanline
Add 2017-11-21 Tuesday
Add 2017-11-20 Monday
Add 2017-11-21 Weekly meeting
Print
Find event != "Weekly meeting"
Last 2017-11-30
Del date > 2017-11-20
Last 2017-11-30
Last 2017-11-01
```

###### Output:

```commanline
2017-11-20 Monday
2017-11-21 Tuesday
2017-11-21 Weekly meeting
2017-11-20 Monday
2017-11-21 Tuesday
Found 2 entries
2017-11-21 Weekly meeting
Removed 2 entries
2017-11-20 Monday
No entries
```

#### Заготовки файлов:

> [token.h](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_token.h?Expires=1628035200&Signature=B8r6puZ9GkpfhSpK3LnG7OVnTHzKeoSePEVkIBaCnVUvaRVfMwYH-eM5No9FEkaoo7I0vo6fn3-sRSEkWecSYd3rCbPRI6lDDFs3GagUxpx-P4sh5BRGa175JPWS8fdhZTawobsyXTKUbD-8NtMhrSXjKWVszUPGM2yqxcvkH30_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [token.cpp](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_token.cpp?Expires=1628035200&Signature=O9heblvMnF5L9yHbRJDfxTjsX3YN4NDcKCXH2axXzPn-4oVfR83OZUfhvK6rWScc2RgG4Q6hEmd8-~VzIj7FUEjH5E-fGww9AKTGjmdkUBhZy-QrEjNslGLCLshajs5Lo7vnPm6Drg57ikExUnGV~J~sX9ZE975Kb9k-0yF0OdU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [condition_parser.h](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_condition_parser.h?Expires=1628035200&Signature=N6Qr6Ona0sdmQG9v~kRjt0azJuSaQa934JFiKT4qAdnHSQBZr3wBDGCtV5P9NhTEGKXox~deOJY2bRL2K0D28o4hKREddWbFS8RjMWHIGtfqPuBp0cPMlgjgPeXyCLZSBpmZyMHFTonswBDFJ-tj3V-2N79u2~uR3RxpR11y0NA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [condition_parser.cpp](https://d3c33hcgiwev3.cloudfront.net/_1640ad9030c0d03640026eccd83d190f_condition_parser.cpp?Expires=1628035200&Signature=HYGEY2syb9Vl7Ymjg4ibRk1-9zFgWoXeVbB4GoOGPzegN-VjyMMl7Q~RxC2UeAil0ZAC0F42lRIRGvWmrEmR6ghz2vwlT1wg~SrdZl6vtiZCnTOjT7AUSnUub6tVR5SMIK9Z4CFHrFjSaeNDGnG4W1wkcU8SwRrVImmHLCodzVQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [condition_parser_test.cpp](https://d3c33hcgiwev3.cloudfront.net/_8238a90130e316da9eabec79c0325d5d_condition_parser_test.cpp?Expires=1628035200&Signature=Min0R5JPH1nw~s0oJEeRMBqPS-EnopTHpNkecys4vP7vxDBVaMqJ9WSSi45hUzZuNJZ27e6zx20HJ-jvGT4tYSg3b6Y200J9VfXch-DULFDAGhaDttaCQQlJFZfdruT1upVbV9NF27BBqze-6JHYs-aSaWWzgBkLDhjbbJ9eZ08_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [main.cpp](https://d3c33hcgiwev3.cloudfront.net/jObtWT8UEeiVZA69vv3iOA_8d4623803f1411e8b699e1a3b32ed99e_main.cpp?Expires=1628035200&Signature=WAwXPCI4shiszE6giivGapb5k3p6p0opoFemAZD9~UnpvuvRrzZPUtOn7--i9EfS3eNs90n6knZ0WWYqtIoiq~qMGULd3tbPSRcaKXta23MLjHTEFZV3Mov51Ofkev47Yp7xJ9dLrAUo0LTYIVXqby0EFXvPn3GaRxr4s~dvUrE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Обратите внимание, что в файле main.cpp мы используем наш фреймворк юнит-тестов, для тестирования функций ParseCondition и ParseEvent. В процессе работы над проектом вы можете разрабатывать свои тесты и добавлять их в функцию TestAll.

#### Tips:

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно попробуйте решить задачу без подсказок.

> [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/gOtr-MMSEeiHqw7NuTbPEA_81690050c31211e886d35bf31cd9316a__________-1.pdf?Expires=1628035200&Signature=Po4EWeGaw-8jdCOAfEM5uNwUQbnnEWhLDN4N9CENktceavCZo~TMQxDzt6vMi48xvxpqd86s~8T9DkvIilFX36yCr9hX3cv0WEGONdSqQf2pNpw1oV5e~26C2dZyrHkLLmX0EXV7xdyv-mVk5HH1Ycyw0GVNzAinQWoZxse4Nkg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/YhZmDsMTEeiZjg4gmeu3pg_62748b00c31311e88260477c31b38644__________-2.pdf?Expires=1628035200&Signature=W-gn~M23GBdE7zK17-mXk60M4j1Z~N7DQ6Q3rTCJWMo-Ef9sEMI7mC5l0qUdovOneICfG0NVwvnKXVvheh96C1S-lOAIlLvzua8yEAaI5MDnqykN8hppH4iODDsl1bE5ES~mesVTp-BPnTHIV7jB5aQgRb8rpldAd35Hw1iNRXE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/YhcpcMMTEeiTIRLEW541JA_62774a20c31311e8ad3f8bdce68cc9f2__________-3.pdf?Expires=1628035200&Signature=GZzSALt1uOLo32p9waAN9leh3ebv9u6NuXI8VQkUkyXVtE7CQtDfOdiJuALHk~-RWjBH3GaeJrrzWlYZPdxzuLRN-K~oYBe4WO3SBfKEBfoqTTqNj8kqZrCMQuNU3A8LRVJ02R097xP6vTGUUx4qCi--YukcSXYXlcuGXpTtgaI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/YhcB8MMTEeiQ4QpwNIMilg_62774a20c31311e8ba890b8f62b9d7b0__________-4.pdf?Expires=1628035200&Signature=DsJ0BQnjmQTlPVkG7F~ldg4Si-6~LPC9rzfA7sTccyI~BgCDFA1QDJjFiPZzkvo8Qk3PSwzgkXYim80iF1TeO9ueJesKQbN5sVYsN9OSWEwZ3VaGJGQLxlP2rks3yu6e6M301px1X4bsKM2umJTNZx1BYNro4j1K67o2i2b8Glw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
