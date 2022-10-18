struct HashMap {
    struct Edge {
        long long key;
        int value;
        int nexx;
    };

    Edge data[size << 1];
    int head[size];
    int cnt;

    HashMap() {
        cnt = 0;
        memset(head, 0, sizeof(head));
    }

    void clear() {
        cnt = 0;
        memset(head, 0, sizeof(head));
        return;
    }

    int hash(long long key) {
        return (key % size + size) % size;
    }

    int& operator [](long long key) {
        int h = hash(key);
        for (int i = head[h]; i; i = data[i].next) {
            if (data[i].key == key) {
                return data[i].value;
            }
        }
        data[++cnt] = (Edge){key, -1, head[h]};
        head[h] = cnt;
        return data[cnt].value;
    }
};