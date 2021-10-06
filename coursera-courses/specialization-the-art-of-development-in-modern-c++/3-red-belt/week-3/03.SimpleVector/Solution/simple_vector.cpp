#include "simple_vector.h"
#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//-------------FOR-VECTOR
template <class L>
ostream& operator << (ostream& os, SimpleVector <L>& l) {
    for (auto &item : l) {
        if (l.Size() == 1) {
            os << "[" << item << "]";
        } else if (item == *l.begin()){
            os << "[" << item << ", ";
        } else if (item == *(l.end() - 1)) {
            os << item << "]";
        } else {
            os << item << ", ";
        }
    }
    return os;
}

void TestConstruction() {
    SimpleVector<int> empty;
    ASSERT_EQUAL(empty.Size(), 0u);
    ASSERT_EQUAL(empty.Capacity(), 0u);
    ASSERT(empty.begin() == empty.end());


    SimpleVector<string> five_strings(5);
    ASSERT_EQUAL(five_strings.Size(), 5u);
    ASSERT(five_strings.Size() <= five_strings.Capacity());

    for (auto& item : five_strings) {
        ASSERT(item.empty());
    }

    five_strings[2] = "Hello";
    five_strings[4] = "Not Hello";

    ASSERT_EQUAL(five_strings[2], "Hello");
    ASSERT_EQUAL(five_strings[4], "Not Hello");
}

void TestPushBack() {
    {
        SimpleVector<int> v;
        v.PushBack(7);
        ASSERT_EQUAL(v.Size(), 1);
        ASSERT_EQUAL(v.Size(), v.Capacity());
        ASSERT_EQUAL(v[0], 7);
        cout << v << " end = " << *(v.end() - 1) << endl;

        v.PushBack(77);
        ASSERT_EQUAL(v.Size(), 2);
        ASSERT_EQUAL(v.Capacity(), 2);
        ASSERT_EQUAL(v[1], 77);
        cout << v << " end = " << *(v.end() - 1) << endl;

        v.PushBack(777);
        ASSERT_EQUAL(v.Size(), 3);
        ASSERT_EQUAL(v.Capacity(), 4);
        ASSERT_EQUAL(v[2], 777);
        cout << v << " end = " << *(v.end() - 1) << endl;

        v.PushBack(7777);
        ASSERT_EQUAL(v.Size(), 4);
        ASSERT_EQUAL(v.Capacity(), 4);
        ASSERT_EQUAL(v[3], 7777);
        cout << v << " end = " << *(v.end() - 1) << endl;

        v.PushBack(77777);
        ASSERT_EQUAL(v.Size(), 5);
        ASSERT_EQUAL(v.Capacity(), 8);
        ASSERT_EQUAL(v[4], 77777);
        cout << v << " end = " << *(v.end() - 1) << endl;
    }
        cout << "-------------------------\n";
    {
        SimpleVector<int> v;
        for (int i = 10; i >= 1; --i) {
            v.PushBack(i);
            ASSERT(v.Size() <= v.Capacity());
        }
        sort(begin(v), end(v));

        const vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ASSERT_EQUAL(v.Size(), expected.size());
        ASSERT(equal(begin(v), end(v), begin(expected)));
    }
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestPushBack);

    return 0;
}
