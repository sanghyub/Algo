#include<cstdio>
#include<string>
#include<map>
#include<iostream>
#include<utility>
using namespace std;
int uf[200001];
int num[200001];
int find(int a) {
	if (a==uf[a]) return a;
	return uf[a] = find(uf[a]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a != b) {
		uf[a] = b;
		num[b] += num[a];
	}
	return num[b];
}

int main() {
	int t; scanf("%d", &t);
		while (t--) {
		int index = 1;
		map<string, int> m;
		char a[21], b[21];
		int n; scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			uf[i] = i;
			num[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			scanf("%s %s", &a, &b);
			if (m.find(a) == m.end()) m[a]= index++;
			if (m.find(b) == m.end()) m[b] = index++;
			printf("%d\n", merge(m[a], m[b]));
		}
	}
}