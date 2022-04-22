## Print Stats Testing

Дано два верных решения задачи «Демографические показатели».

### (A) С минимальным количеством функций:

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;
    Gender gender;
    bool is_employed;
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename iterator_traits<InputIt>::value_type> range_copy(
        range_begin,
        range_end
    );
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
          return lhs.age < rhs.age;
        }
    );
    return middle->age;
  }

int main() {
    int person_count;
    cin >> person_count;
    vector<Person> persons;
    persons.reserve(person_count);
    for (int i = 0; i < person_count; ++i) {
        int age, gender, is_employed;
        cin >> age >> gender >> is_employed;
        Person person{
            age,
            static_cast<Gender>(gender),
            is_employed == 1
        };
        persons.push_back(person);
  }

  auto females_end = partition(
      begin(persons), end(persons),
      [](const Person& p) {
        return p.gender == Gender::FEMALE;
      }
  );
  auto employed_females_end = partition(
      begin(persons), females_end,
      [](const Person& p) {
        return p.is_employed;
      }
  );
  auto employed_males_end = partition(
      females_end, end(persons),
      [](const Person& p) {
        return p.is_employed;
      }
  );

  cout << "Median age = "
       << ComputeMedianAge(begin(persons), end(persons))         << endl
       << "Median age for females = "
       << ComputeMedianAge(begin(persons), females_end)          << endl
       << "Median age for males = "
       << ComputeMedianAge(females_end, end(persons))            << endl
       << "Median age for employed females = "
       << ComputeMedianAge(begin(persons), employed_females_end) << endl
       << "Median age for unemployed females = "
       << ComputeMedianAge(employed_females_end, females_end)    << endl
       << "Median age for employed males = "
       << ComputeMedianAge(females_end, employed_males_end)      << endl
       << "Median age for unemployed males = "
       << ComputeMedianAge(employed_males_end, end(persons))     << endl;

  return 0;
}
```

### (B) Аккуратно разбитое на функции:
```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;
    Gender gender;
    bool is_employed;
};

bool operator==(const Person& lhs, const Person& rhs) {
    return lhs.age == rhs.age
        && lhs.gender == rhs.gender
        && lhs.is_employed == rhs.is_employed;
}

ostream& operator<<(ostream& stream, const Person& person) {
    return stream << "Person(age=" << person.age
        << ", gender=" << static_cast<int>(person.gender)
        << ", is_employed=" << boolalpha << person.is_employed << ")";
}

struct AgeStats {
    int total;
    int females;
    int males;
    int employed_females;
    int unemployed_females;
    int employed_males;
    int unemployed_males;
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename iterator_traits<InputIt>::value_type> range_copy(
        range_begin,
        range_end
    );
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
        begin(range_copy), middle, end(range_copy),
        [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        }
    );
    return middle->age;
}

vector<Person> ReadPersons(istream& in_stream = cin) {
    int person_count;
    in_stream >> person_count;
    vector<Person> persons;
    persons.reserve(person_count);
    for (int i = 0; i < person_count; ++i) {
        int age, gender, is_employed;
        in_stream >> age >> gender >> is_employed;
        Person person{
              age,
              static_cast<Gender>(gender),
              is_employed == 1
        };
        persons.push_back(person);
    }
    return persons;
}

AgeStats ComputeStats(vector<Person> persons) {
  //                 persons
  //                |       |
  //          females        males
  //         |       |      |     |
  //      empl.  unempl. empl.   unempl.

  auto females_end = partition(
      begin(persons), end(persons),
      [](const Person& p) {
        return p.gender == Gender::FEMALE;
      }
  );
  auto employed_females_end = partition(
      begin(persons), females_end,
      [](const Person& p) {
        return p.is_employed;
      }
  );
  auto employed_males_end = partition(
      females_end, end(persons),
      [](const Person& p) {
        return p.is_employed;
      }
  );

  return {
       ComputeMedianAge(begin(persons), end(persons)),
       ComputeMedianAge(begin(persons), females_end),
       ComputeMedianAge(females_end, end(persons)),
       ComputeMedianAge(begin(persons),  employed_females_end),
       ComputeMedianAge(employed_females_end, females_end),
       ComputeMedianAge(females_end, employed_males_end),
       ComputeMedianAge(employed_males_end, end(persons))
  };
}

void PrintStats(const AgeStats& stats,
                ostream& out_stream = cout) {
  out_stream << "Median age = "
             << stats.total              << endl
             << "Median age for females = "
             << stats.females            << endl
             << "Median age for males = "
             << stats.males              << endl
             << "Median age for employed females = "
             << stats.employed_females   << endl
             << "Median age for unemployed females = "
             << stats.unemployed_females << endl
             << "Median age for employed males = "
             << stats.employed_males     << endl
             << "Median age for unemployed males = "
             << stats.unemployed_males   << endl;
}

int main() {
  PrintStats(ComputeStats(ReadPersons()));
  return 0;
}

