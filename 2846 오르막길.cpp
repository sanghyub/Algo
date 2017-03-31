#include<cstdio>
int main() {
	int Max=0, high=0;
	int n; scanf("%d", &n);
	int arr[1001];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			high += arr[i] - arr[i-1];
			if (Max < high) Max = high;
		}
		else high = 0;
	}
	printf("%d", Max);
}