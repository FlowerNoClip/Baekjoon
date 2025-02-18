#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector <int>s(N, 0);
	int v;
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		cin >> s[i];
	}

	cin >> v;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == v) {
			sum += 1;
		}
	}

	cout << sum;
	

}