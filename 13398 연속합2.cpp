#include<cstdio>
#include<algorithm>
using namespace std;
int p = -987654321, r = -987654321;
int q, n;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		q = max(p, q + x); //중간 1개를 제외한 최대 연속 부분합
		p = max(p + x, x); //최대 연속 부분합
		r = max({ r,p,q });
	}
	printf("%d", r);
	return 0;
}