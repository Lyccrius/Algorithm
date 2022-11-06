#include <cstdio>
#include <cstring>

const int maxn = 1e8 + 10;

int minPrimeFactor[maxn];
int prime[maxn];
int cnt;

void primes(int n) {
    std::memset(minPrimeFactor, 0, sizeof(minPrimeFactor));
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (minPrimeFactor[i] == 0) {   //  i is a prime
            minPrimeFactor[i] = i;
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++) {
            if (prime[j] > minPrimeFactor[i] ||         //  prime[j] is greater than minPrimeFactor[i]
                prime[j] > n / i) break;                //  prime[j] * i > n
            minPrimeFactor[i * prime[j]] = prime[j];    //  prime[j] is minPrimeFactor of  i * prime[j]
        }
    }
    return;
}