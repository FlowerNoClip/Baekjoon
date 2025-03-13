#include <iostream>
#include <vector>
#include <algorithm>
#include <string>;
using namespace std;
const int MAX = 10001;
vector<bool> isSelfNumber(MAX, true);
int d(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;

}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	vector<int> nums(MAX, 0);
	for (int i = 1; i < MAX; i++)
	{
		int dn = d(i);
		if (dn < MAX)
		{
			isSelfNumber[dn] = false;
		}
	}
	

	for (int i = 1; i < MAX; i++)
	{
		if (isSelfNumber[i])
		{
			cout << i << endl;
		}
	}
}
