#include <cstdio>
#include <cstring>

const int maxn = 1e8 + 10;

bool visited[maxn];
bool isPrime[maxn];

void Erantonsthenes(int n) {
    for (int i = 2; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        isPrime[i] = true;
        for (int j = i; j <= n / i; j++) visited[i * j] = true;
    }
    return;
}