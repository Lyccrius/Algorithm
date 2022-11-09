#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n < 2) return false;
    int sqrtX = std::sqrt(n);
    for (int i = 2; i <= sqrtN; i++) if (n % i == 0) return false;
    return true;
}