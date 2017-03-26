#include<cstdio>
int f(int x, int y) {
	int sum = 0;
	for (; x>0; x /= y) sum += x%y;
	return sum;
}
int main() {
	for (int i = 1000; i < 10000; i++)
		if (f(i, 10) == f(i, 16) && f(i, 12) == f(i, 16)) printf("%d\n", i);
	return 0;
}