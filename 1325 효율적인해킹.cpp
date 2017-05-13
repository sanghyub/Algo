#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[10010];
int Max = 0;
int num[10010] = { 0 };
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		bool visit[10001];
		fill(visit, visit + 10001, false);
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < adj[cur].size(); j++) {
				int next = adj[cur][j];
				if (visit[next] == false) {
					q.push(next);
					num[i]++;
					visit[next] = true;
				}
			}
		}
		if (num[i] > Max)Max = num[i];
	}
	if (Max == 0) return 0;

	for (int i = 1; i <= n; i++) {
		if (Max == num[i]) printf("%d ", i);
	}
}