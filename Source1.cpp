#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
struct MCMF {
	int n;
	struct Edge {
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev)
			:v(v), cost(cost), cap(cap), rev(rev) {}
	};
	vector<vector<Edge>> vt;
	void addEdge(int s, int e, int cost, int cap) {
		vt[s].emplace_back(e, cost, cap, vt[e].size());
		vt[e].emplace_back(s, -cost, 0, vt[s].size() - 1);
	}
	vector<int> pv, pe;
	MCMF(int n) :n(n) {
		vt.resize(n + 1);
		pv.assign(n + 1, -1);
		pe.assign(n + 1, -1);
	}
	bool spfa(int src, int sink) {
		queue<int> qu;
		vector<int> v(n + 1, 0);
		vector<int> dist(n + 1, INF);
		v[src] = 1;
		dist[src] = 0;
		qu.push(src);
		while (qu.size()) {
			int here = qu.front();
			qu.pop();
			v[here] = 0;
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i].v;
				int cap = vt[here][i].cap;
				if (cap&&dist[there] > dist[here] + vt[here][i].cost) {
					dist[there] = dist[here] + vt[here][i].cost;
					pv[there] = here;
					pe[there] = i;
					if (!v[there]) {
						v[there] = 1;
						qu.push(there);
					}
				}
			}
		}
		return dist[sink] != INF;
	}
	int solve(int src, int sink) {
		int cost = 0;
		while (spfa(src, sink)) {
			int minFlow = INF;
			for (int crt = sink; crt != src; crt = pv[crt]) {
				int prev = pv[crt];
				int idx = pe[crt];
				minFlow = min(minFlow, vt[prev][idx].cap);
			}
			for (int crt = sink; crt != src; crt = pv[crt]) {
				int prev = pv[crt];
				int idx = pe[crt];
				vt[prev][idx].cap -= minFlow;
				vt[crt][vt[prev][idx].rev].cap += minFlow;
				cost += vt[prev][idx].cost*minFlow;
			}
		}
		return -cost;
	}
};
int n;
char a[12][12];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool chk(int x, int y) {
	return 0 <= x&&x < n && 0 <= y&&y < n;
}
int getP(int x, int y, int z, int w) {
	if (a[x][y] > a[z][w]) {
		swap(x, z);
		swap(y, w);
	}
	if (a[x][y] == 'A') {
		if (a[z][w] == 'A')return 100;
		else if (a[z][w] == 'B')return 70;
		else if (a[z][w] == 'C')return 40;
		else return 0;
	}
	else if (a[x][y] == 'B') {
		if (a[z][w] == 'B')return 50;
		else if (a[z][w] == 'C')return 30;
		else return 0;
	}
	else if (a[x][y] == 'C') {
		if (a[z][w] == 'C')return 20;
		else return 0;
	}
	else return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < n; j++)
			scanf("%c", &a[i][j]);
	}
	MCMF mcmf(n*n + 3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i % 2 && j % 2) || (!(i % 2) && !(j % 2))) {
				mcmf.addEdge(n*n + 1, i*n + j, 0, 1);
				mcmf.addEdge(i*n + j, n*n + 2, 0, 1);
				for (int k = 0; k < 4; k++) {
					int cx = i + dx[k];
					int cy = j + dy[k];
					if (!chk(cx, cy))continue;
					int point = getP(i, j, cx, cy);
					mcmf.addEdge(i*n + j, cx*n + cy, -point, 1);
				}
			}
			else
				mcmf.addEdge(i*n + j, n*n + 2, 0, 1);
		}
	}
	printf("%d\n", mcmf.solve(n*n + 1, n*n + 2));
	return 0;
}

