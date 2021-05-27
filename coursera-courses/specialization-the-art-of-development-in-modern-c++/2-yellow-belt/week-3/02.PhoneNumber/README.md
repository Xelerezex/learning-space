## Phone Number

Вам дан заголовочный файл *phone_number.h*, содержащий объявление класса *PhoneNumber*. При этом в комментариях описано поведение, которое ожидается от реализации этого класса.

[phone_number.h](https://d3c33hcgiwev3.cloudfront.net/_cfc497ae3376b86ce5c8aab531b01f56_phone_number.h?Expires=1622246400&Signature=kMO46BcpO5RRgq3vRezBxVvndAL1kACwa6QABuduNHHzWI5AtX7OOE3m2qktf4JcDfSTlYh0yuvlO5LKPi-UdqhbTl1o4EuyQT53qlHh-d3a~amdUUIAdzuTEh9eWKgG2A0cld07wtcXZXrCMazrwRA2TG37pnWFl~ifcUy5GQM_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

```cpp
#pragma once
#include <string>
using namespace std;
class PhoneNumber {
public:
  /* Принимает строку в формате +XXX-YYY-ZZZZZZ
     Часть от '+' до первого '-' - это код страны.
     Часть между первым и вторым символами '-' - код города
     Всё, что идёт после второго символа '-' - местный номер.
     Код страны, код города и местный номер не должны быть пустыми.
     Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.
     Примеры:
     * +7-495-111-22-33
     * +7-495-1112233
     * +323-22-460002
     * +1-2-coursera-cpp
     * 1-2-333 - некорректный номер - не начинается на '+'
     * +7-1233 - некорректный номер - есть только код страны и города
  */
  explicit PhoneNumber(const string &international_number);
  string GetCountryCode() const;
  string GetCityCode() const;
  string GetLocalNumber() const;
  string GetInternationalNumber() const;
private:
  string country_code_;
  string city_code_;
  string local_number_;
};

```
Пришлите *cpp*-файл **с определениями методов** класса *PhoneNumber*, которые реализуют описанное поведение.

***Как будет тестироваться ваш код***

Автоматическая тестирующая система добавит ваш *cpp*-файл в проект, содержащий другой *cpp*-файл с юнит-тестами для класса *PhoneNumber*, а также файл *phone_number.h*. Затем она соберёт этот проект и, если компиляция будет выполнена успешно, запустит получившийся исполняемый файл. Если он завершится успешно (т. е. юнит-тесты не найдут ошибок в вашей реализации), то ваша посылка будет засчитана.
Автоматическая тестирующая система добавит ваш *cpp*-файл в проект, содержащий другой *cpp*-файл с юнит-тестами для класса *PhoneNumber*, а также файл *phone_number.h*. Затем она соберёт этот проект и, если компиляция будет выполнена успешно, запустит получившийся исполняемый файл. Если он завершится успешно (т. е. юнит-тесты не найдут ошибок в вашей реализации), то ваша посылка будет засчитана.
