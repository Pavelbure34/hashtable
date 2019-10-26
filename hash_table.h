#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <iostream>
#include <string>
using namespace std;

template<class T>
class node{
public:
    T* item;
    node<T> *next;

    node(T* item = NULL, Node<T>* next = NULL):
        item(item), next(next){};
};

template<class T>
class hashTable{
private:
    int slots;
    List<T> *table;

public:
    hashTable(int &numSlots);
    hashTable(const hashTable<T> &h);
    ~hashTable();

    T* get(const T &k) const;
    void insert(T *k);
    void remove(const T& k);

    void operator=(const hashTable<T> &h);
    string toStr(int slot) const;

private:

};
#include "hash_table.cpp"
#endif