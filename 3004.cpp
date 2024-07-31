#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max_pieces = 0;
    // ������ ��� (���� �ڸ��� Ƚ��, ���� �ڸ��� Ƚ��) ���� ���
    for (int h = 0; h <= N; ++h) {
        int v = N - h;
        int pieces = (h + 1) * (v + 1);
        max_pieces = max(max_pieces, pieces);
    }

    cout << max_pieces << endl;

    return 0;
}
