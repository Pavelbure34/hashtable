#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

#define DEFAULT_SLOTS 100

template<class T>
class hashTable{
private:
    int slots;        //slots
    int items;        //number of items for calculating load factor
    List<T> *table;   //an array of List<T>

public:
    hashTable(int numSlots = DEFAULT_SLOTS);
    hashTable(const hashTable<T> &h);
    ~hashTable();

    T* get(const T &k) const;
    void insert(T *k);
    void remove(const T &k);
    int slotNum() const;

    void operator=(const hashTable<T> &h);
    string toStr(int slot) const;
    List<T>* getTable() const;

    double loadfactor() const;

private:
    void initializer(int sNum);
    void copy(const hashTable<T> &h);
    void destroy();
    int getLocation(const T &k) const;

    //for hash open addressing and chaining
    int genSlotNum() const;
    int minItemSlot() const;
};
#include "hash_table.cpp"
#endif