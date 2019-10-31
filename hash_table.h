#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#include <iostream>
#include <string>
#include <cmath>
#include "List.h"
using namespace std;

#define DEFAULT_SLOTS 1000

template<class S, class T>
class hashNode{
public:
    S key;
    T value;

    hashNode(S key = NULL, T value = NULL)
        :key(key), value(value){};

    bool operator<(hashNode<S, T> &node) const;
    bool operator>(hashNode<S, T> &node) const;
    bool operator==(hashNode<S, T> node) const;
    bool operator>=(hashNode<S, T> &node) const;
    bool operator<=(hashNode<S, T> &node) const;
    string toString() const;

    // friend ostream& operator<<(ostream &o, hash<S, T> &n){
    //     //this friend function enables osteam operator.
    //     o << n.toString();
    //     return o;
    // }
};

template<class T>
class hashTable{
protected:
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
    int itemNum() const;

    void operator=(const hashTable<T> &h);
    string toStr(int slot) const;
    List<T>* getTable() const;

    double loadfactor() const;

protected:
    int hash(T &val) const;
    void initializer(int sNum);
    void copy(const hashTable<T> &h);
    void destroy();
    int getLocation(const T &k) const;
};
#include "hash_table.cpp"
#endif
