#include<cstdio>
typedef struct NODE {
	char left;
	char right;
}NODE;

NODE node[100];

void pre(char i) {
	if (i >= 'A') {
		printf("%c",i);
		pre(node[i].left);
		pre(node[i].right);
	}
}

void in(char i) {
	if (i >= 'A') {
		in(node[i].left);
		printf("%c", i);
		in(node[i].right);
	}
}
void post(char i) {
	if (i >= 'A') {
		post(node[i].left);
		post(node[i].right);
		printf("%c", i);
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char a, b, c; scanf(" %c %c %c", &a, &b, &c);
		node[a].left = b;
		node[a].right = c;
	}
	pre('A');
	printf("\n");
	in('A');
	printf("\n");
	post('A');
	printf("\n");
}