#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_V = 500;
const int INF = 1<<30;
vector<int> adj[MAX_V];
int c[MAX_V][MAX_V] = { 0 };
int f[MAX_V][MAX_V] = { 0 };
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		adj[n + m].push_back(i);
		adj[i].push_back(n + m);
		c[n + m][i] ++;
		for (int j = 0; j < k; j++) {	
			int a; scanf("%d", &a);
			c[i][a+n-1] ++;
			adj[i].push_back(a+n-1);
			adj[a+n-1].push_back(i);
		}
	}
	for (int j = n; j < n + m; j++) {
		c[j][n + m + 1] ++;
		adj[j].push_back(n + m + 1);
		adj[n + m + 1].push_back(j);
	}
	int total = 0;
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + n+m+2, -1);
		queue<int> q;
		q.push(n + m);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == n + m + 1) break;
				}
			}
		}
		if (prev[n + m + 1] == -1) break;
		int flow = INF;
		for (int i = n + m + 1; i != n + m; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}
		for (int i = n + m + 1; i != n + m; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}