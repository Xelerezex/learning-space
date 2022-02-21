## Spendings Xml

В этой тренировочной задаче вам надо поддержать загрузку расходов из формата ```XML``` в нашей
программе управления личными финансами. При этом вам надо воспользоваться готовой библиотекой
работы с ```XML```. Более конкретно, вам надо написать функцию
```vector<Spending> LoadFromXml(istream& input)```. ```Spending``` — это структура из вводной лекции:

```cpp
struct Spending
{
    string category;
    int amount;
};
```

Поток ```input``` содержит описание расходов в формате ```XML```, например:

```cpp
<july>
    <spend amount="2500" category="food"></spend>
    <spend amount="1150" category="transport"></spend>
    <spend amount="5780" category="restaurants"></spend>
    <spend amount="7500" category="clothes"></spend>
    <spend amount="23740" category="travel"></spend>
    <spend amount="12000" category="sport"></spend>
</july>
```

Важно отметить:

-   формат текста в потоке ```input``` всегда строго такой, как в примере: есть один корневой
    узел, который содержит несколько узлов ```<spend>``` с атрибутами ```"amount"``` и ```"category"```

-   функция ```Load``` из выданной вам библиотеки работы с ```XML``` умеет загружать описанный
    выше формат

-   мы выдаём вам не реальную библиотеку разбора XML, а лишь минимальный код, достаточный для
    работы описанным форматом данных

-   цель этой задачи — не показать, как правильно парсить XML, а познакомить вас с кодом, на
    котором мы в дальнейшем будем разбирать пространства имён, поэтому очень важно, чтобы вы
    реализовали функцию ```LoadFromXml``` через содержимое нашей библиотеки работы с ```XML```.

На проверку пришлите cpp-файл, который подключает файл **xml.h** (дан ниже) и содержит реализацию
функции ```LoadFromXml```. Тестирующая система соберёт его вместе с файлом **xml.cpp** и прогонит
набор юнит-тестов.

### Заготовка решения и библиотека

>   [xml.h](https://d3c33hcgiwev3.cloudfront.net/X1cp9fexEeilxxL_ZeRz_A_5fb0bb50f7b111e8a2f4f31ac9657a8d_xml.h?Expires=1645574400&Signature=Fm~zlgNsdBRlrD0kasYby97qYbDfuy4kYFnvjDc5XraE-w~P~6abABf9V~UR2bmseJL25H1DCccOhyQxruPsmOLDKnUtmPixiZAL2XD6luUCXpVjZeFfUXes-8mNFZ2LqIb-EICHvrJdraccLWP4ib6bKqhjEYjiYhUGhuBmPmM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [xml.cpp](https://d3c33hcgiwev3.cloudfront.net/X1Y_7fexEeiAgQrXx6bp4g_5f8f50a0f7b111e8834415d2586e2901_xml.cpp?Expires=1645574400&Signature=KK2eaZM1jaPrJMMR8cIwa-kvI5i3VzN-UORvBaAy5~XIzwQ~KE5Idb30AnKMTCyA6imswCLUrEyuNsvSafoU98om-LB0gCht5z8eKlPWvW9ntnTEOX5Ia1Vsvo2CtW9iNKsNM3A66azRZ-XK6tb~yKflQWmJy2Cb9j~BhKuK7bE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [spendings_xml.cpp](https://d3c33hcgiwev3.cloudfront.net/X1Xxs_exEeiixgqCUDoEfA_5f73d960f7b111e894354b825341e8a4_spendings_xml.cpp?Expires=1645574400&Signature=Oo9WkRJxl0mmGa7pT~DshzKqbnhitfccvN3ofpnf83FRBsszlhkodnoYqMZFt1zFq4vJuX2es-ELOnI000lxmte0yeems38Mn6ppI7JFIQ8uhdv-uPRRRNIaUhewO7f7vm4k0FONeZwnbDJcfzCEsJ~x3gq2W4eGr6lpYrW9wnQ_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
