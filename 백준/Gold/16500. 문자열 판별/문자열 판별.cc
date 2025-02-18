#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;
int N;
string S;
vector<string> A;
bool DP[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < S.size(); i++) {
        if (DP[i] || i == 0) {
            int st = i;
            for (int j = 0; j < N; j++) { // 단어의 개수만큼 반복
                if (st + A[j].length() > S.length()) {
                    continue;
                }

                bool flag = true;
                for (int k = 0; k < A[j].length(); k++) { // 글자 수
                    if (A[j][k] != S[st + k]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    DP[st + A[j].length()] = true;
                }
            }
        }
    }

    cout << DP[S.length()];




}
