#include<cstdio>
#include<vector>
#include<list>
using namespace std;
vector<pair<int, int>> v;
list<int> lst;
list<int>::iterator iter;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		v.push_back(make_pair(i, a));
	}
	lst.push_back(v.back().first);
	v.pop_back();
	while (!v.empty()) {
		int cnt = 0;
		for (iter = lst.begin(); ;) {
			if (cnt == v.back().second) {
				lst.insert(iter, v.back().first);
				v.pop_back();
				break;
			}
			else {
				if (v.back().first < *iter) cnt++;
				iter++;
			}
		}
	}
	for (iter = lst.begin(); iter != lst.end(); iter++) printf("%d ", *iter);
}