struct Graph {
    struct Vertex {
        int head;
        bool visited;
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

    void DFS(int u) {
        vertex[u].visited = true;
        
        for (int i = vertex[u].head; i; i = edge[i].next) {
            int v = edge[i].head;
            if (vertex[v].visited) {
                continue;
            }

            DFS(v);
        }

        return;
    }
};