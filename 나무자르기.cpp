#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[1000000];
int main() {
	long long n, m; scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	long long left = 0, right = arr[n - 1];
	long long Max = 0;
	
	while (left <= right) {
		long long middle = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (middle < arr[i]) sum += arr[i] - middle;
		}
		if (sum < m) {
			right = middle - 1;
		}
		else if (sum >= m) {
			if (Max<middle) Max = middle;
			left = middle + 1;
		}
	}
	printf("%lld", Max);
}