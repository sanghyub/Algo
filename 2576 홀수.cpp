#include<cstdio>
int main() {
	int sum = 0, Min = 1000;
	for (int i = 0; i < 7; i++) {
		int a; scanf("%d", &a);
		if (a % 2 == 1) {
			sum += a;
			if (Min > a) Min = a;
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, Min);
}