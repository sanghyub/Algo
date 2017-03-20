#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<double> s;
int num[26];
char arr[200];
int main() {
	int n; scanf("%d", &n);
	scanf("%s", arr);
	int len = strlen(arr);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	for (int i = 0, j=0; i < len; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') s.push(num[arr[i] - 'A']);
		else if (arr[i] == '+' || arr[i] == '-' || arr[i]=='*' || arr[i] =='/') {
			double a, b,result;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			if (arr[i] == '+') result = a + b;
			else if (arr[i] == '-') result = b - a;
			else if (arr[i] == '*') result = b*a;
			else if (arr[i] == '/') result = b / a;
			s.push(result);
		}
	}
	printf("%.2lf", s.top());
}