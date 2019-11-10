#include "hash_table.h"
#define KA (sqrt(7) - 2.0) / 2.0

template<class S, class T>
bool hashNode<S,T>::operator<(hashNode<S, T> &node) const{
    return this->key < node.key;
}

template<class S, class T>
bool hashNode<S,T>::operator>(hashNode<S, T> &node) const{
    return this->key > node.key;
}

template<class S, class T>
bool hashNode<S,T>::operator==(hashNode<S, T> node) const{
    return this->key == node.key;
}

template<class S, class T>
bool hashNode<S,T>::operator>=(hashNode<S, T> &node) const{
    return this->key >= node.key;
}

template<class S, class T>
bool hashNode<S,T>::operator<=(hashNode<S, T> &node) const{
    return this->key <= node.key;
}

template<class S, class T>
string  hashNode<S,T>::toString() const{
    string str = to_string(key) + " : " + to_string(value);
    return str;
}

template<>
string  hashNode<string,string>::toString() const{
    string str = key + " : " + value;
    return str;
}

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
    destroy();                //calling private destroy
}

template<class T>
double hashTable<T>::loadfactor() const{
    /*
        this function returns the load factor.

        Pre-condition:
            table has to be initialized as an array of List<T>
    */
    return double(items) / slots;
}

template<class T>
double hashTable<T>::actualLF() const{
  /*
      This function returns more accurate load factor.
      Precondition: table has to initialized with h's slot num
  */
  double sum = 0.0;
  for (int i = 0; i < slots; i++){
    sum += pow(table[i].length(),2); //square the length of linked list in each slot and add up
  }
  sum = sqrt(sum);                  //square root of the sum
  return sum / slots;               //divide by slots for more accruate load factor
}

template<class T>
void hashTable<T>::initializer(int sNum){
    /*
        this fuction set up the class property based on the parameter.

        Pre-condition:
            table and slots has yet to be initialized.
    */
    slots = sNum;                 //copying slots
    items = 0;
    table = new List<T>[slots];   //initializing table pointer
}

template<class T>
T* hashTable<T>::get(T k) const{
    /*
        This function finds and return the pointer
        of the target value

        PreCondition: table has to be initialized as array of List<T>.
    */
    int index = hash(k);
    for (int i = 0; i < table[index].length(); i++){
        if (*table[index][i] == k)
            return table[index][i];
    }
    throw new noKeyException; //if not found,
}

template<class T>
int hashTable<T>::slotNum() const{
    return slots;
}

template<class T>
void hashTable<T>::insert(T *k){
    /*
        this function insert item into the hash table.

        Pre-Condition:
            table has to be initialized as an array of List<T>
    */
    int key = hash(*k);      //key from hash function
    table[key].prepend(k);   //prepend the item.
    // table[key].append(k);   //prepend the item.
    // table[key].insert(k, 0);   //prepend the item.
    items++;
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
            items--;
            return;
        }
    }
    throw new noKeyException;  //if not found,
}

template<class T>
void hashTable<T>::operator=(const hashTable<T> &h){
   /*
        this is assigment operation.
   */
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
    string str = "[" + to_string(slot) + "]=" + table[slot].toString() + "";
    // str += to_string(slot);
    // str += "]=";
    // str += table[slot].toString();
    return str;
}

template<class T>
int hashTable<T>::itemNum() const{
    /*
        this function returns the
    */
    return items;
}

template<class T>
int hashTable<T>::hash(T &key) const{
    /*
        this function returns key for hashtable in key-value pair.

        PreCondition:
            table has to be initialized as an array of List<T>.
    */
    return int(slots * (fmodl(KA * double(key), 1)));
}

template<>
int hashTable<char>::hash(char &key) const{
    /*
        this function returns key for hashtable in key-value pair.

        PreCondition:
            table has to be initialized as an array of List<T>.
    */
    return int(slots * (fmodl(KA * double(key), 1)));
}

template<>
int hashTable<string>::hash(string &key) const{
    /*
        this function returns key for hashtable in key-value pair.

        PreCondition:
            table has to be initialized as an array of List<T>.
    */
    long double sum = 0.0;
    int len = key.length();

  	for(int i=0; i< len; i++){
  		sum += pow(key[i] * (i + 1), 2);
    }
    sum = sqrt(sum);
    // cout << int(fmodl(sum, slots + 9)) << endl;
  	return int(fmodl(sum, slots + 9));
    // long double sum = 0.0;
    // for (int i = 0; i < key.length(); i++)
    //     sum += int(key[i]) * pow(53, i);
    //     // sum += pow((int(key[i]) * (i + 1)),2);
    // // sum = sqrt(sum);
    // // return int(fmodl(slots * (fmodl(KA * sum, 1)), slots + 31));
    // return int(fmodl(sum, slots + 11));
}

template<>
int hashTable<hashNode<string, string>>::hash(hashNode<string, string> &key) const{
    /*
        this function returns key for hashtable in key-value pair.

        PreCondition:
            table has to be initialized as an array of List<T>.
    */
   long double sum = 0.0;
    for (int i = 0; i < key.key.length(); i++)
        sum += pow((int(key.key[i]) * (i + 1)),2);
    sum = sqrt(sum);
    return int(slots * (fmod(KA * sum, 1)));
}

template<class T>
void hashTable<T>::copy(const hashTable<T> &h){
    /*
        This function executes the deep copy.
        Precondition: table has to initialized with h's slot num
    */
    List<T>* copyL = h.getTable();    //table from h
    table = new List<T>[h.slotNum()];
    for (int i = 0; i < h.slotNum(); i++)
        table[i] = copyL[i];          //deep copying element to element.
    items = h.itemNum();
}

template<class T>
void hashTable<T>::destroy(){
   /*
        This function destroys the table pointer.
        PreCondition:
            Table should not be NULL. It is not to be executed when it is NULL.
   */
    for (int i = 0; i < slots; i++) //going through every slot
      table[i].clear();
    items = slots = 0;             //back to 0
    // delete table;                 //delete the pointer. fix here
}

template<class T>
List<T>* hashTable<T>::getTable() const{
    //this function returns the pointer of the table.
    return table;
}
