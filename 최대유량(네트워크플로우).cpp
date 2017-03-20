#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX_V = 52;
const int INF = 1 << 30;

int ctoi(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	int n; scanf("%d", &n);
	int c[MAX_V][MAX_V] = { 0, };
	int f[MAX_V][MAX_V] = { 0, };
	vector<int> adj[MAX_V];
	for (int i = 0; i < n; i++) {
		char u, v;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		u = ctoi(u); v = ctoi(v);
		c[u][v] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int total = 0, s = ctoi('A'), e = ctoi('Z');

	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == e) break;
				}
			}
		}
		if (prev[e] == -1) break;

		int flow = INF;
		for (int i = e; i != s; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}