#include <iostream>
#include <algorithm> // std::min �Լ� ����� ���� ���

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    int C, D;

    cin >> A >> B;
    cin >> C >> D;

    // ù ��° �ٱ��Ͽ��� ����� �������
    int moves1 = B + C; // ù ��° �ٱ����� �������� �� ��° �ٱ��Ϸ� + �� ��° �ٱ����� ����� ù ��° �ٱ��Ϸ�

    // ù ��° �ٱ��Ͽ��� �������� �������
    int moves2 = A + D; // ù ��° �ٱ����� ����� �� ��° �ٱ��Ϸ� + �� ��° �ٱ����� �������� ù ��° �ٱ��Ϸ�

    // �� ��� �� �ּҰ��� ���
    cout << min(moves1, moves2) << endl;

    return 0;
}
