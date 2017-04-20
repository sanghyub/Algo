#include <cstdio>
#include <deque>
using namespace std;
deque<pair<int, int>> q;
pair<int, int> p;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		q.push_back(make_pair(i, a));
	}
	int pos = 0, target, a;
	p = q.front();
	q.pop_front();
	printf("%d", p.first);
	target = p.second;
	while (!q.empty()) {
		pos = 0;
		if (target>0) {
			while (++pos < target) {
				p = q.front(); q.pop_front();
				q.push_back(p);
			}
			p = q.front(); q.pop_front();
		}
		else {
			while (--pos > target) {
				p = q.back(); q.pop_back();
				q.push_front(p);
			}
			p = q.back(); q.pop_back();
		}
		a = p.first;
		target = p.second;
		printf(" %d", a);
	}
}
