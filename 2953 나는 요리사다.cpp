#include<cstdio>
int arr[6][5];
int sum[6];
int MaxIdx = 1;
int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf("%d", &arr[i][j]);
			sum[i] += arr[i][j];
		}
		if (sum[i] > sum[MaxIdx]) MaxIdx = i;
	}
	printf("%d %d", MaxIdx, sum[MaxIdx]);
}