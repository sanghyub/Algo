#include<cstdio>
#include<queue>
using namespace std;
int dir[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int arr[1001][1001];
bool visit[1001][1001] = { false, };
int main() {
	queue<pair<int, int>> q;
	int m, n; scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		char s[1001]; scanf("%s", s);
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
			if (i == 0 && arr[i][j] == 0) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> xy = q.front();
		q.pop();
		visit[xy.first][xy.second] = true;
		for (int i = 0; i < 4; i++) {
			int nextY = xy.first + dir[i][0];
			int nextX = xy.second + dir[i][1];

			if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n && visit[nextY][nextX] == false && arr[nextY][nextX] == 0) {
				q.push(make_pair(nextY, nextX));
				visit[nextY][nextX] = true;
			}
		}
	}
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (visit[m - 1][i] == true) flag = 1;
	}
	if (flag == 1) printf("YES");
	else printf("NO");
}