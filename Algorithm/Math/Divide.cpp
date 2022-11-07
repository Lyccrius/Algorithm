#include <cstdio>
#include <cmath>

const int maxn = 1e8 + 10;

int factor[maxn];
int frequence[maxn];
int cnt;

void divide (int n) {
    cnt = 0;
    int sqrtN = std::sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {   //  i is a prime factor of n
            factor[++cnt] = i;
            frequence[cnt] = 0;
            while (n % i == 0) {
                n /= i;
                frequence[cnt]++;
            }
        }
    }
    if (n > 1) {    //  n is a prime
        factor[++cnt] = n;
        frequence[cnt] = 1;
    }
    return;
}