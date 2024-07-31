#include <iostream>
#include <queue>

using namespace std;

// ����� ���� �� ����ü
struct compare {
	// �� ������ �����ε�
	bool operator()(int o1, int o2) {
		int first_abs = abs(o1);   // ù ��° ���� ����
		int second_abs = abs(o2);  // �� ��° ���� ����
		if (first_abs == second_abs) {
			return o1 > o2;        // ������ ������ ������ ������ ��
		}
		else {
			return first_abs > second_abs; // ������ ���� ������ �켱���� ����
		}
	}
};

int main() {
	ios::sync_with_stdio(false); // ǥ�� ����� �ӵ� ����� ���� ����
	cin.tie(0);                  // �Է°� ����� ������ ����
	cout.tie(0);                 // ��� ��Ʈ���� ������ ����

	priority_queue<int, vector<int>, compare > MyQueue; // ����� ���� �񱳸� ����� �켱���� ť ����

	int N;                       // ����� ����
	cin >> N;

	for (int i = 0; i < N; i++) {
		int request;
		cin >> request;

		if (request == 0) {
			// ť�� ��� ���� ��
			if (MyQueue.empty()) {
				cout << "0" << endl; // 0 ���
			}
			else {
				cout << MyQueue.top() << endl; // ���� �켱������ ���� �� ���
				MyQueue.pop();                 // ��� �� ť���� ����
			}
		}
		else {
			MyQueue.push(request); // 0�� �ƴ� ���, �켱���� ť�� ���� �߰�
		}
	}
}
