#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	string s;

	while (true) {
		getline(cin, s);
		if (s == "") break;

		cout << s << '\n';
	}

    return 0;
}
