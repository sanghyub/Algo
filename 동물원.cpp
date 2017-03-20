#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#define max(a,b) ((a)>(b) ? (a): (b)) 
#define min(a,b) ((a)<(b) ? (a): (b))

using namespace std;
long long dp[3][100001];
int main() {
	int n; cin >> n;
	dp[0][1] = 1;  // 사자가 없는경우
	dp[1][1] = 1;  //왼쪽에만 있는경우
	dp[2][1] = 1; //오른쪽만 있는경우

	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % 9901;
	}

	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % 9901;

}