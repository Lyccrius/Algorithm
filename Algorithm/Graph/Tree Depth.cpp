#include <cstdio>

namespace Tree {
    void DFS(int u, int from) {
        for (i = vertex[u].head; i; i = edge[i].next) {
            int v = edge[i].head;
            if (v == from) continue;
            vertex[v].depth = vertex[u].depth + 1;
            DFS(v, u);
        }
        return;
    }
};