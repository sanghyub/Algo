#include<cstdio>
#include<vector>
using namespace std;
vector<pair<int, int>>v;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	int result = 0;
	int sixMin=10000, oneMin=10000;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if (sixMin > a) sixMin = a;
		if (oneMin > b) oneMin = b;
	}

	if ((oneMin * 6) < sixMin) sixMin = oneMin*6;
	int k = n;
	while (k > 0) {
		if (k <= 6) {
			if (sixMin < k*oneMin) {
				result += sixMin;
				break;
			}
			else {
				result += oneMin*k;
				break;
			}
		}
		else {
			k -= 6;
			result += sixMin;
		}
	}
	printf("%d", result);
}