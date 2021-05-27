## Sum Reverse Sort

Вам дан заголовочный файл *sum_reverse_sort.h*, содержащий объявления трёх функций

[sum_reverse_sort.h](https://d3c33hcgiwev3.cloudfront.net/_3c8d2ebb6fe1005588f14d1408481a9b_sum_reverse_sort.h?Expires=1622246400&Signature=U5PNhGivHTuE2VYyR~TjndnIkff4ihxa5vgHlyvMSOyc7rcz~hCVu17tqCcS81R6Ng9S5v0ffZs3CMhyf2Y-lAw0h~V1AjdRKMPBrlCRfULRqOhAWPoMERbd-0tLVF3pRt~VuIy9FQSNbUHvjaSQLg4yfeiPLdRRgUp81R85Q2c_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

```cpp
#pragma once
#include <string>
#include <vector>
using namespace std;
int Sum(int x, int y);
string Reverse(string s);
void Sort(vector<int>& nums);
```

Вам надо прислать *cpp*-файл, содержащий определения этих функций.

***Как будет тестироваться ваш код***
Автоматическая тестирующая система добавит ваш *cpp*-файл в проект, содержащий другой *cpp*-файл с юнит-тестами для всех трёх функций, а также файл *sum_reverse_sort.h*. Затем она соберёт этот проект и, если компиляция будет выполнена успешно, запустит получившийся исполняемый файл. Если он завершится успешно (т. е. юнит-тесты не найдут ошибок в вашей реализации), то ваша посылка будет засчитана.
