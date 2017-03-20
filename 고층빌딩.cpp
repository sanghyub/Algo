#include<cstdio>
long long dp[101][101][101];
long long mod = 1000000007;
int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	dp[1][1][1] = dp[2][2][1] = dp[2][1][2] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] = ((dp[i - 1][j][k] % mod) * ((i - 2) % mod)) % mod;
				dp[i][j][k] += dp[i - 1][j - 1][k] % mod;
				dp[i][j][k] += dp[i - 1][j][k-1] % mod;
			}
		}
	}
	printf("%lld", dp[n][l][r] % mod);
}
