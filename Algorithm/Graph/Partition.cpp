#include <cstdio>

namespace Graph {
    void DFS(int u, int bel) {
        vertex[u].bel = bel;
        for (int i = vertex[u].head; i; i = edge[i].next) {
            int v = edge[i].head;
            if (vertex[u].visited) continue;
            DFS(v, bel);
        }
    }

    void Partition() {
        for (int i = 1; i <= n; i++) if (!vertex[i].bel) {
            cnt++;
            DFS(i, cnt);
        }
    }
};