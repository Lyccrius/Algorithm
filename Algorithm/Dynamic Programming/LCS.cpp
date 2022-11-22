#include <cstdio>
#include <algorithm>

const int maxN = 1000 + 10;

int N, M;
char A[maxN];
char B[maxN];
int F[maxN][maxN];

int main() {
	scanf("%d%d", &N, &M);
	scanf("%s", A);
	scanf("%s", B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			F[i][j] = std::max(F[i - 1][j], F[i][j - 1]);
			if (A[i] == B[j]) F[i][j] = std::max(F[i][j], F[i - 1][j - 1] + 1);
		}
	}
	printf("%d\n", F[N][M]);
	return 0;
}