struct Graph {
    struct Vertex {
        int out[maxn];
        int ocnt;

        int distance;

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
        vertex[s].distance = 0;
        bool relaxed;

        for (int i = 1; i <= n; i++) {
            relaxed = false;

            for (int u = 1; u <= n; u++) {
                if (vertex[u].distance == inf) {
                    continue;
                }

                for (int xe = 1; xe <= vertex[i].ocnt; j++) {
                    int v = edge[xe].head;
                    if (vertex[v].distance > vertex[u].distance + edge[xe].weight) {
                        vertex[v].distance = vertex[u].distance + edge[xe].weight;
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