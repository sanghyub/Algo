#include<cstdio>
int arr[8];
int main() {
	for (int i = 1; i <= 8; i++) scanf("%d", &arr[i]);
	int flag = 0;
	if (arr[1] == 1) {
		for (int i = 1; i <= 8; i++) {
			if (arr[i] != i) flag = 1;
		}
		if (flag == 0) {
			printf("ascending");
			return 0;
		}
	}
	else if (arr[1] == 8) {
		for (int i = 1; i <= 8; i++) {
			if (arr[i] != 9-i) flag = 1;
		}
		if (flag == 0) {
			printf("descending");
			return 0;
		}
	}
	printf("mixed");
}