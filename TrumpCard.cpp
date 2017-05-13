#include<cstdio>
#include<algorithm>
using namespace std; 
int dp[15][15], Max = 0;
char arr1[15], arr2[15];
int main() {
	for (int i = 0; i < 13; i++) {
		scanf("%c ", &arr1[i]);
		if (arr1[i] == '0') i--;
	}
	for (int i = 0; i < 13; i++) {
		scanf("%c ", &arr2[i]);
		if (arr2[i] == '0') i--;
	}
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			if (arr1[i] != arr2[j]) dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			else dp[i + 1][j + 1] = dp[i][j] + 1;
		}
	}
	for (int i = 1; i <= 13; i++) {
		for (int j = 1; j <= 13; j++) {
			if (Max < dp[i][j])Max = dp[i][j];
		}
	}
	printf("%d", Max);

}