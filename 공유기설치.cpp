#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[200000];
int n, c;
int main() {
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	long long left = 1;
	long long right = arr[n - 1];
	long long Max = 0;
	while (left <= right) {
		long long middle = (left + right) / 2;
		int cnt = 1;
		int index = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[index] >= middle) {
				index = i;
				cnt++;
			}
		}
		if(cnt >= c) {
			if (Max < middle) Max=middle;
			left = middle + 1;
		}
		else right = middle - 1;
	}
	printf("%lld", Max);
}