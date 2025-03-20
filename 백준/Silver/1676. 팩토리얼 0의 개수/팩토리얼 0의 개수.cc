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
	int N; cin >> N;

	int cnt = 0;
	for (int i = 5; i <= N; i *= 5)
	{
		cnt += N / i;
	}

	cout << cnt;
}


