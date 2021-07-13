#ifndef CONTAINER_COUT_CPP
#define CONTAINER_COUT_CPP

#include "container_cout.h"

//--------ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРАТОРОВ ВЫВОДА ДЛЯ КОНТЕЙНЕРОВ--------------------
//--------------------------IMPLEMENTATION-------------------------------------

//------ДЛЯ SET'ОВ--------------
template<class T>
ostream& operator << (ostream& os, const set<T>& m) {
  os << "{";
  bool first = true;
  for (const auto& x : m){
    if(!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

//------ДЛЯ MAP'ОВ--------------
template<class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m){
    if(!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

//------ДЛЯ VECTOR'ОВ--------------
template<class S>
std::ostream& operator << (std::ostream& os, const vector<S>& s) {
  os << "[";
  bool first = true;
  for (const auto& el : s){
    if(!first) {
      os << ", ";
    }
    first = false;
    os << el;
  }
  return os << "]";
}
//------------------------------------------------------------------------------


#endif