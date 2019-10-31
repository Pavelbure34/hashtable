#ifndef _DICT_H
#define _DICT_H
/*
    dict.h is the abstract Data type file.
    Coded by Alistaire Suh and Henri Hegemier
*/
#include <iostream>
#include <sstream>
#include <string>
#include "hash_table.h"  //hash table based on the BST
#include "exceptions.h"
using namespace std;

template<class T>
class dictionary: public hashTable<T> {
private:
    using hashTable<T>::slots;
    using hashTable<T>::items;
    using hashTable<T>::table;

public:
    dictionary(int slots = DEFAULT_SLOTS);

    void insert(T *key);
    // using hashTable<T>::insert;
    using hashTable<T>::get;
    using hashTable<T>::itemNum;
    using hashTable<T>::remove;

private:
    bool isDuplicate(T &key);
    using hashTable<T>::initializer;
};
#include "dict.cpp"
#endif
