## Server Stats

### Условие

Представим, что у нас есть web-сервер, который обслуживает запросы к интернет-магазину.
Он поддерживает следующий набор запросов по протоколу HTTP:

-   GET / HTTP/1.1 — получить главную страницу магазина

-   POST /order HTTP/1.1 — разместить новый заказ

-   POST /product HTTP/1.1 — добавить новый товар в магазин (команда админки)

-   GET /order HTTP/1.1 — получить детали заказа

-   PUT /product HTTP/1.1 — то же самое, что и POST /order HTTP/1.1

-   GET /basket HTTP/1.1 — получить состав текущей корзины клиента

-   DELETE /product HTTP/1.1 — удалить товар из интернет-магазина (команда админки)

-   GET /help HTTP/1.1 — получить страницу о том, как пользоваться интернет-магазином

С точки зрения протокола HTTP, первые части приведённых выше запросов
(*«GET»*, *«POST»*, *«PUT»*, *«DELETE»*) называются **методами**. Вторые части
называются **URI** (*Uniform Resource Identifier*). Третья часть — это версия протокола.
Таким образом, наш web-сервер поддерживает 4 метода: *GET*, *POST*, *PUT*, *DELETE*
и 5 URI: «*/*», «*/order*», «*/product*», «*/basket*», «*/help*».

Главный системный администратор нашего сервера озаботился его масштабированием и для
начала он решил изучить статистику использования. Он хочет для каждого метода и
каждого URI посчитать, сколько раз он встречался в запросах к серверу за последний
месяц. Он попросил вас помочь с этим.

У вас уже есть какая-то кодовая база для изучения запросов к серверу, и вы хотите
воспользоваться ею, чтобы сэкономить время. У вас есть заголовочный файл http_request.h,
 содержащий структуру HttpRequest:

```cpp
#pragma once

#include <string_view>

using namespace std;

struct HttpRequest {
  string_view method, uri, protocol;
};
```

Кроме того, есть заголовочный файл stats.h, содержащий объявления класса
Stats и функции ParseRequest:

```cpp
#pragma once

#include "http_request.h"

#include <string_view>
#include <map>

using namespace std;

class Stats {
public:
  void AddMethod(string_view method);
  void AddUri(string_view uri);
  const map<string_view, int>& GetMethodStats() const;
  const map<string_view, int>& GetUriStats() const;
};

HttpRequest ParseRequest(string_view line);
```

Наконец, у вас есть готовая функция ServeRequests:

```cpp
Stats ServeRequests(istream& input) {
  Stats result;
  for (string line; getline(input, line); ) {
    const HttpRequest req = ParseRequest(line);
    result.AddUri(req.uri);
    result.AddMethod(req.method);
  }
  return result;
}
```

Вам нужно, основываясь на реализации функции ServeRequests, реализовать класс Stats
и функцию ParseRequest.

Дополнительные требования к классу Stats:

-    метод GetMethodStats возвращает словарь, в котором для каждого метода хранится,
     сколько раз он встретился в качестве аргумента метода AddMethod;

-    метод GetUriStats работает аналогично для URI;

-    если метод, переданный в метод AddMethod, не поддерживается нашим сервером
     (список поддерживаемых методов приведён выше), то нужно на единицу увеличить
     счётчик для метода "UNKNOWN" (подробнее см. юнит-тесты в заготовке решения);

-    если URI, переданный в метод AddUri, не поддерживается нашим сервером, то
     нужно на единицу увеличить счётчик для URI "unknown".

Дополнительные сведения о функции ParseRequest:

-    функция ParseRequest разбивает исходный запрос на три соответствующих части
     (метод, URI, версия протокола), возвращая результат в полях соответствующей
     структуры HttpRequest;

-    при разборе исходного запроса, каждую часть запроса необходимо выделять и
     сохранять в результирующую структуру без каких-либо дополнительных изменений.
     Например, для запроса "UNDEFINED /something HTTP/1.1++", в поля метода, URI и
     протокола структуры HttpRequest необходимо записать "UNDEFINED", "/something" и
     "HTTP/1.1++", соответственно.

На проверку пришлите архив, состоящий из файлов stats.h и stats.cpp (а также любых
других файлов, которые вы посчитаете нужным добавить в свой проект). При этом ваши
файлы не должны содержать реализацию функции ServeRequests (если ваша посылка будет
содержать функцию ServeRequests, вы получите ошибку компиляции).

### Заготовка решения

> [http_request.h](https://d3c33hcgiwev3.cloudfront.net/w-Fv-nrEEeiqbAqxMNypOA_c43905107ac411e8bcff7d515fb5592b_http_request.h?Expires=1636416000&Signature=FLo1eh7Etjamd5mBfduroYP-yw8mC9GzCC1VfV93QI031sLsO6g~Je~cfK-iPP2iVsQffQUham0HnRJ7689XG4rNsntNfVEUqgvBEcJVg6Ggctelts1xHy99~1X-ALyZ2q0L3ZKSlBMj2FQjOpJ613As2-aGx2iZrlD47K75CNI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [stats.h](https://d3c33hcgiwev3.cloudfront.net/Bx1E9WTKEei5FgrpHNEYyg_0790c66064ca11e899b2712e81ece485_stats.h?Expires=1636416000&Signature=YEWQoZ-IDOg28~N70qRQBXLpKBh7R2DE229Be3Pdi7YhlBUQO3AT4Yuqr43hjV2Y-dila7sGsJ1eL22rH9n92cnxmhhld1zOG~lo9HVrkKZYDJMZ690Zris3aicohWAWerHqLAFps12jV2sGgYk~LS2nMh~pjBQnhjYtV-oe-0g_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [server_stats.cpp](https://d3c33hcgiwev3.cloudfront.net/IEsKM2TKEei5FgrpHNEYyg_2074d86064ca11e884860b203c60291a_server_stats.cpp?Expires=1636416000&Signature=PknvhIBkkZPataWcWEgliEEhukvQWKpJ5iUzYbXOOp~1wudHqoMzHEeOzDu65Ue80ChDaXwFO67cxybVZLBSdF5wmHCyNlNzaaHsxuW7so1eKYrvpiO-6lXNtnvmERcFuVGcltKhVW13unNEKas8tYBN0z4Q1eEa9w2JTfR8EP0_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

**Как будет тестироваться ваша посылка**

К проекту из вашего архива будет добавлен cpp-файл, который:

-    подключает заголовочный файл stats.h;

-    содержит точно такую же реализацию функции ServeRequests, какая приведена в
     условии;

-    содержит функцию main с набором юнит-тестов для функции ServeRequests

Ваш проект будет собран и запущен.
