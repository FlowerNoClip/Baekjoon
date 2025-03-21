#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;

	vector<pair<int, string>> arr(T);

	for (int i = 0; i < T; i++)
	{
		int temp = 0;
		string tempstr = "";
		cin >> temp >> tempstr;
		arr[i] = make_pair(temp, tempstr);
	}

	stable_sort(arr.rbegin(), arr.rend(), [](const pair<int, string>& a, const pair<int, string>& b) {
		return a.first > b.first; // `first` 값을 기준으로 내림차순 정렬
		});

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first << " " << arr[i].second << endl;
	}
}


