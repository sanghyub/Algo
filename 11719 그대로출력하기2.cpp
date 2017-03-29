#include<cstdio>
char c;
int main() {
	while (~scanf("%c", &c)) putchar(c);
	/* 이런 방법도 있음
	while (fgets(buffer, 100, stdin) != NULL) {
		printf("%s", buffer);
	}
	*/
}