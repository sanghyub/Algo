#include<cstdio>
int main() {
	int m, n; scanf("%d%d", &m, &n);
	int x = 0, y = 0,dir = 0;
	for (int i = 0; i < n; i++) {
		char command[5]; scanf("%s",command);
		if (command[0] == 'T') {
			int d; scanf("%d", &d);
			if (d == 0) {
				if (dir - 1 < 0) dir = 3;
				else dir -= 1;
			}
			else dir = (dir + 1) % 4;
		}
		else {
			int d; scanf("%d", &d);
			if (dir == 0) x += d;
			else if (dir == 1) y -= d;
			else if (dir == 2) x -= d;
			else if (dir == 3) y += d;
		}
		if (x<0 || x>m || y<0 || y>m) {
			printf("-1");
			return 0;
		}
	}
	printf("%d %d", x, y);
}