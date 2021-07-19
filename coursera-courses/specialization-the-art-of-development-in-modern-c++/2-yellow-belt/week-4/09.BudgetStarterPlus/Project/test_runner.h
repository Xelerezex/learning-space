#pragma once
#include "headers.h"

//---------------------------------IMPLEMENTATION-----------------------------------------------//
template <class T>
ostream& operator << (ostream& os, const set  <T>& s);

template <class K,  class V>
ostream& operator << (ostream& os, const map  <K, V>& m);

template <class T,  class U>
void AssertEqual(const T& t,const U& u, const string& hint);

void Assert(bool b, const string& hint);
//----------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------//
template <class T,  class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertionfailed: " << t << " !=  " << u <<" hint: " << hint;
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

    return os << "]" << "\tvector\tsize:" << l.size();
}

//-------------FOR-PAIR
template <class F, class S>
ostream& operator << (ostream& os, const pair <F, S>& fs) {
    return os << "<" << fs.first << " : " << fs.second << ">";
}
//----------------------------------------------------------------------------------------------//
