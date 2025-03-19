#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T = 0;
    while (true)
    {
        string temp = "";
        cin >> temp;
        if (temp == "0") break;

        string answer = "no";

        string revercetemp = temp;
        reverse(revercetemp.begin(), revercetemp.end());
        if (temp == revercetemp)
        {
            answer = "yes";
        }

        cout << answer << endl;
    }
}
