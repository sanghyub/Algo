#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
const int dy[4] = { -1,0,0,1 };
const int dx[4] = { 0,-1,1,0 };
map<int, int> mm;
const int FINISH = 123456789;
int main(){
	int a = 0;
	for (int i = 0; i < 9; i++){
		int tt;
		scanf("%d", &tt);
		if (tt == 0)
			tt = 9; // core idea
		a *= 10;
		a += tt;
	}
	string s;
	queue<int> q;
	q.push(a);
	mm[a] = 0;
	while (!q.empty())
	{
		int tt = q.front(); q.pop();
		if (tt == FINISH)
			break;
		s = to_string(tt);
		int z = s.find('9');
		int y = z / 3;
		int x = z % 3;

		for (int dir = 0; dir < 4; dir++){
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3)
			{
				string nxt = s;
				swap(nxt[ny * 3 + nx], nxt[z]);
				int nxt_num = stoi(nxt);
				if (mm.count(nxt_num) == 0)
				{
					mm[nxt_num] = mm[tt] + 1;
					q.push(nxt_num);
				}
			}
		}
	}
	if (mm.count(FINISH))
		printf("%d", mm[FINISH]);
	else puts("-1");
	return 0;
}
