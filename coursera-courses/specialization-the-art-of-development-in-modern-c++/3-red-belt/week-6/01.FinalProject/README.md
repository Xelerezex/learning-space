## Search Engine

Было бы странно в курсе от Яндекса и не попросить вас сделать свою поисковую систему.
В финальной задаче «Красного пояса» мы именно этим и займёмся :)

В этой задаче вам надо поработать с классом ```SearchServer```, который позволяет
выполнять поиск в базе документов:

```cpp
class SearchServer {
    public:
        SearchServer() = default;
        explicit SearchServer(istream& document_input);

        void UpdateDocumentBase(istream& document_input);
        void AddQueriesStream(istream& query_input, ostream& search_results_output);
};
```

Рассмотрим его интерфейс.

### Конструктор

Конструктор класса SearchServer принимает поток ввода, содержащий базу документов.
При этом

-    один документ — это одна строка входного потока;

-    документы состоят из слов, разделённых одним или несколькими пробелами;

-    слова состоят из строчных латинских букв. Например, код, приведённый ниже,
     загружает в объект класса ```SearchServer``` базу из трёх документов:

```cpp
string docs;
docs += "london is the capital of great britain\n";
    // документ содержит 7 слов
docs += "i am travelling down the river\n";
    // документ содержит 6 слов
docs += "  here     we    go             ";
    // документ содержит 3 слова

istringstream document_input(docs);
SearchServer srv(document_input);
```

### Метод AddQueriesStream(istream& query_input, ostream& search_results_output)

Метод ```AddQueriesStream``` выполняет собственно поиск. Он принимает входной поток
поисковых запросов и выходной поток для записи результатов поиска. При этом

-    один запрос — это одна строка в потоке ```query_input```

-    каждый поисковый запрос состоит из слов, разделённых одним или несколькими
     пробелами

-    так же, как и в документах, слова в запросах состоят из строчных латинских букв

Результатом обработки поискового запроса является набор из **максимум пяти** наиболее
релевантных документов. В реальных поисковых системах метрика релевантности устроена
довольно сложно. В рамках нашей задачи в качестве метрики релевантности мы будем
использовать суммарное количество вхождений всех слов запроса в документ. Например,
допустим, у нас есть поисковая база из трёх документов:
*"london is the capital of great britain"*,
*"moscow is the capital of the russian federation"*,
*"paris is the capital of france"*,
— и поисковый запрос *"the best capital"*. Тогда метрика релевантности у наших
документов будет такой:

-    *london is the capital of great britain* — 2 (слово *"the"* входит в документ
     1 раз, слово *"best"* — ни разу, слово *"capital"* — 1 раз)

-    *moscow is the capital of the russian federation* — 3 (слово *"the"* входит в
     документ 2 раза, слово *"best"* — ни разу, слово *"capital"* — 1 раз)

-    *paris is the capital of france* — 2 (*"the"* — 1, *"best"* — 0, *"capital"* — 1)

В итоге получается, что документ *"moscow is the capital of the russian federation"*
оказывается наиболее релевантным запросу *"the best capital"*.

Для каждого поискового запроса метод *AddQueriesStream* должен вывести в поток
```search_results_output``` одну строку в формате:

**[текст запроса]**: *{docid: <значение>, hitcount: <значение>}*
*{docid: <значение>, hitcount: <значение>}* ..., где ```docid``` — идентификатор
документа (см. ниже), а ```hitcount``` — значение метрики релевантности для данного
документа (то есть суммарное количество вхождений всех слов запроса в данный документ).

Два важных замечания:

-    Добавлять в результаты поиска документы, ```hitcount``` которых равен нулю, не
     нужно.

-    при подсчёте ```hitcount``` нужно учитывать только слова целиком, то есть
     слово *«there»* не является вхождением слова *«the»*

### Метод UpdateDocumentBase(istream& document_input)

Метод ```UpdateDocumentBase``` заменяет текущую базу документов на новую,
которая содержится в потоке ```document_input```. При этом документ из первой
строки этого потока будет иметь идентификатор ```(docid) 0```, документ из второй
строки — идентификатор 1 и т.д. Точно так же должен назначать идентификаторы
документам и конструктор класса ```SearchServer```. Например, код

