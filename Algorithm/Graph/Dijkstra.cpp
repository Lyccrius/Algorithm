#include <cstdio>
#include <queue>

const int inf = 0x3f3f3f3f;
const int maxN = 1e3 + 10;
const int maxM = 1e6 + 10;

namespace Graph {
    struct Vertex {
        int u;
        int head;
        int dis;
        bool relaxed;
        
        bool operator<(Vertex other) const {
            return dis > other.dis;
        }
    };

    struct Edge {
        int head;
        int next;
        int weight;
    };

    Vertex vertex[maxN];
    Edge edge[maxM];
    int ecnt;

    void AddEdge(int tail, int head, int weight) {
        ecnt++;
        edge[ecnt].head = head;
        edge[ecnt].weight = weight;
        edge[ecnt].next = vertex[tail].head;
        vertex[tail].head = ecnt;
        vertex[tail].dis = inf;
        vertex[head].dis = inf;
        vertex[tail].u = tail;
        vertex[head].u = head;
        return;
    }

    void Dijkstra(int s) {
        std::priority_queue<Vertex> waiting;
        vertex[s].dis = 0;
        waiting.push(vertex[s]);
        while (!waiting.empty()) {
            int u = waiting.top().u;
            waiting.pop();
            if (vertex[u].relaxed) continue;
            vertex[u].relaxed = true;
            for (int i = vertex[u].head; i; i = edge[i].next) {
                int v = edge[i].head;
                int w = edge[i].weight;
                if (vertex[v].dis > vertex[u].dis + w) {
                    vertex[v].dis = vertex[u].dis + w;
                    waiting.push(vertex[v]);
                }
            }
        }
        return;
    }
}