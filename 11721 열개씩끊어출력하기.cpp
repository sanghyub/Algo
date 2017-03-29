#include<cstdio>
#include<cstring>
char arr[110];
int main() {
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		if (i % 10 == 0 && i != 0) printf("\n");
		printf("%c", arr[i]);
	}
}