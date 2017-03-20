#include <cstdio>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) q.push(i);
	printf("<");
	while (q.size() != 1) {
		for (int i = 0; i < m - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>",q.front());
}
