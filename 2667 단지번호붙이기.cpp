#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int arr[26][26];
bool visit[26][26];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1} };
vector<int> v;
queue<pair<int, int>> q;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[26]; scanf("%s", s);
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (arr[i][j] == 1 && visit[i][j] == false) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
				cnt++;
				while (!q.empty()) {
					pair<int, int> YX = q.front();
					q.pop();
					for (int l = 0; l < 4; l++) {
						int nextY = YX.first + dir[l][0];
						int nextX = YX.second + dir[l][1];
						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && visit[nextY][nextX] == false && arr[nextY][nextX] == 1) {
							q.push(make_pair(nextY, nextX));
							cnt++;
							visit[nextY][nextX] = true;
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	
}