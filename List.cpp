#include "List.h"

/*
    This is implementation file for single linked list.
    Coded by Alistaire Dominik Suh.
*/

template<typename T>
List<T>::List(){//default constructor
    head = NULL;
}

template<typename T>
List<T>::List(List<T> &copy){//copyConstructor
    deepCopy(copy);
}

template<typename T>
List<T>::~List(){
    clear();
}

template<typename T>
int List<T>::findIndex(const T &item) {
    //this funciton returns the index of the item within the list
    List<T> temp = *this;
    T target;
    for (int i = 0; i < size;i++){
        target = *temp[i];
        if (target == item)
            return i;
    }
    return -1;
}

template<typename T>
void List<T>::append(T *item){
    //this function appends item at the end.
    switch(size){
        case 0:                              //if size equals to 0,
            head = new node<T>();            //set up head with new item.
            head->item = new T(*item);
            head->next = NULL;
            size++;                          //increment the size
            return;
        case 1:                              //if size equals to 1,
            head->next = new node<T>();      //just next to head
            head->next->item = new T(*item); //set up new node
            head->next->next = NULL;
            size++;                          //increment the size
            return;
        default:                             //if size is bigger than 1,
            node<T>* newNode = new node<T>();//set up new node.
            newNode->item = new T(*item);
            newNode->next = NULL;
            node<T>* temp = head;            //move up to the last node.
            for (int i = 0; i < size-1;i++){
                temp = temp->next;
            }
            temp->next = newNode;            //append at the end
            size++;                          //increment the size
            return;
    }
}

template<typename T>
string List<T>::toString(){
    //this funciton prints out an list into a string.
    string str = "{";                     //setting up a string
    node<T>* temp = head;                 //starting from head node
    for (int i = 0; i < size; i++){       //until the tail node
        str = str + to_string(*(temp->item));//concatenate each item
        if (i != size - 1)
            str = str + ",";
        temp = temp->next;                //move to next node.
    }
    str = str + "}";
    return str;                           //return the full string
}

template<>
string List<string>::toString(){
    //this funciton prints out an list into a string.
    string str = "{";                     //setting up a string
    node<string>* temp = head;                 //starting from head node
    for (int i = 0; i < size; i++){       //until the tail node
        str = str + *(temp->item);           //concatenate each item
        if (i != size - 1)
            str = str + ",";
        temp = temp->next;                //move to next node.
    }
    str = str + "}";
    return str;                           //return the full string
}

template<typename T>
int List<T>::length(){
    //this funciton prints out size of the List.
    return size;
}

template<typename T>
int List<T>::count(T item){
    //this function counts how often item appears in the list.
    int count = 0;                  //set up initial count as zero,
    node<T>* temp = head;           //set temp as head
    for (int i = 0;i < size;i++){   //if item at the node equals to target
        if (temp->item == item)
            count++;                //increment the count
        temp = temp->next;          //move to next node.
    }
    return count;                   //return the count.
}

template<typename T>
void List<T>::remove(const T &item){
    //this function deletes the item from the list based on given item.
    node<T>* temp =  head;                        //pointer object for temp as head
    node<T>* deleteNode;                          //pointer object for item for delete
    if (*(temp->item) == item){                      //if item is at head
        head = temp->next;                        //set node next to head as head
        delete temp;                              //delete the old head
        size--;                                   //decrement the size
    }else{                                        //if not,
        for (int i = 0;i < size-1;i++){           //go through each node
            if (*(temp->next->item) == item){
                deleteNode = temp->next;
                if (i ==  size - 2){              //if it is in the last node,
                    temp->next = NULL;            //just delete the last node.
                    delete deleteNode;
                }else{                            //if not, set up next to next-next node.
                    temp->next = temp->next->next;
                    delete deleteNode;            //then delete the target node.
                }
                size--;                           //decrement the size
            }
            temp = temp->next;                    //iteration
        }
    }
}

