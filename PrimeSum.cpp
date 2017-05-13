#include<cstdio>
int main() {
	int n, m; scanf("%d%d", &n, &m);
	long long sum = 0;
	for (int i = n; i <= m; i++) {
		int k = i;
		int flag = 0;
		for (int j = 2; j*j <= k; j++) {
			if (k%j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) sum += i;
	}
	if (sum == 0) printf("-1");
	else printf("%lld", sum);
}