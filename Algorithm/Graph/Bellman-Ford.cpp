struct Graph {
    struct Vertex {
        int distance;
        int out[maxn];
        int ocnt;

        Vertex() {
            ocnt = 0;
            distance = inf;
        }
    };

    struct Edge {
        int tail;
        int head;
        int weight;
    };

    Vertex vertex[maxn];
    Edge edge[maxm];
    int ecnt;

    void AddEdge(int tail, int head, int weight) {
        ecnt++;
        edge[ecnt].tail = tail;
        edge[ecnt].head = head;
        edge[ecnt].weight = weight;
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

                for (int xe = 1; xe <= vertex[u].ocnt; xe++) {
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

        return flag;
    }
};