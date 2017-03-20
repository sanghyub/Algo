#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
vector<pair<int, int>> adj[1001];
int main() {
	int n, m, x; scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> dist(1001, 1 << 30);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dist[i] = 0;
		pq.push(make_pair(dist[i], i));
		while (!pq.empty()) {
			int d = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int j = 0; j < adj[cur].size(); j++) {
				int next = adj[cur][j].first;
				int weight = adj[cur][j].second;
				if (dist[next] > dist[cur] + weight) {
					dist[next] = dist[cur] + weight;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		int temp = dist[x];
		fill(dist.begin(), dist.end(), 1 << 30);
		dist[x] = 0;
		pq.push(make_pair(dist[x], x));
		while (!pq.empty()) {
			int d = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int j = 0; j < adj[cur].size(); j++) {
				int next = adj[cur][j].first;
				int weight = adj[cur][j].second;
				if (dist[next] > dist[cur] + weight) {
					dist[next] = dist[cur] + weight;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		temp += dist[i];
		Max = max(Max, temp);
	}
	printf("%d", Max);
}