struct DSU {
    int ancestor[maxn];
    int size[maxn];

    void Init(const int &x) {
        ancestor[x] = x;
        size[x] = 1;
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

        if (ancestorX < ancestorY) {
            std::swap(ancestorX, ancestorY);
        }

        ancestor[ancestorY] = ancestorX;
        size[ancestorX] += size[ancestorY];
        
        return;
    }
};