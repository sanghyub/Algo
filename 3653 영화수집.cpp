#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int sum(vector<int>&tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<int> &tree, int i, int diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<int> floor(200002);
		vector<int> tree(200002);
		for (int i = 1; i <= n; i++) {
			floor[i] = n - i + 1;
			update(tree, i, 1);
		}

		int next = n + 1;

		for (int i = 0; i < m; i++) {
			int k; scanf("%d", &k);
			printf("%d ", sum(tree, 200001) - sum(tree, floor[k]));
			update(tree, floor[k], -1);
			floor[k] = next++;
			update(tree, floor[k], 1);
		}
		printf("\n");
	}

}