## Refactoring

Продолжим работать с примером, в котором мы создавали программу учёта личных финансов и работали
с форматами ```JSON``` и ```XML```. На этот раз мы решили добавить в неё возможность конвертировать
список расходов из ```XML``` в ```JSON``` и наоборот. Для этого мы написали две функции:

-   ```Json::Document XmlToJson(const Xml::Document& doc)```

-   ```Xml::Document JsonToXml(const Json::Document& doc, string root_name)```

Кроме того, мы покрыли их юнит-тестами в функциях ```TestXmlToJson``` и ```TestJsonToXml```. Но
есть одна проблема — весь этот код писал начинающий специалист, который посмотрел все лекции
нашего курса, но, не решив ни одной задачи, сразу стал применять полученные знания в работе.
Он обратился к вам за помощью, передал свой код и, сказав: «Что-то у меня не компилируется»,
ушёл в отпуск. Ваша задача — привести в порядок код его функций и тестов, то есть сделать так,
чтобы они компилировались и работали.

>   [json.h](https://d3c33hcgiwev3.cloudfront.net/r5joNfPUEeiaxBKyA9PBAg_affed550f3d411e8b293a14f8879aaef_json.h?Expires=1645920000&Signature=ghq5OHcErwi44ji7Xrsw9zWNQMJf5Uts-859Uf-p6m9TU-wOwFD-XOcbU7FSJSkU8N6r1fhL2kWwtthJfWHgJuVzkaE3fYEpVqiV-IOYeSA65Iot7-W2NuzIj1XHjSBVE~KpMYyNjpeqNpq9Lr5-Bgm3Bign83SlU-9YYaDC04Y_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [json.cpp](https://d3c33hcgiwev3.cloudfront.net/r5k2YfPUEei5Kg7DUflKxA_afff7190f3d411e886c665ec0d18e9c6_json.cpp?Expires=1645920000&Signature=WXzyEDKdwQVKHlgTEB0VIIXJ1Cvqd7fyAvq0-vXmpu84H6aX2wbevYbW7PdQ4d1jheKP5y7yqxWJZ9pfY5SHZC~7-uAv4ZdyOAw9Md-YW6g0kqkr~lpgsKSHaR0B3ph0r8HCJliMJ4zqUNWjDlpbkRAIL-V~tStvMiaFXbXGEIA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [xml.h](https://d3c33hcgiwev3.cloudfront.net/r5tZNvPUEeiaxBKyA9PBAg_b0005bf0f3d411e894821fafea8f4186_xml.h?Expires=1645920000&Signature=V74lp3xMkZj3ujVWeRM09m5CS3iY7w7QvAzWd7Bef3s6GOHk9hO~cQxsKr-alJ95eqKsOdtFFO6pa5d8Iua9nsZOpP6vlxYgEKQ06r3baIRrLpr1Bnw82JK0a9cFCaeuha6N--OoR9Q5qGPWtt9uONrXratNhBjBA1hOhrBHduw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [xml.cpp](https://d3c33hcgiwev3.cloudfront.net/r5v03fPUEeiixgqCUDoEfA_afffe6c0f3d411e8bbdf2f9b99305df4_xml.cpp?Expires=1645920000&Signature=L9qOeJurub1TOj6JlIFP3sq-TtBJLKEKcKcK1ay7thz09c2re~NV-7ONReOYXpxPcfr98IjR8En~e4MiMv9AopLvOlTx7ppJoJpli-aJPAmWWQ7p7~Ku2czot~uGylQ1~GKyKhB~5ExmH0BqmjseamsnNbv6YgNe~G9c0HT9jbc_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [refactoring.cpp](https://d3c33hcgiwev3.cloudfront.net/pkVZOfyGEeiixgqCUDoEfA_a6addef0fc8611e89d6e37fb0a9cd3e9_refactoring.cpp?Expires=1645920000&Signature=G-FGuyJUmdrw5k0Yl3nUKYKxOVr4sXNQrRcwFYAIHQ~9XDezCfPDgsTidLcj26mbgQJvWOR~DutjV2xvoe0cBHgt9hCTKs~qSwwYPgc3JrrQzSS1~k6GirFOtFrFoQTRGZEu8TAisIc5n98QF1x3LZlgSTXxMJeOH8EM6-q3Lao_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Более подробно, функция ```XmlToJson``` ожидает на вход документ, имеющий структуру
```<root><spend amount="2500" category="food"></spend>...</root>```, то есть в корневом узле лежит
ноль или больше узлов с именем "```spend```" и атрибутами "```amount```" и "```category```".
Она должна возвращать объект класса ```Json::Document```, имеющий структуру
```[{"amount": 2500, "category": "food"}, ...]```, то есть это массив, содержащий столько словарей,
сколько было узлов ```<spend>``` в **XML**-документе. При этом в словарях узёл по ключу
"```amount```" должен быть целочисленным, а по ключу "```category```" — строковым. Гарантируется,
что в тестирующей системе на вход вашей функции будут подаваться только **XML**-документы,
соответствующие описанному формату (то есть обрабатывать некорректный ввод в данной задаче не надо).

Функция ```JsonToXml``` должна выполнять обратное преобразование. Точно так же в нашей тестирующей
системе ей на вход будут подаваться только **JSON**-документы, соответствующие описанному формату.

Тесты ```TestXmlToJson``` и ```TestJsonToXml``` не должны принимать пустые реализации функций
```XmlToJson``` и ```JsonToXml```, а также реализации, нарушающие формат выходных данных. Вам
не надо добавлять в тесты другие тестовые случаи, надо заставить компилироваться и работать те,
которые есть.

На проверку пришлите **cpp**-файл, который

-   подключает файлы **xml.h** и **json.h**

-   содержит реализацию функций ```XmlToJson```, ```JsonToXml```, ```TestJsonToXml```,
    ```TestXmlToJson```

Вам даны файлы **xml.h**/**cpp** и **json.h**/**cpp**, приведённые в соответствие с рекомендациями
последней лекции. Именно они будут использоваться в процессе тестирования вашей посылки.
