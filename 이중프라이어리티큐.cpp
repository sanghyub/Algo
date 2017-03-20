#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
#include<iostream>
#include<string.h>
using namespace std;
bool visit[1000010];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> max_heap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char c; scanf(" %c", &c);
			int a;
			if (c == 'I') {
				scanf("%d", &a);
				max_heap.push(make_pair(a,i));
				min_heap.push(make_pair(a,i));
			}
			else if (c == 'D') {
				scanf("%d", &a);
				if (a == 1) {
					if (!max_heap.empty()) {
						while (!max_heap.empty() && visit[max_heap.top().second] == true) max_heap.pop();
						if (!max_heap.empty()) {
							visit[max_heap.top().second] = true;
							max_heap.pop();
						}
					}
				}
				else if(a == -1) {
					if (!min_heap.empty()) {
						while (!min_heap.empty() && visit[min_heap.top().second] == true) min_heap.pop();
						if (!min_heap.empty()) {
							visit[min_heap.top().second] = true;
							min_heap.pop();
						}
					}
				}
			}
		}
		while (!max_heap.empty() && visit[max_heap.top().second] == true) max_heap.pop();
		while (!min_heap.empty() && visit[min_heap.top().second] == true) min_heap.pop();
		if (max_heap.size() != 0 && min_heap.size() != 0) printf("%d %d\n", max_heap.top().first, min_heap.top().first);
		else printf("EMPTY\n");
		memset(&visit, false, sizeof(visit));
	}

}