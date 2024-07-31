#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++ ����� �ӵ��� ���̱� ���� ����
	cin.tie(0);                  // ������� ����ȭ�� ����
	cout.tie(0);                 // ��� ��Ʈ���� ������ ����

	int N;                       // �迭�� ũ��
	cin >> N;
	vector<int> A(N, 0);         // �Էµ� ���ڸ� ������ ����
	vector<int> ans(N, 0);       // ����� ������ ����

	for (int i = 0; i < N; i++) {
		cin >> A[i];              // ���� �Է� �ޱ�
	}

	stack<int> myStack;          // ������ ����� �ε����� ����
	myStack.push(0);             // ���ÿ� ù ��° �ε��� �߰�

	for (int i = 1; i < N; i++) {
		// ������ ������� �ʰ�, ���� �ε����� ���� ������ �ֻ��� ������ Ŭ ������ �ݺ�
		while (!myStack.empty() && A[myStack.top()] < A[i]) {
			ans[myStack.top()] = A[i]; // ���� ū ���� ���� ��ġ�� ���
			myStack.pop();             // ���ÿ��� �ֻ��� �ε����� ����
		}
		myStack.push(i);               // ���� �ε����� ���ÿ� �߰�
	}

	// ���ÿ� �����ִ� �ε����� ���, ���� ū ���� �����Ƿ� -1�� ����
	while (!myStack.empty()) {
		ans[myStack.top()] = -1;
		myStack.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";        // ����� ���
	}
}
