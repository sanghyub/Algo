#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		vector<int>::iterator low, hi;
		low=lower_bound(a.begin(), a.end(),k);
		hi = upper_bound(a.begin(), a.end(), k);
		printf("%d ", hi - low);
	}
}