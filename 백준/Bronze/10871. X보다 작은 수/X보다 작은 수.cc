#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, X;
	cin >> N >> X;
	vector <int> S(N, 0);
	

	for (int i = 0; i < S.size(); i++) {
		cin >> S[i];
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i] < X) {
			cout << S[i] << " ";
		}
	}

	
}