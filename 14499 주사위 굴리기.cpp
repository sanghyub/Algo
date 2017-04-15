#include<cstdio>
int arr[30][30];
int dice[7] = { 0 };
int main() {
	int n, m, x, y, k; scanf("%d%d%d%d%d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int right = 3;
	int down = 6;
	int front = 5;

	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		if (a == 1) {
			if (x + 1 < m) {
				x++;
				int temp = 7 - down;
				down = right;
				right = temp;
				if (arr[y][x] != 0) {
					dice[down] = arr[y][x];
					arr[y][x] = 0;
				}
				else {
					arr[y][x] = dice[down];
				}
				printf("%d\n", dice[7-down]);
			}
		}
		else if (a == 2) {
			if (x - 1 >= 0) {
				x--;
				int temp = 7 - right;
				right = down;
				down = temp;
				if (arr[y][x] != 0) {
					dice[down] = arr[y][x];
					arr[y][x] = 0;
				}
				else {
					arr[y][x] = dice[down];
				}
				printf("%d\n", dice[7-down]);
			}
		}
		else if (a == 3) {
			if (y - 1 >= 0) {
				y--;
				int temp = 7 - front;
				front = down;
				down = temp;
				if (arr[y][x] != 0) {
					dice[down] = arr[y][x];
					arr[y][x] = 0;
				}
				else {
					arr[y][x] = dice[down];
				}
				printf("%d\n", dice[7-down]);
			}
		}
		else if (a == 4) {
			if (y + 1 < n) {
				y++;
				int temp = 7 - down;
				down = front;
				front = temp;
				if (arr[y][x] != 0) {
					dice[down] = arr[y][x];
					arr[y][x] = 0;
				}
				else {
					arr[y][x] = dice[down];
				}
				printf("%d\n", dice[7-down]);
			}
		}
	}
}