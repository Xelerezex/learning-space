#pragma once
#include "headers.h"


//---------------------------------IMPLEMENTATION-----------------------------------------------//
template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s);

template <class K,  class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m);

template <class K, class V, class F>
std::ostream& operator << (std::ostream& os,const std::map<K, V, F>& m);

template <class L>
std::ostream& operator << (std::ostream& os, const std::vector<L>& l);

template <class D>
std::ostream& operator << (std::ostream& os, const std::deque<D>& d);

template <class J>
std::ostream& operator << (std::ostream& os, const std::list<J>& j);

template <class P1, class P2>
std::ostream& operator << (std::ostream& os, const std::pair<P1, P2>& p);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {});

inline void Assert(bool b, const std::string& hint);
//----------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------//
template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint)
{
    if (!(t == u))
    {
        std::ostringstream __assert_equal_private_os;
        __assert_equal_private_os
            << "Assertion failed: "
            << t << " != " << u;
        if (!hint.empty())
        {
            __assert_equal_private_os
            << " hint: " << hint;
        }
        throw std::runtime_error(__assert_equal_private_os.str());
    }
}
//----------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------------//
inline void Assert(bool b, const std::string& hint)
{
    AssertEqual(b, true, hint);
}
//----------------------------------------------------------------------------------------------//


//--------------------------------TEMPLATE-CLASS-FUNC-------------------------------------------//
class TestRunner
{
    public:
        template <class TestFunc>
        void RunTest(TestFunc func, const std::string& test_name)
        {
            try
            {
                func();
                std::cerr << test_name << " OK" << std::endl;
            }
            catch (std::exception& e)
            {
                ++fail_count;
                std::cerr << test_name << " fail: " << e.what() << std::endl;
            }
            catch (...)
            {
                ++fail_count;
                std::cerr << "Unknown exception caught" << std::endl;
            }
        }

        ~TestRunner()
        {
            if (fail_count > 0)
            {
                std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
                exit(1);
            }
        }

    private:
        int fail_count = 0;
};
//----------------------------------------------------------------------------------------------//


//------------------------------OUTPUT-OPERATOR-FOR-CONTAINERS----------------------------------//
//-------------FOR-STD::SET
template <class T>
std::ostream& operator << (std::ostream& os, const std::set <T>& s)
{
    os << "{";
    bool first = true;

    for(const auto& x : s)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << x;
  }

  return os << "}";
}


//-------------FOR-STD::MAP
template <class K, class V>
std::ostream& operator << (std::ostream& os,const std::map<K, V>& m)
{
    os << "{";
    bool first = true;

    for(const auto& kv : m)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os <<"}";
}

//-------------FOR-STD::MAP-ALOC
template <class K, class V, class F>
std::ostream& operator << (std::ostream& os,const std::map<K, V, F>& m)
{
    os << "{";
    bool first = true;

    for(const auto& kv : m)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os <<"}.";
}


//-------------FOR-STD::VECTOR
template <class L>
std::ostream& operator << (std::ostream& os, const std::vector<L>& l)
{
    os << "[";
    bool first = true;

    for(const auto& i : l)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << i;
    }
    return os << "]";
}


//-------------FOR-STD::DEQUE
template <class D>
std::ostream& operator << (std::ostream& os, const std::deque <D>& d)
{
    os << "d[";
    bool first = true;

    for(const auto& i : d)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << i;
    }
    return os << "]";
}

//-------------FOR-STD::LIST
template <class J>
std::ostream& operator << (std::ostream& os, const std::list<J>& j)
{
    os << "(";
    bool first = true;

    for(const auto& i : j)
    {
        if (!first)
        {
            os << ", ";
        }

        first = false;
        os << i;
    }
    return os << ")";
}

//-------------FOR-STD::PAIR
template <class P1, class P2>
std::ostream& operator << (std::ostream& os, const std::pair <P1, P2>& p)
{
    return os << "[" << p.first << ", " << p.second << "]";
}
//----------------------------------------------------------------------------------------------//


//-------------------------------------------MACROS---------------------------------------------//


#define ASSERT_EQUAL(x, y) {                            \
    std::ostringstream __assert_equal_private_os;            \
    __assert_equal_private_os                           \
        << #x << " != " << #y << ", "                   \
        << __FILE__ << ":" << __LINE__;                 \
    AssertEqual(x, y, __assert_equal_private_os.str()); \
}

#define ASSERT(x) {                             \
    std::ostringstream __assert_equal_private_os;    \
    __assert_equal_private_os                   \
        << #x << " is false, "                  \
        << __FILE__ << ":" << __LINE__;         \
    Assert(x, __assert_equal_private_os.str()); \
}

#define RUN_TEST(tr, func)  \
    tr.RunTest(func, #func)
//----------------------------------------------------------------------------------------------//
