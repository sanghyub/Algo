#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
vector<pair<int, int>> v[100000];
int main() {
	int t,n; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a, b; scanf("%d %d", &a, &b);
			v[i].push_back(make_pair(a, b));
		}
		sort(v, v + n);
		int cnt = 0;
		int min = 987654321;
		for (int i = 0; i < n; i++) {
			if (min > v[i][0].second) {
				min = v[i][0].second;
				cnt++;
			}
		}

		printf("%d\n", cnt);
		for (int i = 0; i < n; i++) {
			v[i].pop_back();
		}
	}
}