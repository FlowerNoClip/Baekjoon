#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<string> numbers;

    while (N--) {
        string s; cin >> s;
        string temp = "";
        for (char c : s) {
            if (isdigit(c)) {
                temp += c;
            } else {
                if (!temp.empty()) {
                    // 앞자리 0 제거
                    while (temp.size() > 1 && temp[0] == '0')
                        temp.erase(temp.begin());
                    numbers.push_back(temp);
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            while (temp.size() > 1 && temp[0] == '0')
                temp.erase(temp.begin());
            numbers.push_back(temp);
        }
    }
    sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });

    for (auto &num : numbers) {
        cout << num << "\n";
    }
}
