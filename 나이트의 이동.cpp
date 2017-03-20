#include<cstdio>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
int dir[8][2] = { {-1,2},{-2,1},{1,2},{2,1},{-2,-1},{-1,-2},{2,-1},{1,-2}};
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, sx, sy, x, y;
		bool visit[300][300];
		int arr[300][300];
		queue<pair<int, int>> q;
		memset(&visit, false, sizeof(visit));
		memset(&arr, 0, sizeof(arr));
		scanf("%d%d%d%d%d", &n, &sy, &sx, &y, &x);
		if (sy == y && sx == x) {
			printf("0\n");
			continue;
		}
		q.push(make_pair(sy, sx));
		visit[sy][sx] = true;
		while (!q.empty()) {
			int Y = q.front().first;
			int X = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nextY = Y + dir[i][0];
				int nextX = X + dir[i][1];
				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && visit[nextY][nextX] == false) {
					q.push(make_pair(nextY, nextX));
					arr[nextY][nextX] = arr[Y][X] + 1;
					visit[nextY][nextX] = true;
					if (nextY == y && nextX == x) {
						printf("%d\n", arr[nextY][nextX]);
						while (!q.empty()) q.pop();
						break;
					}
				}
			}
		}
	}
}