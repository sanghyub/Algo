#include<cstdio>
int main() {
	int Max = 0;
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int a, b; scanf("%d%d", &a, &b);
		sum += b - a;
		if (Max < sum) Max = sum;
	}
	printf("%d", Max);
}