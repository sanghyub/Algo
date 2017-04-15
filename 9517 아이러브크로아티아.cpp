#include<cstdio>
int main() {
	int k, n; scanf("%d%d", &k, &n);
	int sum = 0;
	int result = -1;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int a; char c; scanf("%d %c", &a, &c);
		if (c == 'T') {
			sum += a;
			if (sum >= 210 && flag == 0) {
				result = k;
				flag = 1;
			}
			k += 1;
			if (k == 9) k = 1;
		}
		else {
			sum += a;
			if (sum >= 210 && flag == 0) {
				result = k;
				flag = 1;
			}
		}
	
	}
	printf("%d", result);
}