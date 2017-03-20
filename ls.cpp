#include<cstdio>
#include<cstring>
#include <vector>
using namespace std;
char p[100];

int main()
{
	scanf("%s", p);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char arr[100];
		scanf("%s", arr);
		int flag = 0;
		for (int j = 0; j < strlen(p);) {
			for (int k = 0; k < strlen(arr);) {
				if (p[j] == '*') {
					while (p[j+1] == '*') j++;
					
					while (p[j] != arr[k]) {
						k++;
						if (k >= strlen(arr)) {
							flag = 1;
							break;
						}
					}

				}
				else {
					if (p[j] == arr[k]) j++, k++;
					else flag = 1;
				}
			}
		}
		if (flag == 0) printf("%s\n", arr);
	}
	
	
	
}