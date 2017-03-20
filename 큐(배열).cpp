#include <cstdio>
#include<iostream>
#include<cstring>
using namespace std;
class Queue {
private:
	int queue[10000];
	int front;
	int back;

public:
	Queue() {
		front = 0;
		back = 0;
		queue[10000] = { 0, };
	}

	void push(int n) {
		queue[back++] = n;
	}

	void pop() {
		if (front == back) printf("-1\n");
		else printf("%d\n", queue[front++]);
	}

	void size() {
		printf("%d\n", back - front);
	}

	void empty() {
		if (front == back) printf("1\n");
		else printf("0\n");
	}

	void getFront() {
		if (front == back) printf("-1\n");
		else printf("%d\n", queue[front]);
	}

	void getBack() {
		if (front == back) printf("-1\n");
		else printf("%d\n", queue[back - 1]);
	}
};

int main() {
	Queue queue;
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char command[10] = "";
		cin >> command;
		if (strcmp(command, "push") == 0) {
			int a;
			scanf("%d", &a);
			if (!(a >= 1 && a <= 100000)) return -1;
			queue.push(a);
		}
		else if (strcmp(command, "pop") == 0) queue.pop();
		else if (strcmp(command, "size") == 0) queue.size();
		else if (strcmp(command, "empty") == 0) queue.empty();
		else if (strcmp(command, "front") == 0) queue.getFront();
		else if (strcmp(command, "back") == 0) 	queue.getBack();
	}
	return 0;
}