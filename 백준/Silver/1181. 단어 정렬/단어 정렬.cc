#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	vector<string> str(T);
	string temp;
	for (int i = 0; i < T; i++) {
		cin >> str[i];
	}

	sort(str.begin(), str.end(), [](const string& a, const string& b)
		{
			if (a.length() == b.length())
			{
				return a < b;
			}
			return a.length() < b.length();
		});

	str.erase(unique(str.begin(), str.end()), str.end());

	for (const auto& s : str) {
		cout << s << '\n';
	}
}


