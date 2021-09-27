## Booking

Разработайте систему бронирования отелей, позволяющую бронировать номера
клиентами и контролировать спрос владельцами отелей. Ваша программа должна
обрабатывать следующие события:

-    **BOOK** ***time hotel_name client_id room_count*** — забронировать клиентом
     ***client_id*** room_count номеров в отеле ***hotel_name*** в момент времени
     ***time***. Время измеряется в секундах, отсчитываемых от некоторого момента.

-    **CLIENTS** ***hotel_name*** — вывести количество различных клиентов, бронировавших
     номера в отеле ***hotel_name*** за последние сутки. Более формально интересующий
     диапазон времени описывается следующим образом: пусть *current_time* — время последнего
     события **BOOK**, тогда в данном запросе нужно учесть все события с *current_time* −
     86400 < time **⩽** *current_time*, где 86400 — количество секунд в сутках.
     Обратите внимание, что последнее бронирование должно учитываться, а бронирование,
     случившееся ровно за сутки до него, учитываться не должно.

-    **ROOMS** ***hotel_name*** — вывести количество номеров, забронированных за последние
     сутки в отеле hotel_name.

### Формат входных данных

В первой строке вводится количество запросов *Q* — натуральное число, не превосходящее 10^5.
В следующих *Q* строках в соответствии с описанным выше форматом вводятся запросы.
Гарантируется, что:

-    ***time*** — целое число в диапазоне от −10^18 до 10^18 и не убывает от события к
     событию.

-    ***hotel_name*** — строка из латинских букв и цифр, имеющая длину не более 12 символов.

-    ***client_id*** — натуральное число, не превосходящее 10^9.

-    ***room_count*** — целое положительное число, не превосходящее 1000.

### Формат выходных данных

Для каждого запроса **CLIENTS** и **ROOMS** выведите единственное целое число — ответ на
запрос. Если указанный в запросе отель пока не имеет ни одного бронирования, выведите 0.

### Ограничения

1 секунда на выполнение всех запросов. Все описанные в условии гарантии действительно
справедливы для всех тестов, на которых будет запускаться ваша программа. Проверять
корректность тестов не нужно.

### Example:

#### Input:

```commandline
11
CLIENTS Marriott
ROOMS Marriott
BOOK 10 FourSeasons 1 2
BOOK 10 Marriott 1 1
BOOK 86409 FourSeasons 2 1
CLIENTS FourSeasons
ROOMS FourSeasons
CLIENTS Marriott
BOOK 86410 Marriott 2 10
ROOMS FourSeasons
ROOMS Marriott
```

#### Output:

```commandline
0
0
2
3
1
1
10
```
#### Комментарии к примеру

После бронирования, случившегося в момент времени 86410, в статистике перестают учитываться
бронирования, случившиеся в момент времени 10.

### Подсказки

Если задача вызывает непреодолимые трудности, вы можете воспользоваться подсказками. Они
помогут быстрее сдать задачу, но в итоге вы получите меньше пользы от процесса поиска
решения.

Не нужно открывать все подсказки сразу. Используйте их последовательно.

> [booking-1.pdf](https://d3c33hcgiwev3.cloudfront.net/gvyqruffEeiaxBKyA9PBAg_833e6db0e7df11e880463dc9adc4d9bc_booking-1.pdf?Expires=1632873600&Signature=EiyMvz40~Rv4kpxvd0r1IYkAWE7o8iaaNxhfgVuonqS4z67Cbxz27o01IPw8hFAZnHFL7yxzRHNLHyAVWQ3oIn26XvGs03Ubh0mezRWmEuyyiNui3~8gkpOyaFrCeABJl7eLDngNZhoKmm4AfRYUipnA97bIQfjXr9ljhIb0Nig_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [booking-2.pdf](https://d3c33hcgiwev3.cloudfront.net/gv0ftuffEeiixgqCUDoEfA_83474750e7df11e8ba36791774dc29a3_booking-2.pdf?Expires=1632873600&Signature=bdTyznh4jXXm5PK435-iEePcGU98i9oCOf8-n4ci470SvGZp5NqbwXMfFFUrRHMu3Jrwl16wrlYH9mntPb-g923-qK1bB3EbY0PIoH~Vw~fLZtUewWBgbi5NlsT86IRJJjlke567jdt9fLOIPK9t9nQdiUetzOeTx1lWoFlG2LY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [booking-3.pdf](https://d3c33hcgiwev3.cloudfront.net/gv9pz-ffEeiaxBKyA9PBAg_833e46a0e7df11e8b0ed5909629489a2_booking-3.pdf?Expires=1632873600&Signature=buEm6MET~2PgQYUBxNS3RHoF8qO03-XVpEJMy1eBa3JlNigTEOClBgh9oBy~axKMZFHvs3SQ7Tuqsr-1GGB1~Bu8-hcg7Kl-M7Tp41WEc8RixckGWYDKjhFgYg0MWPajnhtfA0nkdkNibI4ZlyNCwCL7YTAQPifq0SQjQWes~Ys_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [booking-4.pdf](https://d3c33hcgiwev3.cloudfront.net/gwAFXeffEeiAgQrXx6bp4g_83426550e7df11e89bf1032d5d05de4f_booking-4.pdf?Expires=1632873600&Signature=Fz7vNgk42V-EnvOu4Vz2n3lTTFL5shWktrLQJmH4-aIOckiMRK6v88MSKT~VALgDNjtN9XV5N7rPOIqOfwYsB7VjYQZt9NzKHzBLxAisLj7i9f-1yY~ZBhn8PunFGX3vkm-13IAyb~wMsFqVrx214C-cYAPk6yfkRmvsJjqnlFA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [booking-5.pdf](https://d3c33hcgiwev3.cloudfront.net/gv9pnOffEei5Kg7DUflKxA_8345c0b0e7df11e88c94d51cedeec544_booking-5.pdf?Expires=1632873600&Signature=i-KLbIdnz0wU0nrXaeMLL8tJllWCK0EXuqVWBNiFcNe633iFds8kaKzId5qIeWzVWcN6y5xvYFUXWA294x5wpaSgmKQ4zUjRoNBD-JjyU6cgIt~8ru~nwbU71kCQmsst0U7x8~dmQFP6GCii0qRao7j5dRMPRrvhSXhLXHQgD50_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
