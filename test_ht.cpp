#include "hash_table.h"
#include "assert.h"

#define LOG(x) cout << x << endl;
#define INIT "hash table test initiatied"
#define PASS "hash table has passed the test"

int main(){
    LOG(INIT);
    //testing with default constructor
    hashTable<int> iht(5);
    hashTable<double> dht(5);
    hashTable<float> fht(5);
    hashTable<char> cht(5);
    hashTable<string> sht(50);

    //testing assignment operator on empty tree
    hashTable<int> cIht1 = iht;
    hashTable<double> cDht1 = dht;
    hashTable<float> cFht1 = fht;
    hashTable<char> cCht1 = cht;

    // //testing copy constructor on empty tree
    hashTable<int> cIht2(iht);
    hashTable<double> cDht2(dht);
    hashTable<float> cFht2(fht);
    hashTable<char> cCht2(cht);

    // //testing toStr with empty tree
     for (int i = 0; i < iht.slotNum(); i++){
        assert(iht.toStr(i) == cIht1.toStr(i));
        assert(iht.toStr(i) == cIht2.toStr(i));
        assert(dht.toStr(i) == cDht1.toStr(i));
        assert(dht.toStr(i) == cDht2.toStr(i));
        assert(fht.toStr(i) == cFht1.toStr(i));
        assert(fht.toStr(i) == cFht2.toStr(i));
        assert(cht.toStr(i) == cCht1.toStr(i));

     }

    //testing insert and embedded genSlotNum, minItemSlot.
    for (int i = 0; i < 10; i++){
        int *inum = new int(i+1);
        double *dnum = new double(i+1.0);
        float *fnum = new float(i+1.0f);
        char *cnum = new char(i+60);
        string *snum = new string(to_string(i));
        iht.insert(inum);
        dht.insert(dnum);
        fht.insert(fnum);
        cht.insert(cnum);
        sht.insert(snum);
     }
     string *snum;
     snum = new string("this");
     sht.insert(snum);
     snum = new string("is");
     sht.insert(snum);
     snum = new string("a");
     sht.insert(snum);
     snum = new string("test");
     sht.insert(snum);


    //reaching here, hash has been working fine.
    assert(iht.itemNum() == 10);
    assert(dht.itemNum() == 10);
    assert(fht.itemNum() == 10);
    assert(cht.itemNum() == 10);
    assert(sht.itemNum() == 14);

    // //testing loadfactor
    assert(iht.loadfactor() == 2); //10 items in 5 slots
    assert(dht.loadfactor() == 2);
    assert(fht.loadfactor() == 2);
    assert(cht.loadfactor() == 2);
    assert(sht.loadfactor() == (14 / 50.0));

    // //testing assingment operator and copy constructor with non empty tree
    hashTable<int> cIht3 = iht;
    hashTable<int> cIht4(iht);
    hashTable<double> cDht3 = dht;
    hashTable<double> cDht4(dht);
    hashTable<float> cFht3 = fht;
    hashTable<float> cFht4(fht);
    hashTable<char> cCht3 = cht;
    hashTable<char> cCht4(cht);


    // //testing toStr with non empty tree
    for (int i = 0; i < 5; i++){
        assert(iht.toStr(i) == cIht3.toStr(i));
        assert(iht.toStr(i) == cIht4.toStr(i));
        assert(dht.toStr(i) == cDht3.toStr(i));
        assert(dht.toStr(i) == cDht4.toStr(i));
        assert(fht.toStr(i) == cFht3.toStr(i));
        assert(fht.toStr(i) == cFht4.toStr(i));
        assert(cht.toStr(i) == cCht3.toStr(i));
        assert(cht.toStr(i) == cCht4.toStr(i));
    }

    // //testing remove function
    iht.remove(5);
    dht.remove(7.0);
    fht.remove(7.0f);
    cht.remove(62);

    // //should throw an error when searching for 5 and 7
    try{
        iht.get(5);
    }catch(noKeyException *e){
        assert(e->what() == "No Key was found");
    }

    try{
        dht.get(7.0);
    }catch(noKeyException *e){
        assert(e->what() == "No Key was found");
    }

    try{
        fht.get(7.0f);
    }catch(noKeyException *e){
        assert(e->what() == "No Key was found");
    }

    try{
        cht.get(62);
    }catch(noKeyException *e){
        assert(e->what() == "No Key was found");
    }

    //testing get from the existing item,
    int* a = iht.get(10);
    double* b = dht.get(1.0);
    float* c = fht.get(2.0f);
    char* d = cht.get(61);
    assert(*a == 10);
    assert(*b == 1.0);
    assert(*c == 2.0f);
    assert(*d == 61);

    //reaching up to here, initializer has been working fine.
    //reaching up to here, copy funciton has been working.
    //testing destructor
    //reaching here, with no error, destroy is working.
    LOG(PASS);
    return 0;
}
