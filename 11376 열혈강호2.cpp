#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_V 2002
#define INF 1<<30
using namespace std;
int c[MAX_V][MAX_V] = { 0 };
int f[MAX_V][MAX_V] = { 0 };
vector<int> adj[MAX_V];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		adj[n + m].push_back(i);
		adj[i].push_back(n + m);
		c[n + m][i] += 2;

		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			adj[i].push_back(n + a - 1);
			adj[n + a - 1].push_back(i);
			c[i][n + a - 1] += 1;
		}
	}
	for (int i = n; i < n + m; i++) {
		adj[i].push_back(n + m + 1);
		adj[n + m + 1].push_back(i);
		c[i][n + m + 1] += 1;
	}
	int total = 0;
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> q;
		q.push(n + m);
		while (!q.empty() && prev[n+m+1]==-1) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == n+m+1) break;
				}
			}	
		}
		if (prev[n + m + 1] == -1) break;
		int flow = INF;
		for (int i = n + m + 1; i != n + m; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] -f[prev[i]][i]);
		}
		for (int i = n + m + 1; i != n + m; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d", total);
}