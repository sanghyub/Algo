#include <cstdio>
#include<algorithm>
using namespace std;

#define MAXN 10000007
typedef long long lld;

static int N, K, L;
static int A[MAXN];
static lld D[MAXN], E[MAXN];

lld delivery(int n, int k, int l, int p[])
{
	N = n, K = k, L = l;
	for (int i = 1; i <= N; i++) A[i] = p[i - 1];
	for (int i = 1; i <= N; i++) {
		int j = max(0, i - K);
		D[i] = D[j] + A[i] + min(A[i], L - A[i]);
	}
	for (int i = N; i; i--) {
		int j = min(N + 1, i + K);
		E[i] = E[j] + (L - A[i]) + min(A[i], L - A[i]);
	}
	lld ans = 1e18;
	for (int i = 0; i <= N; i++)
		ans = min(ans, D[i] + E[i + 1]);
	return ans;
}

int p[10000001];
int main() {
	int n, k, l; scanf("%d%d%d", &n, &k, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	printf("%lld", delivery(n, k, l, p));
}

