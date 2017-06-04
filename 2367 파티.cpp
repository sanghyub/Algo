#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_V 302
#define INF 1<<30
vector<int> adj[MAX_V];
int cap[MAX_V][MAX_V] = {0};
int flow[MAX_V][MAX_V] = {0};

int main() {
	int n, k, d; scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		cap[0][i] += k;
	}

	for (int i = n + 1; i <= n + d; i++) {
		int a; scanf("%d", &a);
		adj[i].push_back(n + d + 1);
		adj[n+d+1].push_back(i);
		cap[i][n + d + 1] += a;
	}

	for (int i = 1; i <= n; i++) {
		int a; scanf("%d" ,&a);
		for (int j = 0; j<a; j++) {
			int b; scanf("%d", &b);
			adj[i].push_back(n + b);
			adj[n + b].push_back(i);
			cap[i][n+b] += 1;
		}
	}

	int result = 0;
	int source = 0, sink = n + d + 1;

	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> q;
		q.push(source);
		while (!q.empty() && prev[sink] == -1) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (cap[cur][next] - flow[cur][next] > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = cur;
					if (next == sink) break;
				}
			}
		}
		if (prev[sink] == -1) break;
		int minflow = INF;
		for (int i = sink; i != source; i = prev[i]) {
			minflow = min(minflow, cap[prev[i]][i] - flow[prev[i]][i]);
		}
		for (int i = sink; i != source; i = prev[i]) {
			flow[prev[i]][i] += minflow;
			flow[i][prev[i]] -= minflow;
		}
		result += minflow;
	}
	printf("%d\n", result);
}
