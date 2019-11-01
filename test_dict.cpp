#include "dict.h"
#include "assert.h"

/*
    this file tests dictionary class.
    Coded by Alistaire Suh and Katie Masell
*/

template<class T>
void test_insert(dictionary<T> &d, T item1, T item2){
    //testing distinct item
    d.insert(&item1);
    d.insert(&item2);

    int prev, after;
    prev = d.itemNum();
    //overlapped item should not be added.
    d.insert(&item2);
    after = d.itemNum();
    //testing itemNum constant after duplicateKey insert
    assert(prev == after);
}

template<class T>
void test_remove(dictionary<T> &d, T item1, T item2){
    int prev, after;

    //remove testing on existing item
    d.remove(item1);
    d.remove(item2);
    prev = d.itemNum();

    //remove testing on non existing item
    try{
        d.remove(item2);
    }catch(noKeyException *e){
        after = d.itemNum();
    }
    assert(prev == after);
    assert(prev == 0);
    assert(after == 0);
}

template<class T>
void test_get(dictionary<T> &d, T item1, T item2){
    //first inserting item
    test_insert(d, item1, item2);

    //getting item back
    T *a, *b;
    a = d.get(item1);
    b = d.get(item2);

    //testing
    assert(*a == item1);
    assert(*b == item2);

    //resetting
    test_remove(d, item1, item2);
    assert(d.itemNum() == 0);      //confirming removal
}


int main(){
    cout << "dictionary test init" << endl;
    string ta = "Project";
    string tb = "Done";

    cout << "Testing Constructor : ";
    dictionary<int> id(100);
    dictionary<double> dd(100);
    dictionary<float> fd(100);
    dictionary<char> cd(100);
    dictionary<string> sd(100);
    cout << "passed!" << endl;

    cout << "Testing insert : ";
    test_insert(id, 1, 2);
    test_insert(dd, 1.0, 2.2);
    test_insert(fd, 1.0f, 2.5f);
    test_insert(cd, 'a', 'b');
    test_insert(sd, ta, tb);
    cout << "passed!" << endl;

    cout << "Testing remove : ";
    test_remove(id, 1, 2);
    test_remove(dd, 1.0, 2.2);
    test_remove(fd, 1.0f, 2.5f);
    test_remove(cd, 'a', 'b');
    test_remove(sd, ta, tb);
    cout << "passed!" << endl;

    cout << "Testing get : ";
    test_get(id, 1, 2);
    test_get(dd, 1.0, 2.2);
    test_get(fd, 1.0f, 2.5f);
    test_get(cd, 'a', 'b');
    test_get(sd, ta, tb);
    cout << "passed!" << endl;

    cout << "dictionary test complete" << endl;
    return 0;
}
