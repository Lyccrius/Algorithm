#include <cstdio>

struct SegmentTree {
    int array[maxn];
    int node[maxn << 2];

    void Build(int l, int r, int xn) {
    //  xn is a leaf node
        if (l == r) {
            node[x] = array[l];
        //  node[x] = array[r];
            return;
        }

    //  xn is not a leaf node
        int mid = (l + r) >> 1;
        Build(l, mid, x << 1);
        Build(mid + 1, r, x << 1 + 1);
        node[x] = node[x << 1] + node[x << 1 + 1];
        return;
    }

    
};