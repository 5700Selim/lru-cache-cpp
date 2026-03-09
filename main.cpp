#include <iostream>
#include "LRUCache.h"

using namespace std;

int main() {

    LRUCache cache(2);

    cache.put(1,10);
    cache.put(2,20);

    cout << cache.get(1) << endl;

    cache.put(3,30);

    cout << cache.get(2) << endl;

    return 0;
}