#include<cstdio>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
vector<pair<int, int>> adj[20001];
int main() {
	int V, E, S; scanf("%d%d%d", &V, &E, &S);
	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	vector<int> dist(20001, 1 << 30);
	dist[S] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0,S));

	while (!pq.empty()) {
		int d = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next= adj[cur][i].first;
			int weight = adj[cur][i].second;
			if (dist[next] > dist[cur] + weight) {
				dist[next] = dist[cur] + weight;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 1 << 30) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}