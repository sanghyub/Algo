#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> adj[100001];
bool visit[100001];
int parent[100001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < adj[front].size(); i++) {
			int next = adj[front][i];
			if (visit[next] == false) {
				parent[next] = front;
				q.push(next);
				visit[next] = true;
			}
		}
	}
	for (int i = 2; i <= n; i++) printf("%d\n", parent[i]);
}