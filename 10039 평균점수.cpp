#include<cstdio>
int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int a; scanf("%d", &a);
		if (a < 40) sum += 40;
		else sum += a;
	}
	printf("%d", sum / 5);
}