## Sort By

Давайте представим, что вы разрабатываете инновационный сервис поиска авиабилетов AviaScanner.
В вашем сервисе авиабилет представляется в виде структуры

```cpp
struct Date {
  int year, month, day;
};

struct Time {
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  uint64_t price;
};
```

В данный момент вы работаете над функцией сортировки результатов поиска.
Пользователь вводит свой запрос и получает список подходящих билетов.
Дальше он может задавать параметры сортировки этого списка.
Например, сначала по цене, затем по времени вылета и, наконец, по аэропорту прилёта.

Чтобы реализовать сортировку как в примере, можно воспользоваться [алгоритмом цифровой сортировки](http://neerc.ifmo.ru/wiki/index.php?title=%D0%A6%D0%B8%D1%84%D1%80%D0%BE%D0%B2%D0%B0%D1%8F_%D1%81%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0):

```cpp
void SortTickets(vector<AirlineTicket>& tixs) {
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.to < rhs.to;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.departure_time < rhs.departure_time;
  });
  stable_sort(begin(tixs), end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
    return lhs.price < rhs.price;
  });
}
```

Напишите макрос SORT_BY, который принимает в качестве параметра имя поля структуры AirlineTicket.
Вызов sort(begin(tixs), end(tixs), SORT_BY(some_field)) должен приводить к сортировке вектора tixs
по полю some_field.

Вам дан файл airline_ticket.h, содержащий объявления структур Time, Date и AirlineTicket,
а также заготовка решения в виде cpp-файла sort_by.cpp. Пришлите на проверку cpp-файл, который

-    подключает заголовочный файл airline_ticket.h

-    содержит макрос SORT_BY

-    содержит определения операторов, необходимых для использования классов Date и Time в алгоритме сортировки и макросе ASSERT_EQUAL (формат вывода в поток можете выбрать произвольный)

>   [airline_ticket.h](https://d3c33hcgiwev3.cloudfront.net/fPFKHWAuEeiEZRKxXgWFpg_7d46e380602e11e88d73c38a9a838951_airline_ticket.h?Expires=1629763200&Signature=NJIfatz9Sgk66bAFP55NbVVCQXornze8ueJyakrp20WI41ueuzrSN4jqIlsWA~vfSKLoklHaEqwwiqh0LQbc87knvYWen8BxaqSL9QkdbdBcdD1yoxAXNM~yk8de823yyONKzTWNDpkbwauIeJ0jByQjsjUXqF8Au5TaLIA5sgA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [sort_by.cpp](https://d3c33hcgiwev3.cloudfront.net/fPFKHWAuEeiEZRKxXgWFpg_7d46e380602e11e88d73c38a9a838951_airline_ticket.h?Expires=1629763200&Signature=NJIfatz9Sgk66bAFP55NbVVCQXornze8ueJyakrp20WI41ueuzrSN4jqIlsWA~vfSKLoklHaEqwwiqh0LQbc87knvYWen8BxaqSL9QkdbdBcdD1yoxAXNM~yk8de823yyONKzTWNDpkbwauIeJ0jByQjsjUXqF8Au5TaLIA5sgA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
