## RAII-Booking

На лекции мы написали класс ```TripManager``` для бронирования набора перелётов и отелей, использующий
вспомогательные классы ```FlightProvider``` и ```HotelProvider```. Следуя идиоме ```RAII```, мы вынесли
забронированный набор в отдельный класс ```Trip```. Код, написанный на лекции, мы немного модифицировали
и поместили в файлы **old_booking_providers.h** и **old_trip_manager.h**

Вам теперь предлагается сделать так, чтобы отдельные бронирования перелёта и отеля тоже были оформлены в духе
```RAII```. Это позволит упростить класс ```Trip```: в его функции Cancel не придётся вызывать отмены
бронирований, а достаточно будет просто удалить элементы из векторов.

Вам даны новые версии классов ```TripManager```, ```Trip```, ```FlightProvider``` и ```HotelProvider```,
которые лежат в файлах **new_booking_providers.h** и **new_trip_manager.h**. Функцию ```Cancel``` в новых
классах мы переименовали в ```CancelOrComplete```: она должна будет автоматически вызываться не только
при отмене бронирования, но и при успешном его завершении. Теперь функции ```Book``` и ```CancelOrComplete```
в классах-провайдерах возвращают и принимают не ```BookingId```, а специальный класс, который вам и нужно
создать.

Так как ```FlightProvider``` и ```HotelProvider``` имеют одинаковый интерфейс, то, чтобы избежать
дублирования кода, мы просим вас разработать шаблонный класс ```Booking<Provider>```, где в качестве
шаблонного типа будут выступать FlightProvider и HotelProvider.

Пришлите в тестирующую систему **файл booking.h**, который:

-   содержит пространство имён ```RAII```

-   внутри пространства имён ```RAII``` содержит определение шаблонного класса Booking<Provider>

Интерфейс класса ```Booking<Provider>``` должен стать вам понятен после изучения файлов
**new_booking_providers.h** и **new_trip_manager.h**.

Для удобства тестирования мы сделали счётчик бронирований и максимально допустимое количество бронирований
публичными статическими переменными классов ```FlightProvider``` и ```HotelProvider```.

### Файлы задачи

>   [test.cpp](https://d3c33hcgiwev3.cloudfront.net/hJTtjgriEemU7w7-EFnPcg_851b82500ae211e980492d1bdac1a743_test.cpp?Expires=1650412800&Signature=Fekr03Y1-Lzku7tu3VO5~KSc-gYc4NY4gTYNjK4JnH2DqAvOgl--tv1ciPewfBWY19GuaTHH2XBMHVZDO6fSncCTTqnGvlEyZZ2iWBHZIp-EIPcnwhK7skqIBVvv6htlWts6oq0lc45S2Pp8qa2GL-Q3l8C2k8KuJuZNY9aDamk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [old_booking_providers.h](https://d3c33hcgiwev3.cloudfront.net/hJRRNgriEem5_xLqNrIdUA_851dcc400ae211e99390b5c03f9a3731_old_booking_providers.h?Expires=1650412800&Signature=U~P-CnpK1qbqeChgyiA-DTFeuWJfMJnor4gQ6ObhT3DKwIyjpA~Mni0zzbZ7x7j~3DC-tO4OCpLd4GGpNBXLFohTuNVdVW4~FmtG1kiFyusoPqW-tEtB6DX~5y8MjkFWc2F3qrd-Jmsul7RPdZtdbIkuPiLlRcgmUHUYl5j7KIg_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [old_trip_manager.h](https://d3c33hcgiwev3.cloudfront.net/hJRRqgriEemP8Qpm209XvA_851eb6a00ae211e98467b31a37bf13ae_old_trip_manager.h?Expires=1650412800&Signature=d8J8saMm40oeMTT0kvqFC8bZvZg7m-BTbIfgRmTJuIWDD2ePmitu6hwSg49mM8X9O7uVjbFOM2t2uVg3ax31rrT0NusFxCeQ~kWGwkAJcs-qpP2LbdNfWqDPrTkUd98fMbPf1hWhj85zEeIpPW8YfATAJqbYjx5AB5VLakF4Xkw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [new_booking_providers.h](https://d3c33hcgiwev3.cloudfront.net/hJR4NQriEem6Gg6vVM6M8A_851c93c00ae211e9a83355cd28680ddf_new_booking_providers.h?Expires=1650412800&Signature=azdvevfrdbOSfu2T-SOmiyhU8yn53-lxLR7FnA5fzo~9P4-r-f946FsHGNr9roh-xY2re-MkyJOONx2GzvHZ-9s2lNUTNEZexFHvMAbgvd47iF1oJlp~LWlv0kqTPx3ksxd8jZEnwGGfm9GErfuT6MTdPeJiNDGIv3vqmhacGqI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [new_trip_manager.h](https://d3c33hcgiwev3.cloudfront.net/hJYmogriEemYdRIT0BhLtg_851f52e00ae211e98f16dd63388069b1_new_trip_manager.h?Expires=1650412800&Signature=Kt6HfqFIGvnJ1-AIRAAC3UAZIPhflqv8qRZYDReEUQPOww4lUfls1M0qoJlVJnSGJPCXTJr3bD0zg-uMeZA-DTqpcHHd5KRYJyH8YX8LiPvbyXDo2txeAnJFqTGjzQTDErWgHnaq0uF9-85up-sWKH8BlU78hoVxsGPSbszOPIk_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
