#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    cin >> str;

    int zeroCount = 0;  // '0'이 연속으로 나온 구간 수
    int oneCount = 0;   // '1'이 연속으로 나온 구간 수

    bool in_zero_block = false;
    bool in_one_block = false;

    // 문자열을 한 번만 순회하면서 '0'과 '1' 구간을 각각 세기
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            if (!in_zero_block) {
                zeroCount++;
                in_zero_block = true;  // '0' 블록 시작
            }
            in_one_block = false;  // '1' 블록 종료
        } else if (str[i] == '1') {
            if (!in_one_block) {
                oneCount++;
                in_one_block = true;  // '1' 블록 시작
            }
            in_zero_block = false;  // '0' 블록 종료
        }
    }

    // 두 구간 수 중 더 작은 값을 출력
    cout << min(zeroCount, oneCount) << endl;
    
    return 0;
}
