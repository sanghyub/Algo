#include<cstdio>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int arr[11];
		int n; scanf("%d", &n);
		int Max = 0;
		int sum = 0;
		int MaxIdx = -1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
			if (Max < arr[i]) {
				Max = arr[i];
				MaxIdx = i;
			}
		}
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] == Max && i != MaxIdx) {
				flag = 1;
			}
		}
		if (flag == 1) printf("no winner\n");
		else if (Max > sum / 2) printf("majority winner %d\n", MaxIdx);
		else if(Max<= sum/2) printf("minority winner %d\n", MaxIdx);
	}
}