## Zoo

Вы работаете с иерархией классов, описывающих животных:

```cpp
#include <string>

class Animal
{
    public:
        virtual std::string Voice() const
        {
          return "Not implemented yet";
        }
        virtual ~Animal()
        {
        }
};

class Tiger: public Animal
{
    std::string Voice() const override
    {
      return "Rrrr";
    }
};

class Wolf: public Animal
{
    std::string Voice() const override
    {
      return "Wooo";
    }
};

class Fox: public Animal
{
    std::string Voice() const override
    {
      return "Tyaf";
    }
};
```

Вам нужно определить тип ```Zoo```, представляющий собой набор различных животных, и написать две
функции:

```cpp
Zoo CreateZoo(std::istream& in)

void Process(const Zoo& zoo, std::ostream& out)
```

Функция ```CreateZoo``` должна читать слова из потока ввода. Если на вход поступают слова "**Tiger**",
"**Wolf**" или "**Fox**", она должна помещать соответствующего зверя в зоопарк. В противном случае она
должна прекратить чтение и сгенерировать исключение ```std::runtime_error```.

Функция ```Process``` должна перебрать всех зверей в зоопарке в порядке создания и записать в поток вывода для
каждого из них результат работы виртуальной функции ```Voice```.

Один ваш друг написал решение этой задачи, но оно почему-то не работает. Исправьте его и сдайте в систему.

Замечания:

-   Код классов из файла ```animals.h``` переписывать не надо, просто подключите заголовочный файл ```animals.h```.

-   Обратите внимание, что в нашей версии файла ```animals.h``` голоса зверей могут отличаться от того, что
    приведено в примере.

-   Ваша программа должна создавать ровно столько объектов-зверей, сколько было передано во входном потоке в
    функцию ```CreateZoo```.

### Неверное решение вашего друга и файл ```animals.h```

>   [zoo.cpp](https://d3c33hcgiwev3.cloudfront.net/LhChI_ZIEeilxxL_ZeRz_A_2ea391f0f64811e89aa295b2bbe8221e_zoo.cpp?Expires=1648598400&Signature=CupK9iVfcLCmZehj-XteBqHvbL-UMcQWY2bA48fWRNJt40aXaYv~l3ojLUI9FPuEHXs99eFT4z5HMOCWLo~cYOsM4joMiC16Q67c9dXuL8cACS9iYko8bUoUWpP0uZpXIUIiJP2XzS0N3RyahPms2lzRG4CXKmdx~N8LKAZqdis_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [animals.h](https://d3c33hcgiwev3.cloudfront.net/R6hL3_ZIEeiaxBKyA9PBAg_4807d070f64811e89aa353e40edb32e4_animals.h?Expires=1648598400&Signature=H4nD3gcfJunWCeEGanP~h6XJ-eFWUoChRSDKuXR81LkYOYX8CBx8F6UxffRk52ULFC9pQr9Vo0~kOYK7swAY8uCuv3h4aXQTjp7lRSkGBb06-JLLzgzW4Aze66FGd60t50sUJMrbEAe50Bp-x2-3pxpK5y2~~Pra-TyTl06tJBE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
