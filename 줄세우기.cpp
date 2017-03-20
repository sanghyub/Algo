#include <cstdio>
int arr[1001], dp[1001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1>dp[i]) dp[i] = dp[j] + 1;
		}
	}
	int Max = 0;
	for (int i = 0; i < n; i++) if (Max < dp[i])Max = dp[i];
	printf("%d", Max);
}
