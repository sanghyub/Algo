#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	int k, k35;
	k35 = k =n;
	int sum = 0;
	if (k % 5 == 0) {
		printf("%d", k / 5);
		return 0;
	}
	while (k35>=0) {
		k35 -= 3;
		sum += 1;
		if (k35 % 5 == 0) {
			printf("%d", sum + k35 / 5);
			return 0;
		}
	}
	if (k % 3 == 0) {
		printf("%d", k / 3);
		return 0;
	}
	printf("-1");

}