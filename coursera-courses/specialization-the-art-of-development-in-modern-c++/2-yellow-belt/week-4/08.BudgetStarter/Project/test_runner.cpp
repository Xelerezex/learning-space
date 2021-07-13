#ifndef TEST_RUNNER_CPP
#define TEST_RUNNER_CPP

#include "test_runner.h"

//-----------------------ФУНКЦИИ ДЛЯ ЗАПУСКА ТЕСТОВ-----------------------------
//--------------------------IMPLEMENTATION--------------------------------------

//-----ОСНОВНАЯ ФУНКЦИЯ СРАВНЕННИЯ-------
template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
  if(t != u){
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
    throw runtime_error(os.str());
  }
}

//-----ФУНКЦИЯ СРАВНЕННИЯ С TRUE-------
void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

//-----МЕТОД ЗАПУСКАЮЩИЙ ТЕСТЫ--------
template <class TestFunc>
  void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try{
      func();
      cerr << test_name << " OK" << endl; // ТЕСТЫ ЛУЧШЕ ВЫВОДИТЬ В ПОТОK ОШИБОК
    } catch(runtime_error& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
  }
}

//-----ДИСТРУКТОР--------------------
TestRunner::~TestRunner(){
  if(fail_count > 0){
      cerr << fail_count << " tests failed. Terminate" << endl;
      exit(1); // ПОЛНОСТЬЮ ЗАВЕРШАЕМ РАБОТУ ПРОГРАММЫ
  }
}
//----------------------------------------------------------------------------

#endif
