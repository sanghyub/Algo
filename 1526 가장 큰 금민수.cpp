#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	for (int i = n; i >= 4; i--) {
		int k = i;
		int flag = 0;
		while (k > 0) {
			if (k % 10 == 7 || k % 10 == 4) {
				k /= 10;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			printf("%d", i);
			return 0;
		}
	}
}