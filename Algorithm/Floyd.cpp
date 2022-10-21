struct Graph {
    int f[maxn][maxn];

    void Init() {
        std::memset(f, inf, sizeof(f));
        for (int i = 0; i <= maxn; i++) {
            f[i][i] = 0;
        }

        return;
    }

    void AddEdge(int u, int v, int weight) {
        f[u][v] = weight;
        f[v][u] = weight;
        return;
    }

    int Floyd(int u, int v) {
        for (int k = 1; k <= n; k++) {
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                  f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
                }
            }
        }

        return f[u][v];
    }
}