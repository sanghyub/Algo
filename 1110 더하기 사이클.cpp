#include<cstdio>
int main() {
	int n; scanf("%d", &n);
	int k = n;
	int cycle = 0;
	while (n != k || cycle == 0) {
		int a = k / 10;
		int b = k % 10;
		int c = (a + b) % 10;
		a = b; b = c;
		k = a * 10 + b;
		cycle++;
	}
	printf("%d", cycle);
}