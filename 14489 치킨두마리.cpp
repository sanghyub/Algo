#include<cstdio>
int main() {
	long long a, b,c; scanf("%lld%lld", &a, &b);
	scanf("%lld", &c);
	a = a + b;
	c *= 2;
	if (a >= c) printf("%lld", a - c);
	else printf("%lld", a);
}