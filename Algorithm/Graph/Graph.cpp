//  直接存边
//
//  复杂度
/*  
    查询是否存在某条边：O(m)。
    遍历一个点的所有出边：O(m)。
    遍历整张图：O(nm)。
    空间复杂度：O(m)。
*/
//  应用
/*
    由于直接存边的遍历效率低下，一般不用于遍历图。
    在 Kruskal 算法 中，由于需要将边按边权排序，需要直接存边。
    在有的题目中，需要多次建图（如建一遍原图，建一遍反图），
    此时既可以使用多个其它数据结构来同时存储多张图，
    也可以将边直接存下来，需要重新建图时利用直接存下的边来建图。
*/

struct Graph {
    struct Edge {
        int tail;
        int head;
        bool visited;
    };

    Edge edge[maxm];
    int ecnt;

    void AddEdge(int u, int v) {
        ecnt++;
        edge[ecnt].tail = u;
        edge[ecnt].head = v;
        return;
    }

    bool FindEdge(int u, int v) {
        for (int i = 1; i <= m; i++) {
            if (edge[i].tail == u &&
                edge[i].head == v) {
                return true;
            }
        }

        return false;
    }

    void DFS(int u) {
        if (edge[u].visited) {
            return;
        }
        edge[u].visited = true;

        for (int i = 1; i <= m; i++) {
            if (edge[i].tail == u) {
                DFS(edge[i].head);
            }
        }

        return;
    }
};

//  邻接矩阵
//
//  复杂度
/*
    查询是否存在某条边：O(1)。
    遍历一个点的所有出边：O(n)。
    遍历整张图：O(n^2)。
    空间复杂度：O(n^2)。
*/
//  应用
/*
    邻接矩阵只适用于没有重边（或重边可以忽略）的情况。
    其最显著的优点是可以 O(1) 查询一条边是否存在。
    由于邻接矩阵在稀疏图上效率很低（尤其是在点数较多的图上，空间无法承受），
    所以一般只会在稠密图上使用邻接矩阵。
*/

struct Graph {
    bool adjacency[maxn][maxn];
    bool visited[maxn];

    void AddEdge(int u, int v) {
        adjacency[u][v] = true;
        return;
    }

    bool FindEdge(int u, int v) {
        return adjacency[u][v];
    }

    void DFS(int u) {
        if (visited[u]) {
            return;
        }
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (adjacency[u][v]) {
                DFS(v);
            }
        }

        return;
    }
};

//  邻接表
//
//  复杂度
/*
    查询是否存在 u 到 v 的边：O(d+(u))
    （如果事先进行了排序就可以使用 二分查找 做到 O(log(d+(u)))）。
    遍历点 u 的所有出边：O(d+(u))。
    遍历整张图：O(n+m)。
    空间复杂度：O(m)。
*/
//  应用
/*
    存各种图都很适合，除非有特殊需求（如需要快速查询一条边是否存在，且点数较少，可以使用邻接矩阵）。
    尤其适用于需要对一个点的所有出边进行排序的场合。
*/

struct Graph {
    struct Vertex {
        bool visited;
    };

    Vertex vertex[maxn];
    vector<vector<int> > adjacency;
    //  使用 int adjacency[maxn][maxn] 则空间复杂度为 O(n^2)。

    void AddEdge(int u, int v) {
        adjacency[u].push_back(v);
        return;
    }

    bool FindEdge(int u, int v) {
        for (int i = 0; i < adjacency[u].size(); i++) {
            if (adjacency[u][i] == v) {
                return true;
            }
        }

        return false;
    }

    void DFS(int u) {
        if (vertex[u].visited) {
            return;
        }
        vertex[u].visited = true;

        for (int i = 0; i <= adjacency[u].size(); i++) {
            DFS(adjacency[u][i]);
        }

        return;
    }
};

//  链式前向星
//
//  复杂度
/*
    查询是否存在 u 到 v 的边：O(d+(u))。
    遍历点 u 的所有出边：O(d+(u))。
    遍历整张图：O(n+m)。
    空间复杂度：O(m)。
*/
//  应用
/*
    存各种图都很适合，但不能快速查询一条边是否存在，也不能方便地对一个点的出边进行排序。
    优点是边是带编号的，有时会非常有用，
    而且如果 cnt 的初始值为奇数，存双向边时 i ^ 1 即是 i 的反边（常用于 网络流）。
*/

struct Graph {
    struct Vertex {
        int head;
        bool visited;
    };

    struct Edge {
        int head;
        int next;

        Edge() {
            next = -1;
        }
    }

    Vertex vertex[maxn];
    Edge edge[maxm];
    int ecnt;

    void AddEdge(int u, int v) {
        ecnt++;
        edge[ecnt].next = vertex[u].head;
        edge[ecnt].head = v;
        vertex[u].head = ecnt;
        return;
    }

    bool FindEdge(int u, int v) {
        for (int i = vertex[u].head; ~i; i = edge[i].next) {    // ~i means i != -1
            if (edge[u].head == v) {
                return true;
            }
        }

        return false;
    }

    void DFS(int u) {
        if (vertex[u].visited) {
            return;
        }
        vertex[u].visited = true;

        for (int i = vertex[u].head; ~i; i = edge[i].next) {
            DFS(edge[i].head);
        }

        return;
    }
};