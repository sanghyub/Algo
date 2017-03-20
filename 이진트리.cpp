#include<cstdio>
#include<algorithm>
using namespace std;
int weight[1 << 21];
int main() {
	int n; scanf("%d",&n);
	int sum = 0;
	for (int i = 2; i < (1 << (n + 1)); i++) {
		scanf("%d", &weight[i]);
		sum += weight[i];
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = 1 << i; j < 1 << i + 1; j+=2) {
			sum += abs(weight[j] - weight[j + 1]);
			weight[j/2]+=max(weight[j], weight[j + 1]);
		}
	}
	printf("%d", sum);
}