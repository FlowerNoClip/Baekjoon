#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int answer = 0;

    for (int i = 1; i <= N; i++)  
    {
        string temp = to_string(i);
        bool isHan = true;
        int tempint = temp[1] - temp[0];

        for (int j = 1; j < temp.length() - 1; j++)
        {
            if (temp[j + 1] - temp[j] != tempint) {
                isHan = false;
                break;
            }
        }
        if (isHan) answer++; 
    }

    cout << answer;
    return 0;
}
