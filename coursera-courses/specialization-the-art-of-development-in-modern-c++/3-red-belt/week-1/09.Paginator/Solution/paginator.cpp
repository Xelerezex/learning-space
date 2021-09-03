#include "test_runner.h"

/* UNCOMMENT FOR COURSERA SERVER PUSH
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <cmath>

using namespace std;
*/


template <typename Iterator>
class Paginator {
    private:
        Iterator Begin, End;
        size_t Page_Size;

        template <typename iterator>
        class IteratorRange {
            private:
                iterator first, last;
            public:
                IteratorRange(iterator f, iterator l) : first(f), last(l) {}

                auto begin() const {
                    return first;
                }

                auto end() const {
                    return last;
                }

                size_t size() const {
                    return last - first;
                }
        };

        vector<IteratorRange<Iterator>> Pages;

    public:
        Paginator(Iterator begin, Iterator end, size_t page_size) : Begin(begin), End(end), Page_Size(page_size) {
            size_t sz = ceil(static_cast<double>(End - Begin) / static_cast<double>(Page_Size));

            Iterator t_beg = Begin;
            Iterator t_end = End;

            for (size_t i = 0; i < sz; ++i) {
                IteratorRange<Iterator> iter = {t_beg, next(t_beg, min(static_cast<size_t>(t_end - t_beg), Page_Size))};
                t_beg = next(t_beg, min(static_cast<size_t>(t_end - t_beg), Page_Size));
                Pages.push_back(iter);
            }

        }

        auto begin()  {
            return Pages.begin();
        }

        auto end()  {
            return Pages.end();
        }


        size_t size() const {
            return Pages.size();
        }
};


template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator { c.begin(), c.end(), page_size };
}


void TestPageCounts() {
    vector<int> v(15);

    ASSERT_EQUAL(Paginate(v, 1).size(), v.size());
    ASSERT_EQUAL(Paginate(v, 3).size(), 5u);
    ASSERT_EQUAL(Paginate(v, 5).size(), 3u);
    ASSERT_EQUAL(Paginate(v, 4).size(), 4u);
    ASSERT_EQUAL(Paginate(v, 15).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 150).size(), 1u);
    ASSERT_EQUAL(Paginate(v, 14).size(), 2u);
}


void TestLooping() {
    vector<int> v(15);
    iota(begin(v), end(v), 1);

    Paginator<vector<int>::iterator> paginate_v(v.begin(), v.end(), 6);
    ostringstream os;
    for (const auto& page : paginate_v) {
        for (int x : page) {
            os << x << ' ';
        }
        os << '\n';
    }

    ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 \n7 8 9 10 11 12 \n13 14 15 \n");
}


void TestModification() {
    vector<string> vs = {"one", "two", "three", "four", "five"};
    for (auto page : Paginate(vs, 2)) {
        for (auto& word : page) {
            word[0] = toupper(word[0]);
        }
    }

    const vector<string> expected = {"One", "Two", "Three", "Four", "Five"};
    ASSERT_EQUAL(vs, expected);
}


void TestPageSizes() {
    string letters(26, ' ');

    Paginator letters_pagination(letters.begin(), letters.end(), 11);
    vector<size_t> page_sizes;
    for (const auto& page : letters_pagination) {
        page_sizes.push_back(page.size());
    }

    const vector<size_t> expected = {11, 11, 4};
    ASSERT_EQUAL(page_sizes, expected);
}


void TestConstContainer() {
    const string letters = "abcdefghijklmnopqrstuvwxyz";

    vector<string> pages;
    for (const auto& page : Paginate(letters, 10)) {
        pages.push_back(string(page.begin(), page.end()));
    }

    const vector<string> expected = {"abcdefghij", "klmnopqrst", "uvwxyz"};
    ASSERT_EQUAL(pages, expected);
}


void TestPagePagination() {
    vector<int> v(22);
    iota(begin(v), end(v), 1);

    vector<vector<int>> lines;
    for (const auto& split_by_9 : Paginate(v, 9)) {
        for (const auto& split_by_4 : Paginate(split_by_9, 4)) {
            lines.push_back({});
            for (int item : split_by_4) {
                lines.back().push_back(item);
            }
        }
    }

    const vector<vector<int>> expected = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9},
            {10, 11, 12, 13},
            {14, 15, 16, 17},
            {18},
            {19, 20, 21, 22}
    };
    ASSERT_EQUAL(lines, expected);
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, TestPageCounts);
    RUN_TEST(tr, TestLooping);
    RUN_TEST(tr, TestModification);
    RUN_TEST(tr, TestPageSizes);
    RUN_TEST(tr, TestConstContainer);
    RUN_TEST(tr, TestPagePagination);

    return 0;
}
