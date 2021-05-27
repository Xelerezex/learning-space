## Time Server

Вам дана функция *string AskTimeServer()*, про которую известно следующее:

- в процессе своей работы она обращается по сети к удалённому серверу, запрашивая текущее время;
- если обращение к серверу прошло успешно, функция возвращает текущее время в виде строки;
- если в процессе обращения к серверу возникла сетевая проблема, функция выбрасывает исключение *system_error*;
- функция может выбрасывать другие исключения, чтобы сообщить о других проблемах.

Используя функцию *AskTimeServer*, напишите класс *TimeServer* со следующим интерфейсом:
```objectivec
class TimeServer {
public:
  string GetCurrentTime();
private:
  string LastFetchedTime = "00:00:00";
};
```

Метод *GetCurrentTime* должен вести себя так:

* он должен вызвать функцию *AskTimeServer*, записать её результат в поле *LastFetchedTime* и вернуть значение этого поля;
* если *AskTimeServer* выбросила исключение *system_error*, метод *GetCurrentTime* должен его поймать и вернуть текущее значение поля *LastFetchedTime*. Таким образом мы скрываем от пользователя сетевые проблемы, возвращая значение, которое было получено при последнем успешном обращении к серверу;
* если *AskTimeServer* выбросила другое исключение, метод *GetCurrentTime* должен пробросить его дальше, потому что в рамках класса *TimeServer* мы не знаем, как обрабатывать проблемы, не связанные со сбоями сети.

***Как выполнять задание***
Вам дан файл, содержащий заготовку класса *TimeServer*. В нём вам надо реализовать метод *GetCurrentTime* так, как описано выше. Файл содержит пустую функцию *AskTimeServer*. Для тестирования своей реализации вы можете пробовать добавлять разные команды в её тело:

* возврат строки;
* выброс исключения *system_error* (класс *system_error* принимает в конструкторе параметр типа *error_code*, поэтому самый простой способ выбросить это исключение — *throw system_error(error_code());*, подробнее см. [https://en.cppreference.com/w/cpp/error/system_error](https://en.cppreference.com/w/cpp/error/system_error);
* выброс других исключений.

[rational_throw.cpp](https://d3c33hcgiwev3.cloudfront.net/kjUumNJWEem1wRICcqBpcA_a5ec3a928d2e4d4e90c110498ea0fce4_time_server.cpp?Expires=1622246400&Signature=SHUSqCiAnOhxY7oj4R1i9S9XfyF31MDPjNIa~6elcfBI4ik6Byd6B5P87oULem7jHhVDn8yZzb-33p4pKqO3t2IupIR6Zczba6kmB2UO9VLL~he~Pj26NnD5AtzOTykaLB1TzXR1UDB2~ablSRkswElr-8qnpyM6QyNG87SYmPI_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
