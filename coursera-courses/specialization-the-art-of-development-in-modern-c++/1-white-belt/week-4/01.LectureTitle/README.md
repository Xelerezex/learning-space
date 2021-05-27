## Licture Title

Дана структура *LectureTitle*:
```cpp
struct LectureTitle {
  string specialization;
  string course;
  string week;
};
```
Допишите конструктор и структуры *Specialization*, *Course*, *Week* так, чтобы объект *LectureTitle* можно было создать с помощью кода

```cpp
LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
);
```
но нельзя было с помощью следующих фрагментов кода:

```cpp
LectureTitle title("C++", "White belt", "4th");

LectureTitle title(string("C++"), string("White belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);

LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);
```
