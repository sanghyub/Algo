#include<cstdio>
#include<algorithm>
using namespace std;
int dist[1010][1010];
int main() {
	int n, m, x; scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1 << 29;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dist[i][x] + dist[x][i]);
	}
	printf("%d\n", Max);
}