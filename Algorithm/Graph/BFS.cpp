#include <cstdio>
#include <queue>
#include <stack>

const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;

struct Graph {
    struct Vertex {
        int head;
        bool visited;
        int distance;
        int from;
    };

    struct Edge {
        int head;
        int next;
    };

    Vertex vertex[maxn];
    Edge edge[maxm << 1];
    int ecnt;

    void AddEdge(int u, int v) {
        ecnt++;
        edge[ecnt].head = v;
        edge[ecnt].next = vertex[u].head;
        vertex[u].head = ecnt;
        return;
    }

    void BFS(int u) {
        std::queue<int> waiting;
        waiting.push(u);
        vertex[u].visited = true;
        vertex[u].distance = 0;
        vertex[u].from = 0;

        while (!waiting.empty()) {
            u = waiting.front();
            waiting.pop();

            for (int i = vertex[u].head; i; i = edge[u].next) {
                int v = edge[i].head;
                if (vertex[v].visited) {
                    continue;
                }

                waiting.push(v);
                vertex[v].visited = true;
                vertex[v].distance = vertex[u].distance + 1;
                vertex[v].from = u;
            }
        }

        return;
    }

    void PrintPath(int v) {
        std::stack<int> path;
        for (int u = v; u; u = vertex[u].from) {
            path.push(u);
        }

        while (!path.empty()) {
            printf("%d ", path.top());
            path.pop();
        }
        printf("\n");

        return;
    }
};