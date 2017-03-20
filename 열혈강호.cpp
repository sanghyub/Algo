#include<vector>
#include<cstdio>
#include<algorithm>
#define MAX_V 1100
using namespace std;
vector<int> adj[MAX_V];
bool visited[MAX_V];
int A[MAX_V], B[MAX_V];
bool dfs(int a) {
	visited[a] = true;
	for (int i = 0; i < adj[a].size(); i++) {
		int next = adj[a][i];
		if (B[next] == -1 || !visited[B[next]] && dfs(B[next])) {
			A[a] = next;
			B[next] = a;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int a; scanf("%d", &a);
			adj[i].push_back(a - 1);
		}
	}
	int total = 0;
	fill(A, A + n, -1);
	fill(B, B + m, -1);
	for (int i = 0; i < n; i++) {
		if (A[i] == -1) {
			fill(visited, visited + n, false);
			if (dfs(i))total++;
		}
	}
	printf("%d", total);
}