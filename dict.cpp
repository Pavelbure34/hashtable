#include "dict.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
    dict.cpp is the implementation file for dict.h.
    Coded by Alistaire Suh and Katie Masell (almost all of the work is done by the BST)
*/

template<class KeyType>
dictionary<KeyType>::dictionary(int slots){
    initializer(slots);
}


template<class KeyType>
void dictionary<KeyType>::insert(KeyType *key) { //key is a key value pair
  if(isDuplicate(*key)) { //check if node key's key is already in the BST
    return;               //error
  }
  hashTable<KeyType>::insert(key); //otherwise, insert the node into the BST
}


template<class KeyType>
bool dictionary<KeyType>::isDuplicate(KeyType &key){
  try{
    KeyType *hn = get(key); //just node key? or do we overwrite get
   return true;
  }catch(noKeyException *e){
    return false;
  } 
}
