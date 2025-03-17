#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> N(26, -1); // 알파벳 개수(26) 만큼 초기화
    string temp;
    cin >> temp;

    for (int j = 0; j < temp.length(); j++) {
        int idx = temp[j] - 'a'; 
        if (N[idx] == -1) {
            N[idx] = j;
        }
    }

    for (int i = 0; i < N.size(); i++) {
        cout << N[i] << " "; 
    }
    cout << endl;

    return 0;
}