#include <cstdio>
#include <queue>

const int maxN = 1e6 + 10;
const int maxM = 1e6 + 10;

int n, m;

namespace Graph {
    struct Vertex {
        int head;
        int degree;
    };

    struct Edge {
        int head;
        int next;
    };

    Vertex vertex[maxN];
    Edge edge[maxM * 2];
    int ecnt;

    void AddEdge(int tail, int head) {
        ecnt++;
        edge[ecnt].head = head;
        edge[ecnt].next = vertex[tail].head;
        vertex[tail].head = ecnt;
        vertex[head].degree++;
    }

    int topoRank[maxN];
    int tcnt;

    void TopoSort() {
        std::queue<int> waiting;
        for (int i = 1; i <= n; i++) if (!vertex[i].degree) waiting.push(i);
        while (!waiting.empty()) {
            int u = waiting.front();
            waiting.pop();
            tcnt++;
            topoRank[tcnt] = u;
            for (int i = vertex[u].head; i; i = edge[i].next) {
                int v = edge[i].head;
                vertex[v].degree--;
                if (!vertex[v].degree) waiting.push(v);
            }
        }
        return;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        Graph::AddEdge(u, v);
    }
    Graph::TopoSort();
    for (int i = 1; i <= Graph::tcnt; i++) printf("%d ", Graph::topoRank[i]);
    printf("\n");
    return 0;
}