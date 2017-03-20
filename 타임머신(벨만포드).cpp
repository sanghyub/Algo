#include<cstdio>
#include<vector>
using namespace std;
vector< pair <int, int> > graph[501];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}
	bool minusCycle = false;
	vector<int> dist(501, 1 << 30);
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int next = graph[j][k].first;
				int weight = graph[j][k].second;
				if (dist[j] != 1 << 30 && dist[next] > dist[j] + weight) {
					dist[next] = dist[j] + weight;
					if (i == n) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle)printf("-1");
	else {
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] != 1 << 30 ? dist[i] : -1);
	}
}