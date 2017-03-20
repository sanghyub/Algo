#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100];
bool pluged[100];
int result[100];
int order[100];
int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
	}

	int start = 0;
	for (int i = 0; i < n;) {
		for (int j = 0; j < k; j++) {
			if (pluged[arr[j]] == false) {
				result[i] = arr[j];
				pluged[arr[j]] = true;
				i++;
				start = j + 1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = k - 1; j >= start; j--) {
			if (result[i] == arr[j]) {
				order[i] =k-j;
			}
		}
	}

	for (int i = 0; i < n; i++) {

	}


}