#include<cstdio>
bool visit[1001] = { false };
int main() {
	int n, k; scanf("%d%d", &n, &k);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (visit[i] == true) continue;
		int a = i;
		for (int j = 2; j <= i; j++) {
			if (a%j == 0) {
				for (int l = 1; a*l <= n; l++) {
					if (visit[a*l] == false) {
						cnt++;
						visit[a*l] = true;
						if (cnt == k) {
							printf("%d", a*l);
							return 0;
						}
					}
				}
			}
		}
	}
}