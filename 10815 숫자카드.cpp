#include<cstdio>
#include<algorithm>
int a[500001];
using namespace std;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		int left = 0, right = n - 1;
		int flag = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] < k) {
				left = mid + 1;
			}
			else if (a[mid] > k) {
				right = mid - 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 1) printf("1 ");
		else printf("0 ");
	} 
}