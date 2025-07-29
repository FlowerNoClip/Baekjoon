#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // INT_MIN, INT_MAX
#include <cmath>    // 수학 관련 함수

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int N;
vector<int> number;
int max_result = INT_MIN;
int min_result = INT_MAX;

void backtrack(int depth, int current_value, int plus, int minus, int mul, int div) {
    if (depth == N) {
        max_result = max(max_result, current_value);
        min_result = min(min_result, current_value);
        return;
    }

    if (plus > 0)
        backtrack(depth + 1, current_value + number[depth], plus - 1, minus, mul, div);
    if (minus > 0)
        backtrack(depth + 1, current_value - number[depth], plus, minus - 1, mul, div);
    if (mul > 0)
        backtrack(depth + 1, current_value * number[depth], plus, minus, mul - 1, div);
    if (div > 0)
        backtrack(depth + 1, current_value / number[depth], plus, minus, mul, div - 1);
}

int main() {
    FAST_IO;
    cin >> N;
    number.resize(N);
    for (int& a : number) cin >> a;

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    backtrack(1, number[0], plus, minus, mul, div);

    cout << max_result << "\n";
    cout << min_result << "\n";
}