template<typename T>
void List<T>::insert(T *item, int index){
    //this function inserts the element between the list.
    try{
        if (index > size-1 || index < size * -1)           //if index is out of bound,
            throw new IndexOutOfBoundException;            //throw an error
        node<T>* temp =  head;                             //set up temp as head
        node<T>* newNode = new node<T>();                  //set up new node
        *(newNode->item) = *item;
        if (index == 0 || index == size * -1){             //if insert to head
            newNode->next = temp;                          //append at the front.
            head = newNode;                                //make it as new head
        }else{
            if (index >= 0)                                //if positive index,
                for (int i = 0;i < index-1;i++){
                    temp = temp->next;
                }
            if (index < 0)                                 //if negative index,
                for (int i = size * -1;i < index-1;i++){
                    temp = temp->next;
                }
            newNode->next = temp->next;                    //set new node inbetween.
            temp->next = newNode;
        }
        size++;                                            //increment the size
    }catch(IndexOutOfBoundException& e){                   //if error thrown
        cout << e.what() << endl;                          //indicate what is about
    }
}

template<typename T>
T* List<T>::operator[](int index){
    //this operator returns the item in the given index.
    try{
        if (index >= size || index < size * -1)   //if index is out of bound,
            throw new IndexOutOfBoundException;   //throw an error
        node<T>* temp = head;                     //set up temp as head
        if (index >= 0){                          //if positive index,
            for (int i = 0; i < index;i++){       //return the item from matching node
                if (i == index)                   //in right index
                    return temp->item;
                temp = temp->next;
            }
            return temp->item;
        }
        else if (index < 0){                      //if negative index,
            for (int i = size * -1; i < 0;i++){   //return the item from matching node
                if (i == index)                   //in right index
                    return temp->item;
                temp = temp->next;
            }
            return temp->item;
        }
    }catch(IndexOutOfBoundException& e){
        cout << e.what() << endl;
    }
}

template<typename T>
void List<T>::operator=(List<T> &copy){
    //this is assignment operation.
    clear();         //freeing up memory and prevent leak first.
    deepCopy(copy);
}

template<typename T>
T* List<T>::pop(int index){
    //this function deletes the element with the given element.
    try{
        if (index > size-1 || index < size * -1)        //if index is out of bound,
            throw new IndexOutOfBoundException;         //throw an error
        T* returnValue;                                  //set up return value
        node<T>* temp = head;                           //set up temp as head
        node<T>* deleteValue;                           //delete value
        if (index == 0 || index == size * -1){          //if index is at head,
            returnValue = temp->item;                   //pop the old head
            head = temp->next;                          //make second node as new head
            delete temp;
            size--;                                     //decrement the size
            return returnValue;
        }else if (index == size-1 || index == -1){      //if at the end,
            return pop();                               //remove the last element.
        }else{
            if (index < 0)                              //if inbetween,
                for (int i = size * -1;i < index-1;i++){//if negative index,
                    temp = temp->next;
                }
            else                                        //if positive index,
                for (int i = 0;i < index-1;i++){
                    temp = temp->next;
                }
            deleteValue = temp->next;                   //delete the target node
            temp->next = deleteValue->next;             //and link the front and back node.
            returnValue = deleteValue->item;
            delete deleteValue;
            size--;                                     //decrement the size
            return returnValue;
        }
    }catch(IndexOutOfBoundException& e){
        cout << e.what() << endl;
    }
}

template<typename T>
T* List<T>::pop(){
    //pop function overloaded #1
    T* returnValue;
    node<T>* temp = head;
    for (int i = 0;i < size-1;i++){
        temp = temp->next;
    }
    returnValue = temp->item;
    size--;
    delete temp;
    return returnValue;
}

template<typename T>
void List<T>::clear(){
    //this function deletes each node in the list.
    //node<T>* temp = head;
    for (int i = 0; i < size; i++){
        this->pop(i);
        // delete temp;
        // temp = temp->next;
    }
    head = NULL;
    size = 0;
}

template<typename T>
void List<T>::deepCopy(List<T> &copy){
    //this function carry out deep copy.
    head = new node<T>();
    // head->item = copy[0];                  //copy each item from copy list
    // node<T>* temp = head;                  //to node in the current list.
    // node<T>* newNode;
    for (int i = 0; i < copy.length(); i++){
        this->append(copy[i]);
        // newNode = new node<T>();
        // newNode->item = copy[i];
        // temp->next = newNode;
        // temp = temp->next;
    }
    size = copy.length();                  //set up the size equivalent to copy list.
}
