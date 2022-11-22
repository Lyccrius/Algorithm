#include <cstdio>
#include <algorithm>

const int maxN = 1000 + 10;

int N;
int A[maxN];
int F[maxN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++) {
		F[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) F[i] = std::max(F[i], F[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = std::max(ans, F[i]);
	printf("%d\n", ans);
	return 0;
}