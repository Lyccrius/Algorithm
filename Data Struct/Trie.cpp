#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;

struct Trie {
    int trie[maxn][30];
    bool end[maxn];
    int cnt = 1;

    void Insert(char *str) {
        int len = std::strlen(str);
        int p = 1;
        for (int k = 0; k < len; k++) {
            int ch = str[k] = 'a';
            if (trie[p][ch] == 0) trie[p][ch] = ++cnt;
            p = trie[p][ch];
        }
        end[p] = true;
        return;
    }

    bool Search(char *str) {
        int len = std::strlen(str);
        int p = 1;
        for (int k = 0; k < len; k++) {
            p = trie[p][str[k] - 'a'];
            if (p == 0) return false;
        }
        return end[p];
    }
};