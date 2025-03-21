#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

struct coordinate {
	int x;
	int y;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;

	
	coordinate arr[100001];
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr+T, [](const coordinate& a, const coordinate& b) 
		{
		return (a.x == b.x) ? a.y > b.y : a.x > b.x;
		});

	reverse(arr, arr + T);

	for (int i = 0; i < T; i++)
	{
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
}


