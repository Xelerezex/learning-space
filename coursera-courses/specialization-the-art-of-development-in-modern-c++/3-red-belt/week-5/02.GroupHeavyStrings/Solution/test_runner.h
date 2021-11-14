#pragma once
#include "headers.h"


//---------------------------------IMPLEMENTATION-----------------------------------------------//
template <class T>
ostream& operator << (ostream& os, const set    <T>& s);

template <class K,  class V>
ostream& operator << (ostream& os, const map    <K, V>& m);

template <class L>
ostream& operator << (ostream& os, const vector <L>& l);

template <class D>
ostream& operator << (ostream& os, const deque <D>& d);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {});

inline void Assert(bool b, const string& hint);
//----------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------//
template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (!(t == u)) {
        ostringstream __assert_equal_private_os;
        __assert_equal_private_os
        << "Assertion failed: "
        << t << " != " << u;
        if (!hint.empty()) {
            __assert_equal_private_os
            << " hint: " << hint;
        }
            throw runtime_error(__assert_equal_private_os.str());
    }
}


inline void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}
//----------------------------------------------------------------------------------------------//


//--------------------------------TEMPLATE-CLASS-FUNC-------------------------------------------//
class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};
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

//-------------FOR-MAP-FUNC
template <class K, class V, class F>
ostream& operator << (ostream& os,const map <K, V, F>& m) {
    os <<"{";
    bool first = true;

    for(const auto& kv : m) {
        if (!first) {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;

    }
    return os <<"}.";
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


//-------------------------------------------MACROS---------------------------------------------//


#define ASSERT_EQUAL(x, y) {               \
    ostringstream __assert_equal_private_os;                      \
    __assert_equal_private_os   \
    << #x << " != " << #y << ", "       \
    << __FILE__ << ":" << __LINE__;      \
    AssertEqual(x, y, __assert_equal_private_os.str());           \
}

#define ASSERT(x) {                       \
    ostringstream __assert_equal_private_os;                     \
    __assert_equal_private_os       \
    << #x << " is false, "             \
    << __FILE__ << ":" << __LINE__;     \
    Assert(x, __assert_equal_private_os.str());                  \
}

#define RUN_TEST(tr, func)        \
    tr.RunTest(func, #func)
//----------------------------------------------------------------------------------------------//
