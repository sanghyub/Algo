#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int cToi(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}
int main() {
	vector<int> adj[52];
	int c[52][52] = { 0 };
	int f[52][52] = { 0 };
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char u, v;
		int w; scanf(" %c %c %d", &u, &v, &w);
		u = cToi(u), v = cToi(v);
		c[u][v] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int result = 0;
	int source = cToi('A');
	int sink = cToi('Z');

	while (1) {
		int prev[52];
		fill(prev, prev + 52, -1);
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == sink) break;
				}
			}
		}
		if (prev[sink] == -1) break;
		int flow = 987654321;
		for (int i = sink; i != source; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = sink; i != source; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		result += flow;
	}
	printf("%d\n", result);
}