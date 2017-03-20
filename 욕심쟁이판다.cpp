#include<cstdio>
#define max(a,b) ((a)>(b) ? (a) : (b))
int n,Max = 0;
int arr[500][500], dp[500][500];
int dir[4][2] = { {-1,0},{ 1,0 } ,{ 0,-1 } ,{ 0,1 } }; 

int solve(int y, int x) {
	if (dp[y][x] == 1) {
		for (int i = 0; i < 4; i++) {
			int nextY = y + dir[i][0];
			int nextX = x + dir[i][1];
			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (arr[y][x] > arr[nextY][nextX]) {
				dp[y][x] = max(dp[y][x], solve(nextY, nextX) + 1);
			}
		}
	}
	return dp[y][x];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) dp[i][j] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) Max=max(Max,solve(i, j));
		
	}
	printf("%d", Max);
}