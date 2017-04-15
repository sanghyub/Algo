#include<cstdio>
int arr[20];
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		char c;
		scanf("%d %c", &arr[i], &c);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n - i; j++) arr[j] = arr[j + 1] - arr[j];
	}
	for (int i = 0; i < n - k-1; i++) printf("%d,", arr[i]);
	printf("%d", arr[n - k-1]);
}