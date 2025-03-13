#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    string str;
    cin >> str;
    int answer = 0;
    
    for (int i = 0; i < str.length(); i++)
    {
        answer += str[i] - '0';
    }

    cout << answer << endl;
}
