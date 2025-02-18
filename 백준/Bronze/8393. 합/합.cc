#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int answer = 0;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		answer += i;
	}

	cout << answer;
}