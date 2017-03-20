#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<char> s;
char arr[200];
int main() {
	scanf("%s", arr);
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') printf("%c", arr[i]);
		else if(arr[i]>='a' && arr[i]<='z')  printf("%c", arr[i]);
		else if (arr[i] == '(') s.push(arr[i]);
		else if (arr[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				if(s.top()!='(')printf("%c", s.top());
				s.pop();
			}
			s.pop();
		}
		else if (arr[i] == '*' || arr[i] == '/') {
			if (!s.empty() &&(s.top() == '*' || s.top() == '/')) {
				if (s.top() != '(')printf("%c", s.top());
				s.pop();
			}
			s.push(arr[i]);
		}
		else if (arr[i] == '+' || arr[i] == '-') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')) {
				if (s.top() != '(')printf("%c", s.top());
				s.pop();
			}
			s.push(arr[i]);
		}
	}
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
}