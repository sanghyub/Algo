#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[10000];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	long long a; scanf("%lld", &a);
	sort(arr, arr + n);
	long long Max = 0;
	long long left = 0;
	long long right = arr[n - 1];
	while (left <= right) {
		long long middle = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (middle < arr[i]) sum += middle;
			else sum += arr[i];
		}

		if (a >=sum) {
			if (Max < middle) Max = middle;
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	printf("%lld", Max);
}