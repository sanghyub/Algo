#include<cstdio>
#include<list>
using namespace std;
char s[1000001];
int main() {
	int t;  scanf("%d", &t);
	while (t--) {
		list<char> l;
		auto p = l.begin();
		scanf("%s", s);
		for (int i = 0; s[i]; i++) {
			if (s[i] == '-') {
				if (p != l.begin()) p = l.erase(--p);
			}
			else if (s[i] == '<') {
				if (p != l.begin()) p--;
			}
			else if (s[i] == '>') {
				if (p != l.end()) p++;
			}
			else {
				p = l.insert(p, s[i]);
				p++;
			}
		}
		for (char c : l) printf("%c", c);
		printf("\n");
	}
	return 0;
}