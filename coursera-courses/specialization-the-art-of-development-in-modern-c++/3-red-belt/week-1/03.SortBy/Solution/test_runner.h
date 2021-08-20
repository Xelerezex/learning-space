#pragma once
#include "headers.h"


#define ASSERT_EQUAL(x, y) {                                          \
    ostringstream os;                                                 \
    os << #x << " != " << #y << ", " << __FILE__ << ":" << __LINE__;  \
    AssertEqual(x, y, os.str());                                      \
}

#define ASSERT(x) {                   \
    ostringstream os;                 \
    os << #x << " is false, "         \
    << __FILE__ << ":" << __LINE__;   \
    AssertEqual(x, os.str());         \
}

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)


//---------------------------------IMPLEMENTATION-----------------------------------------------//
template <class T>
ostream& operator << (ostream& os, const set  <T>& s);

template <class K,  class V>
ostream& operator << (ostream& os, const map  <K, V>& m);

template <class L>
ostream& operator << (ostream& os, const vector <L>& l);

template <class D>
ostream& operator << (ostream& os, const deque <D>& d);

template <class T,  class U>
void AssertEqual(const T& t,const U& u, const string& hint);

void Assert(bool b, const string& hint);
//----------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------//
template <class T,  class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: \n" << t << " != " << u <<" \nhint: ";
        throw runtime_error(os.str());
    }
}
//----------------------------------------------------------------------------------------------//


//--------------------------------TEMPLATE-CLASS-FUNC-------------------------------------------//
class TestRunner {
    public:
        template <class TestFunc>
        void RunTest (TestFunc func, const string& test_name);

        ~TestRunner();

    private:
        int fail_count = 0;
};

template <class TestFunc>
void TestRunner::RunTest (TestFunc func, const string& test_name) {
    try{
        func();
        cerr << test_name << " OK " <<  endl;
    } catch(runtime_error & e) {
        ++fail_count;
        cerr << test_name << " fail: " << e.what () <<endl;
    }
}
//----------------------------------------------------------------------------------------------//


//------------------------------OUTPUT-OPERATOR-FOR-CONTAINERS----------------------------------//
//-------------FOR-SET
template <class T>
ostream& operator << (ostream& os, const set <T>& s) {
    os << "{";
    bool first = true;

    for(const auto& x : s) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << x;
    }

    return os << "}";
}


//-------------FOR-MAP
template <class K, class V>
ostream& operator << (ostream& os,const map <K, V>& m) {
    os <<"{";
    bool first = true;

    for(const auto& kv : m) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;

    }
    return os <<"}";
}


//-------------FOR-VECTOR
template <class L>
ostream& operator << (ostream& os, const vector <L>& l) {
    os << "[";
    bool first = true;

    for(const auto& i : l) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]";
}


//-------------FOR-DEQUE
template <class D>
ostream& operator << (ostream& os, const deque <D>& d) {
    os << "d[";
    bool first = true;

    for(const auto& i : d) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << i;
    }

    return os << "]";
}
//----------------------------------------------------------------------------------------------//
