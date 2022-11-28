#include <cstdio>

const int maxN = 5e5 + 10;
const int maxM = 5e5 + 10;

int n, m;
int a[maxN];

struct BinaryIndexedTree {
	struct Node {
		int pre;
		int value;
	};

	Node node[maxN];

	void Build(int *array, int n) {
		for (int xNode = 1; xNode <= n; xNode++) {
			node[xNode].pre = node[xNode - 1].pre + array[xNode];
			node[xNode].value = node[xNode].pre - node[xNode - LowBit(xNode)].pre;
		}
		return;
	}

	int LowBit(int xNode) {
		return xNode & -xNode;
	}

	void Modify(int xNode, int value) {
		while (xNode <= n) {
			node[xNode].value += value;
			xNode += LowBit(xNode);
		}
		return;
	}

	int Query(int xNode) {
		int res = 0;
		while (xNode > 0) {
			res += node[xNode].value;
			xNode -= LowBit(xNode);
		}
		return res;
	}
};

BinaryIndexedTree BIT;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	BIT.Build(a, n);
	for (int i = 1; i <= m; i++) {
		int opt, x, y, k;
		scanf("%d", &opt);
		switch (opt) {
			case 1: {
				scanf("%d%d", &x, &k);
				BIT.Modify(x, k);
				break;
			}
			case 2: {
				scanf("%d%d", &x, &y);
				printf("%d\n", BIT.Query(y) - BIT.Query(x - 1));
				break;
			}
		}
	}
	return 0;
}