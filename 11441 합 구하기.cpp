#include<cstdio>
#include<vector>
using namespace std; 

int query(vector<int> &tree, int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}
void update(vector<int> &tree, int i, int diff) {
	while (i <= tree.size()) {
		tree[i] += diff;
		i += (i&-i);
	}
}

int main() {
	vector<int> tree(100001);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		update(tree,i, a);
	}
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", query(tree, b) - query(tree, a - 1));
	}
}