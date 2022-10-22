struct Graph {
    struct Vertex {
        int distance;
        int out[maxn];
        int ocnt;
        int pcnt;
        bool relaxed;

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

    bool SPFA(int s) {
        bool relaxed;
        std::queue<int> waiting;
        waiting.push(s);
        vertex[s].distance = 0;
        vertex[s].relaxed = true;

        while (!waiting.empty()) {
            int u = waiting.front();
            waiting.pop();
            vertex[u].relaxed = false;

            for (int xe = 1; xe <= vertex[u].ocnt; xe++) {
                int v = edge[xe].head;
                int w = edge[xe].weight;
                if (vertex[v].distance > vertex[u].distance + w) {
                    vertex[v].distance = vertex[u].distance + w;
                    vertex[v].pcnt = vertex[u].pcnt + 1;

                    if (vertex[v].pcnt >= n) {
                        return false;
                    }

                    if (!vertex[v].relaxed) {
                        waiting.push(v);
                        vertex[v].relaxed = true;
                    }
                }
            }
        }

        return true;
    }
};