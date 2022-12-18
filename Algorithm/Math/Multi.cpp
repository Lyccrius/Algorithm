#include <cstdio>

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        b >>= 1;
        a = (a * 2) % p;
    }
    return ans;
}