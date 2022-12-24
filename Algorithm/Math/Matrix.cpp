#include <cstdio>
#include <cstring>

const int maxN = 1000 + 10;
const int maxM = 1000 + 10;

struct Matrix {
    int n, m;
    int a[maxN][maxM];

    void clear() {
        n = 0;
        m = 0;
        std::memset(a, 0, sizeof(a));
        return;
    }

    Matrix operator+(const Matrix &other) const {
        Matrix ret;
        ret.n = n;
        ret.m = m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                ret.a[i][j] = a[i][j] + other.a[i][j];
        return ret;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix ret;
        ret.n = n;
        ret.m = m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                ret.a[i][j] = a[i][j] - other.a[i][j];
        return ret;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix ret;
        ret.clear();
        ret.n = n;
        ret.m = other.m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= other.m; j++)
                for (int k = 1; k <= m; k++)
                    ret.a[i][j] += a[i][k] * other.a[k][j];
        return ret;
    }
};