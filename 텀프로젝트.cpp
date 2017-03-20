#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int arr[100001];
		bool visit[100001];
		bool team[100001];
		memset(&team, false, sizeof(team));
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
		for (int i = 1; i <= n; i++) {
			int start = i;
			for (int j = 1; j <= n; j++) {
				if(i-1!=j)visit[j] = false;
			}
			stack<int> s;
			s.push(i);
			while (!s.empty()) {
				int top = s.top();
				if (visit[arr[top]] == false) {
					visit[arr[top]] = true;
					s.push(arr[top]);
					top = s.top();
					if (start == top) {
						while (!s.empty()) {
							team[s.top()] = true;
							s.pop();
						}
					}
				}
				else break;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (team[i] == false) cnt++;
		}
		printf("%d\n", cnt);
	}
}