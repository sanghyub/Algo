#include <cstdio>
int main() {
	int arr[1001][10], result = 0;
	int n; scanf("%d", &n);
	for (int i = 0; i < 10; i++) arr[1][i] = 1;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			int sum = 0;
			for (int k = 0; k <= j; k++) {
				sum += arr[i - 1][k];
				sum %= 10007;
			}
			arr[i][j] = sum;
		}
	}
	for (int i = 0; i <= 9; i++) {
		result += arr[n][i];
		result %= 10007;
	}
	printf("%d", result);
}