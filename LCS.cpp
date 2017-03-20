#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1001][1001],Max=0;
char arr1[1001], arr2[1001];
int main() {
	scanf("%s", arr1);
	scanf("%s", arr2);
	for (int i = 0; i < strlen(arr1); i++) {
		for (int j = 0; j < strlen(arr2); j++) {
			if (arr1[i] != arr2[j]) dp[i+1][j+1] = max(dp[i+1][j], dp[i][j +1]);
			else dp[i + 1][j + 1] = dp[i][j] + 1;	
		}
	}
	for (int i = 1; i <= strlen(arr1); i++) {
		for (int j = 1; j <= strlen(arr2); j++) {
			if (Max < dp[i][j])Max = dp[i][j];
		}
	}
	printf("%d", Max);
}