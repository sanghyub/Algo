#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
bool visit[100][100];
char a[101][101];
int arr1[101][101], arr2[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", a[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'R') {
				arr1[i][j] = 0;
				arr2[i][j] = 0;
			}
			else if (a[i][j] == 'G') {
				arr1[i][j] = 1;
				arr2[i][j] = 0;
			}
			else {
				arr1[i][j] = 2;
				arr2[i][j] = 1;
			}
		}
	}
	queue<pair<int,int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
				cnt++;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nextY = y + dir[k][0];
						int nextX = x + dir[k][1];
						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && visit[nextY][nextX] == false && arr1[y][x] == arr1[nextY][nextX]) {
							visit[nextY][nextX] = true;
							q.push(make_pair(nextY, nextX));
						}
					}
				}
			}
		}
	}
	printf("%d ", cnt);
	memset(&visit, false, sizeof(visit));
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
				cnt++;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nextY = y + dir[k][0];
						int nextX = x + dir[k][1];
						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && visit[nextY][nextX] == false && arr2[y][x] == arr2[nextY][nextX]) {
							visit[nextY][nextX] = true;
							q.push(make_pair(nextY, nextX));
						}
					}
				}
			}
		}
	}
	printf("%d", cnt);

}