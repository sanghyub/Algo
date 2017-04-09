#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v(1000001, 0);
int query(vector<int> &tree, int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

void update(vector<int> &tree, int i, int diff) {
	while (i <= tree.size()){
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		int q =  query(v,v.size()-1)-query(v, a);
		printf("%d\n", min(q+1,i));
		update(v, a, 1);
	}
}