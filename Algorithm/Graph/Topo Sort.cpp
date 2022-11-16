#include <cstdio>
#include <queue>

namespace Graph {
    void BFS() {
        std::queue<int> waiting;
        waiting.push(1);
        while (!waiting.empty()) {
            int u = waiting.front();
            waiting.pop();
            for (int i = vertex[u].head; i; i = edge[i].next) {
                int v = edge[i].head;
                if (vertex[v].rank) continue;
                vertex[v].rank = vertex[u].rank + 1;
                waiting.push(v);
            }
        }
        return;
    }
};