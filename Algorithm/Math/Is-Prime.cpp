#include <cstdio>
#include <cmath>

bool isPrime(int x) {
    if (x < 2) return false;
    int sqrtX = std::sqrt(x);
    for (int i = 2; i <= sqrtX; i++) if (n % i == 0) return false;
    return true;
}