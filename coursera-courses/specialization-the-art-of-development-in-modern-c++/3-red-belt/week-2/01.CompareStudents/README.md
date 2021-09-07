## Compare Students

В данной задаче необходимо оптимизировать код, использующийся для сортировки студентов по рейтингу.
Данные каждого студента находятся в структуре Student, объявленной в файле student.h.
Рейтинг студента записан в поле rating:

```c++
struct Student {
    string first_name;
    string last_name;
    map<string, double> marks;
    double rating;

    bool operator < (const Student& other) const {
        return GetName() < other.GetName();
    }

    bool Less(const Student& other) const {
        return rating > other.rating;
    }

    string GetName() const {
        return first_name + " " + last_name;
    }
};
```

Для сортировки студентов по рейтингу используется функция сравнения, возвращающая true,
если рейтинг студента first выше рейтинга студента second.

```c++
bool Compare(Student first, Student second) {
    return first.Less(second);
}
```

Было выявлено, что эта функция является узким местом процесса сортировки, и именно её нужно оптимизировать.

Пришлите на проверку файл, содержащий оптимизированную версию функции Compare. Если ваша реализация будет
недостаточно эффективной, то решение не уложится в ограничение по времени.

> [students.h](https://d3c33hcgiwev3.cloudfront.net/uNZEiWQZEeiaEg6Thd1Wwg_b9344290641911e8af492fae745a22e6_student.h?Expires=1631145600&Signature=NlGNT-FxiztyaOvHsCaqVrVXekZBnrczmcrh7SWhtA2yW-qXK96LtzIqda3~UzO7x10TLf83LiYtYewHJ0bbygNfbKw7HqxmQC~D0IBrWs5u2KbevRMNrem7G17Ao-N9YMx-V~mcmfXAm~d0YL0L1EIJkAlg8W4871ec6DbDRX4_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)

> [sort_students.cpp](https://d3c33hcgiwev3.cloudfront.net/zW9nEnu0EeiC-BK3XY5K_A_cdc464d07bb411e88b6339ac39854c06_sort_students.cpp?Expires=1631145600&Signature=UdCzo7KOOAQSE-bLNjFJlmM4FQQBtgG6xpxno6KWCSHqjX9sEHn5YHWr863VUVxl6TFzvy4OZXwnVUy6VAa9TU0R8P-kzhd-dtNhJDLyKRX~fj7OjZikzqMYLsHpXzertkHHv-nLQoIrl3lZAWJc2sJNCl~hqRgJB3fxZtq59CA_&Key-Pair-Id=APKAJLTNE6QMUY6HBC5A)
