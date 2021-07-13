#ifndef CONTAINER_COUT_H
#define CONTAINER_COUT_H

#include "headers.h"

//------------------INTERFACE----------------------------

template<class S>
ostream& operator << (ostream& os, const vector<S>& s);

template<class T>
ostream& operator << (ostream& os, const set<T>& m);

template<class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m);

#endif