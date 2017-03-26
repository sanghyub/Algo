#include<cstdio>
#include<vector>
using namespace std;
bool fluged[101] = { false, };
int arr[101];
int main(){
	int n, k; scanf("%d%d", &n, &k);
	vector<int> v;
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &arr[i]);
		if (fluged[arr[i]] == false && cnt != n) {
			v.push_back(arr[i]);
			fluged[arr[i]] = true;
			cnt++;
		}
	}
	int result = 0;
	for (int i = cnt+1; i <= k; i++) {
		if (fluged[arr[i]]) continue;
		else {
			int flugIdx = -1;
			int distMax = 0;
			int vIdx = 0;
			for (int j = 0; j < v.size(); j++) {
				int dist = 0;
				int flag = 0;
				for (int l = i+1; l <= k; l++) {
					dist++;
					if (v[j]== arr[l]) {
						flag = 1;
						if (distMax < dist) {
							distMax = dist;
							flugIdx = v[j];
							vIdx = j;
						}	
						break;
					}
				}
				if (flag == 0) {
					flugIdx = v[j];
					vIdx = j;
					break;
				}
			}
			fluged[flugIdx] = false;
			fluged[arr[i]] = true;
			v[vIdx] = arr[i];
			result++;
		}
	}
	printf("%d", result);
}
