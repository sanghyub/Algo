#include<cstdio>
int max = 0, sum = 0;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		sum += a;
		if (max < a) max = a;
	}
	printf("%d", sum - max);
}