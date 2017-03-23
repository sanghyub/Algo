#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int, int>> adj[10001];
queue<pair<int, int>> q;
bool visit[10001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	q.push(make_pair(1, 0));
	vector<int> dist(10001, 0);
	dist[1] = 0;
	visit[1] = true;
	int Max = 0;
	int MaxIndex;
	while (!q.empty()) {
		int cur = q.front().first;
		int weight = q.front().second;
		q.pop();
		visit[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int w = adj[cur][i].second;
			if (visit[next] == false) {
				q.push(make_pair(next, w));
				if (dist[next] < dist[cur] + w) {
					dist[next] = dist[cur] + w;
					if (Max < dist[next]) {
						Max = dist[next];
						MaxIndex = next;
					}
				}
			}
		}
	}
	memset(&visit, false, sizeof(visit));
	memset(&dist, 0, sizeof(dist));
	dist.resize(10001);
	q.push(make_pair(MaxIndex, 0));
	while (!q.empty()) {
		int cur = q.front().first;
		visit[cur] = true;
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int weight = adj[cur][i].second;
			if (visit[next] == false) {
				q.push(make_pair(next, weight));
				if (dist[next] < dist[cur] + weight) {
					dist[next] = dist[cur] + weight;
					Max = max(Max, dist[next]);
				}
			}
		}
	}
	printf("%d", Max);
}