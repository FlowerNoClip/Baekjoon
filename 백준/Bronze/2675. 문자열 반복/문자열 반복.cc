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
	int T; cin >> T;
	int N; 
	string temp;
	
	while (T--)
	{
		cin >> N;
		cin >> temp;
		for (int i = 0; i < temp.length(); i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << temp[i];
			}
		}
		cout << endl;
	}


}
