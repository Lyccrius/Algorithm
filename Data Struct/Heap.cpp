#include <cstdio>
#include <algorithm>

const int maxn = 1e6 + 10;

int n;

struct Heap {
    const int root = 1;
    int heap[maxn];
    int cnt;

    void PushUp(int xNode) {
        while (xNode != root) {
            if (heap[xNode] > heap[xNode / 2]) {
                std::swap(heap[xNode], heap[xNode / 2]);
                xNode /= 2;
            } else break;
        }
        return;
    }

    void Push(int val) {
        cnt++;
        heap[cnt] = val;
        PushUp(cnt);
        return;
    }

    int Top() {
        return heap[root];
    }

    void PushDown(int xNode) {
        int sNode = xNode * 2;
        while (sNode <= xNode) {
            if (sNode < xNode && heap[sNode] < heap[sNode + 1]) s++;
            if (heap[sNode] > heap[xNode]) {
                std::swap(heap[sNode], heap[xNode]);
                xNode = sNode;
                sNode = xNode * 2;
            } else break;
        }
        return;
    }

    void Pop() {
        heap[root] = heap[cnt];
        cnt--;
        PushDown(root);
        return;
    }

    void Remove(int xNode) {
        heap[xNode] = heap[cnt];
        cnt--;
        PushUp(xNode);
        PushDown(xNode);
        return;
    }
};