```cpp
const string doc1 = "london is the capital of great britain";
const string doc2 = "moscow is the capital of the russian federation";
istringstream doc_input1(doc1 + '\n' + doc2);
SearchServer srv(doc_input1);

const string query = "the capital";
istringstream query_input1(query);
srv.AddQueriesStream(query_input1, cout);

istringstream doc_input2(doc2 + '\n' + doc1);
srv.UpdateDocumentBase(doc_input2);
istringstream query_input2(query);
srv.AddQueriesStream(query_input2, cout);
```

должен выводить

```cpp
the capital: {docid: 1, hitcount: 3} {docid: 0, hitcount: 2}
the capital: {docid: 0, hitcount: 3} {docid: 1, hitcount: 2}
```

## Первая часть задачи

Эта задача состоит из двух частей. В первой части вам дана корректная реализация
класса ```SearchServer```, которая работает недостаточно быстро. Вам нужно найти
и устранить узкие места в её реализации. В тестирующую систему нужно сдать
cpp-файл или архив из нескольких исходных файлов, содержащий вашу ускоренную
реализацию.

Тестирование реализации будет проводиться на производительность и на целостность.

При тестировании на производительность, Ваша реализация будет тестироваться вот
такой функцией (объект класса ```SearchServer``` будет создан один раз, и у него
один раз будет вызван метод ```AddQueriesStream```):

```cpp
void TestSearchServer(istream& document_input, istream& query_input,
                      ostream& search_results_output) {
    SearchServer srv(document_input);
    srv.AddQueriesStream(query_input, search_results_output);
}
```

При этом:

-    ```document_input``` содержит не более 50000 документов

-    каждый документ содержит не более 1000 слов

-    общее число различных слов во всех документах не превосходит 15000

-    максимальная длина одного слова — 100 символов, слова состоят из строчных
     латинских букв и разделены одним или несколькими пробелами

-    ```query_input``` содержит не более 500 000 запросов, каждый запрос содержит
     от 1 до 10 слов.

В отличие от тестирования на производительность, при тестировании на целостность и
корректность работы исходного функционала сервера допускается вызов
```UpdateDocumentBase``` в том числе и у уже созданного и проинициализированного
объекта класса ```SearchServer```.

Смотрите юнит-тесты в заготовке решения для более подробного ознакомления с тем,
как должен работать класс ```SearchServer```

