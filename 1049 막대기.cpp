#include<cstdio>
int main() {
	int n = 64;
	int x; scanf("%d", &x);
	int sum = 0;
	int cnt = 0;
	while (sum != x) {
		if (n + sum > x) {
			n /= 2;
		}
		else {
			sum += n;
			cnt++;
		}
	}
	printf("%d", cnt);
}