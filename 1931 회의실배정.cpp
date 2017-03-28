#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <pair<int, int>> v;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		v.push_back(make_pair(b, a));
	}
	sort(v.begin(), v.end());

	int Max = v[0].first;
	int cnt = 1;
	for (int i = 1; i<v.size(); i++) {
		if (v[i].second >= Max) {
			cnt++;
			Max = v[i].first;
		}
	}
	printf("%d", cnt);
}