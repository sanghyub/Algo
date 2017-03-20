#include<cstdio>
int arr[100000];
int left = 0, right, fst=0, Min = 987654321;
int main() {
	int n,m; scanf("%d%d", &n,&m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		right += arr[i];
		if (fst < arr[i]) fst = arr[i];
	}
	if (m == n) {
		printf("%d", fst);
		return 0;
	}
	while (left <= right) {
		int middle = (left + right) / 2;
		int index = 0, Max = 0, cnt = 0, flag = 0;
		for (int i = 0; i < n; i++) {
			if (flag == 1) break;
			int sum = 0;
			for (int j = index; j < n; j++) {
				sum += arr[j];
				if (sum > middle) {
					sum -= arr[j];
					index = j;
					cnt++;
					break;
				}
				if (j == n - 1) {
					cnt++;
					flag = 1;
					break;
				}
			}
			if (Max < sum) Max = sum;
		}
		if (cnt <= m) {
			if (Max < Min) Min = Max;
			right = middle - 1;
		}
		else if (cnt > m) left = middle + 1;
	}
	printf("%d", Min);
}