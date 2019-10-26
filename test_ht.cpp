#include "hash_table.h"
#include "assert.h"

#define LOG(x) cout << x << endl;
#define INIT "hash table test initiatied"
#define PASS "hash table has passed the test"

int main(){
    LOG(INIT);
    //testing with default constructor
    hashTable<int> iht;

    //testing assignment operator
    //hashTable<int> cIht1 = iht;

    //testing copy constructor
    //hashTable<int> cIht2(iht);

    //testing ostream and toStr with testing
    // cout << iht << endl;
    // cout << cIht1 << endl;
    // cout << cIht2 << endl;

    //testing destructor

    return 0;
}