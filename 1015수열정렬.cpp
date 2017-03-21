#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<pair<int, int>> v;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;  scanf("%d", &k);
		v.push_back(make_pair(k, i));
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>> p;
	for (int i = 0; i < v.size(); i++) {
		p.push_back(make_pair(v[i].second, i));
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) {
		printf("%d ", p[i].second);
	}
}