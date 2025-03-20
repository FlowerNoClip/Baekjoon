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

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	int num;

	if (s1[3] != 'z') {
		num = stoi(s1) + 3;
	}
	if (s2[3] != 'z') {
		num = stoi(s2) + 2;
	}
	if (s3[3] != 'z') {
		num = stoi(s3) + 1;
	}

	if (num % 5 == 0 && num % 3 == 0) {
		cout << "FizzBuzz\n";
	}
	else if (num % 3 == 0) {
		cout << "Fizz\n";
	}
	else if (num % 5 == 0) {
		cout << "Buzz\n";
	}
	else {
		cout << num << endl;
	}
        // 이 코드는 다른사람 풀이 참고했음 
	return 0;
}


