#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int count = 1;
	int sum = 1;
	int start_index = 1;
	int end_index = 1;

	while (end_index != N) {
		if (sum == N) {
			count++;
			end_index++;
			sum = sum + end_index;
		}

		else if (sum > N) {
			sum = sum - start_index;
			start_index++;
		}

		else {
			end_index++;
			sum = sum + end_index;
		}
	}

	cout << count << endl;
}