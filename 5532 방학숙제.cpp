#include<cstdio>
int main() {
	int l, a, b, c, d; scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);
	int cnt = 0;
	while (a > 0 || b > 0) {
		a -= c;
		b -= d;
		cnt++;
	}
	printf("%d", l - cnt);
}