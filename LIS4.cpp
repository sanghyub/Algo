#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;  scanf("%d", &n);
	vector<long long> arr(n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	long long result = 0;
	vector<long long>dp;
	dp.push_back(-(1 << 30));
	for (int i = 0; i < n; i++) {
		auto idx = lower_bound(dp.begin(), dp.end(), arr[i]);
		if (idx == dp.end()) {
			result++;
			dp.push_back(arr[i]);
		}
		else if (*idx > arr[i]) *idx = arr[i];
	}
	printf("%lld", result);
	return 0;
}