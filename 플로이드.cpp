#include<cstdio>
#include<algorithm>
using namespace std;
int dist[101][101];
int main() {
	int n, m; scanf("%d%d",&n,&m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dist[i][j]= (i!=j ? 1 << 30 : 0);
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; scanf("%d%d%d",&u,&v,&w);
		dist[u][v] = min(dist[u][v], w);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(dist[i][k]!=1<<30) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}