#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn = 1e6 + 10;
const int maxs = 1e3 + 10;
const int sqrtn = 1e3;

struct BlockList {
    BlockList *next;
    int size;
    char array[(sqrtn << 1) + 10];

    BlockList() {
        next = NULL;
        size = 0;
    }

    vois pushBack() {
        
    }
}