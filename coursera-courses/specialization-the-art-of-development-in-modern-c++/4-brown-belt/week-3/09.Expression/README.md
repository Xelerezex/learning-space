## Expression

В этой задаче мы воспользуемся умным указателем ```unique_ptr``` для управления временем жизни дерева
полиморфных объектов. А конкретнее, будем работать с деревом арифметического выражения. Узлами дерева
будут числа и операции.

Например, выражение ```2*(3+4)``` будет представлено вот таким деревом:

<img src="https://github.com/Xelerezex/learning-space/blob/learning-space/coursera-courses/specialization-the-art-of-development-in-modern-c%2B%2B/4-brown-belt/week-3/09.Expression/Source/tree.png" width="200"/>

В программе узлы дерева представляются объектами типов, унаследованных от интерфейса ```Expression```,
который объявлен в файле **Common.h**. У интерфейса есть два метода:

-    ```Evaluate()``` возвращает численное значение выражения. Для нашего примера это будет ```14```.

-    ```ToString()``` форматирует выражение как строку. Для простоты реализации, чтобы не учитывать
     приоритеты операций, каждый узел берётся в скобки. То есть для нашего примера этот метод вернёт
    ```(2)*((3)+(4))```.

Так как ```Expression``` — это абстрактный класс, работать с ним можно только через указатель или ссылку.
Чтобы не заниматься ручным управлением памятью, будем использовать умный указатель ```unique_ptr```. Чтобы
не загромождать код выражениями ```unique_ptr<Expression>```, в файле **Common.h** для этого выражения
предоставлен синоним ```ExpressionPtr```.

Реализуйте функции, которые позволяют создавать такое дерево выражения. Они объявлены в файле **Common.h**,
который приведён ниже:

-    ```Value()``` возвращает дерево из одного узла, представляющего целое число.

-    ```Sum()``` возвращает новое дерево, которое представляет сумму двух переданных выражений.

-    ```Product()``` возвращает новое дерево, которое представляет произведение двух переданных выражений.

Таким образом, следующий код создаст дерево для выражения ```2*(3+4)```:

```cpp
Product(Value(2), Sum(Value(3), Value(4)));
```

На проверку пришлите cpp-файл, который

-    подключает заголовочный файл **Common.h**

-    содержит реализацию функций ```Product()```, ```Value()``` и ```Sum()```

Заготовка решения содержится в файле main.cpp


### Заготовка решения

>   [main.cpp](https://d3c33hcgiwev3.cloudfront.net/_kLcxgOBEem6Gg6vVM6M8A_fe984f90038111e99d5403b934a6bc34_main.cpp?Expires=1649203200&Signature=Iqc1q3V3ZtfWQGulqQ7Cn-4riABy~VWV-9ozbd7rtFGXcAND4nRya9Gtvz7P0Kl1ftjP2jb2yTjN6J-1l2ZTmIQFLgpJcE~PY~j3vH4asocjx8IIlJVqLreMjL7vNpkxc0JrZIZKJ8RwZgDHNUyapEihfHXrYERP1b~l3RE9ZYY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Common.h](https://d3c33hcgiwev3.cloudfront.net/aiiyxf3_EeilxxL_ZeRz_A_6a8eee80fdff11e891270765d8b4cf4e_Common.h?Expires=1649203200&Signature=UGp~~kwJoQBUAKmoea6xiwDRQHLF1SVd6q7Pj0623XEsz0QPo5UwyOV3BA7SPqLsZYGNCCnBrFh01~AL0vO5Zwxa51QaKFYdJ9Yc-6KVKsKErRGx5~MofmQsaOphNHCzmJsxwww~pP2r57sDttueKXza0Bu5Q7uHZsCRIA47aZQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки

Для этой задачи есть набор подсказок, которые должны помочь вам с решением. Если вам не удаётся решить
задачу и вы чувствуете, что у вас кончились идеи, вы можете ими воспользоваться. Но сначала обязательно
попробуйте решить задачу без подсказок.

>   [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/V6IquPbhEei5Kg7DUflKxA_57ce4310f6e111e882cf5b014df25ce8__________-1.pdf?Expires=1649203200&Signature=Euja8-p0oCEuThaiZfkWbpCK1-Xmar3C5SzLnN7aExkX-3hmKaXiVkMF008FoojJbBp4MC0uFYKCyM6yA2yOCl37DAAcwNSJ67npAnFsBLhiaUVqBDWR6C9kWTS7xsm921lubxNrRnNH3x7sz9gWqCGTM51DmVMUx8beiCivFN4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/V6TpavbhEeiAgQrXx6bp4g_57ce6a20f6e111e88717b75766913400__________-2.pdf?Expires=1649203200&Signature=QqpJrdM~zUvZRuGWN8x~wIxxTWfKI80Ad9qVh9RX9EI6pSTMJkuBLTmo-8pbvxr4M4JfXI2vou6z2eP033hmbN0eIhssqW1M3AmlA2D35ms2SbNzlac6sakAHK12GBIu6~plbHRhKRXrlpXHcIfp0tQZYFIC6pa8JIomHGfvA3s_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
