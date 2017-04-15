#include<cstdio>
int main() {
	int m; scanf("%d", &m);
	int arr[4] = { 0,1,0,0 };
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		int temp;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) printf("%d", i);
	}
}