#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;

    cin >> a >> b;

	cout << gcd(a,b) << endl << lcm(a,b);


}
