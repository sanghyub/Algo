#include<cstdio>
#include<vector>
using namespace std;
long long query(vector<int> &tree, int start) {
	long long ans=0;
	while (start > 0) {
		ans += tree[start];
		start -= (start & -start);
	}
	return ans;
}

void update(vector<int> &tree, int start, int diff) {
	while (start <= tree.size()) {
		tree[start] += diff;
		start += (start & -start);
	}
}

int main() {
	int n; scanf("%d", &n);
	vector<int> tree(100001,0);
	for (int i = 1; i <= n; i++) {
		long long Lquery = 0, Rquery = 0;
		int L, R;
		scanf("%d%d", &L, &R);
		Lquery = query(tree, L);
		Rquery = query(tree, R);
		printf("%lld\n", Lquery+Rquery);

		update(tree,L, -Lquery); 
		update(tree,L + 1, Lquery);
		update(tree,R, -Rquery); 
		update(tree,R + 1, Rquery);
		update(tree, L+1, 1);
		update(tree, R, -1);
	}
}