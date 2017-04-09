#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll val;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = ((init(arr, tree, node * 2, start, (start + end) / 2) % MOD) * (init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end) % MOD)) % MOD;
}

ll update(vector<ll> &tree, int node, int start, int end, int index)
{ 
	if (!(start <= index && index <= end))
		return tree[node];
	if (start == end)
		return tree[node] = val;
	return tree[node] = (update(tree, node * 2, start, (start + end) / 2, index) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index)) % MOD;
}

ll mul(vector<ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return (mul(tree, node * 2, start, (start + end) / 2, left, right) * mul(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;
}
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<ll> arr(n);
	vector<ll> tree(tree_size);
	for (int i = 0; i < n; i++)scanf("%lld", &arr[i]);
	init(arr, tree, 1, 0, n - 1);
	m += k;
	while (m--)
	{
		int get;
		scanf("%d", &get);
		if (get == 1){
			int pos;
			scanf("%d %lld", &pos, &val);
			update(tree, 1, 0, n - 1, pos - 1);
		}
		else if (get == 2){
			int left, right;
			scanf("%d %d", &left, &right);
			printf("%lld\n", mul(tree, 1, 0, n - 1, left - 1, right - 1) % MOD);
		}
	}
	return 0;
}
