#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
long long arr[1000000];
int main() {
	long long x, n;
	while (scanf("%lld", &x) == 1) {
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
		x *= 10000000;
		sort(arr, arr + n);
		
		long long l1 = 0, l2 = 0;
		for (int i = 0; i < n; i++) {
				long long left = i+1;
				long long right = n - 1;
				while (left <= right) {
					long long middle = (left + right) / 2;
					if (arr[i] + arr[middle] <= x) {
						if (arr[i] + arr[middle] == x && arr[middle] - arr[i] >= l2 - l1  && i!=middle) {
							l1 = arr[i];
							l2 = arr[middle];
						}
						left = middle + 1;
					}
					else {
						right = middle - 1;
					}
				}
		}
		if(l1==0 && l2==0)printf("danger\n");
		else {
			printf("yes %lld %lld\n", l1, l2);
		}
		memset(&arr, 0, sizeof(arr));
	}
}