#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // C++ ǥ�� ��Ʈ���� C ǥ�� ��Ʈ���� ����ȭ�� �����Ͽ� ����� ������ ����
    cin.tie(NULL); // �Է°� ����� ���� �������ν� ���� ����ȭ
    cout.tie(NULL);

    int N, M;
    cin >> N >> M; // N�� �迭 ũ��, M�� ���� ��

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); // 1-based �ε����� ����ϱ� ���� N+1 ũ���� 2���� �迭 A ����

    vector<vector<int>> D(N + 1, vector<int>(N + 1, 0)); // ���� ���� ������ 2���� �迭 D ����

    // �迭 A�� �Է°��� �����ϰ�, ���� �� �迭 D�� ���
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            // D[i][j]�� (1,1)���� (i,j)������ �κ� ��� ��
            D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
        }
    }

    // M���� ���� ó��
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // �� ������ ��ǥ (x1, y1), (x2, y2) �Է�

        // D �迭�� ����Ͽ� ���� �� ���
        // (x1, y1)���� (x2, y2)������ ���� ���� ������ ���� ���
        int result = D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1];
        cout << result << endl; // ��� ���
    }
}
