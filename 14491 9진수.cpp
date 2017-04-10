#include<cstdio>
#include<cstring>
int main() {
	int n; scanf("%d", &n);
	int index = 0, s[6];
	while (n >= 9) {
		s[index++]= n % 9;
		n /= 9;
	}
	s[index] = n;
	for (int i = index; i >= 0; i--) printf("%d", s[i]);
}