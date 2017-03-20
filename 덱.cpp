#include<cstdio>
#include<deque>
#include<cstring>
using namespace std;
deque<int> dq;
int main() {
	int n,a; scanf("%d", &n);
	char command[15];
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (strcmp(command, "push_back") == 0) {
			scanf("%d", &a);
			dq.push_back(a);
		}
		else if (strcmp(command, "push_front") == 0) {
			scanf("%d", &a);
			dq.push_front(a);
		}
		else if (strcmp(command, "pop_back") == 0) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n",dq.back());
				dq.pop_back();
			}
		}
		else if (strcmp(command, "pop_front") == 0) {
			if (dq.size() == 0) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (strcmp(command, "size") == 0) printf("%d\n", dq.size());
		else if (strcmp(command, "front") == 0) {
			if (dq.size() == 0) printf("-1\n");
			else printf("%d\n", dq.front());
		}
		else if (strcmp(command, "back") == 0) {
			if (dq.size() == 0) printf("-1\n");
			else printf("%d\n", dq.back());
		}
		else if (strcmp(command, "empty") == 0) {
			if(dq.empty())printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}