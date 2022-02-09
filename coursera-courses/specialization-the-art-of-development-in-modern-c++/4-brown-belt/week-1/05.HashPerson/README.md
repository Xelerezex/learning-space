## Hash Person

Мы хотим научиться встраивать структуру ```Person``` в контейнер
```unordered_set<Person, PersonHasher>```. Для этого вам нужно реализовать структуры
```PersonHasher```, ```AddressHasher```, и операторы сравнения:

```cpp
struct Address
{
    string city, street;
    int building;

    bool operator==(const Address& other) const
    {
      // реализуйте оператор
    }
};

struct Person
{
    string name;
    int height;
    double weight;
    Address address;

    bool operator==(const Person& other) const
    {
      // реализуйте оператор
    }
};

struct AddressHasher
{
  // реализуйте структуру
};

struct PersonHasher
{
  // реализуйте структуру
};
```

Для этого используйте стандартные хеш-функции ```std::hash``` и комбинируйте хеши полей с помощью
полинома, как показано в лекции.

### Требования:

-   хеш-функции должны зависеть от всех полей структур

-   хеш-функция должна равномерно рассеивать объекты типа ```Person```; это её свойство
проверяется тестом ```TestDistribution``` в заготовке решения.

### Заготовка решения

>   [hash_person.cpp](https://d3c33hcgiwev3.cloudfront.net/GjFI-fPOEeilxxL_ZeRz_A_1a8de700f3ce11e882cf5b014df25ce8_hash_person.cpp?Expires=1644537600&Signature=foD2p2JwkfbbvM8RTRyUwGQSe9kuiJp0ghE5An~WUAfXoiUKZ86Nj59bI3EeeGPkZoafREoFkI7cnKZfuBJmhnomdeB2WtzzvBt-2v5Viy~PbakQWHl57EdfrHs16f~-Ej7VYTfyRzIe~Hw-rX8nit5hK~lFiJaOBrJ6XNouqHo_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
