#include<cstdio>
#include<cstring>
int alpha[26];
char s[101];
int main() {
	for (int i = 0; i < 26; i++) alpha[i] = -1;
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (alpha[s[i] - 'a'] == -1) alpha[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)printf("%d ", alpha[i]);
}