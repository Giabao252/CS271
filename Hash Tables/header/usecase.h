#include <iostream>
#include <string>
#include "../header/hash_table.h"

using namespace std;

#ifndef USECASE_H
#define USECASE_H


template <class T>
HashTable<T>*   create_table    (string fname, int m);

template <class T>
bool            login           (HashTable<T>* ht, T username, string password);




#endif