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
	vector<int> N();
	int T; cin >> T;
	string temp;
	int answer;
	int count;
	while (T--)
	{
		cin >> temp;
		count = 1;
		answer = 0;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == 'O')
			{
				answer += count;
				count += 1;
			}
			else
			{
				count = 1;
			}
		}
		cout << answer << endl;
	}

	
}
