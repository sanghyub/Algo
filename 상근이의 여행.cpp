#include<cstdio>
int main() {
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) { int u, v; scanf("%d%d", &u, &v);}
		printf("%d\n", n - 1);
	}
}