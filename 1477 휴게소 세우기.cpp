#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int arr[102];
	int n, m, l; scanf("%d%d%d", &n, &m, &l);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	arr[n + 1] = l;
	sort(arr, arr + n + 2);
	int left = 1;
	int right = 0;
	for (int i = 0; i <= n; i++) if (right < arr[i + 1] - arr[i]) right = arr[i + 1] - arr[i];
	int result = 1000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n + 1; i++) {
			int a = arr[i];
			while (a+mid < arr[i+1]) {
				cnt++;
				a += mid;
			}
		}
		if (cnt > m) {
			left = mid + 1;
		}
		else if (cnt <= m) {
			right = mid - 1;
			if (result > mid) result = mid;
		}
	}
	printf("%d", result);
}