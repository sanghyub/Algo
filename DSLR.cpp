#include<cstdio>
#include<queue>
#include<utility>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int  a, b, d, s, l, r;
bool visit[10000];
char result[10000];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(&visit, false, sizeof(visit));
		memset(&result, 0, sizeof(result));
		queue<int> q;
		vector<pair<int, char>> v[10000];
		scanf("%d%d", &a, &b);
		d = (2 * a) % 10000;
		if (a == 0) s = 9999;
		else s = a - 1;
		int temp = a / 1000;
		l = (a % 1000) * 10 + temp;
		temp = a % 10;
		r = (a / 10) + temp * 1000;
		v[a].push_back(make_pair(-1, -1));
		visit[a] = true;
		q.push(a);
		int index = 0;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			if (f == b) {
				int parent = v[f].back().first; 
				result[index++] = v[f].back().second;
				while (v[parent].back().first != -1) {
					result[index++] = v[parent].back().second;
					parent = v[parent].back().first;
				}
				break;
			}
			else {
				d = (2 * f) % 10000;
				if (f == 0) s = 9999;
				else s = f - 1;
				int temp = f / 1000;
				l = (f % 1000) * 10 + temp;
				temp = f % 10;
				r = (f / 10) + temp * 1000;

				if (visit[d] == false) {
					visit[d] = true;
					q.push(d);
					v[d].push_back(make_pair(f, 'D'));
				}
				if (visit[s] == false) {
					visit[s] = true;
					q.push(s);
					v[s].push_back(make_pair(f, 'S'));
				}
				if (visit[l] == false) {
					visit[l] = true;
					q.push(l);
					v[l].push_back(make_pair(f, 'L'));
				}
				if (visit[r] == false) {
					visit[r] = true;
					q.push(r);
					v[r].push_back(make_pair(f, 'R'));
				}
			}
		}
		for (int i = strlen(result) - 1; i >= 0; i--) {
			printf("%c", result[i]);
		}
		printf("\n");
	}
}