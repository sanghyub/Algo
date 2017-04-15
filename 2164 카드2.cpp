#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		if (q.size() == 1) {
			printf("%d", q.front());
			return 0;
		}
		q.pop();
		if (q.size() == 1) {
			printf("%d", q.front());
			return 0;
		}
		q.push(q.front());
		q.pop();
	}
}