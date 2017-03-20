#include<cstdio>
#include<algorithm>
using namespace std;
int jadu[1002];
int dp[3][1002][32];
int main() {
	int T, W; scanf("%d%d",&T,&W);
	for (int i = 1; i <= T; i++) scanf("%d", &jadu[i]);
	
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			if (jadu[i] == 1) {
				dp[1][i][j] = max(dp[1][i][j], dp[1][i - 1][j] + 1);
				dp[1][i][j] = max(dp[1][i][j], dp[2][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[2][i][j], dp[1][i - 1][j - 1]);
				dp[2][i][j] = max(dp[2][i][j], dp[2][i - 1][j]);
			}
			else {
				dp[1][i][j] = max(dp[1][i][j], dp[1][i - 1][j]);
				dp[1][i][j] = max(dp[1][i][j], dp[2][i - 1][j - 1]);
				dp[2][i][j] = max(dp[2][i][j], dp[1][i - 1][j - 1] + 1);
				dp[2][i][j] = max(dp[2][i][j], dp[2][i - 1][j] + 1);
			}
		}
	}
	int Max = 0;
	for (int i = 0; i <= W; i++) {
		Max = max(Max, dp[1][T][i]);
		Max = max(Max, dp[2][T][i]);
	}
	printf("%d\n", Max);
}