#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    using Id = typename map<pair<int, int>, T>::iterator;

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object) { // O(log n)
        return Data.insert({make_pair(0, id++), move(object)}).first;
    }

    // Добавить все элементы диапазона [range_begin, range_end)
    // с помощью перемещения, записав выданные им идентификаторы
    // в диапазон [ids_begin, ...)
    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt range_begin, ObjInputIt range_end, IdOutputIt ids_begin) {
        while (range_begin != range_end) {
            *ids_begin++ = Add(move(*range_begin++));
        }
    }

    // Определить, принадлежит ли идентификатор какому-либо
    // хранящемуся в контейнере объекту
    bool IsValid(Id id) const { // O(log n)
        return (Data.find(id->first) != Data.end()) ? true : false;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const {
        return id->second;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) { // O(1)
        int priority = (id->first).first;
        int identificator = (id->first).second;

        auto key_handler = Data.extract(id);
        key_handler.key() = make_pair(++priority, identificator);

        Data.insert(move(key_handler));
    }

    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const { // O(1)
        auto last = prev(Data.end());
        return {last->second, last->first.first};
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax() { // O(1)
        auto last = prev(Data.end());
        auto temp = move(*last);
        Data.erase(last);

        return make_pair(move(temp.second), move(temp.first.first));
    }

    stringstream Print() const {
        stringstream os;
        for (const auto &pairs : Data) {
            os  << "\n["
                << "priority = " << pairs.first.first  << ", "
                << "id = "       << pairs.first.second << ", "
                << "value = "    << pairs.second
                << "]";
        }
        return os;
    }

private:
    map<pair<int, int>, T> Data;
    int id = 0;
};
//------------------------------------------------------------------------------------------------------//
class StringNonCopyable : public string {
    public:
        using string::string;   // Позволяет использовать конструкторы строки
        StringNonCopyable(const StringNonCopyable&) = delete;
        StringNonCopyable(StringNonCopyable&&) = default;
        StringNonCopyable& operator=(const StringNonCopyable&) = delete;
        StringNonCopyable& operator=(StringNonCopyable&&) = default;
};
//------------------------------------------------------------------------------------------------------//
using ID = PriorityCollection<StringNonCopyable>::Id;
void PromoteAmount(PriorityCollection<StringNonCopyable> &obj, size_t number, vector<ID> &&v) {
        size_t numbers_of_promotion = 0;
        while(numbers_of_promotion < number) {
            for (const auto &q : v) {
                obj.Promote(q);
            }
            ++numbers_of_promotion;
        }
}
//------------------------------------------------------------------------------------------------------//
void TestAddPromote() {
    PriorityCollection<StringNonCopyable> strings;
    {
        const auto one_id   = strings.Add("one");
        const auto two_id   = strings.Add("two");
        const auto three_id = strings.Add("three");
        const auto four_id  = strings.Add("four");
        const auto five_id  = strings.Add("five");
        const auto six_id   = strings.Add("six");

        string expected = R"""(
[priority = 0, id = 0, value = one]
[priority = 0, id = 1, value = two]
[priority = 0, id = 2, value = three]
[priority = 0, id = 3, value = four]
[priority = 0, id = 4, value = five]
[priority = 0, id = 5, value = six])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 4, {one_id, two_id, three_id});

        expected = R"""(
[priority = 0, id = 3, value = four]
[priority = 0, id = 4, value = five]
[priority = 0, id = 5, value = six]
[priority = 4, id = 0, value = one]
[priority = 4, id = 1, value = two]
[priority = 4, id = 2, value = three])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 2, {one_id, four_id, five_id});

        expected = R"""(
[priority = 0, id = 5, value = six]
[priority = 2, id = 3, value = four]
[priority = 2, id = 4, value = five]
[priority = 4, id = 1, value = two]
[priority = 4, id = 2, value = three]
[priority = 6, id = 0, value = one])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        stringstream get0;
        get0 << strings.GetMax();
        ASSERT_EQUAL(get0.str(), "[one, 6]");
        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 6, {six_id});

        expected = R"""(
[priority = 2, id = 3, value = four]
[priority = 2, id = 4, value = five]
[priority = 4, id = 1, value = two]
[priority = 4, id = 2, value = three]
[priority = 6, id = 0, value = one]
[priority = 6, id = 5, value = six])""";

        stringstream get1;
        get1 << strings.GetMax();
        ASSERT_EQUAL(get1.str(), "[six, 6]");
        ASSERT_EQUAL(strings.Print().str(), expected);

    }
    {
        stringstream get0;
        get0 << strings.GetMax();
        ASSERT_EQUAL(get0.str(), "[six, 6]");

        strings.PopMax();
        string expected = R"""(
[priority = 2, id = 3, value = four]
[priority = 2, id = 4, value = five]
[priority = 4, id = 1, value = two]
[priority = 4, id = 2, value = three]
[priority = 6, id = 0, value = one])""";

        stringstream get1;
        get1 << strings.GetMax();
        ASSERT_EQUAL(get1.str(), "[one, 6]");
        ASSERT_EQUAL(strings.Print().str(), expected);
    }
}
//------------------------------------------------------------------------------------------------------//
void TestNoCopy() {
    PriorityCollection<StringNonCopyable> strings;
    //const auto white_id =
    strings.Add("white");
    const auto yellow_id = strings.Add("yellow");
    const auto red_id = strings.Add("red");

    PromoteAmount(strings, 1, {yellow_id});

    PromoteAmount(strings, 2, {red_id});

    PromoteAmount(strings, 1, {yellow_id});
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "red");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "yellow");
        ASSERT_EQUAL(item.second, 2);
    }
    {
        const auto item = strings.PopMax();
        ASSERT_EQUAL(item.first, "white");
        ASSERT_EQUAL(item.second, 0);
    }
}
//------------------------------------------------------------------------------------------------------//
void TestAddPop() {
    PriorityCollection<StringNonCopyable> strings;
    {
        const auto one_id   = strings.Add("one");
        const auto two_id   = strings.Add("two");
        // const auto three_id =
        strings.Add("three");
        const auto four_id  = strings.Add("four");
        const auto five_id  = strings.Add("five");
        const auto six_id   = strings.Add("six");

        string expected = R"""(
[priority = 0, id = 0, value = one]
[priority = 0, id = 1, value = two]
[priority = 0, id = 2, value = three]
[priority = 0, id = 3, value = four]
[priority = 0, id = 4, value = five]
[priority = 0, id = 5, value = six])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 6, {four_id, five_id, six_id});

        expected = R"""(
[priority = 0, id = 0, value = one]
[priority = 0, id = 1, value = two]
[priority = 0, id = 2, value = three]
[priority = 6, id = 3, value = four]
[priority = 6, id = 4, value = five]
[priority = 6, id = 5, value = six])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        ostringstream pop1;
        pop1 << strings.PopMax();
        ASSERT_EQUAL(pop1.str(), "[six, 6]");

        ostringstream pop2;
        pop2 << strings.PopMax();
        ASSERT_EQUAL(pop2.str(), "[five, 6]");

        ostringstream pop3;
        pop3 << strings.PopMax();
        ASSERT_EQUAL(pop3.str(), "[four, 6]");

        ostringstream pop4;
        pop4 << strings.PopMax();
        ASSERT_EQUAL(pop4.str(), "[three, 0]");

        expected = R"""(
[priority = 0, id = 0, value = one]
[priority = 0, id = 1, value = two])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 7, {one_id, two_id});

        const auto new_six_id = strings.Add("six");

        expected = R"""(
[priority = 0, id = 6, value = six]
[priority = 7, id = 0, value = one]
[priority = 7, id = 1, value = two])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 7, {new_six_id});

        expected = R"""(
[priority = 7, id = 0, value = one]
[priority = 7, id = 1, value = two]
[priority = 7, id = 6, value = six])""";

        ASSERT_EQUAL(strings.Print().str(), expected);
    }
}
//------------------------------------------------------------------------------------------------------//
void TestAddGetValid() {
    PriorityCollection<StringNonCopyable> strings;
    {
        const auto white_id = strings.Add("white");
        const auto yellow_id = strings.Add("yellow");
        const auto red_id = strings.Add("red");

        ASSERT_EQUAL(strings.Get(white_id), "white");
        ASSERT_EQUAL(strings.Get(yellow_id), "yellow");
        ASSERT_EQUAL(strings.Get(red_id), "red");

        ASSERT_EQUAL(strings.IsValid(white_id), true);
        strings.PopMax();
        ASSERT_EQUAL(strings.IsValid(red_id), false);
    }
}

//------------------------------------------------------------------------------------------------------//
void TestAddCount() {
    {
        using Id = PriorityCollection<int>::Id;
        vector<Id> ids;
        vector<int> arr{ 1,2,3,4,5 };
        PriorityCollection<int> collect;
        collect.Add(arr.begin(), arr.end(), std::back_inserter(ids));
        collect.Promote(ids[0]);
        collect.Promote(ids[0]);
        collect.Promote(ids[0]);
        auto res = collect.GetMax();
        ASSERT_EQUAL(res.first, 1);
        ASSERT_EQUAL(res.second, 3);
    }
}

//-----------------------------------------------------------------------------------------------------//

int main() {
    TestRunner tr;

    RUN_TEST(tr, TestAddPromote);
    RUN_TEST(tr, TestNoCopy);
    RUN_TEST(tr, TestAddPop);
    RUN_TEST(tr, TestAddGetValid);
    RUN_TEST(tr, TestAddCount);
    return 0;
}
//------------------------------------------------------------------------------------------------------//
