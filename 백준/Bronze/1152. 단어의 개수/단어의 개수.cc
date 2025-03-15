#include <iostream>
#include <vector>
#include <algorithm>
#include <string>;
#include <sstream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	string str; getline(cin, str);
	stringstream ss(str);
	string temp = "";
	int cnt = 0;
	while (ss >> temp)
	{
		cnt++;
	}

	cout << cnt;


}
