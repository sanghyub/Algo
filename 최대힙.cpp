#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int> pq;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a == 0) {
			if (pq.size() == 0) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(a);
		}
	}
}