#include<cstdio>
int main() {
	int a, b,c,d; scanf("%d%d", &a, &b);
	c = a / 100 + (a / 10) % 10 * 10 + a % 10 * 100;
	d = b / 100 + (b / 10) % 10 * 10 + b % 10 * 100;
	if (c > d) printf("%d", c);
	else printf("%d", d);
}