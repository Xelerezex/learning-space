#pragma once

#include "iterator_range.h"

#include <string_view>
#include <sstream>
#include <vector>
using namespace std;

// Joins container in one string, with custom delimiters
template <typename Container>
string Join(char c, const Container& cont)
{   // O(N)
    ostringstream os;
    for (const auto& item : Head(cont, cont.size() - 1))
    {
        os << item << c;
    }
    os << *rbegin(cont);
    return os.str();
}

// Shows string without spaces in front/back
// Function works with string_view!
string_view Strip(string_view s);

// Split string_view by separator. And gets us vector of string_view
vector<string_view> SplitBy(string_view s, char sep);
