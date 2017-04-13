#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int x[50001], v[50001];
int n; double t;
int result = 0;
int cnt = 0;
void search(double left, double right, double mid) {
	int flag = 0;
	cnt++;
	if (cnt > 10000) return;
	for (int i = 0; i < n; i++) {
		if (abs(x[i] - mid) / double(v[i]) > t) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		result = 1;
		return;
	}

	if (left <= right) {
		search(left, mid - 1, (left + mid - 1) / 2.0);
		search(mid + 1, right, (mid + 1 + right) / 2.0);
	}
	else return;
}


int main() {
	scanf("%d %lf", &n, &t);
	int left = 0, right = 1000000001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	search(left, right, (left + right) / 2);
	printf("%d", result);
}