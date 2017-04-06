#include<cstdio>
bool visit[42] = { false, };
int main() {
	for (int i = 0; i < 10; i++) {
		int n;  scanf("%d", &n);
		visit[n % 42] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (visit[i] == true) cnt++;
	}
	printf("%d", cnt);
}