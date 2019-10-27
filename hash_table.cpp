#include "hash_table.h"

template<class T>
hashTable<T>::hashTable(int numSlots){
    initializer(numSlots); //initializing class properties
}

template<class T>
hashTable<T>::hashTable(const hashTable<T> &h){
    initializer(h.slotNum()); //initializing class properties
    copy(h);                  //deep copying element from h
}

template<class T>
hashTable<T>::~hashTable(){
    destroy();                      //calling private destroy
}

template<class T>
void hashTable<T>::initializer(int sNum){
    /*
        this fuction set up the class property based on the parameter.

        Pre-condition:
            table and slots has yet to be initialized.
    */
    slots = sNum;                 //copying slots
    table = new List<T>[slots];   //initializing table pointer
}

template<class T>
T* hashTable<T>::get(const T &k) const{
    /*
        This function finds and return the pointer
        of the target value

        PreCondition: table has to be initialized as array of List<T>.
    */
    int index;
    for (int i = 0; i < slots; i++){
        index = table[i].findIndex(k);
        if (index != -1){
            T *val = new T(table[i][index]);
            return val;
        }
    }
    throw new noKeyException; //if not found,
}

template<class T>
int hashTable<T>::slotNum() const{
    return slots;
}

template<class T>
void hashTable<T>::insert(T *k){
    int slotNumber;
    try{
        slotNumber = genSlotNum();  //search for empty spot
    }catch(fullTableException *e){  //if not full
        slotNumber = minItemSlot(); //find spot with min number of item
    }
    table[slotNumber].append(*k);   //append the item.
}

template<class T>
int hashTable<T>::genSlotNum() const{
    /*
        This function returns the slot where
        there is no item stored yet, thus
        using open addressing with linear probing

        Pre-condition:
            table has to be initialzied as array of List<T>.
            table has to have empty slot.
    */
    for (int i = 0; i < slots; i++)
        if (table[i].length() == 0)
            return i;
    throw new fullTableException;
}

template<class T>
int hashTable<T>::minItemSlot() const{
    /*
        This function returns the slot where
        there is a minimum number of item inside,
        thus, executing chaining operation only if needed

        Pre-condition:
            table has to be initialzied as array of List<T>.
            table has to have no empty slots.
    */
    int min = table[0].length();
    int spot = 0;
    for (int i = 1; i < slots; i++)
        if (table[i].length() < min){
            min = table[i].length();
            spot = i;
        }
    return spot;
}

template<class T>
void hashTable<T>::remove(const T &k){
    /*
        This function finds and remove the value inside

        PreCondition: table has to be initialized as array of List<T>.
    */
    int index;
    for (int i = 0; i < slots; i++){
        index = table[i].findIndex(k);
        if (index != -1){
            table[i].remove(k);
            return;
        }
    }
    throw new noKeyException;  //if not found,
}

template<class T>
void hashTable<T>::operator=(const hashTable<T> &h){
   destroy();                 //freeing memory first
   initializer(h.slotNum());  //initializing class properties
   copy(h);                   //deep copy the h.
}

template<class T>
string hashTable<T>::toStr(int slot) const{
    /*
        this function returns the linked list in the given slot.

        PreCondition:
            table has to be initialized as an array of List<T>.
    */
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
    for (int i = 0; i < h.slotNum(); i++)
        table[i] = copyL[i];                //deep copying element to element.
}
    
template<class T>
void hashTable<T>::destroy(){
   /*
        This function destroys the table pointer.
        PreCondition:
            Table should not be NULL. It is not to be executed when it is NULL.
   */
    for (int i = 0; i < slots; i++) //going through every slot
        if (table[i].length() != 0) //if linked list in the slot is not empty
            table[i].clear();       //clear the single linked list

    //delete table;                   //delete the pointer. fix here
}

template<class T>
List<T>* hashTable<T>::getTable() const{
    //this function returns the pointer of the table.
    return table;
}

template<class T>
int hashTable<T>::getLocation(const T &k) const{
    /*
        this function returns the exact location 
        of the item within the table.

        Pre-condition:
            table has to be initialized as an array of List<T>
    */
    int key, index;
    for (int i = 0; i < slots; i++){         //iterating among each key
        index = table[i].findIndex(k);       //if item found,
        if (index != -1){             
            key = i;                         //get the hash key
            return (i * slots * 10) + index; //return after giving a pattern.
        }
    }
}