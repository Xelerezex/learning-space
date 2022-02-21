## Spendings Json

В этой тренировочной задаче вам надо поддержать загрузку расходов из формата ```JSON``` в нашей
программе управления личными финансами. При этом вам надо воспользоваться готовой библиотекой
работы с ```JSON```. Более конкретно, вам надо написать функцию
```vector<Spending> LoadFromJson(istream& input)```. ```Spending``` — это структура из вводной лекции:

```cpp
struct Spending
{
    string category;
    int amount;
};
```

Поток ```input``` содержит описание расходов в формате ```JSON```, например:

```cpp
[
    {"amount": 2500, "category": "food"},
    {"amount": 1150, "category": "transport"},
    {"amount": 5780, "category": "restaurants"},
    {"amount": 7500, "category": "clothes"},
    {"amount": 23740, "category": "travel"},
    {"amount": 12000, "category": "sport"}
]
```

Важно отметить:

-   формат текста в потоке ```input``` всегда строго такой, как в примере: есть массив, который
    содержит несколько словарей с ключами ```"amount"``` и ```"category"```

-   функция ```Load``` из выданной вам библиотеки работы с ```JSON``` умеет загружать описанный
    выше формат

-   мы выдаём вам не реальную библиотеку разбора ```JSON```, а лишь минимальный код, достаточный
    для работы описанным форматом данных

-   цель этой задачи — не показать, как правильно парсить ```JSON```, а познакомить вас с кодом,
    на котором мы в дальнейшем будем разбирать пространства имён, поэтому очень важно, чтобы вы
    реализовали функцию ```LoadFromJson``` через содержимое нашей библиотеки работы с ```JSON```.

На проверку пришлите cpp-файл, который подключает файл **json.h** (дан ниже) и содержит реализацию
функции ```LoadFromJson```. Тестирующая система соберёт его вместе с файлом **json.cpp** и прогонит
набор юнит-тестов.

### Заготовка решения и библиотека

>   [json.h](https://d3c33hcgiwev3.cloudfront.net/gJ-FSfexEeiAgQrXx6bp4g_80bcd090f7b111e8834415d2586e2901_json.h?Expires=1645574400&Signature=gJO9Afmwd~qjK4PmlyfjYsgUlIpSduZJ3xjjzNAxVXAdwLsv83SFBr6SrAPmpdkpW3Y9NlNSPz2XitXBn0xdGGT7Y9zyW~eOXmtnbSEP99lWco5VNPlvskDP1NgCSAyKCamWaSy17d53erI3LzvXak7lhOYuK~JjwvGbYo01aUg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [json.cpp](https://d3c33hcgiwev3.cloudfront.net/gKGoKvexEeiAgQrXx6bp4g_80ceaae0f7b111e886f2bd05ce727db8_json.cpp?Expires=1645574400&Signature=alneXEcE5o6cFhjaabyGkGQWOB6KbxiSSkw13oPH~ZnBzPr3UKn2IYjXOM6p1VEi5o5M4NRG0K2qjOG5zz5g2HU~QVCKeBbX4nsNi-37GRMN0NQ5iCd06x-2V0GUefj9SOKZ4vYYyPakCA45anfLEMMkHf~jv6fJD6FM5VqGxKA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [spendings_json.cpp](https://d3c33hcgiwev3.cloudfront.net/uWQcVviDEeiixgqCUDoEfA_b9b23bb0f88311e8a4985bed36272680_spendings_json.cpp?Expires=1645574400&Signature=bn3xe2Tp4FEZAh0mGxTOwq60ORbRKM9OjSJv45k3eIM1d~JRnfK2BZ6E1f4EEBuv3EeQjIgZTdiX7ukhE5Srw0sd0Rz9qbkaj7YtGuKk-FbbQglZVJ2q-jQ3C30NVc7KjP3VwPbOxDZiJQNRkb2WTuOA9gR7XtiWk50HG8oudKI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
