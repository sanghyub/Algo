#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
int main() {
	deque<int> dq;
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) dq.push_back(i);
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		int front = dq.front();
		if (front == a) {
			dq.pop_front();
			continue;
		}
		else {
			deque<int> dq1, dq2;
			dq1 = dq2 = dq;
			int cnt1 = 0, cnt2 = 0;
			while (dq1.front() != a) {
				dq1.push_back(dq1.front());
				dq1.pop_front();
				cnt1++;
			}
			dq1.pop_front();
			while (dq2.front() != a) {
				dq2.push_front(dq2.back());
				dq2.pop_back();
				cnt2++;
			}
			dq2.pop_front();

			if (cnt2 > cnt1) {
				cnt += cnt1;
				dq = dq1;
			}
			else {
				cnt += cnt2;
				dq = dq2;
			}
		}

	}
	printf("%d", cnt);
}