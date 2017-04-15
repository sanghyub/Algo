#include <stdio.h>
#include <algorithm>
using namespace std;

#define ldb ldouble
typedef long long ll;
typedef double db;
const ll LL_INF = 1234567890123456789ll;

int x[50050], v[50050];

int main() {
	int N, i;
	db mn = -LL_INF, mx = LL_INF, T;

	scanf("%d", &N);
	scanf("%lf", &T);
	for (i = 1; i <= N; i++) scanf("%d", &x[i]);
	for (i = 1; i <= N; i++) scanf("%d", &v[i]);
	for (i = 1; i <= N; i++) {
		mn = max(mn, x[i] - v[i] * T);
		mx = min(mx, x[i] + v[i] * T);
	}
	if (mn <= mx) printf("1\n");
	else printf("0\n");

	return 0;
}