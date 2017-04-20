#include<iostream>
#include<algorithm>
using namespace std;
struct point { short x, y; };
int dist(point &p, point &q) { return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y); }
bool cmpPointX(point &p, point &q) { return p.x < q.x; }
bool cmpPointY(point &p, point &q) { return p.y < q.y; }
point P[100001];
point Mid[100001];

int closestPair(point *P, int n) {
	if (n == 2) return dist(P[0], P[1]);
	if (n == 3) return min({ dist(P[0], P[1]), dist(P[1], P[2]), dist(P[2], P[0]) });

	int line = (P[n / 2 - 1].x + P[n / 2].x) / 2;
	int d = min(closestPair(P, n / 2), closestPair(P + n / 2, n - n / 2));
	int midN = 0;
	for (int i = 0; i<n; i++) {
		int t = line - P[i].x;
		if (t*t <= d) Mid[midN++] = P[i];
	}
	sort(Mid, Mid + midN, cmpPointY);
	for (int i = 0; i < midN; i++) {
		for (int j = i + 1; j < midN && j <= i + 6; j++) {
			d = min(d, dist(Mid[i], Mid[j]));
		}
	}
	return d;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) scanf("%d %d", &P[i].x, &P[i].y);
	sort(P, P + n, cmpPointX);
	cout << closestPair(P, n);
	return 0;
}