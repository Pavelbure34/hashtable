#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "exceptions.h"
using namespace std;

/*
    This is header file for single linked list.
    Coded by Alistaire Dominik Suh.
*/

template<class T>
class node{
public:
    T* item;
    node<T> *next;

    node(T* item = NULL, node<T>* next = NULL){
          this->item = new T(*item);
          this->next = next;
    };

    ~node(){
      delete item;
    }
};


template<class T>
class List{
private:
    node<T>* head;
    int size = 0;

public:
    List();             //default constructor
    List(List<T> &copy);//copyConstructor
    ~List();            //constructor
    void prepend(T* item);
    void append(T* item);
    string toString();
    int length();
    int count(T item);
    void remove(const T& item);
    void insert(T *item, int index);
    T* operator[](int index);
    void operator=(List<T> &copy);
    friend ostream& operator<<(ostream &o, List<T> &list){
        //this friend function enables osteam operator.
        o << list.toString();
        return o;
    }
    T* pop(int index);
    T* pop();
    int findIndex(T item);
    void clear();

private:
    void deepCopy(List<T> &copy);
};

#include "List.cpp"
#endif
