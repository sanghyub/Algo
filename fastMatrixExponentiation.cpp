#include<cstdio>
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int arr[101][101],result[101][101], temp[101][101];
		int n,p; scanf("%d%d", &n, &p);
		for (int i = 0; i < n; i++) {
			for(int j=0; j<n; j++){
				scanf("%d", &arr[i][j]);
				if (i == j) result[i][j]=temp[i][j] = 1;
				else result[i][j] = temp[i][j] = 0;
			}
		}
		while (p != 1) {
			if (p % 2 == 0) {
				p /= 2;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						result[i][j] = 0;
						for (int k = 0; k < n; k++) {
							result[i][j] += (arr[i][k] * arr[k][j]) % 10007;
							result[i][j] %= 10007;
						}
					}
				}
				for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = result[i][j];
			}
			else {
				p -= 1;
				int t[101][101];
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						t[i][j] = 0;
						for (int k = 0; k < n; k++) {
							t[i][j] += (temp[i][k] * arr[k][j]) % 10007;
							t[i][j] %= 10007;
						}
					}
				}
				for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) temp[i][j] = t[i][j];
			}
		}
		int ans[101][101];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = 0;
				for (int k = 0; k < n; k++) {
					ans[i][j] += (temp[i][k] * result[k][j]) % 10007;
					ans[i][j] %= 10007;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
}