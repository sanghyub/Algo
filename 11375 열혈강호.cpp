#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_V 2002
#define INF 1<<30
vector<int> adj[MAX_V];
int capacity[MAX_V][MAX_V] = { 0 };
int flow[MAX_V][MAX_V] = { 0 };
int main() {
	int n, m; scanf("%d%d",&n, &m);
	for (int i = 0; i < n; i++) {
		adj[i].push_back(n + m);
		adj[n + m].push_back(i);
		capacity[n+m][i] += 1;
	
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			adj[i].push_back(n + a - 1);
			adj[n + a - 1].push_back(i);
			capacity[i][n + a - 1] += 1;
		}
	}
	for (int i = n; i < n + m; i++) {
		adj[i].push_back(n + m + 1);
		adj[n + m + 1].push_back(i);
		capacity[i][n + m + 1] += 1;
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
				if (capacity[cur][next] - flow[cur][next] > 0 && prev[next]==-1) {
					q.push(next);
					prev[next] = cur;
					if (next == n + m + 1) break;
				}
			}	
		}
		if (prev[n + m + 1] == -1) break;
		int minflow = INF;
		for (int i = n + m + 1; i != n + m; i = prev[i]) {
			minflow = min(minflow, capacity[prev[i]][i] - flow[prev[i]][i]);
		}
		for (int i = n + m + 1; i!= n + m; i = prev[i]) {
			flow[prev[i]][i] += minflow;
			flow[i][prev[i]] -= minflow;
		}
		total += minflow;
	}
	printf("%d\n", total);
}