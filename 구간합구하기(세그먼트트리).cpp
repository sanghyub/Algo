#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node*2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	vector<long long> arr(n+1);
	int h = (int)ceil (log2(n));
	int tree_size = (1 << (h + 1));
	vector<long long>tree(tree_size);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	m += k;
	init(arr, tree, 1, 1, n);
	while (m--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if (a == 1) {
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, 1, n , b, diff);
		}
		else if(a==2) {
			printf("%lld\n", sum(tree, 1, 1, n, b, c));
		}
	}
}