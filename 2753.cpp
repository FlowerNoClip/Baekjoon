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

	//윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.

	if (sol == 0 && (one != 0 || four == 0)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}