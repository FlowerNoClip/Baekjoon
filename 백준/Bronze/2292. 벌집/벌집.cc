#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long N; cin >> N;
    int answer = 1;
    int max = 1;
    int add = 6;
    while (true)
    {
        if (N <= max) break;
        
        max += add;
        add += 6;
        answer++;
        
    }

    cout << answer;
    return 0;
}