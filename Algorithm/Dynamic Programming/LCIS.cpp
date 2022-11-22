#include <cstdio>
#include <algorithm>

const int maxN = 3000 + 10;

int N;
int A[maxN];
int B[maxN];
int F[maxN][maxN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
	for (int i = 1; i <= N; i++) {
		int val = 0;
		for (int j = 1; j <= N; j++) {
			if (A[i] == B[j]) F[i][j] = val + 1;
			else F[i][j] = F[i - 1][j];
			if (A[i] > B[j]) val = std::max(val, F[i - 1][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = std::max(ans, F[N][i]);
	printf("%d\n", ans);
	return 0;
}