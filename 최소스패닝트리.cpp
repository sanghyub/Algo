#include<cstdio>
#include<algorithm>
using namespace std;
int uf[10000];

struct Edge {
	int u, v, w;
	Edge() : Edge(-1,-1,0){}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1){}
	bool operator <(const Edge &O) const {
		return w < O.w;
	}
};

int find(int a){
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

Edge edge[100000];
int main() {
	int v, e; scanf("%d%d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		edge[i] = Edge(a - 1, b - 1, c);
	}
	sort(edge, edge + e);
	fill(uf, uf + v, -1);

	int result = 0, cnt = 0;
	for (int i = 0; ; i++) {
		if (merge(edge[i].u ,edge[i].v)) {
			result += edge[i].w;
			cnt++;
		}
		if (cnt == v - 1) break;
	}
	printf("%d", result);
}