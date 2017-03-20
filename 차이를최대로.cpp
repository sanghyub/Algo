#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
int main() {
	int n, t; scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d",&a);
		pq.push(make_pair(a, i));
	}
	for (int i = 0; i < t; i++) {
		int a = pq.top().first-1;
		int b = pq.top().second;
		pq.pop();
		pq.push(make_pair(a, b));
	}
	printf("hel");
}