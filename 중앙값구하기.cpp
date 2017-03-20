#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d",&n);
		int arr[10000];
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		printf("%d\n", n / 2 + 1);
		for (int i = 1; i <= n; i += 2) {
			sort(arr + 1, arr + 1 + i);
			printf("%d ", arr[i / 2 + 1]);
		}
		printf("\n");
	}
}