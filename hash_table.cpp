#include "hash_table.h"

template<class T>
hashTable<T>::hashTable(int numSlots){
    slots = numSlots;               //copying slots
    table = new List<T>[slots];   //initializing table pointer
}

template<class T>
hashTable<T>::hashTable(const hashTable<T> &h){
    slots = h.slotNum();            //copying slots
    table = new List<T>[slots];     //initializing table pointer
    copy(h);                        //deep copying element from h
}

template<class T>
hashTable<T>::~hashTable(){
    destroy();                      //calling private destroy
    cout << "destroyed" << endl;    //for debugging
}

template<class T>
T* hashTable<T>::get(const T &k) const{

}

template<class T>
int hashTable<T>::slotNum() const{
    return slots;
}

template<class T>
void hashTable<T>::insert(T *k){
    
}

template<class T>
void hashTable<T>::remove(const T &k){
    
}

template<class T>
void hashTable<T>::operator=(const hashTable<T> &h){
   destroy();                       //freeing memory first
   slots = h.slotNum();            //copying slots
   table = new List<T>[slots];     //initializing table pointer
   copy(h);                        //deep copy the h.
}

template<class T>
string hashTable<T>::toStr(int slot) const{
    string str = "[";
    str += to_string(slot);
    str += "]=";
    str += table[slot].toString();
    return str;
}

template<class T>
void hashTable<T>::copy(const hashTable<T> &h){
    /*
        This function executes the deep copy.
        Precondition: table has to initialized with h's slot num
    */
    List<T>* copyL = h.getTable();          //table from h
    for (int i = 0; i < h.slotNum(); i++){
        table[i] = copyL[i];                //deep copying element to element.
    }
}
    
template<class T>
void hashTable<T>::destroy(){
   /*
        This function destroys the table pointer.
        PreCondition: Table should not be NULL. It is not to be executed
        when it is NULL.
   */
    for (int i = 0; i < slots; i++) //going through every slot
        if (table[i].length() != 0) //if linked list in the slot is not empty
            table[i].clear();       //clear the single linked list

    delete table;                   //delete the pointer. fix here
}

template<class T>
List<T>* hashTable<T>::getTable() const{
    return table;
}