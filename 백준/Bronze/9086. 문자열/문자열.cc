#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector <string> S(N);

	for (int i = 0; i < S.size(); i++)
	{
		cin >> S[i];
	}
	for (int i = 0; i < S.size(); i++)
	{
		cout << S[i].front() << S[i].back() << endl;
	}
}