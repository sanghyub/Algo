#include<cstdio>
#include<queue>
using namespace std;
int arr[1000][1000];
bool visit[1000][1000] = { false, };
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
queue<pair<int, int>> q;
int main() {
	int m, n; scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = y + dir[i][0];
			int nextX = x + dir[i][1];
			if (nextY >= 0 && nextY < n && nextX >= 0 &&nextX <m &&  arr[nextY][nextX]!=-1 && visit[nextY][nextX] == false) {
				q.push(make_pair(nextY, nextX));
				visit[nextY][nextX] = true;
				arr[nextY][nextX] = arr[y][x] + 1;
			}
		}
	}
	int max = 0, flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) flag = 1;
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	if (flag == 1) printf("-1");
	else printf("%d", max - 1);
}