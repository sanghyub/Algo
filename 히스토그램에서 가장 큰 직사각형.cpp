#include <cstdio>
#define max(x,y)((x)<(y)?(y):(x))
long long n, a[100002], d[100002], t, i, s;
int main()
{
	while (~scanf("%lld", &n)) {
		if (!n)break; s = 0;
		for (i = 1; i <= n; i++)
			scanf("%lld", a + i);
		for (a[n + 1] = t = 0, i = 1; i <= n + 1; d[++t] = i++)
			while (t && a[d[t]]>a[i])
				s = max(s, (i - d[t - 1] - 1)*a[d[t]]), t--;
		printf("%lld\n", s);
	}
}