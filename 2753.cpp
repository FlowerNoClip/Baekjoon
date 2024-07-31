#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int sol;
	int one;
	int four;

	sol = N % 4;
	one = N % 100;
	four = N % 400;

	//������ ������ 4�� ����̸鼭, 100�� ����� �ƴ� �� �Ǵ� 400�� ����� ���̴�.

	if (sol == 0 && (one != 0 || four == 0)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}