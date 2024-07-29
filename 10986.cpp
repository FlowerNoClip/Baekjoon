#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long> S(N, 0);
    vector<long> C(M, 0);
    long answer = 0;

    // ù ��° �Է°�
    cin >> S[0];

    // ������ �Է°� ����
    for (int i = 1; i < N; i++) {
        int temp;
        cin >> temp;
        S[i] = S[i - 1] + temp;
    }

    // ������ ���� ������� ������ �迭 ������Ʈ
    for (int i = 0; i < N; i++) {
        int remainder = S[i] % M;

        if (remainder == 0) {
            answer++;
        }

        C[remainder]++;
    }

    // ������ �迭�� ������� ���� ���� ���
    for (int i = 0; i < M; i++) {
        if (C[i] > 1) {
            answer += C[i] * (C[i] - 1) / 2;
        }
    }

    cout << answer << "\n";
}
