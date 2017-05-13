#include<cstdio>
#include<algorithm>
using namespace std;
int arr[11];
int result[11];
int n, m;
int res = 0;

void solve(int start, int cnt) {
	if (cnt > n) return;
	if (start == m) return;
	if (cnt == n) {
		int flag = 0;
		int hol = 0, jak = 0;
		for (int i = 0; i < m; i++) {
			if (result[i] % 2 == 0) jak++;
			else hol++;
		}
		if (hol >= 1 && jak >= 1) flag = 1;
		if (flag == 1) res++;
	}

	for (int i = start + 1; i < m; i++) {
		result[cnt] = arr[i];
		solve(i, cnt + 1);
		result[cnt] = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + m);
	for (int i = 0; i < m - n; i++) {
		result[i] = arr[i];
		solve(i,1);
	}
	printf("%d", res);
}