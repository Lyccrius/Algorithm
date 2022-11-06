#include <cstdio>
#include <cstring>

const int maxn = 1e8 + 10;

bool isPrime[maxn];

void Erantonsthenes(int n) {
    std::memset(isPrime, false, sizeof(isPrime));
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) continue;
        printf("%d\n", i);
        for (int j = i; j <= n / i; j++) isPrime[i * j] = true;
    }
    return;
}