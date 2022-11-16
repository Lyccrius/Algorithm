#include <cstdio>
#include <algorithm>

namespace Tree {
    void DFS(int u, int from) {
        int maxPart = 0;
        for (int i = vertex[u].head; i; i = edge[i].next) {
            int v = edge[i].head;
            if (v == from) continue;
            DFS(v, u);
            vertex[u].size += vertex[v].size;
            maxPart = std::max(maxPart, vertex[v].size);
        }
        maxPart = std::max(maxPart, n - vertex[u].size);
        if (maxPart < ans) {
            ans = maxPart;
            focus = u;
        }
        return;
    }
};