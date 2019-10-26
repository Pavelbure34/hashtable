#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

#define DEFAULT_SLOTS 5

template<class T>
class hashTable{
private:
    int slots;        //slots
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
    // friend ostream& operator<<(ostream &o, hash<T> &h){
    //     //this friend function enables osteam operator.
    //     o << h.toStr();
    //     return o;
    // }

private:
    void copy(const hashTable<T> &h);
    void destroy();
};
#include "hash_table.cpp"
#endif