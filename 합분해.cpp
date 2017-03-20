#include<cstdio>
int n, k;
long long dp[201][201];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
		dp[2][i] = i + 1;
	}

	for (int i = 3; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i - 1][j - l] % 1000000000;
				dp[i][j]%= 1000000000;
			}
		}
	}

	printf("%lld", dp[k][n] % 1000000000);
}