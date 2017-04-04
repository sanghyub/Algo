#include<cstdio>
#include<cstring>
int main() {
	char a[51], b[51];
	scanf("%s %s", a, b);
	int diff = strlen(b) - strlen(a);
	int Min = 987654321;
	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = i, k=0; k<strlen(a); j++, k++) {
			if (b[j] != a[k]) cnt++;
		}
		if (Min > cnt) Min = cnt;
	}
	printf("%d", Min);
	
}