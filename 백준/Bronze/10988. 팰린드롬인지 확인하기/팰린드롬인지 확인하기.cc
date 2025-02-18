#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    bool t;
    cin >> s;

    for (int i = 0; i < (s.length()/2); i++) 
    {
        if (s[i] == s[s.length()-1-i]) {
            t = true;
        }
        else {
            t = false;
            break;
        }
    }
    
    if (t == true) {
        cout << 1;
    }
    else {
        cout << 0;
    }

}
