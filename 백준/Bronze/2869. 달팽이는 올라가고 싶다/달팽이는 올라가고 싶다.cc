#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int A, B, V;

    cin >> A >> B >> V;

    int day = 1;
    day += (V - A) / (A - B);
    if ((V - A) % (A - B) != 0)
    {
        day++;
    }
    if (A >= V)
    {
        cout << "1";
    }
    else
    {
        cout << day;
    }
}
