#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<char> ans;
	stack<int> myStack;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}	

	for (int i = 0; i < N; i++) {
		int su = A[i];
		if (myStack.empty()) {
			myStack.push(i);
			ans[i] = '+';
		}
		else {
			if (su == A[myStack.top()]) {
				myStack.pop();
				ans[i] = '-';
			}
			else if (su > A[myStack.top()]) {
				myStack.pop();
				ans[i] = '-';
			}
			else {
				myStack.push(i);
				ans[i] = '+';
			}

		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	

}