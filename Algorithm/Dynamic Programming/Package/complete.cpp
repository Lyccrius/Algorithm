#include <cstdio>
#include <algorithm>

const int maxN = 1000 + 10;

int N, V;
int v[maxN], w[maxN];
int F[maxN];

int main() {
	scanf("%d%d", &N, &V);
	for (int i = 1; i <= N; i++) scanf("%d%d", &v[i], &w[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = v[i]; j <= V; j++) {
			F[j] = std::max(F[j], F[j - v[i]] + w[i]);
		}
	}
	printf("%d\n", F[V]);
	return 0;
}