#include<cstdio>
#include<algorithm>
#include<functional>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int, vector<int>, less<int>> pq;
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		double a; scanf("%lf", &a);
		pq.push(int(ceil(a / k)));
	}
	int cnt = 0;
	while (!pq.empty()) {
		int first = pq.top();
		pq.pop();
		int second = 0;
		if (!pq.empty()) {
			second = pq.top();
			pq.pop();
		}
		if (second == 0) {
			cnt += first;
			break;
		}
		first -= second;
		cnt += second;
		if (first > 0) pq.push(first);
	}
	printf("%d", cnt);
}