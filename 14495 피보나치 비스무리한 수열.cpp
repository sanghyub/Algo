#include<cstdio>
long long arr[120];
int main() {
	arr[1] = arr[2] = arr[3]=1;
	for (int i = 4; i <= 116; i++) arr[i] = arr[i - 1] + arr[i - 3];
	int n; scanf("%d", &n);
	printf("%lld", arr[n]);
}