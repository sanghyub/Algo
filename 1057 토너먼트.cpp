#include<cstdio>
int arr[100010];
int main() {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	if (n % 2 == 1) n += 1;
	for (int i = 1; i <= n; i++) {
		if (i == a || i==b) arr[i] = 1;
		else arr[i] = 0;
	}
	int flag = 0,cnt = 1;
	for (int i = 1; i<=n-1; i += 2) {
		if (arr[i] == 1 && arr[i+1]==1) {
			flag = 1;
			printf("%d", cnt);
			return 0;
		}
		else if (arr[i] == 1) arr[(i + 1) / 2] = 1;
		else if (arr[i + 1] == 1) {
			arr[(i + 1) / 2] = 1;
			arr[i + 1] = 0;
		}
		else if (arr[i] == 0 && arr[i + 1] == 0) arr[(i + 1) / 2] = 0;
		if (i == n - 1) {
			i = -1;
			n /= 2;
			if (n % 2 == 1) n += 1;
			cnt++;
		}
	}
	if (flag == 0) printf("-1");
}