#include <cstdio>
#include <cmath>

int maxn = 1e8 + 10;

int factor[maxn];
int cnt;

void factors(int n) {
    int sqrtN = std::sqrt(n);
    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            factor[++cnt] = i;
            if (i != n / i) factor[++cnt] = n/i;
        }
    }
    return;
}