#include<stdio.h>
int main() {
	int a[100001],b[100001];
	int n, l, r; scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (i < l || i> r) {
			if (a[i] != b[i]) flag = 1;
		}
	}
	if (flag == 0) printf("TRUTH");
	else printf("LIE");
	return 0;
}