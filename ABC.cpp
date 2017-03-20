#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int abc[3];
	char ABC[3];
	for (int i = 0; i < 3; i++) scanf("%d", &abc[i]);
	for (int i = 0; i < 3; i++) scanf(" %c", &ABC[i]);
	sort(abc, abc + 3);
	for (int i = 0; i < 3; i++) {
		if (ABC[i] == 'A') printf("%d ", abc[0]);
		if (ABC[i] == 'B') printf("%d ", abc[1]);
		if (ABC[i] == 'C') printf("%d ", abc[2]);
	}
}