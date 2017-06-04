#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_V 400
#define INF 1<<30
bool visited[MAX_V];

bool bfs(int graph[MAX_V][MAX_V], int s, int t, int parent[]) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	visited[s] = true; parent[s] = -1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v = 0; v < MAX_V; v++) {
			if (visited[v] == false && graph[u][v] > 0) {
				q.push(v); parent[v] = u; visited[v] = true;
			}
		}
	}
	return visited[t] = true;
}

int fordFulkerson(int (*graph)[MAX_V], int s, int t) {
	int u, v;
	int rGraph[MAX_V][MAX_V];
	for (u = 0; u < MAX_V; u++) {
		for (v = 0; v < MAX_V; v++) {
			rGraph[u][v] = graph[u][v];
		}
	}
	int parent[MAX_V];
	int max_flow = 0;

	while (bfs(rGraph, s, t, parent)) {
		int path_flow = INF;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v]; path_flow = min(path_flow, rGraph[u][v]);
		}
		for (v = t; v != s; v = parent[v]) {
			u = parent[v]; rGraph[u][v] -= path_flow; rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}
int graph[MAX_V][MAX_V];
int main() {
	memset(&graph, 0, sizeof(graph));
	int n, k, d; scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++) {
		graph[0][i] = k;
	}

	for (int i = n + 1; i <= n + d; i++) {
		int a; scanf("%d", &a);
		graph[i][n + d + 1] = a;
	}

	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int b; scanf("%d", &b);
			graph[i][n + b] += 1;
		}
	}
	printf("%d", fordFulkerson(graph, 0, n + d + 1));

}