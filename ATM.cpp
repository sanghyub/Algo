#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000],sum=0,result;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		result += sum;
	}
	printf("%d", result);
}