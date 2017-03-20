#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	long long s, f, t, arr[100000];
	int n;
	scanf("%lld%lld%lld%d", &s, &f, &t,&n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	long long first,watingTimeFirst;
	if (arr[0] != 0) {
		first = arr[0] - 1;
		watingTimeFirst = s - first;
	}
	long long curTime=arr[0];
	if (curTime < s) {
		curTime = s;
	}
	
	long long result;
	for (int i = 1; i < n; i++) {
		curTime += t;
		if (curTime >= f) break;
		if (curTime < arr[i]) {
			result = curTime;
			break;
		}
	}
	
	printf("%lld", max(result, watingTimeFirst));
	
}