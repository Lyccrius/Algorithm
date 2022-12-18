#include <cstdio>

long long pow(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}