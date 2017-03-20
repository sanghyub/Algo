#include<cstdio>
#include<string.h>
#include<algorithm>
#include<functional>
using namespace std;
int sum=0,length;
char arr[100001];
int result[100001];
int main() {
	scanf("%s", arr);
	length = strlen(arr);
	for (int i = 0; i<length; i++) {
		result[i] = arr[i] - '0';
		sum += result[i];
	}
	sort(result, result + length, greater<int>());

	if (sum % 3 == 0 && result[length - 1] == 0) {
		for (int i = 0; i<length; i++) printf("%d", result[i]);
	}
	else printf("-1");
}
