#include<cstdio>
int arr[101];
int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	for (int i = 0; i < 3; i++) {
		int d, e; scanf("%d%d", &d, &e);
		for (int j = d+1; j <= e; j++) arr[j] += 1;
	}
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if (arr[i] == 1) sum += a;
		else if (arr[i] == 2)sum += b*2;
		else if (arr[i] == 3) sum += c*3;
	}
	printf("%d", sum);
}