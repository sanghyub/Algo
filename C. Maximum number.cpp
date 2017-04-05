#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) printf("1");
	}
	else {
		printf("7");
		for (int i = 0; i < n / 2-1; i++)printf("1");
	}
}