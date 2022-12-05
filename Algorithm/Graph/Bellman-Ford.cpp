struct Graph {
    struct Vertex {
        int head;
        int distance;
    };

    struct Edge {
        int head;
        int weight;
        int next;
    };

    Vertex vertex[maxn];
    Edge edge[maxm];
    int ecnt;

    void AddEdge(int tail, int head, int weight) {
        ecnt++;
        edge[ecnt].head = head;
        edge[ecnt].weight = weight;
        edge[ecnt].next = vertex[u].head;
        vertex[u].head = ecnt;
        return;
    }

    bool BellmanFord(int s) {
        bool relaxed;
        vertex[s].distance = 0;

        for (int i = 1; i <= n; i++) {
            relaxed = false;

            for (int u = 1; u <= n; u++) {
                if (vertex[u].distance == inf) {
                    continue;
                }

                for (int xe = vertex[u].head; xe; xe = edge[xe].next) {
                    int v = edge[xe].head;
                    int w = edge[xe].weight;
                    if (vertex[v].distance > vertex[u].distance + w) {
                        vertex[v].distance = vertex[u].distance + w;
                        relaxed = true;
                    }
                }
            }

            if (!relaxed) {
                break;
            }
        }

        return relaxed;
    }
};