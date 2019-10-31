#include "dict.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
    dict.cpp is the implementation file for dict.h.
    Coded by Alistaire Suh and Katie Masell
*/

template<class T>
dictionary<T>::dictionary(int slots){
    initializer(slots);
}


template<class T>
void dictionary<T>::insert(T *key) { //key is a key value pair
  if(isDuplicate(*key)) { //check if node key's key is already in the BST
    return;               //error
  }
  hashTable<T>::insert(key); //otherwise, insert the node into the BST
}


template<class T>
bool dictionary<T>::isDuplicate(T &key){
  try{
    T *hn = get(key); //just node key? or do we overwrite get
   return true;
  }catch(noKeyException *e){
    return false;
  } 
}
