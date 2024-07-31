#include <iostream>  // ����� ����� ���� �ʿ�
#include <vector>    // ���� �ڷᱸ�� ����� ���� �ʿ�
#include <deque>     // �� �ڷᱸ�� ����� ���� �ʿ�

using namespace std; // ǥ�� ���̺귯���� ���ӽ����̽� ���
typedef pair<int, int> Node; // (��, �ε���) ������ ���� Node�� ����

int main() {
    ios::sync_with_stdio(false); // C�� C++ ǥ�� ��Ʈ���� ����ȭ�� ��Ȱ��ȭ�Ͽ� ����� �ӵ��� ����
    cin.tie(0); // cin�� cout�� ������ �����Ͽ� �Է� �ӵ��� ����
    cout.tie(0); // cout�� ������ �����Ͽ� ��� �ӵ��� ����

    int N, L; // N�� ������ ����, L�� �����̵� �������� ũ��
    cin >> N >> L; // N�� L�� �Է¹���
    deque<Node> mydeque; // ���� ����Ͽ� ������ ���� �ּҰ��� ����

    for (int i = 0; i < N; i++) {
        int now; // ���� �Է� ���ڸ� ������ ����
        cin >> now; // ���ڸ� �Է¹���

        // ���� �ڿ������� ���� ���ں��� ū ��� ��Ҹ� ����
        while (!mydeque.empty() && mydeque.back().first > now) {
            mydeque.pop_back();
        }

        // ���� ���ڿ� �� �ε����� ���� �ڿ� �߰�
        mydeque.push_back(Node(now, i));

        // ���� ���ʿ� �ִ� ��Ұ� ������ ������ ����� ����
        if (mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }

        // ���� �����쿡���� �ּҰ��� ���
        cout << mydeque.front().first << " ";
    }
}
