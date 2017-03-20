#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int length;
char arr[500000];
vector<int> result;
int main(){
	int n, k; scanf("%d%d", &n, &k);
	int cnt = k;
	scanf("%s", arr);
	length = strlen(arr);
	result.push_back(arr[0] - '0');
	for (int i = 1; i < length; i++) {
		if (!result.empty()&&result.back() < arr[i] - '0' &&cnt != 0) {
			while (!result.empty()&&result.back() < arr[i] - '0' &&cnt != 0) {
				result.pop_back();
				cnt--;
			}
			result.push_back(arr[i] - '0');
		}
		else {
			result.push_back(arr[i] - '0');
		}
	}
	while (cnt != 0) {
		result.pop_back();
		cnt--;
	}
	for (int i = 0; i < result.size(); i++) printf("%d", result[i]);
	return 0;
}
