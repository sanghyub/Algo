#include<cstdio>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		double arr[1000];
		double sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &arr[i]);
			sum += arr[i];
		}
		double cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sum / n) cnt++;
		}
		printf("%.3lf%%\n", (cnt / n)*100);
	}
}