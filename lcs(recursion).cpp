#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int lcs(int xlen, int ylen, char*x, char *y) {
	if (xlen == 0 || ylen == 0) return 0;
	if (x[xlen - 1] == y[ylen - 1]) {
		return 1 + lcs(xlen - 1, ylen - 1, x, y);
	}
	else {
		return max(lcs(xlen - 1, ylen, x, y), lcs(xlen, ylen - 1, x, y));
	}
}

int main() {
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int xlen = strlen(X);
	int ylen = strlen(Y);

	printf("%d",lcs(xlen, ylen, X, Y));
}