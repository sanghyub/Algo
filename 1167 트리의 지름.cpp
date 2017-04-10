#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<pair<int,int>> adj[100001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v; scanf("%d", &v);
		while (1) {
			int a, b; scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			adj[v].push_back(make_pair(a, b));
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	bool visit[100001];
	int distance[100001];
	memset(&distance, 0, sizeof(distance));
	memset(&visit, false, sizeof(visit));
	int Max = 0;
	int MaxIndex = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		visit[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int weight = adj[cur][i].second;

			if (visit[next] == false && distance[next] < distance[cur] + weight) {
				distance[next] = distance[cur] + weight;
				q.push(make_pair(next, distance[next]));
				if (distance[next] > Max) {
					Max = distance[next];
					MaxIndex = next;
				}
			}
		}
	}

	memset(&visit, false, sizeof(visit));
	memset(&distance, 0, sizeof(distance));
	q.push(make_pair(MaxIndex, 0));
	Max = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		visit[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int weight = adj[cur][i].second;
			if (visit[next] == false && distance[next] < distance[cur] + weight) {
				distance[next] = distance[cur] + weight;
				q.push(make_pair(next, distance[next]));
				if (distance[next] > Max) {
					Max = distance[next];
				}
			}
		}
	}
	printf("%d", Max);
}