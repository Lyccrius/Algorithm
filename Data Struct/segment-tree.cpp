#include <cstdio>

const int maxn = 1e5 + 10;

struct SegmentTree {
    struct Node {
        int l, r;
        int lNode, rNode;
        int tag;
        int val;
    }

    int array[maxn];
    Node node[maxn << 2];

    void Build(int l, int r, int xNode) {
    //  set l and r of xNode
        node[xNode].l = l;
        node[xNode].r = r;

    //  xNode is a leaf node
        if (l == r) {
            node[xNode].val = array[l];
        //  node[xNode].val = array[r];
            return;
        }

    //  xNode is not a leaf node
        int mid = l + r >> 1;
    //  int mid = l + (r - l >> 1);
        node[xNode].lSon = xNode << 1;
        node[xNode].rSon = xNode << 1 + 1;
        Build(l, mid, node[xNode].lSon);
        Build(mid + 1, r, node[xNode].rSon);
        node[xNode].val = node[node[xNode].lSon].val
                        + node[node[xNode].rSon].val;

        return;
    }

    void PushDown(int xNode) {
        int lNode = node[xNode].lNode;
        int rNode = node[xNode].rNode;
        node[lNode].tag += node[xNode].tag;
        node[rNode].tag += node[xNode].tag;
        node[lNode].val += node[xNode].tag * (node[lNode].r - node[lNode].l + 1);
        node[rNode].val += node[xNode].tag * (node[rNode].r - node[rNode].l + 1);
        node[xNode].tag = 0;
        return;
    }

    void PushUp() {

    }

    void Modify(int l, int r, int xNode, int xVal) {
    //  [l, r] completely contains xNode
        if (node[xNode].l >= l && 
            node[xNode].r <= r) {
            node[xNode].tag += xVal;
            node[xNode].val += xVal * (r - l + 1);
            return;
        }

    //  [l, r] incompletely contains xNode
        if (node[xNode].tag && 
            node[xNode].l != node[xNode].r) PushDown(xNode);
        int lNode = node[xNode].lNode;
        int rNode = node[xNode].rNode;
        if (l <= node[lNode].r) Modify(l, r, lNode, xVal);
        if (r >= node[rNode].l) Modify(l, r, rNode, xVal);
        return;
    }

    int Query(int l, int r, int xNode) {
    //  [l, r] completely contains xNode
        if (l <= node[xNode].l && 
            r >= node[xNode].r) return node[xNode].val;

    //  [l, r] imcompletely contain xNode
        int lNode = node[xNode].lSon;
        int rNode = node[xNode].rSon;
        if (node[xNode].tag) PushDown(xNode);
        int sum = 0;
        if (l <= node[lNode].r) sum += Query(l, r, lNode);
        if (r >= node[rNode].l) sum += Query(l, r, rNode);
        return sum;
    }
};