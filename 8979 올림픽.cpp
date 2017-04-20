#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
#include<tuple>
using namespace std;
int main() {
	vector<tuple<int, int, int, int>> v;
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &d, &a, &b, &c);
		v.push_back(make_tuple(a, b, c, d));
	}
	sort(v.begin(), v.end(),greater<tuple<int,int,int,int>>());
	int index = 0;
	for(int i=0; i<v.size(); i++) {
		if (get<3>(v[i]) == k) {
			index = i;
		}
	}
	int cnt = 0;
	for (int i = 0; i < index; i++) {
		if (get<0>(v[i]) == get<0>(v[index]) && get<1>(v[i]) == get<1>(v[index]) && get<2>(v[i]) == get<2>(v[index])) break;
		cnt++;
	}
	printf("%d", cnt+1);
}