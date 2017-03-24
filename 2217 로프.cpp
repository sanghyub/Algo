#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	int n; scanf("%d", &n);
	int Min = 20000,Max=0;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		Min = min(v.back(), Min);
		Max = max(Max, Min*i);
		v.pop_back();
	}
	printf("%d", Max);
}