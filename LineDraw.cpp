#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	int sum = 0;
	for (int j = 2; j < 2*n; j++) {
		sum+=(2*n - j)*(j - 2);
	}
	printf("%d", sum);
}