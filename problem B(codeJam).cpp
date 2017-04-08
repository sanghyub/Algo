#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[20];
int main() {
	int t; scanf("%d", &t);
	for (int l = 1; l <= t; l++) {
		char s[20]; scanf("%s", &s);
		for (int i = 0; i < strlen(s); i++) arr[i] = s[i] - '0';
		for (int i = 0; i < strlen(s) - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				arr[i] -= 1;
				for (int j = i + 1; j < strlen(s); j++) {
					arr[j] = 9;
				}
				i = -1;
			}
		}
		int startIndex = 0;
		while (arr[startIndex] == 0) startIndex++;
		printf("Case #%d: ", l);
		for (int i = startIndex; i < strlen(s); i++) printf("%d", arr[i]);
		printf("\n");
	}
}