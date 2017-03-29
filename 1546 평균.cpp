#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	double arr[1001],Max=0,sum=0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
		if (Max < arr[i]) Max = arr[i];
	}
	for (int i = 0; i < n; i++) {
		sum += (arr[i] / Max)*100;
	}
	printf("%.2lf", sum / n);
}