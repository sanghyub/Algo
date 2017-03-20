#include<cstdio>
#include<algorithm>
using namespace std;
int man[1001];
int woman[1001];
int dp[1001][1001];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &man[i]);
	for (int j = 1; j <= m; j++) scanf("%d", &woman[j]);
	sort(man+1, man + n+1);
	sort(woman+1, woman + m+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) dp[i][j] = dp[i - 1][j - 1] + abs(man[i] - woman[j]);
			else if (i < j)dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i] - woman[j]), dp[i][j - 1]);
			else dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i] - woman[j]), dp[i-1][j]);
		}
	}
	printf("%d", dp[n][m]);
}