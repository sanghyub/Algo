#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int arr[2001];
vector<int> three;
int sum = 0;
int Min;

void solve(int start, int sum) {
 	if (start >= three.size()) return;

 	sum -= three[start];
	if (Min > sum) Min = sum;
	for (int i = start+3; i < three.size(); i++) {
		solve(i, sum);
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	Min = sum;

	for (int i = 0; i < n - 2; i++) {
		int a;
		a= min(arr[i], min(arr[i+1],arr[i+2]));
		three.push_back(a);
	}
	
	for (int i = 0; i < three.size(); i++) {
		solve(i, sum);
	}

	printf("%d", Min);
} 