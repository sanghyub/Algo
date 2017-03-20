#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[10001];
int main() {
	long long n, k; scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	long long left = 0, right = arr[n - 1];
	long long Max = 0;
	while (left <= right) {
		long long middle = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += arr[i] / middle;
		}
		if (cnt < k) {
			right = middle - 1;
		}
		else {
			if (Max < middle) Max = middle;
			left = middle + 1;
		}
	}
	printf("%lld", Max);
}