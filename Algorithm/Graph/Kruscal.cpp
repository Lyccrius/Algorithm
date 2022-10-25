struct Graph {
    struct Edge {
        int u, v;
        int w;

        bool operator<(const Edge &other) const {
            return w < other.w;
        }
    };

    struct DSU {
        int ancestor[maxn];

        void Init(const int &x) {
            ancestor[x] = x;
            return;
        }

        int Find(const int &x) {
            if (ancestor[x] == x) {
                return ancestor[x];
            } else {
                return ancestor[x] = Find(ancestor[x]);
            }
        }

        void Union(const int &x, const int &y) {
            int ancestorX = Find(x);
            int ancestorY = Find(y);

            if (ancestorX == ancestorY) {
                return;
            }

            ancestor[ancestorX] = ancestorY;
            return;
        }
    };

    Edge edge[maxm];
    int ecnt;
    
    DSU dsu;

    Graph() {
        ecnt = 0;
    }

    void AddEdge(const int &u, const int &v, const int &w) {
        ecnt++;
        edge[ecnt].u = u;
        edge[ecnt].v = v;
        edge[ecnt].w = w;
        dsu.Init(u);
        dsu.Init(v);
        return;
    }

    void SortEdge() {
        std::sort(edge + 1, edge + ecnt + 1);
        return;
    }
};

void Kruskal() {
    Graph.SortEdge();

    int connected = 0;

    for (int i = 1; i <= Graph.ecnt; i++) {
        int u = Graph.edge[i].u;
        int v = Graph.edge[i].v;
        int ancestorU = Graph.dsu.Find(u);
        int ancestorV = Graph.dsu.Find(v);

        if (ancestorU != ancestorV) {
            Graph.dsu.Union(ancestorU, ancestorV);
            connected++;
        }

        if (connected == N - 1) {
            break;
        }
    }
}