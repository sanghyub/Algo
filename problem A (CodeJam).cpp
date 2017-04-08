#include<cstdio>
#include<cstring>
int main() {
	int t; scanf("%d",&t);
	for (int l = 1; l <= t; l++) {
		char s[1001];
		int n;
		scanf("%s %d", s, &n);
		int cnt = 0;
		for (int i = 0; i < strlen(s) - n+1; i++) {
			if (s[i] == '-') {
				cnt++;
				for (int j = i; j < i + n; j++) {
					if (s[j] == '-') s[j] = '+';
					else s[j] = '-';
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '-') flag = 1;
		}
		printf("Case #%d:",l);
		if (flag == 1)printf(" IMPOSSIBLE\n");
		else  printf(" %d\n", cnt);
	}
}