#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;
int main() {
	char arr[51];
	char fst[26], sec[26];
	memset(&arr, 0, sizeof(arr));
	memset(&fst, 0, sizeof(fst));
	memset(&sec, 0, sizeof(sec));
	scanf("%s", arr);
	int p = 0;
	sort(arr, arr + strlen(arr));
	stack<int> s;
		for (int i = 0; i < strlen(arr); i++) {
			if (!s.empty()) {
				if (arr[i] == s.top()) {
					s.pop();
					fst[p] = arr[i];
					sec[p++] = arr[i];
				}
				else s.push(arr[i]);
			}
			else s.push(arr[i]);
		}

		if (s.size() == 0) {
			for (int i = 0; i < strlen(fst); i++) printf("%c", fst[i]);
			for (int i = strlen(sec)-1; i >= 0; i--) printf("%c", sec[i]);
			return 0;
		}
		else if (s.size() == 1) {
			if (strlen(fst)+strlen(sec)+1!=strlen(arr)) {
				printf("I'm Sorry Hansoo");
				return 0;
			}
			for (int i = 0; i < strlen(fst); i++) printf("%c", fst[i]);
			printf("%c", s.top());
			for (int i = strlen(sec) - 1; i >= 0; i--) printf("%c", sec[i]);
			return 0;

		}
		else {
			printf("I'm Sorry Hansoo");
			return 0;
		}
}