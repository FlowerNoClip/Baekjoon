#include <iostream>>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

    for (int i = 1; i <= N; i++) {
        // 공백 출력
        for (int j = 0; j < N - i; j++) {
            cout << ' ';
        }
        // 별 출력
        for (int k = 0; k < i; k++) {
            cout << '*';
        }
        cout << endl;
    }

}