#include<cstdio>
int main() {
	int m, n; scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		int k = i;
		bool sosu = false;
		for (int j = 2; j*j <= k; j++) {
			if (k%j == 0) { sosu = true; break; }
		}
		if (sosu == false) printf("%d\n", i);
	}
}