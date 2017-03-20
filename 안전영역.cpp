#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;
int arr[100][100];
int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int Max = 0;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i <= 100; i++) {
		int cnt = 0;
		queue<pair<int, int>> q;
		bool visit[100][100];
		memset(&visit, false, sizeof(visit));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visit[j][k] == false) {
					if (arr[j][k] <= i) visit[j][k] = true;
					else {
						visit[j][k] = true;
						q.push(make_pair(j, k));
						cnt++;
						while (!q.empty()) {
							int y = q.front().first;
							int x = q.front().second;
							q.pop();
							for (int l = 0; l < 4; l++) {
								int nextY = y + dir[l][0];
								int nextX = x + dir[l][1];
								if (nextY >= 0 && nextY < n &&nextX >= 0 && nextX <n && visit[nextY][nextX] == false && arr[nextY][nextX]>i) {
									q.push(make_pair(nextY, nextX));
									visit[nextY][nextX] = true;
								}
							}
						}
					}
				}
			}
		}
		if (Max < cnt) Max = cnt;
	}	
	printf("%d", Max);
}	