```


Этой задачей мы хотим продемонстрировать, насколько легче решение **(B)** позволяет отлавливать ошибки с
помощью юнит-тестов.

Даны 6 вариантов решения **(A)**, в каждом из которых есть некоторая ошибка. Вам необходимо разработать
юнит-тесты на решение **(B)**, покрывающее ошибки в решении **(B)**, полностью аналогичные
продемонстрированным ошибкам в решении **(A)**.

>   [bug1_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zju-IvIFEeiAgQrXx6bp4g_ce92b700f20511e8867d83b1b5022ae3_bug1_bad.cpp?Expires=1650758400&Signature=H~F3EirSNHT8MuakQM8cmZLkLdIQhpUCUqnpOsFGCQSIrSdXZvrTQy58fgbm~Mkf2agNXwdhbWX9SE9eXIkQoLZtZ1~yyr6gmG2aUWBXFGk2rNoWzHfXBjES2agT81p1jXc9T1~kkT5Mz0h942kKLxEiIZQ0McC7VFgiXUpXQOU_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [bug2_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zjxaVfIFEei5Kg7DUflKxA_ce92b700f20511e8beaef52b9c2b7147_bug2_bad.cpp?Expires=1650758400&Signature=EQivrUvZogCf54msp7AbXjDFDB1leWqeE41cTpOZqIrc5-1CO~wFCMfYVPGysOuTFPtXZ6g6hv39H7BUCqooPSY7MwOY8kuduL4MPBfroSGJFOtPy~b8X8caVjkrgaFzOz4IJtkTvkYAA6snf4F75n-8Z1~OEFLNCAjWFOw2Cbo_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [bug3_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zjwzjfIFEeiixgqCUDoEfA_ce93ef80f20511e8a53427d55398189f_bug3_bad.cpp?Expires=1650758400&Signature=H7IpTIn3ejyQl-wAan30Vz4G4CaAQndTrNpyE~ORBhZovE~NqIdvZB-G35QGkag1hlkkhsDMA~yKfirDA-PISkrQNYpO6ASpcoci8fPSWYT8SWFY1qHf-h3eQVCADdEA1ay7WuBozE5MCQJEZRp8pLrl-QEJHLxWMp~zqj4tlNE_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [bug4_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zjtvUvIFEeilxxL_ZeRz_A_ce959d30f20511e8a63c6544b1563662_bug4_bad.cpp?Expires=1650758400&Signature=GlZ4S54VcsDUlnvzawAFX0L1vWzMdDfYf7xh~CQMD1rUcqPSOsexLdhaGQoX~R9NwWUHxrtF0~ygbKo20MDWgWfZLOXAybBSranmkiCaR8bDLwmRrLWWe18rDipBDOfJN951LSRwtVLLnC2ntglJAaMfAbC3wyRaeCp~FvwUdLY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [bug5_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zjxaDvIFEeiaxBKyA9PBAg_ce94b2d0f20511e8ba4e7f6b9561c098_bug5_bad.cpp?Expires=1650758400&Signature=hDz-lG3mPU59NDk3faXL-zg24bJpULlCqpEDiKtEWSmWX0LyM4eNcfDBheV0MGHYZKXvoWENtF1BWyHfiRaWvf-iJSw654tDuomp6ggI6ojqEJy~6l~uyeFQClFGs6jZ5kIYIhuCBeAgGey8aPwBboYZiqpYGMjn2QieMg8Kdc4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

>   [bug6_bad.cpp](https://d3c33hcgiwev3.cloudfront.net/zj3gYvIFEeiTKQ5ajE7PqA_ce92b700f20511e8b771fd4eba196166_bug6_bad.cpp?Expires=1650758400&Signature=JeRPD8h1~LGjUhCIBX-z9Z~VSI8p59W36Y3skLdZpk0EkRov3~ZyLcemttB8JUd3FlhoLDl4syv6tBJYNgoEx7TT~0TLbk1bES-Tjnfjd8Xj3r29dI3KtR2NIlnua6HfpGSEylIDpOu15mXc1mDiLlrMvQKMReBw8yzxPNIlwqw_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

При написании юнит-тестов используйте библиотеку юнит-тестов **test_runner.h** из «Красного пояса»:

>   [test_runner.h](https://d3c33hcgiwev3.cloudfront.net/FQpr7PIGEeiAgQrXx6bp4g_1532b390f20611e8bc2333bd1397cc77_test_runner.h?Expires=1650758400&Signature=OSI-Qa-uot~1AMt7d3JbQtYyusrRy-w6eJ8RRcM1obRZ0dhXanlFE0C9SKsyKM8Sso9dGNDQg7oihbdO575rEk61cKVSn4Tpq1qjns-ruhDSyVmJc1scciyJCODQyF0qpYmc2BGL1LnmiQKHbAlsq1X-fLujM-jcM3K5M39AywY_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

Отправленная вами на проверку программа должна содержать функцию main, прямо или косвенно вызывающую необходимые юнит-тесты.

Ваша программа с юнит-тестами будет тестироваться следующим образом:

1.    Для каждого из решений **bugX_bad.cpp** нами создано решение **bugX_good.cpp** с такой же ошибкой, но
      в решении **(B)**.

2.    К каждому решению **bugX_good.cpp** добавляется отправленная вами программа, полученная большая
      программа запускается.

3.    Каждый из запусков должен упасть, то есть юнит-тесты должны найти все 6 ошибок.

4.    Аналогичный запуск для самого решения **(B)** должен пройти успешно.
