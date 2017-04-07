#include<cstdio>
int main() {
	int a, b, v; scanf("%d%d%d", &a, &b, &v);
	int left = 1, right = v;
	int Min = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (((mid - 1)*(a - b) + a) >= v) {
			if (Min > mid) Min = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d", Min);
}