#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int, int>> adj[501];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	bool minusCycle = false;
	vector<int> dist(501, 1 << 30);
	dist[1] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++) {
				int next = adj[j][k].first;
				int weight = adj[j][k].second;
				if (dist[j] != 1 << 30 && dist[next] > dist[j] + weight) {
					dist[next] = dist[j] + weight;
					if (i == n-1)minusCycle = true;
				}
			}
		}
	}

	if (minusCycle) printf("-1\n");
	else {
		for (int i = 2; i <= n; i++) {
			printf("%d\n", dist[i] != 1 << 30 ? dist[i] : -1);
		}
	}
}