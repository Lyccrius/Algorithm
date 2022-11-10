#include <cstdio>
#include <cstring>

const int maxn = 1e6 + 10;

int n, m;
char a[maxn];
char b[maxn];
int next[maxn];
int f[maxn];

void KMP() {
    next[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && a[i] != a[j + 1]) j = next[j];
        if (a[i] == a[j + 1]) j++;
        next[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++) {
        while (j > 0 && (j == n || b[i] != a[j + 1])) j = next[j];
        if (a[i] == a[j + 1]) j++;
        f[i] = j;
    //  if (f[i] == n)
    }
    return;
}

int main() {
    scanf("%s%s", a + 1, b + 1);
    n = std::strlen(a + 1);
    m = std::strlen(b + 1);
    KMP();
}