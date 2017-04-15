#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) q.push(i);
	while (!q.empty()) {
		printf("%d ", q.front());
		if (!q.empty())q.pop();
		if (!q.empty())q.push(q.front());
		if(!q.empty())q.pop();
	}
}