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
	vector<int> numbers(10, 0);

	int a = 0, b = 0, c= 0; cin >> a >> b >> c;
	int num = a * b * c;
	int temp;
	while (num != 0)
	{
		int temp;
		temp = num % 10;
		num /= 10;
		numbers[temp]++;
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

}
