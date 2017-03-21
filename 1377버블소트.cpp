#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int arr[500001];
vector<int> v;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());

	vector<int>::iterator upper;
	int Max = 0; 
	for (int i = 0; i < n; i++) {
		upper = upper_bound(v.begin(), v.end(), arr[i]);
		if (Max < i - (upper - v.begin() - 1)) {
			Max = i - (upper - v.begin() - 1);
		}
	}
	printf("%d", Max+1);
}