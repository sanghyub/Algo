#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = min(init(a, tree, node * 2, start, (start + end) / 2), init(a, tree, node * 2+1, (start + end) / 2 + 1, end));
	}
}

long long query(vector<long long>&tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INF;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return min(query(tree, node * 2, start, (start + end) / 2, left, right), query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size(1 << (h + 1));
	vector<long long> tree(tree_size);
	
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	init(a, tree, 1, 0, n - 1);

	for (int i = 0; i < m; i++) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%lld\n", query(tree, 1, 0, n - 1, l - 1, r - 1));
	}

}