#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int A, B, C;

	cin >> A >> B >> C;

	cout << (A + B) % C << endl << ((A % C) + (B % C)) % C << endl << (A*B) % C << endl << ((A % C) * (B % C)) % C << endl;

}