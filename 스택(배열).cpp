#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class Stack {
private:
	int top;
	int stack[200000];
public:
	Stack() {
		top = -1;
	}

	void push(int n) {
		stack[++top] = n;
	}

	void pop() {
		if (top != -1) {
			printf("%d\n", stack[top--]);
		}
		else if (top == -1) {
			printf("-1\n");
		}
	}
	
	void getTop() {
		if (top != -1)	printf("%d\n", stack[top]);
		else if (top == -1) printf("-1\n");
	}

	void size() {
		printf("%d\n", top + 1);
	}

	void isEmpty() {
		if (top == -1) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
};

int main()
{
	int t;
	Stack stack;
	string command = "";
	cin >> t;
	if (!(t >= 1 && t <= 10000)) return -1;
	for (int i = 0; i < t; i++) {
		cin >> command;
		if (command == "push") {
			int n; cin >> n;
			stack.push(n);
		}
		else if (command == "pop") stack.pop();
		else if (command == "size") stack.size();
		else if (command == "top") stack.getTop();
		else if (command == "empty") stack.isEmpty();
		command = "";
	}
	return 0;
}