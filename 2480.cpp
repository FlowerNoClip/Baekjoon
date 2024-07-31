#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> A(3, 0);

	for (int i = 0; i < A.size(); i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int maxNum = A.back();


	if (A[0] == A[1] && A[1] == A[2]) { // 모든 숫자가 같은 경우
		cout << 10000 + (A[0] * 1000);
	}
	else if ((A[0] == A[1]) || ((A[1] == A[2]) || (A[0] == A[2]))) {
		if (A[0] == A[1]) {
			cout << 1000 + (A[0] * 100);
		}
		else if (A[1] == A[2]) {
			cout << 1000 + (A[1] * 100);
		}

		else if (A[0] == A[2]) {
			cout << 1000 + (A[0] * 100);
		}
	}
	else {
		cout << maxNum * 100;
	}

}