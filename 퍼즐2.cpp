// 아 이렇게 짜면 안될거같은데.................
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
typedef struct bo {
	int count;
	int board;
}B;
queue<B> q;
set<int> s;
bool isTrueBoard(int board) {
	switch (board) {
	case  23456789: return true;
	case 103456789: return true;
	case 120456789: return true;
	case 123056789: return true;
	case 123406789: return true;
	case 123450789: return true;
	case 123456089: return true;
	case 123456709: return true;
	case 123456780: return true;
	}
	return false;
}
int ZeroLocation(int board) {
	for (int i = 0; i < 9; i++) {
		int temp = board % 10;
		if (temp == 0) return 8 - i; // 0 1 2 3 4 5 6 7 8
		board /= 10;
	}
	return -1;
}
int swap(int board, int zeroloc, int swaploc) {
	int temp = board;
	int sloc = 1;
	int zloc = 1;
	switch (swaploc) {
	case 0:
		sloc = (temp / 100000000) % 10;
		temp = temp - (temp / 100000000) % 10 * 100000000; break;
	case 1:
		sloc = (temp / 10000000) % 10;
		temp = temp - (temp / 10000000) % 10 * 10000000; break;
	case 2:
		sloc = (temp / 1000000) % 10;
		temp = temp - (temp / 1000000) % 10 * 1000000; break;
	case 3:
		sloc = (temp / 100000) % 10;
		temp = temp - (temp / 100000) % 10 * 100000; break;
	case 4:
		sloc = (temp / 10000) % 10;
		temp = temp - (temp / 10000) % 10 * 10000; break;
	case 5:
		sloc = (temp / 1000) % 10;
		temp = temp - (temp / 1000) % 10 * 1000; break;
	case 6:
		sloc = (temp / 100) % 10;
		temp = temp - (temp / 100) % 10 * 100; break;
	case 7:
		sloc = (temp / 10) % 10;
		temp = temp - (temp / 10) % 10 * 10; break;
	case 8:
		sloc = (temp / 1) % 10;
		temp = temp - (temp / 1) % 10 * 1; break;
	}
	switch (zeroloc) {
	case 0: temp = temp + sloc * 100000000; break;
	case 1: temp = temp + sloc * 10000000; break;
	case 2: temp = temp + sloc * 1000000; break;
	case 3: temp = temp + sloc * 100000; break;
	case 4: temp = temp + sloc * 10000; break;
	case 5: temp = temp + sloc * 1000; break;
	case 6: temp = temp + sloc * 100; break;
	case 7: temp = temp + sloc * 10; break;
	case 8: temp = temp + sloc * 1; break;
	}
	return temp;
}
void qinsert(B temp) {
	pair<set<int>::iterator, bool> sett;
	sett = s.insert(temp.board);
	if (sett.second) {
		q.push(temp);
	}
}
int main() {
	int input = 0;
	int temp = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &temp);
		input *= 10;
		input += temp;
	} // input data 000,000,000

	B firstBoard;
	firstBoard.count = 0;
	firstBoard.board = input;
	q.push(firstBoard);
	s.insert(input);
	pair<int, bool> sett;
	while (!q.empty()) {
		B b = q.front();
		q.pop();

		int current_count = b.count;
		int current_board = b.board;
		if (isTrueBoard(current_board)) {
			printf("%d\n", current_count);
			return 0;
		}
		else {
			int zeroLoc = ZeroLocation(current_board);
			int next_count = current_count + 1;
			B temp;
			temp.board = current_board;
			temp.count = next_count;
			switch (zeroLoc) {
			case 0:
				temp.board = swap(current_board, 0, 1);
				qinsert(temp);
				temp.board = swap(current_board, 0, 3);
				qinsert(temp);
				break;
			case 1:
				temp.board = swap(current_board, 1, 0);
				qinsert(temp);
				temp.board = swap(current_board, 1, 2);
				qinsert(temp);
				temp.board = swap(current_board, 1, 4);
				qinsert(temp);
				break;
			case 2:
				temp.board = swap(current_board, 2, 1);
				qinsert(temp);
				temp.board = swap(current_board, 2, 5);
				qinsert(temp);
				break;
			case 3:
				temp.board = swap(current_board, 3, 0);
				qinsert(temp);
				temp.board = swap(current_board, 3, 4);
				qinsert(temp);
				temp.board = swap(current_board, 3, 6);
				qinsert(temp);
				break;
			case 4:
				temp.board = swap(current_board, 4, 1);
				qinsert(temp);
				temp.board = swap(current_board, 4, 3);
				qinsert(temp);
				temp.board = swap(current_board, 4, 5);
				qinsert(temp);
				temp.board = swap(current_board, 4, 7);
				qinsert(temp);
				break;
			case 5:
				temp.board = swap(current_board, 5, 2);
				qinsert(temp);
				temp.board = swap(current_board, 5, 4);
				qinsert(temp);
				temp.board = swap(current_board, 5, 8);
				qinsert(temp);
				break;
			case 6:
				temp.board = swap(current_board, 6, 3);
				qinsert(temp);
				temp.board = swap(current_board, 6, 7);
				qinsert(temp);
				break;
			case 7:
				temp.board = swap(current_board, 7, 4);
				qinsert(temp);
				temp.board = swap(current_board, 7, 6);
				qinsert(temp);
				temp.board = swap(current_board, 7, 8);
				qinsert(temp);
				break;
			case 8:
				temp.board = swap(current_board, 8, 5);
				qinsert(temp);
				temp.board = swap(current_board, 8, 7);
				qinsert(temp);
				break;
			}
		}
	}
	printf("-1\n");
	return 0;
}