#include<cstdio>
int arr[14];
int result[7];
int n;

void solve(int start, int cnt) {
	if (cnt > 7) return;
	else if (cnt == 7) {
		for (int i = 1; i <= 6; i++) printf("%d ", result[i]);
		printf("\n");
		return ;
	}
	else {
		for (int i = start; i <= n; i++) {
			result[cnt] = arr[i];
			solve(i + 1, cnt + 1);
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n - 5; i++) {
			result[1] = arr[i];
			solve(i+1, 2);
		}
		printf("\n");
	}
}