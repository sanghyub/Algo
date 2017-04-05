#include<cstdio>
#include<vector>
#include<algorithm>

char people[200001];
int main() {
	int n,c1,c2; scanf("%d%d%d", &n,&c1,&c2);
	int adult = 0, student = 0;
	scanf("%s", people);
	for (int i = 0; i < n; i++) {
		if (people[i] == 0) student++;
		else adult++;
	}


}