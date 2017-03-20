#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		deque<int> dq;
		char p[100000]; scanf("%s", p);
		int n; scanf("%d", &n);
		int arr[100000];
		char k; scanf(" %c", &k);
		for (int i = 0; i < n-1; i++) {
			scanf(" %d",&arr[i]);
			dq.push_back(arr[i]);
			scanf(" %c", &k);
		}
		scanf("%d", &arr[n-1]);
		if(n!=0)dq.push_back(arr[n - 1]);
		scanf("%c", &k);
		int len, flag = 0;
		bool errCheck = false;
		len = strlen(p);
		for (int i = 0; i < len; i++) {
			if (p[i] == 'R') {
				if (flag == 0) flag = 1;
				else flag = 0;
			}
			else {
				if (!dq.empty() &&flag == 0) dq.pop_front();
				else if(!dq.empty() && flag == 1) dq.pop_back();
				else if (dq.empty()) {
					errCheck = true;
					break;
				}
			}
		}
		
		if (errCheck) {
			printf("error\n");
		}
		else {
			printf("[");
			if (flag == 0) {
				while (!dq.empty()) {
					int a; a=dq.front();
					dq.pop_front();
					printf("%d", a);
					if(dq.size()!=0)printf(",");
				}
			}
			else {
				while (!dq.empty()) {
					int a; a=dq.back();
					dq.pop_back();
					printf("%d", a);
					if (dq.size() != 0)printf(",");
				}
				
			}
			printf("]\n");
		}

	}

}