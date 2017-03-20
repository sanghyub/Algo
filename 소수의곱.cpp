#include<cstdio>
#include<queue>
using namespace std;
int arr[100];
queue<int> q;
int main() {
	int k, n; scanf("%d%d", &k, &n);
	int cnt = 0;
	for (int i = 0; i < k; i++) scanf("%d", &arr[i]);
	for (int i = 1; cnt<=n+1; i++) {
		int flag = 0;
		for (int j = 0; j < k; j++) {
			if (i%arr[j] == 0) {
				cnt++;
				flag = 1;
				break;
			}
		}
		if (flag == 1) q.push(i);
	}
	for (int i = 0; i < n; i++) q.pop();
	printf("%d", q.front());
}