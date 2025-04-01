#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int result = 0;
    string temp = "";
    bool isMinus = false;

    for (int i = 0; i <= s.length(); i++) {
        if (i < s.length() && isdigit(s[i])) {
            temp += s[i];
        }
        else {
            int num = stoi(temp);
            if (isMinus) {
                result -= num; // '-' 이후 모든 숫자는 빼기
            }
            else {
                result += num; // '-' 이전 모든 숫자는 더하기
            }
            temp = "";

            if (i < s.length() && s[i] == '-') {
                isMinus = true; // '-' 등장하면 이후 숫자는 전부 빼기
            }
        }
    }

    cout << result << endl;
    return 0;
}