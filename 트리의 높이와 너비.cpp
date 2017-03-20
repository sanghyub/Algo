#include<cstdio>
#include<queue>
using namespace std;
struct NODE {
	int left;
	int right;
	int row;
	int col;
};

struct DIFF {
	int min=987654321;
	int max=0;
	int result;
};

int index = 1;
bool visit[10001];
struct NODE node[10001];
struct DIFF minMax[10001];

void inorder(int i) {
	if(node[i].left!=-1) inorder(node[i].left);
	node[i].col = index++;
	if(node[i].right!=-1) inorder(node[i].right);
}

int main() {
	int n,root; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num, left, right; scanf("%d%d%d", &num, &left, &right);
		node[num].left = left;
		node[num].right = right;
		if(left!=-1)visit[left] = true;
		if(right!=-1)visit[right] = true;
	}
	for (int i = 1; i <= n; i++) if (visit[i] == false) root = i;
	node[root].row = 1;

	queue<int> q;
	q.push(root);
	for (int i = 1; i <= n; i++) visit[i] = false;
	visit[root] = true;
	
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		int left = node[front].left;
		int right = node[front].right;
		if (visit[left] == false) {
			q.push(left);
			visit[left] = true;
			node[left].row = node[front].row + 1;
		}
		if (visit[right] == false) {
			q.push(right);
			visit[right] = true;
			node[right].row = node[front].row + 1;
		}
	}
	
	inorder(root);
	
	for (int i = 1; i <= n; i++) {
		if (minMax[node[i].row].min > node[i].col) {
			minMax[node[i].row].min = node[i].col;
			minMax[node[i].row].result = minMax[node[i].row].max - minMax[node[i].row].min + 1;
		}
		if (minMax[node[i].row].max < node[i].col) {
			minMax[node[i].row].max = node[i].col;
			minMax[node[i].row].result = minMax[node[i].row].max - minMax[node[i].row].min + 1;
		}
	}
	
	int depth, Max=0;
	for (int i = 1; minMax[i].result!= 0; i++) {
		if (Max < minMax[i].result) {
			depth = i;
			Max = minMax[i].result;
		}
	}
	printf("%d %d", depth, Max);
}