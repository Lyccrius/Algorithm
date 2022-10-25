#include <cstdio>
#include <algorithm>
#include <vector>

const int maxn = 1e4 + 10;
const int maxm = 1e4 + 10;

struct Graph {
    struct Vertex {
        int distance;
        int distance1;
        int distance2;
    };

    Vertex vertex[maxn];
    std::vector<std::vector<int> > edge;

    Graph() {
        edge.resize(maxm);
    }

    void AddEdge(int u, int v) {
        edge[u].push_back(v);
        return;
    }

    int point;

    void DFS(int u, int from) {
        for (int v : edge[u]) {
            if (v == from) {
                continue;
            }

            vertex[v].distance = vertex[u].distance + 1;
            if (vertex[v].distance > vertex[point].distance) {
                point = v;
            }
            
            DFS(v, u);
        }

        return;
    }

    int diameter;

    void DP(int u, int from) {
        for (int v : edge[u]) {
            if (v == from) {
                continue;
            }

            DP(v, u);
            int distanceV = vertex[v].distance1 + 1;
            if (distanceV > vertex[u].distance1) {
                vertex[u].distance2 = vertex[u].distance1;
                vertex[u].distance1 = distanceV;
            } else 
            if (vertex[u].distance2 < distanceV) {
                vertex[u].distance2 = distanceV;
            }

            diameter = std::max(diameter, 
                                vertex[u].distance1 + 
                                vertex[u].distance2);
        }

        return;
    }
};

int N;
Graph tree;

int main() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree.AddEdge(u, v);
        tree.AddEdge(v, u);
    }

    tree.DFS(1, 0);
    tree.vertex[tree.point].distance = 0;
    tree.DFS(tree.point, 0);
    printf("%d\n", tree.vertex[tree.point].distance);

    tree.DP(1, 0);
    printf("%d\n", tree.diameter);

    return 0;
}