#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<pair<int, string>> A(n);
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		A[i].first = temp.length();
		A[i].second = temp;
	}
	sort(A.begin(), A.end());
	cout << A[0].second << endl;
	for (int i = 1; i < n; i++) {
		if (A[i].second.compare(A[i - 1].second) == 0) continue;
		else cout << A[i].second << endl;
	}

}