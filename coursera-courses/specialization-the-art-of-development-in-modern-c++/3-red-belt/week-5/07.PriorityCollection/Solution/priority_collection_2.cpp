#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

template <typename T>
class PriorityCollection {
public:
    using IT = typename deque<pair<T, int>>::iterator;
    using Bunch = pair<int, pair<int, IT>>;
    using Id = typename set<Bunch>::iterator;

    // Добавить объект с нулевым приоритетом
    // с помощью перемещения и вернуть его идентификатор
    Id Add(T object) { // O(log n)
        return Data.insert(make_pair(0,
                                     make_pair(id++,
                                               Pool.insert(Pool.end(),
                                                           make_pair(move(object), 0)
                                               )
                                     )
                           )
        ).first;
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
    bool IsValid(Id id) const {
        return Data.find(*id) != Data.end() ? true : false;
    }

    // Получить объект по идентификатору
    const T& Get(Id id) const {
        return (*(id->second.second)).first;
    }

    // Увеличить приоритет объекта на 1
    void Promote(Id id) { // O(1)
        Id iter_to_set = id;                                    // iter to det
        int max_priority = move(id->first);                     // priority
        Bunch temporary = move(*id);                            // <id, deque::iterator>> deque::iterator -> <obj, priority>
        (*(temporary.second).second).second = ++max_priority;   // deque<obj, ++priority>
        Data.erase(iter_to_set);                                // Cause set::iterator const
        //     hint to nearest          <priority      , <id, deque::iterator>>
        Data.insert(iter_to_set, make_pair(max_priority, move(temporary.second)));
    }

    // Получить объект с максимальным приоритетом и его приоритет
    pair<const T&, int> GetMax() const { // O(1)
        Id last_of_Data = --Data.end();
        return *((last_of_Data->second).second);
    }

    // Аналогично GetMax, но удаляет элемент из контейнера
    pair<T, int> PopMax() {
        Id last_of_Data = --Data.end();
        pair<T, int> temp = move(*((last_of_Data->second).second));
        Data.erase(last_of_Data);
        return move(temp);
    }

    stringstream Print() const {
        stringstream os;
        for (const auto &pairs : Data) {
            os << "\n["
                 << "priority = " << pairs.first            << ", "
                 << "id = "       << (pairs.second.first)   << ", "
                 << "value = "    << *(pairs.second.second)
                 << "]";
        }
        return os;
    }

private:
    // Id -> Data::iterator -> Pool
    // pair<priority, <id, deque::iterator>>
    set<Bunch> Data;
    //  <object, priority>
    deque<pair<T, int>> Pool;
    int id = 0;
};


class StringNonCopyable : public string {
    public:
        using string::string;   // Позволяет использовать конструкторы строки
        StringNonCopyable(const StringNonCopyable&) = delete;
        StringNonCopyable(StringNonCopyable&&) = default;
        StringNonCopyable& operator=(const StringNonCopyable&) = delete;
        StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

using FUCKINGFUCK = typename set<pair<int, pair<int, typename deque<pair<StringNonCopyable, int>>::iterator>>>::iterator;
void PromoteAmount(PriorityCollection<StringNonCopyable> &obj, size_t number, vector<FUCKINGFUCK> &&v) {
        size_t numbers_of_promotion = 0;
        while(numbers_of_promotion < number) {
            for (const auto &q : v) {
                obj.Promote(q);
            }
            ++numbers_of_promotion;
        }
}

//------------------------------------------------------------------------------------------------------//
void TestAddCont() {
    PriorityCollection<StringNonCopyable> strings;
    {
        vector<StringNonCopyable> from;
        from.push_back("white");
        from.push_back("yellow");
        from.push_back("red");
        from.push_back("green");
        from.push_back("blue");
        vector<FUCKINGFUCK> to(from.size());

        strings.Add(from.begin(), from.end(), to.begin());

        ostringstream os;
        for (const auto &item : to) {
            os << strings.Get(item) << '\n';
        }

        ASSERT_EQUAL(os.str(), "white\nyellow\nred\ngreen\nblue\n");
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
[priority = 0, id = 0, value = [one, 0]]
[priority = 0, id = 1, value = [two, 0]]
[priority = 0, id = 2, value = [three, 0]]
[priority = 0, id = 3, value = [four, 0]]
[priority = 0, id = 4, value = [five, 0]]
[priority = 0, id = 5, value = [six, 0]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 4, {one_id, two_id, three_id});

        expected = R"""(
[priority = 0, id = 3, value = [four, 0]]
[priority = 0, id = 4, value = [five, 0]]
[priority = 0, id = 5, value = [six, 0]]
[priority = 4, id = 0, value = [one, 4]]
[priority = 4, id = 1, value = [two, 4]]
[priority = 4, id = 2, value = [three, 4]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 2, {four_id, five_id});

        expected = R"""(
[priority = 0, id = 5, value = [six, 0]]
[priority = 2, id = 3, value = [four, 2]]
[priority = 2, id = 4, value = [five, 2]]
[priority = 4, id = 0, value = [one, 4]]
[priority = 4, id = 1, value = [two, 4]]
[priority = 4, id = 2, value = [three, 4]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        stringstream get0;      get0 << strings.GetMax();
        ASSERT_EQUAL(get0.str(), "[three, 4]");
        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 6, {six_id});

        expected = R"""(
[priority = 2, id = 3, value = [four, 2]]
[priority = 2, id = 4, value = [five, 2]]
[priority = 4, id = 0, value = [one, 4]]
[priority = 4, id = 1, value = [two, 4]]
[priority = 4, id = 2, value = [three, 4]]
[priority = 6, id = 5, value = [six, 6]])""";

        stringstream get1;      get1 << strings.GetMax();
        ASSERT_EQUAL(get1.str(), "[six, 6]");
        ASSERT_EQUAL(strings.Print().str(), expected);

    }
    {
        stringstream get0;      get0 << strings.GetMax();
        ASSERT_EQUAL(get0.str(), "[six, 6]");

        strings.PopMax();
        string expected = R"""(
[priority = 2, id = 3, value = [four, 2]]
[priority = 2, id = 4, value = [five, 2]]
[priority = 4, id = 0, value = [one, 4]]
[priority = 4, id = 1, value = [two, 4]]
[priority = 4, id = 2, value = [three, 4]])""";

        stringstream get1;      get1 << strings.GetMax();
        ASSERT_EQUAL(get1.str(), "[three, 4]");
        ASSERT_EQUAL(strings.Print().str(), expected);
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
[priority = 0, id = 0, value = [one, 0]]
[priority = 0, id = 1, value = [two, 0]]
[priority = 0, id = 2, value = [three, 0]]
[priority = 0, id = 3, value = [four, 0]]
[priority = 0, id = 4, value = [five, 0]]
[priority = 0, id = 5, value = [six, 0]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 6, {four_id, five_id, six_id});

        expected = R"""(
[priority = 0, id = 0, value = [one, 0]]
[priority = 0, id = 1, value = [two, 0]]
[priority = 0, id = 2, value = [three, 0]]
[priority = 6, id = 3, value = [four, 6]]
[priority = 6, id = 4, value = [five, 6]]
[priority = 6, id = 5, value = [six, 6]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        ostringstream pop1;     pop1 << strings.PopMax();
        ASSERT_EQUAL(pop1.str(), "[six, 6]");

        ostringstream pop2;     pop2 << strings.PopMax();
        ASSERT_EQUAL(pop2.str(), "[five, 6]");

        ostringstream pop3;     pop3 << strings.PopMax();
        ASSERT_EQUAL(pop3.str(), "[four, 6]");

        ostringstream pop4;     pop4 << strings.PopMax();
        ASSERT_EQUAL(pop4.str(), "[three, 0]");

        expected = R"""(
[priority = 0, id = 0, value = [one, 0]]
[priority = 0, id = 1, value = [two, 0]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 7, {one_id, two_id});

        const auto new_six_id = strings.Add("six");

        expected = R"""(
[priority = 0, id = 6, value = [six, 0]]
[priority = 7, id = 0, value = [one, 7]]
[priority = 7, id = 1, value = [two, 7]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);

        PromoteAmount(strings, 7, {new_six_id});

        expected = R"""(
[priority = 7, id = 0, value = [one, 7]]
[priority = 7, id = 1, value = [two, 7]]
[priority = 7, id = 6, value = [six, 7]])""";

        ASSERT_EQUAL(strings.Print().str(), expected);
    }
}
//-----------------------------------------------------------------------------------------------------//
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


//-----------------------------------------------------------------------------------------------------//
int main() {
/*    TestRunner tr;
    RUN_TEST(tr, TestAddCont);
    RUN_TEST(tr, TestAddGetValid);
    RUN_TEST(tr, TestAddPromote);
    RUN_TEST(tr, TestAddPop);
    RUN_TEST(tr, TestNoCopy);*/
    return 0;
}
//------------------------------------------------------------------------------------------------------//
