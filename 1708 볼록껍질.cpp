#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int lli;
struct Vector {
	lli x, y;
	Vector() {}
	Vector(lli tx, lli ty) { x = tx, y = ty; }
	Vector operator-(const Vector& B) { return Vector(x - B.x, y - B.y); }
} p[100002], piv;
lli dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
lli cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
bool compare1(Vector A, Vector B) { return A.y == B.y ? A.x<B.x : A.y<B.y; }
bool compare2(Vector A, Vector B) { return cross(A - piv, B - piv)>0; }
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	sort(p, p + n, compare1);
	piv = p[0];
	sort(p + 1, p + n, compare2);
	Vector st[100002] = { piv,p[1] };
	int top = 2;
	for (int i = 2; i<n; i++) {
		bool parallel = false;
		while (top >= 2) {
			lli c = cross(st[top - 1] - st[top - 2], p[i] - st[top - 1]);
			lli d = dot(st[top - 1] - st[top - 2], p[i] - st[top - 1]);
			if (c>0) break;
			else if (c == 0 && d<0) {
				parallel = true;
				break;
			}
			top--;
		}
		if (!parallel) st[top++] = p[i];
	}
	for (int i = 0; i<top; i++)
		printf("%lld %lld\n", st[i].x, st[i].y);
	//printf("%d",top);
	return 0;
}

