#include<cstdio>
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		int Max = 0;
		int k = i;
		for (int j = 2; j*j <= k; j++) {
			while (k%j == 0) {
				if (Max < j) Max = j;
				k /= j;
			}
		}
		if (k > 1) {
 			if (k > Max) Max = k;
		}
		if (Max <= m) cnt++;
	}
	printf("%d", cnt);
}