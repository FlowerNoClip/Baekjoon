#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<int> sum(26, 0); // 26개의 알파벳을 위한 벡터

    // 알파벳 대문자로 변환하면서 빈도수 계산
    for (char& ch : s) {
        ch = toupper(ch);
        sum[ch - 'A']++; // 알파벳 A는 인덱스 0, B는 1, ... Z는 25에 해당
    }

    int maxCount = 0;
    char lastChar = '?';
    bool same = false;

    for (int i = 0; i < 26; i++) {
        if (sum[i] > maxCount) {
            maxCount = sum[i];
            lastChar = 'A' + i; // 최대 빈도 문자를 업데이트
            same = false; // 최대가 변경되었으므로 false
        }
        else if (sum[i] == maxCount) {
            same = true; // 같은 최대 빈도 문자가 있음
        }
    }

    if (same) {
        cout << "?";
    }
    else {
        cout << lastChar;
    }

    return 0;
}
