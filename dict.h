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

template<class KeyType>
class dictionary: public hashTable<KeyType> {
private:
    using hashTable<KeyType>::slots;
    using hashTable<KeyType>::items;
    using hashTable<KeyType>::table;

public:
    dictionary(int slots = DEFAULT_SLOTS);

    void insert(KeyType *key);
    using hashTable<KeyType>::insert;
    using hashTable<KeyType>::get;
    using hashTable<KeyType>::itemNum;
    using hashTable<KeyType>::remove;

private:
    bool isDuplicate(KeyType &key);
    using hashTable<KeyType>::initializer;
    
};
#include "dict.cpp"
#endif
