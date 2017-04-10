#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int query(vector<int> &tree, int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i&-i);
	}
	return sum;
}

void update(vector<int> &tree, int i, int diff) {
	while (i <= tree.size()) {
		tree[i] += diff;
		i += (i&-i);
	}
}

vector<int> tree(1148600);
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int a; scanf("%d", &a);
			update(tree, n*i + j, a);
		}
	}
	for (int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		if (k == 0) {
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			int q = query(tree, (x - 1)*n + y)-query(tree,(x-1)*n+y-1);
			int diff = c-q;
			update(tree, (x-1)*n+y, diff);
		}
		else {
			int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			long long result = 0;
			for (int j = x1; j <= x2; j++) {
				result += query(tree, (j - 1)*n + y2) - query(tree, (j - 1)*n + y1 - 1);
			}
			printf("%lld\n", result);
		}
	}
}