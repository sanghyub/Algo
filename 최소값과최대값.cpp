#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void init(vector<int>&arr,vector<pair<int, int>> &tree, int node, int start, int end) {
	if (start == end) {
		 tree[node] = make_pair(arr[start],arr[end]);
	}
	else {
		int Min, Max;
		init(arr, tree, node * 2, start, (start + end) / 2);
		init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node].first = min(tree[node * 2].first, tree[node * 2].first);
		tree[node].second = max(tree[node * 2].second, tree[node * 2].second);
	}
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int i, int j) {
	if (start>j || end<i) return make_pair(-1, -1);
	if (start >= i&&end <= j) return tree[node];
	pair<int, int> m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	pair<int, int> m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1.first == -1)return m2;
	if (m2.first == -1)return m1;
	return make_pair(min(m1.first, m2.first), max(m1.second, m2.second));
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> arr(n+1);
	int h = ceil(log2(n));
	int tree_size = 1 << h + 1;
	vector<pair<int, int>> tree(tree_size);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	init(arr, tree, 1, 0, n-1);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d %d\n", query(tree, 1, 0, n-1, a-1, b-1).first, query(tree, 1, 0, n-1, a-1, b-1).second);
	}

}