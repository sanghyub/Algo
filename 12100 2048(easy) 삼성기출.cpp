#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n, Max = 0;
bool visit[21][21] = { false, };
void right(vector<int> arr[21], int cnt);
void left(vector<int> arr[21], int cnt);
void up(vector<int> arr[21], int cnt);
void down(vector<int> arr[21], int cnt);

void right(vector<int> arr[21], int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (Max < arr[i][j]) Max = arr[i][j];
		return;
	}
	if (cnt > 5) return;
	memset(&visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (arr[i][j] == 0 && arr[i][j - 1] != 0) {
				arr[i][j] = arr[i][j - 1];
				arr[i][j - 1] = 0;
				while (j + 1 < n && arr[i][j + 1] == 0) {
					arr[i][j + 1] = arr[i][j];
					arr[i][j] = 0;
					j++;
				}
				j = n - 1;
			}
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1] && visit[i][j] == false && visit[i][j - 1] == false) {
				arr[i][j] *= 2;
				arr[i][j - 1] = 0;
				visit[i][j] = true;
			}
		}
	}

	vector<int> vl[21], vr[21], vu[21], vd[21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vl[i].push_back(arr[i][j]),vr[i].push_back(arr[i][j]),vu[i].push_back(arr[i][j]),vd[i].push_back(arr[i][j]);
		}
	}
	right(vr, cnt + 1);
	left(vl, cnt + 1);
	up(vu, cnt + 1);
	down(vd, cnt + 1);
}

void left(vector<int> arr[21], int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (Max < arr[i][j]) Max = arr[i][j];
		return;
	}
	if (cnt > 5) return;
	memset(&visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == 0 && arr[i][j + 1] != 0) {
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = 0;
				while (j - 1 >= 0 && arr[i][j - 1] == 0) {
					arr[i][j - 1] = arr[i][j];
					arr[i][j] = 0;
					j--;
				}
				j = 0;
			}
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1] && visit[i][j] == false && visit[i][j + 1] == false) {
				arr[i][j] *= 2;
				arr[i][j + 1] = 0;
				visit[i][j] = true;
			}
		}
	}
	vector<int> vl[21], vr[21], vu[21], vd[21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vl[i].push_back(arr[i][j]),vr[i].push_back(arr[i][j]),vu[i].push_back(arr[i][j]),vd[i].push_back(arr[i][j]);
		}
	}
	right(vr, cnt + 1);
	left(vl, cnt + 1);
	up(vu, cnt + 1);
	down(vd, cnt + 1);
}
void up(vector<int> arr[21], int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (Max < arr[i][j]) Max = arr[i][j];
		return;
	}
	if (cnt > 5) return;
	memset(&visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][i] == 0 && arr[j + 1][i] != 0) {
				arr[j][i] = arr[j+1][i];
				arr[j+1][i] = 0;
				while (j - 1 >= 0 && arr[j-1][i] == 0) {
					arr[j-1][i] = arr[j][i];
					arr[j][i] = 0;
					j--;
				}
				j = 0;
			}
			if (arr[j][i] != 0 && arr[j][i] == arr[j+1][i] && visit[j][i] == false && visit[j+1][i] == false) {
				arr[j][i] *= 2;
				arr[j+1][i] = 0;
				visit[j][i] = true;
			}
		}
	}
	vector<int> vl[21], vr[21], vu[21], vd[21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vl[i].push_back(arr[i][j]),vr[i].push_back(arr[i][j]),vu[i].push_back(arr[i][j]),vd[i].push_back(arr[i][j]);
		}
	}
	right(vr, cnt + 1);
	left(vl, cnt + 1);
	up(vu, cnt + 1);
	down(vd, cnt + 1);
}
void down(vector<int> arr[21], int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (Max < arr[i][j]) Max = arr[i][j];
		return;
	}
	if (cnt > 5) return;
	memset(&visit, 0, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (arr[j][i] == 0 && arr[j-1][i] != 0) {
				arr[j][i] = arr[j-1][i];
				arr[j-1][i] = 0;
				while (j + 1 < n && arr[j+1][i] == 0) {
					arr[j+1][i] = arr[j][i];
					arr[j][i] = 0;
					j++;
				}
				j = n - 1;
			}
			if (arr[j][i] != 0 && arr[j][i] == arr[j-1][i] && visit[j][i] == false && visit[j-1][i] == false) {
				arr[j][i] *= 2;
				arr[j-1][i] = 0;
				visit[j][i] = true;
			}
		}
	}
	vector<int> vl[21], vr[21], vu[21], vd[21];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vl[i].push_back(arr[i][j]),vr[i].push_back(arr[i][j]),vu[i].push_back(arr[i][j]),vd[i].push_back(arr[i][j]);
		}
	}
	right(vr, cnt + 1);
	left(vl, cnt + 1);
	up(vu, cnt + 1);
	down(vd, cnt + 1);
}
int main() {
	vector<int> vl[21], vr[21], vu[21], vd[21];
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j++) {
			int a; scanf("%d", &a);
			vl[i].push_back(a),vr[i].push_back(a),vu[i].push_back(a),vd[i].push_back(a);
		}
	}
	right(vr,0);
	left(vl,0);
	up(vu,0);
	down(vd,0);
	printf("%d", Max);
}