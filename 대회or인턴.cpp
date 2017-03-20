#include<cstdio>
int main() {
	int n, m, k,Max=0; scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= m - i; j++) {
			if (j * 2 > n- (k - i)) break;
			if (Max < j) Max = j;
		}
	}
	printf("%d", Max);
}