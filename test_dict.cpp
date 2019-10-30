#include "dict.h"
#include "assert.h"

void test_constructors(){
    dictionary<int> x();
    dictionary<string> y(100);
}

void test_insert(){
    dictionary<int> x;
    dictionary<string> y(100);
    int num = 5;
    x.insert(&num);
    string s = "test";
    int a, b;
    y.insert(&s);
    a = y.itemNum();
    y.insert(&s);
    b = y.itemNum();
    assert(a == b);
}


int main(){
    cout << "Testing Constructors" << endl;
    test_constructors();
    cout << "Testing insert" << endl;
    test_insert();
    return 0;
}