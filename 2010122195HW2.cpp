#include<cstdio>
#include<map>
using namespace std;
int arr[1000001], tree[1000001], lcnt[1000001], rcnt[1000001];
long long result = 0;

int query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i&-i);
	}
	return sum;
}

void update(int i, int num) {
	while (i <= 1000001) {
		tree[i] += num;
		i += (i&-i);
	}
}

int main() {
	map<int, int> a,b;
	int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			a[arr[i]]+=1;
			lcnt[i] = a[arr[i]];      
		}
		
		for (int i = n; i > 0; i--) {
			b[arr[i]]+=1;
			rcnt[i] = b[arr[i]];  
		}
		
		for (int i = n-1; i > 0; i--) {
			update(rcnt[i+1], 1);
			result += query(lcnt[i] - 1);
		}
		printf("%lld\n", result);
		return 0;
}