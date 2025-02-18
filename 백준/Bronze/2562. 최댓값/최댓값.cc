#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector <int> N(9);

    for (int i = 0; i < N.size(); i++) {
        cin >> N[i];
    }

    int max = 0;
    int num = 0;

    for (int i = 0; i < N.size(); i++) {
        if (N[i] > max) {
            max = N[i];
            num = i + 1;
        }
    }

    cout << max << endl << num;



}
