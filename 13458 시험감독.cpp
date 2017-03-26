#include<cstdio>
#include<cmath>
int arr[1000000];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int b, c; scanf("%d%d", &b, &c);
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
			arr[i] -= b;
			cnt++;
			if (arr[i] > 0) cnt += ceil(arr[i] / (double)c);
	}
	printf("%lld", cnt);
}