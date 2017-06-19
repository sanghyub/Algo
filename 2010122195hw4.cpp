#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_V 130
#define INF 1<<30

vector<int> adj[MAX_V];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
bool visit[MAX_V];
int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];

int main() {
	char arr[12][12];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	int source = n*n + 1, sink = n*n + 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int black, white;
			black = i*n + j;
			if (i % 2 == j % 2) {
				adj[source].push_back(black);
				adj[black].push_back(source);
				adj[black].push_back(sink);

				cap[black][sink] = 1;
				cap[source][black] = 1;

				for (int k = 0; k < 4; k++) {
					int nextY = i + dir[k][0];
					int nextX = j + dir[k][1];
					if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;

					white = nextY*n + nextX;

					adj[black].push_back(white);
					adj[white].push_back(black);
					cap[black][white] = 1;

					if (arr[i][j] == 'A') {
						if (arr[nextY][nextX] == 'A') {
							cost[black][white] = -100;
							cost[white][black] = 100;
						}
						else if (arr[nextY][nextX] == 'B') {
							cost[black][white] = -70;
							cost[white][black] = 70;

						}
						else if (arr[nextY][nextX] == 'C') {
							cost[black][white] = -40;
							cost[white][black] = 40;
						}
					}

					else if (arr[i][j] == 'B') {
						if (arr[nextY][nextX] == 'A') {
							cost[black][white] = -70;
							cost[white][black] = 70;
						}
						else if (arr[nextY][nextX] == 'B') {
							cost[black][white] = -50;
							cost[white][black] = 50;

						}
						else if (arr[nextY][nextX] == 'C') {
							cost[black][white] = -30;
							cost[white][black] = 30;
						}
					}

					else if (arr[i][j] == 'C') {
						if (arr[nextY][nextX] == 'A') {
							cost[black][white] = -40;
							cost[white][black] = 40;

						}
						else if (arr[nextY][nextX] == 'B') {
							cost[black][white] = -30;
							cost[white][black] = 30;
						}
						else if (arr[nextY][nextX] == 'C') {
							cost[black][white] = -20;
							cost[white][black] = 20;
						}
					}
				}
			}
			adj[black].push_back(sink);
			adj[sink].push_back(black);
			cap[black][sink] = 1;
		}
	}
	
	int result = 0;
	while (1) {
		int prev[MAX_V], dist[MAX_V];
		fill(prev, prev + MAX_V, -1);
		fill(dist, dist + MAX_V, INF);
		fill(visit, visit + MAX_V, 0);
		dist[source] = 0;
		visit[source] = true;
		
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			visit[cur] = false;
			for (int i = 0; i<adj[cur].size(); i++) {
				int next = adj[cur][i];
				if (cap[cur][next] - flow[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
					dist[next] = dist[cur] + cost[cur][next];
					prev[next] = cur;

					if (visit[next] == false) {
						q.push(next);
						visit[next] = true;
					}
				}
			}
		}
		if (prev[sink] == -1) break;

		for (int i = sink; i != source; i = prev[i]) {
			flow[prev[i]][i] +=1;
			flow[i][prev[i]] -=1;
			result -= cost[prev[i]][i];
		}
	}
	printf("%d\n", result);
}