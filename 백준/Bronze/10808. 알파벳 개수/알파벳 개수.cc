#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;

int main() {
	FAST_IO
	string str; 
    cin >> str;

	int arr[26] = {0};

	for(int i = 0; i < str.size(); i++)
	{
		arr[str[i] - 'a']++;
	}

	for(int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}