> [course_project_first_part](https://d3c33hcgiwev3.cloudfront.net/dO2HqHCSEeiMwApe4i-fLg_751bc350709211e8a2b191c246483517_course_project_first_part.zip?Expires=1639785600&Signature=fePfLqPPM4FA~yHeJmaDZQy2dZZr3hg~-Cg5H~W7kEqEVFwBiwXqcYO5FiVHojGM3s1XgZ3CvvI2IXutE6fngy7OyuydpM76KwgflUIR2-IhM6Ygg9KAYHqu856htOrP3dXBv7SLQGfbI0q7HOWf5ejjidoklqFoKVfVdP7-kZw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

## Вторая часть задачи

В этой части мы смоделируем работу web-сервера, который одновременно обрабатывает
несколько потоков поисковых запросов, а также обновления базы документов. Ваша
реализация будет тестироваться так:

```cpp
void TestSearchServer(vector<pair<istream, ostream*>> streams) {
    // IteratorRange — шаблон из задачи Paginator
    // random_time() — функция, которая возвращает случайный
    // промежуток времени

    LOG_DURATION("Total");
    SearchServer srv(streams.front().first);
    for (auto& [input, output] :
        IteratorRange(begin(streams) + 1, end(streams))) {
        this_thread::sleep_for(random_time());
        if (!output) {
            srv.UpdateDocumentBase(input);
        } else {
            srv.AddQueriesStream(input, *output);
        }
    }
}
```

Как видите, с помощью макроса ```LOG_DURATION``` мы замеряем общее время работы
тестирующей функции. Ваша реализация должна работать быстрее, чем простое
последовательное применение методов ```UpdateDocumentBase``` и ```AddQueriesStream```.

На практике такой web-сервер бо̀льшую часть времени обрабатывает поисковые запросы.
База документов обновляется не очень часто с определённой периодичностью, например,
один раз в сутки. Обновление базы может занимать значительное время, поэтому сервер
не должен прекращать обработку запросов, пока оно выполняется. Ваше решение второй
части задачи должно это учитывать.

-    Метод ```AddQueriesStream``` должен быть готов к тому, что параллельно с ним
     будет выполняться метод ```UpdateDocumentBase``` и наоборот.

-    Метод ```AddQueriesStream``` не обязан обрабатывать все запросы с той версией
     базы документов, которая была актуальна во время его запуска. То есть, если
     во время работы метода ```AddQueriesStream``` база документов была обновлена,
     он может использовать новую версию базы для обработки оставшихся запросов.

### Благодарность

Благодарим [Василия Зяблицева](https://www.coursera.org/user/91db60f0dd0fd4128bd789647136b440)
за помощь в усовершенствовании этой задачи.

### Подсказки для первой части

> [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/NzvO53CTEei8FQ6TnIKJEA_378a6400709311e8a426e39149140b1f__________-1.pdf?Expires=1639785600&Signature=gd2bJxoy~igebgPpu2yizPfGtK7UePcJUQEuYf~SY20D0vq4aXT~KiCQ0stp7KpirEBAXTh4tatfV3KdUwdF0z~dzPI87nuqZVuexpzfRCpcItnpn35pyRM7lGXLu9qoeCudaws69RsTyYWkIvTwcf-rz78Z9APUz72pljDnoGU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/RbIM13CTEeiMwApe4i-fLg_45e24400709311e8900ad1fa6db602e5__________-2.pdf?Expires=1639785600&Signature=lRCwcnInoCR9xUj5V-yIsL1IcCJpb2gyswidv0u0hBTy8mbIjdOjyf8C8ooD7z0R58cXySACdGTy~eIySsNL5tB6oleH7PYoL5Iwg2alsWzRcQmtkTP8jge2i78GggZibQKo55ekUT~Y1UleoVKfNb-p05MUw0z2zwbo6jPOdDY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/RbCFoXCTEeiYxxI-37QEMA_46084290709311e8af9ddfa51df93fce__________-3.pdf?Expires=1639785600&Signature=jFXV8spQzgcacQngIFUj97TjfVcCl90j83j9Sb3KFRFomDiqIkQyC4AxZ3Mmt7UPRN69o3XZ-T9uFA-PqseCjurquNw~OlXNDi2QQAMlPsohWu8VVOyasFolklvb-J7vMqwjoK8tibfuIUXggP90HgEOktcPw9wm7CHCI5xZwvE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/RbNFW3CTEeiMwApe4i-fLg_46050e40709311e88758978c6b812679__________-4.pdf?Expires=1639785600&Signature=WfAmKRI2NdxGRijVn11jVIVXwfGuzWH3bzchkJ0ykWLg780HWpHK6bTUqTS3~TfOo036KJBJWSPMFwxmfD771TiWE8OM-mT2z4G7mEXYwwBDOjszrS1hHNf9DbJEmBHLak6K8b07CKPO0YD55eA4rUtZjmj0EjqDC4gGUk5zCJc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 5.pdf](https://d3c33hcgiwev3.cloudfront.net/RbPhnHCTEeiMwApe4i-fLg_46066dd0709311e8a2b191c246483517__________-5.pdf?Expires=1639785600&Signature=B4vaIpSlAD5GQFEo65A3w4ABSFq~h0w08uNYmjTM5dQWv1HPT-u4kQkHxeXeNLD07aSTu5Qcp0STAEW9Bc6SXEP7QaRXt0357gbdvg~Y6cS16dZDuZhnvTnrtVP14HkHjXE9HK1gjPhlYvzZvbHu5yrW0-6U1kvpOPyiR4DIXvI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 6.pdf](https://d3c33hcgiwev3.cloudfront.net/RbJa-HCTEeiMwApe4i-fLg_46050e40709311e88c6bcd0532dc5d2d__________-6.pdf?Expires=1639785600&Signature=PKl9O7VDw4wkdDb51JUEYNYqQhqnb8xyu-uaw-6Q9TiLArt2XNUl6BI0Awp~Ga6LIF0objVTijmVJw8a1iOiWWaicbj7395CvVIBIb6-lZmgoPHN9dzIsCa5ddQa1R9H8Y3v5RGmsO7UHN01~PFcnx5Tn~IluNDjWevUOtAucyE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 7.pdf](https://d3c33hcgiwev3.cloudfront.net/RbLQKXCTEeiMwApe4i-fLg_46044af0709311e8ba44a5a7d9ded0dd__________-7.pdf?Expires=1639785600&Signature=eBHsa71CKl8DO-sjG8Cl6Qh7HbSyjR5F9zxzUs37Ma8SXXCbgp6MTLxaYd04jQ8KMTRKP5lwiNHwP1PXsCYunK6AecaikXjpEf~9C-qUccswQlh7qCKdLsRlSzQd0ZnXg8JmsxKS23jTrEcvmwde7wJPwG75iB-RdhMwqX8gWTI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 8.pdf](https://d3c33hcgiwev3.cloudfront.net/RbMeSnCTEeiMwApe4i-fLg_4623e0e0709311e8900ad1fa6db602e5__________-8.pdf?Expires=1639785600&Signature=FxcMBDT4IRi6323B8zVqPnzuOcEajXtGoJrsQm3d9ngwI~eeLpZzJ4kRDVsPM8UL6pqDdGDWxD2tYN6MTA0N-O98okOiBrOWQ~E7~GyCHnbJTv0Jy7BjiL0OBT3vi6Znj4ot5aebP2Y5j9gvob8~bf7RriWlexGrkEJoMJ6mIws_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

### Подсказки для второй части

> [Подсказка 1.pdf](https://d3c33hcgiwev3.cloudfront.net/rrjz1HCTEei8FQ6TnIKJEA_aee24d10709311e8900ad1fa6db602e5__________-1.pdf?Expires=1639785600&Signature=RzTEfqfx86AUVYzrDcBCy-F9Twep5CoPXV2kV3W1XdWV~hRrwXnDqu0FULcQv0fc-01wZVXA6voAc22sSMjwjBjs4zaD8pWfeRvvlrvgC1BJiSx5DhqxqAaXbsNDyu9UU-f2qIA-b~U5HnUCvNTAvVySxd1Ur3D1jltsYMcbSPc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 2.pdf](https://d3c33hcgiwev3.cloudfront.net/rrqhlHCTEeiMwApe4i-fLg_aee951f0709311e8a2b191c246483517__________-2.pdf?Expires=1639785600&Signature=YKupjPat7zUok~NdzPQ0LgCrGOSW-tjqnZ95NGZ4J-ixLY5EJhVmYODU-lMTZiaY4Ifb8tFpyH6Pw9wScWYQoHCc6j53IoM~WEFAa923oRhAe98t6wMjTJcaa92Y6ygnGs2hCteAWXDOtLsKEvL78wQ8oOfBqLKOWPimeYIoFlQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 3.pdf](https://d3c33hcgiwev3.cloudfront.net/rrfh13CTEeiYxxI-37QEMA_aee3aca0709311e88c6bcd0532dc5d2d__________-3.pdf?Expires=1639785600&Signature=PhB4qw6tpaOYen~MMNvTfsvS~D2VCJ5LJkMfhvXMZDLghMjXIgXFJl18SkMeD1FIF0xMFVqAfPnvgWixLtCEDT1TiaeKBYZhpx-QzemS42pIIrgvdGXE-T7cRRqsZIiDx91xv8DQGDpA3e8BhjU3ZrB5LgrHxFw7UJkr7Hwc2dQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [Подсказка 4.pdf](https://d3c33hcgiwev3.cloudfront.net/rre6xnCTEeiYxxI-37QEMA_aee55a50709311e8974bdb6d8d62625b__________-4.pdf?Expires=1639785600&Signature=L~l21vh8ix9edyCKJBgQ0hCjlERZSK0D0iNMWs92BeVgGCveIT5BMez7AxdXBk5X0llbl6DsVW9h4U5MHXlF1hxzo5YRBmzn8LB~nqXLbPQT3pj9crBmfiTAxvhttDVlmuDoJv29LPeCO4R8eIf27NXwYRz55B6lKtn-VlLvYmQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
