#include<cstdio>

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	else if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int a, b; scanf("%d%d", &a, &b);
		int gc = gcd(a, b);
		printf("%d\n", gc*(a / gc)*(b / gc));
	}
}