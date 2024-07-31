#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); // C++ ǥ�� ������� �ӵ� ����� ���� ���
	cin.tie(0);                  // ������� ����ȭ�� ����
	cout.tie(0);                 // ��� ��Ʈ���� ������ ����

	queue<int> myQueue;          // ������ ������ ť ����
	int N;                       // ������ ����
	cin >> N;                    // ���� ���� �Է�

	// 1���� N������ ���ڸ� ť�� �߰�
	for (int i = 1; i <= N; i++) {
		myQueue.push(i);
	}

	// ť�� ũ�Ⱑ 1���� Ŭ ���� �ݺ�
	while (myQueue.size() > 1) {
		myQueue.pop();                  // ù ��° ���ڸ� ����
		myQueue.push(myQueue.front());  // �� ��° ���ڸ� �� �ڷ� �̵�
		myQueue.pop();                  // �̵��� ���ڸ� �ٽ� ����
	}

	cout << myQueue.front();  // ť�� ���� �ִ� ������ ���ڸ� ���
}
