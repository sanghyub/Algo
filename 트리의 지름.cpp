#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;
vector<pair<int, int>> tree[10001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		tree[u].push_back(make_pair(v, w));
		tree[v].push_back(make_pair(u, w));
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		queue<pair<int,int>> q;
		bool visit[10001];
		memset(&visit, false, sizeof(visit));
		visit[i] = true;
		for (int j = 0; j < tree[i].size(); j++) {
			q.push(make_pair(tree[i][j].first,tree[i][j].second));
			visit[tree[i][j].first] = true;
		}
		while (!q.empty()) {
			int cur = q.front().first;
			int weight = q.front().second;
			q.pop();
			for (int k = 0; k < tree[cur].size(); k++) {
				if (visit[tree[cur][k].first] == true) continue;
				Max = max(tree[cur][k].second + weight, Max);
				q.push(make_pair(tree[cur][k].first, tree[cur][k].second+weight));
				visit[tree[cur][k].first] = true;
			}
		}
	}
	printf("%d", Max);
}