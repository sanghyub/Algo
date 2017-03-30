#include<cstdio>
#include<cstring>
char a[1000001];
char b[400000];
int main() {
	scanf("%s", a);
	int index = 0;
	for (int i = strlen(a) - 1; i >= 0; i -= 3) {
		int k = (a[i] - '0') * 1;
		if(i-1>=0)k += (a[i-1] - '0') * 2;
		if(i-2>=0)k += (a[i-2] - '0') * 4;
		b[index++] = k + '0';
	}
	for (int i = strlen(b) - 1; i >= 0; i--) printf("%c", b[i]);
}