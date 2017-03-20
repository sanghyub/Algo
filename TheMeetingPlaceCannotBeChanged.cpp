#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int x[60000], v[60000], n ,r=1000;
double low = 1 << 30;
double high = 0;
double mid1, mid2, minTime=1<<30,midTime1=0,midTime2=0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		if (x[i] < low) low = x[i];
		if (x[i] > high) high = x[i];
	}
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	while (r--) {
		mid1 = (low*2.0) / 3.0 + high / 3.0;
		mid2 = (low) / 3.0 + (high*2.0) / 3.0;
		midTime1 = midTime2 = 0;
		for (int i = 0; i < n; i++) {
			midTime1 = max(abs(mid1 - x[i]) / v[i], midTime1);
			midTime2 = max(abs(mid2 - x[i]) / v[i], midTime2);
		}
		if (midTime1 < midTime2) {
			if (midTime1 < minTime) minTime = midTime1;
			high = mid2;

		}
		else {
			if (midTime1 < minTime) minTime = midTime2;
			low = mid1;
		}
	}
	printf("%.9lf", minTime);
}