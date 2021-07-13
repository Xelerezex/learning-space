#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include "headers.h"
#include "container_cout.h"

//----------------------------INTERFACE---------------------------------------

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

class TestRunner{
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name);
  ~TestRunner();
private:
  int fail_count = 0;
};
//----------------------------------------------------------------------------


#endif
