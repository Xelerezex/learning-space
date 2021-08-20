## Log

Вам дан класс Logger и макрос LOG

```cpp
class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file = value; }

  void Log(const string& message);

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) ...
```

Параметры макроса LOG — объект класса Logger и строковое сообщение, которое должно быть передано в метод Log.
В зависимости от настроек объекта класса Logger логируемое сообщение должно предваряться именем файла или номером строки.
Смотрите юнит-тесты в заготовке решения для более подробного описания поведения.

Реализуйте макрос LOG так, чтобы он добавлял в логируемое сообщение имя файла и номер строки в зависимости от настроек объекта logger.
Пришлите на проверку cpp-файл, содержащий:

-    реализацию макроса LOG

-    объявление класса Logger, при этом вы можете при необходимости добавлять в него дополнительные поля и методы

-    определения всех методов класса Logger

> [log.cpp](https://d3c33hcgiwev3.cloudfront.net/j612m2NVEeiEZRKxXgWFpg_90050c20635511e8b5518f2623e240b4_log.cpp?Expires=1629590400&Signature=OCealjC6uJaPKyCpxQg7KTfwhdMXoaIOXYBrSHKpTOyiAUnAhbTAf0ZA8pj9HyNIgRxteCS1a7KLcy7MaNzDiWQDYTlZDwWr6Gyvs6Byu4CN9R689Lzo54LSHQuBV4RHbQmqZNc4HuKXPW2B-NwkbmDEnA0s0Ds~6GQT05I9qBU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

**Замечание**

Если вы используете Visual Studio, у вас могут не проходить юнит-тесты из заготовки, потому что в этой среде макрос __FILE__ раскрывается в абсолютный путь до файла. Учитывайте это при отладке своего решения.
